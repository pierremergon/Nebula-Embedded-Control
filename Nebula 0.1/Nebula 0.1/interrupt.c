#include <avr/interrupt.h>
#include "interrupt.h"
#include "config.h"
#include "apds9960.h"

#define F_CPU 1000000UL

unsigned char int0Setup(void)
{
	return 0;
}

unsigned char pcIntSetup(void)

{
	PCICR |= (1<<PCIE1);
	PCMSK1 |= (1<<PCINT10);
	sei();
	return 0;
}

ISR(PCINT1_vect)
{
	//flashy();
	//charging();
	batteryLow();

}
/*
INT0_vect()
{
	//prox etc
	return 0;
}
*/

unsigned char timerSetup(unsigned int timerValue)
{
	TCCR1A = 0x00;// normal port operation, no PWM, etc
	TCCR1B = 0x05;// clock divided by 1024
	TCNT1 = 0;// sets the default value for the timer.
	OCR1A = timerValue;// sets the value for the timer delay, example the 2 minutes or few seconds.
	TIMSK1 = 0x01;// interrupt mask for timer 1A compare match
	
	return 0;
	
}

ISR(TIMER1_COMPA_vect);// Interrupt service routine  for timer
