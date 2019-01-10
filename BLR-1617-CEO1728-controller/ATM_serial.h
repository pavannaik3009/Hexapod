
//////////////////////////AT-MEGA164--TWO SERIALS////////////////////////////

#define F_CPU 8000000UL

void Serial0_Init(unsigned int);
void Serial1_Init(unsigned int);
void Serial0_Out(unsigned char);
void Serial1_Out(unsigned char);
void Serial0_Conout(const unsigned char *,unsigned char);
void Serial1_Conout(const unsigned char *,unsigned char);
void Serial0_Decimal3(unsigned char );
void Receive0(char);
void Receive1(char);

void Serial0_Init(unsigned int BAUD)
{
	DDRD |= (0<<0) | (1<<1);
	PORTD=0xff;
	UBRR0H = (((unsigned char)((F_CPU/(BAUD*16UL)))-1)>>8) ;
	UBRR0L = ((unsigned char)(F_CPU/(BAUD*16UL)))-1;
	UCSR0A = 0x80;
	UCSR0B = (0x01<<TXEN0);
    UCSR0C = (1<<URSEL0)|(3 << UCSZ10);
}
void Serial1_Init(unsigned int BAUD)
{
	DDRB |= (0<<3) | (1<<4);
	PORTB=0xff;
	UBRR1H = (unsigned char) (((F_CPU/(BAUD*16UL))-1)>>8) ;
	UBRR1L = (unsigned char) (F_CPU/(BAUD*16UL))-1;
	UCSR1A = 0x80;
	UCSR1B = (1<<TXEN1);
    UCSR1C = (1<<URSEL1)|(3 << UCSZ10);
}
void Serial0_Out(unsigned char data0)
{
	while ( !(UCSR0A & (1<<UDRE0)) ); //Wait for empty transmit buffer
	UDR0 = data0; //Start transmition
}
void Serial1_Out(unsigned char data1)
{
	while ( !(UCSR1A & (1<<UDRE1)) ); //Wait for empty transmit buffer
	UDR1 = data1; //Start transmition
}

void Serial0_Conout(const unsigned char *dat,unsigned char n)
{
	unsigned char ser_j;
	for(ser_j=0;ser_j<n;ser_j++)
	{
		Serial0_Out(dat[ser_j]);
	}
}
void Serial1_Conout(const unsigned char *dat,unsigned char n)
{
	unsigned char ser_j;
	for(ser_j=0;ser_j<n;ser_j++)
	{
		Serial1_Out(dat[ser_j]);
	}
}

void Serial0_Decimal3(unsigned char val)
{
	unsigned int Lcd_h,Lcd_hr,Lcd_t,Lcd_o;

	Lcd_h=val/100;
	Lcd_hr=val%100;
	Lcd_t=Lcd_hr/10;
	Lcd_o=Lcd_hr%10;
	
	Serial0_Out(Lcd_h+0x30);
	Serial0_Out(Lcd_t+0x30);
	Serial0_Out(Lcd_o+0x30);
}
void Receive0(char c)
{
	switch (c)
	{
		case 1:
		UCSR0B |= (1<<RXCIE0)|(1<<RXEN0);
		break;
		case 0:
		UCSR0B &= ~(1<<RXCIE0);
		UCSR0B &= ~(1<<RXEN0);
		break;
	}
}
void Receive1(char c)
{
	switch (c)
	{
		case 1:
		UCSR1B |= (1<<RXCIE1)|(1<<RXEN1);
		break;
		case 0:
		UCSR1B &= ~(1<<RXCIE1);
		UCSR1B &= ~(1<<RXEN1);
		break;
	}
}
