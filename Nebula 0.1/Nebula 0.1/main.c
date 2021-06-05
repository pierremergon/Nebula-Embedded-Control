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
#include "vcnl36826s.h"
#include "drv8836.h"
#include <avr/sleep.h>
#define F_CPU 1000000

	int num;
int main(void)
{

		DDRD |= (1<<greenPort);
		DDRD |= (1<<bluePort);
		DDRD |= (1<<redPort); PORTD |= ((1<<greenPort) | (1<<bluePort) | (1<<redPort));
		//PORTE &= ~(1<<drvSleep);

	/*	DDRC |= (1<<drvIn1);
		DDRC |= (1<<drvIn2);
		PORTC &= ~(1<<drvIn1);
		PORTC &= ~(1<<drvIn2);
		//PORTE |= (1<<drvSleep);

		*/
		boostEnable();
		//boostDisable();

		pcIntSetup();

		timerSetup(2000);
		sei();
		//apdsInit();
		//SMCR |=(1<<0x07);
		//DDRB |=(1<<1)|(1<<7);
		//DDRE |=(1<<3);
		//PORTB &= ~(1<<1);
		////PORTB &= ~(1<<7);
		//PORTE &= ~(1<<3);
		///SMCR |=(1<<0x07);//07 powersave
		//sleep_mode();
        //sei();
/*
		i2c_init();
		i2c_start(0xC0);
		*/
		//vcnlBegin();
			
		vcnlSend(0xC0,0x00,0x83,0x02);
		/*i2c_init();
		i2c_start(0xC0);
		i2c_write(0x00);
		i2c_write(0x83);
		i2c_write(0x02);
		i2c_stop();
		*/

    while(1)
    {

		//2c_init();
		//i2c_start(0x41);

//sleep_mode();
//flashy();
//reboot();//fix

//batteryLow();
//checkBattery();
//DDRE |=(1<<2);
//PORTE |= (1<<2);
//systemNoGo();
//solOff();
//solOff();
//solOn();
//drvActuate(1);
//flashy();
//vcnlTransceive();
//_delay_ms(10000);
//solOff();
//apdsTransceive();
//PORTD &= ~(1<<5);
	}
	return(0);
}
/*
		ISR(INT0_vect)
		{
			num = apdsTransceive();
		}
		*/

/*
unsigned char vcnlSend(unsigned char writeAddress, unsigned char writeReg, unsigned char value1, unsigned char value2)
{
	//unsigned char i2cStatus;
	//i2c_init();
	i2c_start(writeAddress);//write address
	i2c_write(writeReg);//register
	i2c_write(value1);//first 8 bits
	i2c_write(value2);//second 8 bits
	i2c_stop();
	return 0;
	
} */