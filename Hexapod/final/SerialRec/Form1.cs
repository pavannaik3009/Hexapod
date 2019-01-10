using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.IO.Ports;
using System.Windows.Forms;
using System.Threading;


namespace SerialRec
{

  
      
    public partial class Form1 : Form
    {
       
        internal delegate void SerialDataReceivedEventHandlerDelegate(object sender, SerialDataReceivedEventArgs e);
        delegate void SetTextCallback(string text);

        string InputData = String.Empty;
        public string inputbuf = String.Empty;
        public string inputbuf1 = String.Empty;
        public int n, i, initcmd;


        public Form1()
        {
            InitializeComponent();
            
          
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            string[] ArrayComPortsNames = null;
            int index = -1;
            string ComPortName = null;

            //Com Ports
            ArrayComPortsNames = SerialPort.GetPortNames();
            do
            {
                index += 1;
                cboPorts.Items.Add(ArrayComPortsNames[index]);
            }
            while (!((ArrayComPortsNames[index] == ComPortName) || (index == ArrayComPortsNames.GetUpperBound(0))));

            Array.Sort(ArrayComPortsNames);

            if (index == ArrayComPortsNames.GetUpperBound(0))
            {
                ComPortName = ArrayComPortsNames[0];
            }

            //get first item print in text
            cboPorts.Text = ArrayComPortsNames[0];


            cboBaudRate.Items.Add(110);
            cboBaudRate.Items.Add(600);
            cboBaudRate.Items.Add(1200);
            cboBaudRate.Items.Add(2400);
            cboBaudRate.Items.Add(9600);
            cboBaudRate.Items.Add(14400);
            cboBaudRate.Items.Add(19200);
            cboBaudRate.Items.Add(38400);
            cboBaudRate.Items.Add(57600);
            cboBaudRate.Items.Add(115200);
            cboBaudRate.Items.ToString();
            cboBaudRate.Text = cboBaudRate.Items[4].ToString(); 
        }

        

        private void serialPort1_DataReceived(object sender, SerialDataReceivedEventArgs e)
        {
            InputData = serialPort1.ReadExisting();
            if (InputData != String.Empty)
            {
                this.BeginInvoke(new SetTextCallback(SetText), new object[] { InputData });
            }
           
        }
        private void SetText(string text)
        {


            try
            {
                inputbuf += text;
                richTextBox1.Text = inputbuf;




                n = inputbuf.Length;


                for (i = 0; i <= n; i++)
                {

                    if (inputbuf.Substring(i, 1) == "*")
                    {
                        if (inputbuf.Substring(i + 1, 1) == "1")
                        {
                            label2.Text = "FIRE DETECTED";
                        }
                        else if (inputbuf.Substring(i + 1, 1) == "2")
                        {
                            label2.Text = "";
                        }
                        if (inputbuf.Substring(i + 1, 1) == "3")
                        {
                            label3.Text = "BOMB DETECTED";
                        }
                        else if (inputbuf.Substring(i + 1, 1) == "4")
                        {
                            label3.Text = "";
                        }
                    }
                }


            }
            catch (System.Exception excep)
            {

                label1.Text = excep.Message;

            }
        }


    
        private void SerialButton_Click_1(object sender, EventArgs e)
        {
            if (serialPort1.IsOpen==false)
            {
                serialPort1.PortName = Convert.ToString(cboPorts.Text);
                serialPort1.BaudRate = Convert.ToInt32(cboBaudRate.Text);
                serialPort1.Open();
                SerialButton.Text = "DisConnect";
            }
            else if (serialPort1.IsOpen == true)
            {
                serialPort1.Close();
                SerialButton.Text = "Connect";
            }
        }

        private void Form1_SizeChanged(object sender, EventArgs e)
        {
            Int32 x = Convert.ToInt32((Convert.ToDouble(this.Width) / 1.1) - 1);
            Int32 y =Convert.ToInt32((Convert.ToDouble(this.Height) / 1.5) - 40);

                
        }

        private void textBox3_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox2_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox4_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void button2_Click(object sender, EventArgs e)
        {

        }

        private void textBox1_TextChanged_1(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            serialPort1.Write("*1\r\n");
        }

        private void button4_Click(object sender, EventArgs e)
        {
            serialPort1.Write("*2\r\n");
        }

        private void button2_Click_1(object sender, EventArgs e)
        {
            serialPort1.Write("*3\r\n");
        }

        private void button5_Click(object sender, EventArgs e)
        {
            serialPort1.Write("*5\r\n");
        }

        private void button3_Click(object sender, EventArgs e)
        {
            serialPort1.Write("*4\r\n");
        }


        
    }
}
