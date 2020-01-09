//#include <avr/io.h>
#ifndef interrupt_H_INCLUDED
#define interrupt_H_INCLUDED
#include <avr/interrupt.h>
// Define
unsigned char int0Setup(void);// gesture interrupt setup
unsigned char pcIntSetup(void);// pin change interrupt setup
unsigned char timerSetup(unsigned int timerValue);// timer interrupt setup
unsigned char timer(unsigned int delayTime);// timer delay, interrupt

//End 

#endif




