#define First_Line 0x80
#define Second_Line 0xc0
#define Curser_On  0x0f
#define Curser_Off 0x0c
#define Clear_Display 0x01
#define Data_Port PORTA
#define enable  PORTA |= 0x10  // pin 35
#define disable PORTA &= ~0x10
#define data_mode PORTA |= 0x20  // pin 34
#define cmd_mode  PORTA &= ~0x20

void Lcd4_Init();
void Lcd4_Command(unsigned char);
void Lcd4_Write(unsigned char,unsigned char);
void Lcd4_Display(unsigned char,const  char*,unsigned int);
void Lcd4_Decimal2(unsigned char,unsigned char);
void Lcd4_Decimal3(unsigned char,unsigned char);
//void Lcd4_Decimal4(unsigned char,unsigned int);
void Delay(unsigned int);

unsigned char Lcd_com1,Lcd_com2,Lcd_Temp;

void Lcd4_Init()
{
	DDRA=0x3f;
	Lcd4_Command(0x38);		
	Lcd4_Command(0x02);		//return home
	Lcd4_Command(0x28);		//to select function set	
	Lcd4_Command(0x06);		//entry mode set
	Lcd4_Command(0x0c);		//display on	
	Lcd4_Command(0x01);		//clear display
}
void Lcd4_Display(unsigned char com,const  char *word,unsigned int n)
{
	unsigned char Lcd_i;
	for(Lcd_i=0;Lcd_i<n;Lcd_i++)
	{ 
		Lcd4_Write(com+Lcd_i,word[Lcd_i]);
  	}
}
void Lcd4_Command(unsigned char com)
{
	Lcd_com1 = com & 0xf0;
	Lcd_com2 = com & 0x0f;
	Lcd_com1 = Lcd_com1>>4;

//	disable;
	          		//sel command reg
	Lcd_Temp = Data_Port & 0xf0;        
	Data_Port=Lcd_Temp | Lcd_com1; 
	cmd_mode;		//send com to po
	enable;         //clock
	_delay_ms(1);
	disable;
	_delay_ms(1);
	Lcd_Temp = Data_Port & 0xf0;        
	Data_Port=Lcd_Temp | Lcd_com2;
	cmd_mode;       //send com to po
	enable;         //clock
	_delay_ms(1);
	disable;
	_delay_ms(1);
}
void Lcd4_Write(unsigned char com,unsigned char dat)
{
	Lcd4_Command(com);
	_delay_ms(1);
	Lcd_com1 = dat & 0xf0;
	Lcd_com2 = dat & 0x0f;
	Lcd_com1 = Lcd_com1>>4;	

//	disable;
	        					//sel data reg
	Lcd_Temp = Data_Port & 0xf0;        
	Data_Port=Lcd_Temp | Lcd_com1;  
	data_mode;        			//send com to po
	enable;            				//clock
	_delay_ms(1);
	disable; 
	_delay_ms(1);       					//sel data reg
	Lcd_Temp = Data_Port & 0xf0;        
	Data_Port=Lcd_Temp | Lcd_com2; 
	data_mode;         			//send com to po
	enable;            				//clock
	_delay_ms(1);
	disable;
	cmd_mode; 
	_delay_ms(1);
}
void Lcd4_Decimal2(unsigned char com,unsigned char val)
{
	unsigned int Lcd_hr,Lcd_t,Lcd_o;

	Lcd_hr=val%100;
	Lcd_t=Lcd_hr/10;
	Lcd_o=Lcd_hr%10;
	
	Lcd4_Write(com,Lcd_t+0x30);
	Lcd4_Write(com+1,Lcd_o+0x30);
}
void Lcd4_Decimal3(unsigned char com,unsigned char val)
{
	unsigned int Lcd_h,Lcd_hr,Lcd_t,Lcd_o;

	Lcd_h=val/100;
	Lcd_hr=val%100;
	Lcd_t=Lcd_hr/10;
	Lcd_o=Lcd_hr%10;
	
	Lcd4_Write(com,Lcd_h+0x30);
	Lcd4_Write(com+1,Lcd_t+0x30);
	Lcd4_Write(com+2,Lcd_o+0x30);
}

void Delay(unsigned int del)
{
	while(del--);
}     
