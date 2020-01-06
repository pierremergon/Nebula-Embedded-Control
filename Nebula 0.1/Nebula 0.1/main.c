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
#include "vcnl4010.h"
#include "drv8835.h"
//#define vcnl_write 0x26
	int num;
int main(void)
{
	/*
		//unUsed();//disable unused ports
		unsigned char test;
		DDRC |=(1<<1)|(1<<0);
		i2c_init();//initialize i2c
		test=apdsTransceive();
		if ((test=0x92))
		{
			PORTC |=(1<<0);
		}
		else
		{
			PORTC |=(1<<1);
		}
		//intSetup();//enables external interrupt
		//sei();
		//solOn();
		//ISR(INT1_vect);

		//ledInitialize();
		
		int1Setup();
		apds9960_prox_write();
		sei();
		*/
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

		/*apdsBegin(nebula_write);
		apdsCalibrate(1);
		sei();
		portSetup();*/
		portSetup();
		timerSetup(0x0000);
		DDRD|= (1<<0);
		PORTD = (0<<0);
		int num;
		i2c_init();
		vcnlBegin(vcnl_write);
		num = vcnlTransceive();
    while(1)
    {
if ((num = 0x21))
{
 PORTD|= (1<<0);			
}

else
{
	PORTD = ( 0<<0);
}

	}
	
	return(0);
}
/*
		ISR(INT0_vect)
		{
			num = apdsTransceive();
		}
		*/
