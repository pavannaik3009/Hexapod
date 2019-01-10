#define First_Line 0x80
#define Second_Line 0xc0
#define Curser_On  0x0f
#define Curser_Off 0x0c
#define Clear_Display 0x01

#define Data_Port PORTA

#define enable  PORTC |= 0x20
#define disable PORTC &= ~0x20

#define data_mode PORTC |= 0x80
#define cmd_mode  PORTC &= ~0x80

void Lcd4_Init();
void Lcd4_Command(unsigned char);
void Lcd4_Write(unsigned char,unsigned char);
void Lcd4_Display(unsigned char,const unsigned char*,unsigned int);
void Lcd4_Decimal2(unsigned char,unsigned char);
void Lcd4_Decimal3(unsigned char,unsigned char);
void Lcd4_Decimal4(unsigned char,unsigned int);
void Delay(unsigned int);

unsigned char Lcd_com1,Lcd_com2,Lcd_Temp;

void Lcd4_Init()
{
	DDRA=0xff;
	DDRC|=(1<<5)|(1<<6)|(1<<7);
	Lcd4_Command(0x38);		

	Lcd4_Command(0x02);		//return home

	Lcd4_Command(0x28);		//to select function set
	
	Lcd4_Command(0x06);		//entry mode set
	
	Lcd4_Command(0x0c);		//display on
	
	Lcd4_Command(0x01);		//clear display
}

void Lcd4_Display(unsigned char com,const unsigned char *word,unsigned int n)
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
	Lcd_com2 = Lcd_com2<<4;

//	disable;
	          		//sel command reg
	Lcd_Temp = Data_Port & 0x0f;        
	Data_Port=Lcd_Temp | Lcd_com1; 
	cmd_mode;          			//send com to po
	enable;            				//clock
	_delay_ms(5);
	disable;
	_delay_ms(5);
	Lcd_Temp = Data_Port & 0x0f;        
	Data_Port=Lcd_Temp | Lcd_com2;
	cmd_mode;           			//send com to po
	enable;            				//clock
	_delay_ms(5);
	disable;
	_delay_ms(5);
}

void Lcd4_Write(unsigned char com,unsigned char dat)
{
	Lcd4_Command(com);
	_delay_ms(5);
	Lcd_com1 = dat & 0xf0;
	Lcd_com2 = dat & 0x0f;
	Lcd_com2 = Lcd_com2<<4;	

//	disable;
	        					//sel data reg
	Lcd_Temp = Data_Port & 0x0f;        
	Data_Port=Lcd_Temp | Lcd_com1;  
	data_mode;        			//send com to po
	enable;            				//clock
	_delay_ms(5);
	disable; 
	_delay_ms(5);       					//sel data reg
	Lcd_Temp = Data_Port & 0x0f;        
	Data_Port=Lcd_Temp | Lcd_com2; 
	data_mode;         			//send com to po
	enable;            				//clock
	_delay_ms(5);
	disable;
	cmd_mode; 
	_delay_ms(5);
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

void Lcd4_Decimal4(unsigned char com,unsigned int val) 
{
	unsigned int Lcd_th,Lcd_thr,Lcd_h,Lcd_hr,Lcd_t,Lcd_o;

	val = val%10000;
	Lcd_th=val/1000;
	Lcd_thr=val%1000;
	Lcd_h=Lcd_thr/100;
	Lcd_hr=Lcd_thr%100;
	Lcd_t=Lcd_hr/10;
	Lcd_o=Lcd_hr%10;

	Lcd4_Write(com,Lcd_th+0x30);
	Lcd4_Write(com+1,Lcd_h+0x30);
	Lcd4_Write(com+2,Lcd_t+0x30);
	Lcd4_Write(com+3,Lcd_o+0x30);
}

void Delay(unsigned int del)
{
	while(del--);
}     
