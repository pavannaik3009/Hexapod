

unsigned int delay0,dd;
unsigned char step1,step2,step3,step4,step5,step6,step7,step8,step9;
unsigned char step10,step11,step12,step13,step14,step15,step16,step17,step18;

void timer_init()
{
	TCCR0 = (1<<CS01) ;// start timer0 with /1024 prescaler
	TCNT0=0x9D;// set timer0 counter initial value 
	
	TIMSK=(1<<TOIE0);
	
/*	TCCR1B = (1<<CS12) | (1<<CS10) ;// start timer1 with /1024 prescaler
	TCNT1H=0xFC;
	TCNT1L=0xF4;
 	
	TCCR2 = (1<<CS20) | (1<<CS21) |  (1<<CS22) ;// start timer2 with /1024 prescaler
	TCNT2=0x3D;// set timer2 counter initial value

	
	TCCR3B = (1<<CS32) | (1<<CS30) ;// start timer3 with /1024 prescaler
	TCNT3H=0xFC;					//not working accurately
	TCNT3L=0xF4;
	
	TIMSK=(1<<TOIE0) | (1<<TOIE1) | (1<<TOIE2) ;
	ETIMSK=(1<<TOIE3);
*/
	
	
}

ISR(TIMER0_OVF_vect)
{
	TCNT0=0x9D;		//EVERY 100us
	
	if(delay0<step1) PORTB |= (1<<0);
	else PORTB &= ~(1<<0);
	
	if(delay0<step2) PORTB |= (1<<1);
	else PORTB &= ~(1<<1);
	
	if(delay0<step3) PORTB |= (1<<2);
	else PORTB &= ~(1<<2);
	
	if(delay0<step4) PORTB |= (1<<3);
	else PORTB &= ~(1<<3);
	
	if(delay0<step5) PORTB |= (1<<4);
	else PORTB &= ~(1<<4);
	
	if(delay0<step6) PORTB |= (1<<5);
	else PORTB &= ~(1<<5);
	
	if(delay0<step7) PORTB |= (1<<6);
	else PORTB &= ~(1<<6);
	
	if(delay0<step8) PORTB |= (1<<7);
	else PORTB &= ~(1<<7);

//
	
	if(delay0<step9) PORTD |= (1<<2);
	else PORTD &= ~(1<<2);
	
	if(delay0<step10) PORTD |= (1<<3);
	else PORTD &= ~(1<<3);

	if(delay0<step11) PORTD |= (1<<4);
	else PORTD &= ~(1<<4);
	
	if(delay0<step12) PORTD |= (1<<5);
	else PORTD &= ~(1<<5);
	
	if(delay0<step13) PORTD |= (1<<6);
	else PORTD &= ~(1<<6);
	
	if(delay0<step14) PORTD |= (1<<7);
	else PORTD &= ~(1<<7);

//

	if(delay0<step15) PORTC |= (1<<0);
	else PORTC &= ~(1<<0);
	
	if(delay0<step16) PORTC |= (1<<1);
	else PORTC &= ~(1<<1);
	
	if(delay0<step17) PORTC |= (1<<2);
	else PORTC &= ~(1<<2);
	
	if(delay0<step18) PORTC |= (1<<3);
	else PORTC &= ~(1<<3);
//

	delay0++;dd++;
	
	if(delay0>200)	delay0=0;//20ms	
}

/*
ISR(TIMER1_OVF_vect)
{
	TCNT1H=0xFC;
	TCNT1L=0xF4;	//100ms
	delay1++;
	if(delay1>=10)	//200ms
	{
		PORTB ^= (1<<1);time3++;
		delay1=0;
	}
}

ISR(TIMER2_OVF_vect)
{
	TCNT2=0x3D;		//EVERY 25ms
	delay2++;	
	if(delay2>=40)	//1000ms
	{
		PORTB ^= (1<<2);time1++;
		delay2=0;
	}
}

ISR(TIMER3_OVF_vect)
{
	TCNT3H=0xFC;
	TCNT3L=0xF4;
	delay3++;
	
	if(delay3>=10)	//1000ms working accurately only in hardware
	{
		PORTB ^= (1<<3);time4++;
		delay3=0;
	}
}
*/

/*

	CS02	CS01	CS00	DEFAULTLY ZERO
	0		0		0		NO CLK SOURCE TIMER/COUNTER STOPPED
	0		0		1		NO PRESCALING
	0		1		0		CLK/8
	0		1		1		CLK/64
	1		0		0		CLK/256
	1		0		1		CLK/1024
	1		1		0		EXTERNAM CLK ON T0 PIN.CLK ON FALLING EDGE
	1		1		1		EXTERNAM CLK ON T0 PIN.CLK ON RISING EDGE
	
	CS12	CS11	CS10	DEFAULTLY ZERO
	0		0		0		NO CLK SOURCE TIMER/COUNTER STOPPED
	0		0		1		NO PRESCALING
	0		1		0		CLK/8
	0		1		1		CLK/64
	1		0		0		CLK/256
	1		0		1		CLK/1024
	1		1		0		EXTERNAM CLK ON T1 PIN.CLK ON FALLING EDGE
	1		1		1		EXTERNAM CLK ON T1 PIN.CLK ON RISING EDGE
	
	CS22	CS21	CS20	DEFAULTLY ZERO
	0		0		0		NO CLK SOURCE TIMER/COUNTER STOPPED
	0		0		1		NO PRESCALING
	0		1		0		CLK/8
	0		1		1		CLK/32
	1		0		0		CLK/64	
	1		0		1		CLK/128
	1		1		0		CLK/256
	1		1		1		CLK/1024
	
	CS32	CS31	CS30	DEFAULTLY ZERO
	0		0		0		NO CLK SOURCE TIMER/COUNTER STOPPED
	0		0		1		NO PRESCALING
	0		1		0		CLK/8
	0		1		1		CLK/64
	1		0		0		CLK/256
	1		0		1		CLK/1024
	1		1		0		CLK/16
	1		1		1		CLK/32
*/

/*
	COUNT	=	(DELAY/CLOCK_TIME_PERIOD)-1					CLOCK_TIME_PERIOD=1/CLOCK_FRQUENCY		
															CLOCK_FRQUENCY=CLOCK_FRQUENCY/PRESCALE
															
we need 100ms	-->
															CLOCK_TIME_PERIOD=1/7812.5	=	128us
															CLOCK_FRQUENCY=8Mhz/1024	=	7812.5	
	COUNT	=	(100ms/128us)-1		=	780.25
	8 bit timer	=	256 counts
	we need	780	counts
		780/256	=	3.04	(not so accurate WE NEED WHOLE NUMBER)
		780/4	=	195
		
		if we count 195 pulses for 4 times	--> 100 ms
		
		To count 195 pulses	256-195	=	61	-->		0x3D
		
	16 bit timer	=	65536 counts
	we need	780	counts
		
		65536-780	=	64756	-->	FCF4

*/