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
#include "config.h"
#include "interrupt.h"
#include "i2c.h"
#include "indicate.h"
#include "apds9960.h"
#include "vcnl4010.h"
#include "drv8835.h"
#include <avr/sleep.h>
#define F_CPU 1000000
//#include "USI_TWI_"
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
		sei();*/
		//portSetup();
		//portSetup();
		//timerSetup(0x0000);

		/*int num;
		i2c_init();
		vcnlBegin(vcnl_write);
		num = vcnlTransceive();
		*/
		/*DDRD = (1<<6);
		DDRD |= (1<<redPort);
		DDRD |= (1<<greenPort);
		DDRD |=(1<<redPort);
		DDRD |=(1<<bluePort);
		DDRE |=(1<<drvSleep);
		DDRC &= ~(1<<2);
		PORTC |=(1<<2);
		DDRB &= ~(1<<0);
		PORTB |= (1<<0);
		*/
		DDRD |= (1<<greenPort);
		DDRD |= (1<<bluePort);
		DDRD |= (1<<redPort); PORTD |= ((1<<greenPort) | (1<<bluePort) | (1<<redPort));
		boostDisable();
        //cli();
	/*	DDRC |= (1<<drvIn1);
		DDRC |= (1<<drvIn2);
		PORTC &= ~(1<<drvIn1);
		PORTC &= ~(1<<drvIn2);
		//PORTE |= (1<<drvSleep);
		
		*/
		//boostEnable();
		//boostDisable();
		//pcIntSetup();
		//int0Setup();
		
		//sei();
		/*PORTC |=(1<<1);
		_delay_ms(20);
		PORTC &= ~(1<<1);
		PORTC |=(1<<0);
		_delay_ms(20);
		PORTC &= ~(1<<0);
*/
		/*PORTC &= ~(1<<1);
		_delay_ms(20);
		PORTC |=(1<<1);
		*/
		
				
		
		//solOn();
		//solOff();
		//DDRD &= ~(1<<2);
		//PORTD |= (1<<2);
		//apdsInit();
		//i2c_init();
		//apdsBegin(nebula_write);
		//proximity();
		//int0Setup();
		//apdsInit();
		//apdsTransceive();
		//solOn();
		//solOn();
		//_delay_ms(5000);
		//solOff();
		//_delay_ms(5000);
		//proximity();
		//sei();
		//apdsInit();
		//SMCR |=(1<<0x07);
		//DDRB |=(1<<1)|(1<<7);
		//DDRE |=(1<<3);
		//PORTB &= ~(1<<1);
		////PORTB &= ~(1<<7);
		//PORTE &= ~(1<<3);
		//SMCR |=(1<<0x07);//07 powersave
		//sleep_mode();
       // sei();
    while(1)
    {
			//sleep_mode();
//flashy();
batteryLow();
//checkBattery();
//DDRE |=(1<<2);
//PORTE |= (1<<2);
//systemNoGo();
//solOff();
//solOff();
//solOn();
//_delay_ms(10000);
//solOff();
//apdsTransceive();
//PORTD &= ~(1<<redPort);
	}
	return(0);
}
/*
		ISR(INT0_vect)
		{
			num = apdsTransceive();
		}
		*/
