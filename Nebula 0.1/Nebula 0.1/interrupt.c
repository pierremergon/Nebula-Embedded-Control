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
	PCICR = 0x02;
	PCMSK1 |= (1<<PCINT10);
	sei();
	return 0;
}

PCINT1_vect()
{
	batteryLow();
}