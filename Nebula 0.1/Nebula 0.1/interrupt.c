#include "interrupt.h"
#include "config.h"
#include "apds9960.h"

#define F_CPU 1000000UL
#include <util/delay.h>

unsigned char int0Setup(void)
{	
	EICRA = (0x00);
	EIMSK |= (1<<INT0);
	return 0;
}

ISR(INT0_vect)
{   
	
	
	
	//i2c_check();
	//batteryLow();
	//flashy();
	//i2c_start(nebula_write);
	//i2c_write(0xE5);
	apdsTransceive();
	//i2c_start(nebula_write);
	//apdsTransceive();
	i2c_start(nebula_write);
	i2c_write(0xE5);
	i2c_stop();
	//i2c_start(nebula_write);
	//apdsSend(enableReg,0x25);
	//apdsStop();
	//_delay_ms(100);
	//i2c_write(0x00);	
}

unsigned char pcIntSetup(void)

{   
	PCICR |= (1<<PCIE1) | (1<<PCIE0);
	PCMSK1 |= (1<<PCINT10) |(1<<PCINT0);
	return 0;
}

ISR(PCINT1_vect)
{   
	if ((PINC & (1<<2))==0)
	{
	solOn();
	_delay_ms(500);
	solOff();
	_delay_ms(20);
	flashy();
	//_delay_ms(1000);
	}
}

ISR(PCINT0_vect)
{
	charging();
}
unsigned char timerSetup(unsigned int timerValue)
{
	TCCR1A = 0x00;// normal port operation, no PWM, etc
	TCCR1B = 0x05;// clock divided by 1024
	TCNT1 = 0;// sets the default value for the timer.
	OCR1A = timerValue;// sets the value for the timer delay, example the 2 minutes or few seconds.
	TIMSK1 = 0x01;// interrupt mask for timer 1A compare match
	return 0;
	
}

ISR(TIMER1_COMPA_vect)// Interrupt service routine  for timer
{
	solOff();
}
