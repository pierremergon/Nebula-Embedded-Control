#include "config.h"
#include "i2c.h"
#include "apds9960.h"


unsigned char unUsed (void)//disable unused ports
{
	DDRB |= (1<<6)|(1<<7);
	DDRC |= (1<<0)|(1<<1)|(1<<2)|(1<<3)|(1<<6)|(1<<7);
	DDRD |= (1<<0)|(1<<1);
	DDRB |= (1<<0)|(1<<1)|(1<<2);//set as led output
	return 0;
}

//solenoid operations
unsigned char solOn(void)
{   PORTD |=(1<<5);
	PORTD =(1<<PORTD6)|(0<<PORTD7);//forward
	PORTD &= ~(1<<5);//SLEEP
	return 0;
}

unsigned char solOff(void)
{   PORTD |=(1<<5);
	PORTD =(0<<PORTD6)|(1<<PORTD7);//reverse
	PORTD &= ~(1<<5);//SLEEP
	return 0;
}


//LED Indication Operations
unsigned char systemGo(void)
{//green connects to PB2
	PORTB &= ~(1<<PORTB2);

	return 0;
}

unsigned char systemNoGo(void)
{//red led on PB0
	//PORTB =(0<<PORTB0);
	PORTB |= (1<<PORTB2);
	return 0;
}

unsigned char systemSetup(void)
{
	PORTB &= ~(1<<PORTB1);
	return 0;
}
/////////////////////////////////////////////////////////////////////////////Sleep States
unsigned char powerSave(void)//sleep length
{
	SMCR |= ~(1<<SM2)|(1<<SM1)|(1<<SM0);
	return 0;
}
unsigned char idle(void)
{

	return 0;
}

//////////////////////////////////////////////////////////////////////////////////////
unsigned char ledInit(void)//initialize led to zero
{
	DDRC = 0xFF;
	DDRB = 0x07;
	PORTB |= ((1<<PORTB0))|((1<<PORTB1))|((1<<PORTB2));//set them as output,turn off led lights
	return 0;
}

//Timer Operation
unsigned char proxDuration(unsigned char t)//timer duration
{	TCCR0A |=(0X02);//ports not used, timer is in ctc mode

	//For Proximity sensed, there is a delay of 3 seconds from the time that it does not detect a user
	return 0;
}
unsigned char gestureDuration(unsigned char t)//timer duration
{

return 0;
}

unsigned char apds9960_prox_write(void)
{
	apdsBegin(nebula_write);
	apdsSend(0x80,0x25);//enable reg
	apdsSend(0x8C,0x40);//persistence reg
	apdsSend(0x8B,0xFA);// high int threshold
	apdsSend(0x89,0x05);//low int threshold
	apdsSend(0x8E,0x54);//prox pulse count
	return 0;
}
unsigned char portSetup(void)
{
	//battery indicator ports
	DDRB |= (1<<6);
	PORTB &= ~(1<<6);
	DDRB |= (1<<7);
	PORTB &= ~(1<<7);
	//button initialize
	DDRD &= ~(1<<1);//Input pin
	PORTD |= (1<<1);//PULL UP

}
//initializes and checks the battery status 1=
unsigned char checkBattery(void) {
	unsigned char batteryStatus;
	PORTB |= (1<<6);
	DDRB &= ~(1<<7);
	PINB |=(7);
	if ((PINB & 7)==1)
	{
		batteryStatus=1;
	}
	else
	{
		batteryStatus=0;
	}
	return batteryStatus;
}

unsigned char batteryLow(void)//low battery indicator
{
	;
}
unsigned char fullCharge(void)//full charge indictor
{
	;
}
//Button press actions 
unsigned char buttonPress(void)
{
	;
}


