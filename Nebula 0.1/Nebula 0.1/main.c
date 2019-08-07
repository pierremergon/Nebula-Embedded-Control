/*
 * Nebula 0.1.c
 *
 * Created: 1/11/2019 2:48:09 AM
 * Author : Mergon Pierre
 * Website: Amstartechnology.com
 */ 
/*
Initialize Ports, Initialize I2C, I2C write default data

*/
#include <avr/io.h>
#include <avr/interrupt.h>
#include "config.h"
#include "interrupt.h"
#include "i2c.h"
#include "indicate.h"
#include "apds9960.h"
#define F_CPU 1000000UL
#include <util/delay.h>
	int num;
int main(void)
{
		//unUsed();//disable unused ports
		//i2c_init();//initialize i2c
		//intSetup();//enables external interrupt 
		//sei();
		//solOn();
		//ISR(INT1_vect);
	
		ledInitialize();
		int1Setup();
		apds9960_prox_write();
		sei();
		//_delay_ms(500);;
		//apdsBegin();
		//_delay_ms(500);
		//num=apdsSend(0x00,0x00);
		//apdsStop();
		//ISR(INT0_vect);
		/*if (num==0)
		{
			DDRC |= (0xff);
			PORTC |=(1<<0);
		}
		
		else if(num==1)
		{
			DDRC |= (0xff);
			PORTC |=(1<<1);
		}
		
		else
		{
			;
		}
		
		
		//i2c_stop();
		*/
    while (1) 
    {
;
    return(0);
	}
}

	