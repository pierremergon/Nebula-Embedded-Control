#include "config.h"
#define F_CPU 1000000UL
#include <util/delay.h>

unsigned char comp = 0;
unsigned char buttonCount = 0;
unsigned char i = 0;


unsigned char unUsed (void)//disable unused ports
{
	DDRB &= ~(1<<unused1);//inputs
	DDRD & ~(1<<unused2);
	DDRE & ~(1<<unused3);
	PORTB |= (1<<unused1);//pullup
	PORTD |= (1<<unused2);//pullup
	PORTE |= (1<<unused3);//pullup
	return 0;
}

unsigned char portSetup(void)
{
	unUsed();
	//battery indicator ports
	DDRD |= (1<<redPort);//internal pullup
	DDRD |= (1<<greenPort);
	DDRD |= (1<<bluePort);
	PORTD |= (1<<redPort);
	PORTD |= (1<<greenPort);
	PORTD |= (1<<bluePort);// disables LED
	//battery status
	DDRB &= ~(1<<batteryStatusPort) & ~(1<<compOutput);//status and charger
  PORTB |= (1<<batteryStatusPort) | (1<<compOutput);//input pullup

	//button initialize
	DDRC &= ~(1<<button);//Input pin
	PORTC |= (1<<button);//pull up
	return 0;
	//solenoid
	//drv8836 input control for solenoid and actuator
	DDRB |= (1<<drv1A);
	DDRB |= (1<<drv1B);
	DDRC |= (1<<drv2A);
	DDRC |= (1<<drv2B);
	DDRE |= (1<<drvSleep);// sleep via pulldown
	PORTE &= ~(1<<drvSleep);//^^

	//stepper
	//DDRB &= ~(1<<stepVcc);//disable via pullup
	//DDRB &= ~(1<<stepMode);
	//DDRD &= ~(1<<ain1);
	//DDRD &= ~(1<<ain2);
	//DDRE &= ~(1<<bin1);
	//DDRE &= ~(1<<bin1);
//
	//PORTB &= ~(1<<stepVcc);
	//PORTB &= ~(1<<stepMode);
	//PORTD &= ~(1<<ain1);
	//PORTD &= ~(1<<ain2);
	//PORTE &= ~(1<<bin1);
	//PORTE &= ~(1<<bin2);

	// reboot
	DDRC |= (1<<rebootpin);//port enable
	PORTC |=(1<<rebootpin);//high
	//PORTC &= ~(1<<rebootpin);//high
/*
	//comparator
	DDRB &= ~(1<<2);//Input/ pullup
	PORTD |= (1<<2);
*/

	//Proximity Setup
	DDRD &= ~(1<<proxInt);
	PORTD |= (1<<proxInt);
}

// boost converter enable/disable
unsigned char boostEnable(void)
{
	DDRE |=(1<<boostEn);//high
	PORTE |= (1<<boostEn);
	return 0;
}

unsigned char boostDisable(void)
{
  DDRE |=(1<<boostEn);
	PORTE &= ~(1<<boostEn);//low
	return 0;
}

//Battery comparator output
unsigned char comparator(void)
{
	PORTB |= (1<<2);
	if (((PINB & (1<<2)) == 0))
	{
		return 0;
	}
	else
	{
		return 1;
	}

}

//solenoid operations
unsigned char solOn(void)

{   PORTE |= (1<<drvSleep);
	PORTC |=(1<<1);
	_delay_ms(10);
	PORTC &= ~(1<<1);
	//_delay_ms(10);
	PORTC &= ~(1<<0);
	//PORTC |=(1<<0);
	PORTE &= ~(1<<drvSleep);
	//PORTC &= ~(1<<1);
	//_delay_ms(500);
	//PORTC |= (1<<0) | (1<<1);
	return 0;
}

unsigned char solOff(void)
{    PORTE |= (1<<drvSleep);
	 PORTC |=(1<<0);
	_delay_ms(10);
	PORTC &= ~(1<<0);
	//_delay_ms(10);
	//PORTC |=(1<<0);
	PORTC &= ~(1<<1);
	PORTE &= ~(1<<drvSleep);
	//PORTC |= (1<<0) | (1<<1);
	return 0;
}


//LED Indication Operations
unsigned char systemGo(void)
{//green connects to PB2
	unsigned char status = 0;
	portSetup();
	status = comparator();
	if (status == 0)
	{
	batteryLow();
	}

	else
	{
	flashy();//all good,m
	}


	return 0;
}

unsigned char systemNoGo(void)
{
	batteryLow();
	return 0;

}

unsigned char flashy(void)
{
		PORTD &= ~(1<<redPort);
		_delay_ms(800);
		PORTD |= (1<<redPort);
		_delay_ms(800);
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
	PORTD &= ~(1<<redPort);
	_delay_ms(50);
	PORTD |= (1<<redPort);
	_delay_ms(50);
	PORTD &= ~(1<<redPort);
	_delay_ms(50);
	PORTD |= (1<<redPort);
	_delay_ms(50);
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

//initializes and checks the battery status
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
	//boostDisable();

	PORTD &= ~(1<<redPort);
	_delay_ms(300);
	PORTD |= (1<<redPort);
	PORTD &= ~(1<<greenPort);
	_delay_ms(300);
	PORTD |= (1<<greenPort);
	PORTD &= ~(1<<bluePort);
	_delay_ms(300);
	PORTD |= (1<<bluePort);
	PORTD &= ~(1<<redPort) & ~(1<<bluePort);
	_delay_ms(300);
	PORTD |= (1<<redPort) | (1<<bluePort);
	PORTD &= ~(1<<greenPort) & (1<<redPort);
	_delay_ms(300);
	PORTD |= (1<<greenPort) |(1<<redPort);
	PORTD &= ~(1<<bluePort) & ~(1<<greenPort);
	_delay_ms(300);
	PORTD |= (1<<bluePort) | (1<<greenPort);
	PORTD &= ~(1<<redPort) & ~(1<<greenPort);
	_delay_ms(300);
	PORTD |= (1<<redPort) | (1<<greenPort);
	//idle();
	return 0;
}
/*
unsigned char charging(void)//charge indicator
{
	//pin change int
	comp = comparator();
	if ((PINB & (1<<batteryPort)) == 0)
	{
		PORTD &= ~(1<<redPort);
	}
	else if((((PINB & (1<<batteryPort)) != 0) & (comp)))
	{
		PORTD |= (1<<redPort);
	}
	else
	{
		PORTD &= ~(1<<redPort);
	}

	return 0;
}
*/
//Button press actions
unsigned char buttonPress(void)
{
	// pin change interrupt

	if ((PINC & (1<<2)) == 0)
	{
		//do task for single button press
		buttonCount += 1;
	}
	return 0;
}

unsigned char reboot(void)//reboot
{
	//PORTC |= (1<<3);
	_delay_ms(3000);
	PORTC &= ~(1<<rebootpin);
	_delay_ms(400);
	PORTC |= (1<<rebootpin);
	//batteryLow();
	return 0;

}

unsigned char i2c_check(void)
{
	PORTD &= ~(1<<greenPort);
	_delay_ms(50);
	PORTD |= (1<<greenPort);
	_delay_ms(50);

	return 0;
}


unsigned char drvIN_IN(void)
{
	PORTE |= (1<<drvSleep);
	PORTE &= ~(1<<drvMode);
	return 0;
}

unsigned char drvPhase_En(void)
{
	PORTE |= (1<<drvSleep);
	PORTE |= (1<<drvMode);
	return 0;
}

unsigned char drvActuate(unsigned char mode)
{
	if(mode == 1)
	{   drvIN_IN();
		for(i = 0; i<20; i++)
		{
			PORTB &= ~(1<<drv1A);
			_delay_ms(50);
			PORTB |= (1<<drv1B);
			_delay_ms(2000);

			PORTB &= ~(1<<drv1B);
			_delay_ms(50);
			PORTB |= (1<<drv1A);
			_delay_ms(500);
		}
		PORTE &= ~(1<<drvSleep);// sleep mode after actuation
		_delay_ms(1000);
	}
	return 0;
}
