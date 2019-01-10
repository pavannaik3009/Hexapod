/*
 * led.c
 *
 * Created: 07-Nov-15 11:15:30 AM
 *  Author: Embedded
 */ 

#define F_CPU 8000000UL  
#include <avr/io.h>
#include<avr/interrupt.h>
#include <util/delay.h>
#include "ATMEGA_LCD4_NEW.h"
#include "TIMER0.h"
#include "ATM_serial.h"
void init();
void call();

#define fire ( !(PINC & (1<<4)) )
#define bomb ( !(PINC & (1<<5)) )

int time1,time2,time3,time4;
unsigned char toggle,a;
unsigned char rec[16],r;
void servo1(int a)
{
	if(a==0) step1=11;
	else if(a==90) step1=8;
	else if(a==180) step1=5;
}
void servo1a(int a)
{
	if(a==0) step2=16;
	else if(a==90) step2=14;
	else if(a==180) step2=10;
}
void servo1b(int a)
{
	if(a==0) step3=12;
	else if(a==90) step3=15;
	else if(a==180) step3=19;
}

void servo2(int a)
{
	if(a==0) step4=15;
	else if(a==90) step4=12;
	else if(a==180) step4=8;
}
void servo2a(int a)
{
	if(a==0) step5=16;
	else if(a==90) step5=15;
	else if(a==180) step5=10;
}
void servo2b(int a)
{
	if(a==0) step6=12;
	else if(a==90) step6=14;
	else if(a==180) step6=18;
}

void servo3(int a)
{
	if(a==0) step7=14;
	else if(a==90) step7=11;
	else if(a==180) step7=7;
}
void servo3a(int a)
{
	if(a==0) step8=10;
	else if(a==90) step8=8;
	else if(a==180) step8=4;
}
void servo3b(int a)
{
	if(a==0) step9=12;
	else if(a==90) step9=17;
	else if(a==180) step9=19;
}

void servo4(int a)
{
	if(a==0) step10=13;
	else if(a==90) step10=17;
	else if(a==180) step10=20;
}
void servo4a(int a)
{
	if(a==0) step11=10;
	else if(a==90) step11=12;
	else if(a==180) step11=16;
}
void servo4b(int a)
{
	if(a==0) step12=11;
	else if(a==90) step12=14;
	else if(a==180) step12=19;
}

void servo5(int a)
{
	if(a==0) step13=16;
	else if(a==90) step13=20;
	else if(a==180) step13=24;
}
void servo5a(int a)
{
	if(a==0) step14=18;
	else if(a==90) step14=20;
	else if(a==180) step14=25;
}
void servo5b(int a)
{
	if(a==0) step15=13;
	else if(a==90) step15=15;
	else if(a==180) step15=19;
}

void servo6(int a)
{
	if(a==0) step16=15;
	else if(a==90) step16=19;
	else if(a==180) step16=22;
}
void servo6a(int a)
{
	if(a==0) step17=19;
	else if(a==90) step17=22;
	else if(a==180) step17=25;
}
void servo6b(int a)
{
	if(a==0) step18=11;
	else if(a==90) step18=15;
	else if(a==180) step18=18;
}
unsigned int cc;
void forward(int a)
{
	switch (a)
	{
		case 1:
		servo2(0);servo2a(0);
		servo4(0);servo4a(0);
		servo6(0);servo6a(0);
		break;
		case 2:
		servo3b(180);servo1b(90);servo5b(90); // forward position(1,3,5)
		break;
		case 3:
		servo2(90);servo2a(90);
		servo4(90);servo4a(90);
		servo6(90);servo6a(90);
		break;
		case 4:
		servo1(0);servo1a(0);
		servo3(0);servo3a(0);
		servo5(0);servo5a(0);
		break;
		case 5:
		servo2b(180);servo6b(90);servo4b(0);
		break;
		case 6:
		servo1(90);servo1a(90);
		servo3(90);servo3a(90);
		servo5(90);servo5a(90);
		break;
		case 7:
		servo2(0);servo2a(0);
		servo4(0);servo4a(0);
		servo6(0);servo6a(0);
		break;
		case 8:
		servo3b(180);servo1b(90);servo5b(90);
		servo2b(90);servo6b(180);servo4b(90);
		break;
		case 9:
		servo2(90);servo2a(90);
		servo4(90);servo4a(90);
		servo6(90);servo6a(90);
		break;
		case 10:
		servo1(0);servo1a(0);
		servo3(0);servo3a(0);
		servo5(0);servo5a(0);
		break;
		case 11:
		servo3b(90);servo1b(0);servo5b(180);
		servo2b(180);servo6b(90);servo4b(0);
		break;
		case 12:
		servo1(90);servo1a(90);
		servo3(90);servo3a(90);
		servo5(90);servo5a(90);
		break;
		default:
		servo1(90);servo1a(90);
		servo2(90);servo2a(90);
		servo3(90);servo3a(90);
		servo4(90);servo4a(90);
		servo5(90);servo5a(90);
		servo6(90);servo6a(90);
		break;
	}
}
void reverse(int a)
{
	switch (a)
	{
		case 1:
		servo2(0);servo2a(0);
		servo4(0);servo4a(0);
		servo6(0);servo6a(0);
		break;
		case 2:
		servo3b(90);servo1b(0);servo5b(180);
		break;
		case 3:
		servo2(90);servo2a(90);
		servo4(90);servo4a(90);
		servo6(90);servo6a(90);
		break;
		case 4:
		servo1(0);servo1a(0);
		servo3(0);servo3a(0);
		servo5(0);servo5a(0);
		break;
		case 5:
		servo2b(90);servo6b(180);servo4b(90);
		break;
		case 6:
		servo1(90);servo1a(90);
		servo3(90);servo3a(90);
		servo5(90);servo5a(90);
		break;
		case 7:
		servo2(0);servo2a(0);
		servo4(0);servo4a(0);
		servo6(0);servo6a(0);
		break;
		case 8:
		servo3b(90);servo1b(0);servo5b(180);
		servo2b(180);servo6b(90);servo4b(0);
		break;
		case 9:
		servo2(90);servo2a(90);
		servo4(90);servo4a(90);
		servo6(90);servo6a(90);
		break;
		case 10:
		servo1(0);servo1a(0);
		servo3(0);servo3a(0);
		servo5(0);servo5a(0);
		break;
		case 11:
		servo3b(180);servo1b(90);servo5b(90);
		servo2b(90);servo6b(180);servo4b(90);
		break;
		case 12:
		servo1(90);servo1a(90);
		servo3(90);servo3a(90);
		servo5(90);servo5a(90);
		break;
		default:
		servo1(90);servo1a(90);
		servo2(90);servo2a(90);
		servo3(90);servo3a(90);
		servo4(90);servo4a(90);
		servo5(90);servo5a(90);
		servo6(90);servo6a(90);
		break;
	}
}
void right(int a)
{
	switch (a)
	{
		case 1:
		servo3(0);servo3a(0);servo3b(0);
		break;
		case 2:
		servo3(90);servo3a(90);
		break;
		case 3:
		servo2(0);servo2a(0);servo2b(0);
		break;
		case 4:
		servo2(90);servo2a(90);
		break;
		
		case 5:
		servo6(0);servo6a(0);servo6b(0);
		break;
		case 6:
		servo6(90);servo6a(90);
		break;
		case 7:
		servo5(0);servo5a(0);servo5b(0);
		break;
		case 8:
		servo5(90);servo5a(90);
		break;
		
		case 9:
		servo1(0);servo1a(0);servo1b(0);
		break;
		case 10:
		servo1(90);servo1a(90);
		break;
		
		case 11:
		servo4(0);servo4a(0);servo4b(0);
		break;
		case 12:
		servo4(90);servo4a(90);
		break;
		
		case 13:
		servo3b(180);servo2b(180);servo1b(180);
		servo6b(180);servo5b(180);servo4b(180);
		break;
		
		
		default:
		servo1(90);servo1a(90);
		servo3(90);servo3a(90);
		servo5(90);servo5a(90);
		servo2(90);servo2a(90);
		servo4(90);servo4a(90);
		servo6(90);servo6a(90);
		break;
	}
}
void left(int a)
{
	switch (a)
	{
		case 1:
		servo3(0);servo3a(0);servo3b(180);
		break;
		case 2:
		servo3(90);servo3a(90);
		break;
		case 3:
		servo2(0);servo2a(0);servo2b(180);
		break;
		case 4:
		servo2(90);servo2a(90);
		break;
		
		case 5:
		servo6(0);servo6a(0);servo6b(180);
		break;
		case 6:
		servo6(90);servo6a(90);
		break;
		case 7:
		servo5(0);servo5a(0);servo5b(180);
		break;
		case 8:
		servo5(90);servo5a(90);
		break;
		
		case 9:
		servo1(0);servo1a(0);servo1b(180);
		break;
		case 10:
		servo1(90);servo1a(90);
		break;
		
		case 11:
		servo4(0);servo4a(0);servo4b(180);
		break;
		case 12:
		servo4(90);servo4a(90);
		break;
		
		case 13:
		servo3b(0);servo2b(0);servo1b(0);
		servo6b(0);servo5b(0);servo4b(0);
		break;
		
		
		default:
		servo1(90);servo1a(90);
		servo3(90);servo3a(90);
		servo5(90);servo5a(90);
		servo2(90);servo2a(90);
		servo4(90);servo4a(90);
		servo6(90);servo6a(90);
		break;
	}
}

void stop1(int a)
{
	switch (a)
	{
		case 1:
			servo1(0);servo1a(0);servo1b(0);
			break;
		case 2:
			servo1(90);servo1a(90);
			break;
		case 3:
			servo2(0);servo2a(0);servo2b(90);
			break;
		case 4:
			servo2(90);servo2a(90);
			break;
		
		case 5:
			servo3(0);servo3a(0);servo3b(180);
			break;
		case 6:
			servo3(90);servo3a(90);
			break;
		case 7:
			servo4(0);servo4a(0);servo4b(0);
			break;
		case 8:
			servo4(90);servo4a(90);
			break;
		
		case 9:
			servo5(0);servo5a(0);servo5b(90);
			break;
		case 10:
			servo5(90);servo5a(90);
			break;
		case 11:
			servo6(0);servo6a(0);servo6b(180);
			break;
		case 12:
			servo6(90);servo6a(90);
			break;
		
		default:
			servo1(90);servo1a(90);
			servo3(90);servo3a(90);
			servo5(90);servo5a(90);
			servo2(90);servo2a(90);
			servo4(90);servo4a(90);
			servo6(90);servo6a(90);
			break;
	}
}
int all,flag;
unsigned char forw,rev,lef,rig,stop=1;
char one,two,three,four;

int main()
{
	init();


    while(1)
    {
		if(fire==0) 
		{
			if(one==0)
			{
				Serial0_Conout("*1\r",3);
				Lcd4_Write(0xc0,'F');
				one=1;two=0;
			}
		}
		else 
		{
			if(two==0)
			{
				Serial0_Conout("*2\r",3);
				Lcd4_Write(0xc0,' ');
				one=0;two=1;
			}
		}
		
		if(bomb==1)
		{
			if(three==0)
			{
				Serial0_Conout("*3\r",3);
				Lcd4_Write(0xc2,'B');
				three=1;four=0;
			}
		}
		else
		{
			if(four==0)
			{
				Serial0_Conout("*4\r",3);
				Lcd4_Write(0xc2,' ');
				three=0;four=1;
			}
		}
		//Lcd4_Decimal3(0xc0,r);
		if(flag==1)
		{
			flag=0;
			if(rec[1]=='1')
			{
				Lcd4_Display(0xc0,"    FORWARD     ",16);
				forw=1;rev=0;lef=0;rig=0;stop=0;toggle=0;a=0;
			}
			else if(rec[1]=='2')
			{  
				Lcd4_Display(0xc0,"    REVERSE     ",16);
				forw=0;rev=1;lef=0;rig=0;stop=0;toggle=0;a=0;
			}
			else if(rec[1]=='3')
			{
				Lcd4_Display(0xc0,"       LEFT     ",16);
				forw=0;rev=0;lef=1;rig=0;stop=0;toggle=0;a=0;
			}
			else if(rec[1]=='4')
			{
				Lcd4_Display(0xc0,"       RIGHT    ",16);
				forw=0;rev=0;lef=0;rig=1;stop=0;toggle=0;a=0;
			}
			else if(rec[1]=='5')
			{
				Lcd4_Display(0xc0,"      STOP      ",16);
				forw=0;rev=0;lef=0;rig=0;stop=1;toggle=0;a=0;
			}
			Receive0(1);
		}
		
		if(dd>3000) 
		{
			if(forw==1)
			{
				forward(toggle);
				toggle++;
				if(toggle>12) {toggle=7;all++;}
			}
			else if(lef==1)
			{
				if(a<4)
				{
					left(toggle);
					toggle++;
					if(toggle>13){toggle=1;a++;}
					if(a==4) toggle=0;
				}
				else
				{
					forward(toggle);
					toggle++;
					if(toggle>12) {toggle=7;}
				}
			}
			else if(rev==1)
			{
				reverse(toggle);
				toggle++;
				if(toggle>12) {toggle=7;}
			}
			else if(rig==1)
			{
				if(a<4)
				{
					right(toggle);
					toggle++;
					if(toggle>13){toggle=1;a++;}
					if(a==4) toggle=0;
				}
				else
				{
					forward(toggle);
					toggle++;
					if(toggle>12) {toggle=7;}
				}
			}
			else if(stop==1)
			{
				stop1(toggle);   
				toggle++;
				if(toggle>16) {toggle=0;}
			}
			dd=0;
		}
	
    }
}


void init()
{
	DDRB = 0xff;
	PORTB = 0xff; 
	
	DDRC = 0x0f;
	PORTC= 0xff;
	
	DDRD = 0xfe;
	PORTD = 0xff;
	
	cli();
	Lcd4_Init();
	timer_init();
	Serial0_Init(9600);
	Serial0_Conout("WORKING\r",8);
	Receive0(1);
	

	Lcd4_Display(0x80," HEXAPOD ROBOT  ",16);

	
	sei();	
}

void call()
{
	_delay_ms(100);
	Lcd4_Decimal2(0x80,time1);
	Lcd4_Decimal2(0x8a,time2);
	Lcd4_Decimal2(0xc0,time3);
	Lcd4_Decimal2(0xca,time4);
}

ISR (USART0_RXC_vect)
{
	rec[r]=UDR0;
	if(rec[0]=='*') r++;
	if(r>=2) {r=0;flag=1;Receive0(0);}
}