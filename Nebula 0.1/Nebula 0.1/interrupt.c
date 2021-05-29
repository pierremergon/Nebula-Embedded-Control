#include "interrupt.h"
#include "config.h"
#include "apds9960.h"
#include <avr/sleep.h>

#define F_CPU 1000000UL
#include <util/delay.h>

unsigned char count = 0;

unsigned char int0Setup(void)
{	
	EICRA = (0x00);
	EIMSK |= (1<<INT0);
	return 0;
}

ISR(INT0_vect)
{  
	//sleep_disable();
	count = 1;
	solOn();
	//timerSetup(19530);
	apdsTransceive();
	i2c_start(nebula_write);
	i2c_write(0xE5);
	i2c_stop();	
	//sleep_mode();
	
}

unsigned char pcIntSetup(void)

{   
	PCICR |= (1<<PCIE1) | (1<<PCIE0);
	PCMSK1 |= (1<<PCINT10) |(1<<PCINT0);
	return 0;
}

ISR(PCINT1_vect)
{  // sleep_disable();
	if ((PINC & (1<<2))==0)
	{
	solOn();
	_delay_ms(500);
	solOff();
	_delay_ms(20);
	flashy();
	//sleep_mode();
	//_delay_ms(1000);
	}
}

ISR(PCINT0_vect)
{   //sleep_disable();
	//charging();
	//sleep_mode();
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
	//if (count == 1)
	//{
	solOff();
	count = 0;
	//}
	//TCCR1B = 0x00;
	flashy();
}
