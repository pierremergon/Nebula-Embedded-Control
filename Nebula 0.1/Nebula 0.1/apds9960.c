#include "i2c.h"
#include "apds9960.h"
#include "interrupt.h"
#include "config.h"
#include <avr/interrupt.h>

unsigned char apdsBegin(unsigned char apdsaddr)
{
	unsigned char i2cStatus;
	i2c_init();
	i2cStatus = i2c_start(apdsaddr);
	if (i2cStatus != 0)
	{
		batteryLow();
	}
	return 0;
}

unsigned char apdsSend(unsigned char address, unsigned char value)
{
	i2c_write(address);
	i2c_write(value);
	return 0;
}
unsigned char apdsReceive(void)
{	unsigned char value;
	value=i2c_readNak();
	return value;

}
unsigned char apdsTransceive(void)
{ unsigned char data;

	i2c_write(nebula_write);
	i2c_write(proxDataReg);
	apdsBegin(nebula_read);
	data=TWDR0;
	return data;
}
unsigned char apdsStop(void)
{
	i2c_stop();
	return 0;
}

unsigned char apdsInit(void)
{	unsigned char data;
	apdsBegin(nebula_read);
	data = TWDR0;
	if ((data = 0x92))
	{
		return 0;
	}
	else{
		return 1;
	}

}
//##########################################################################
unsigned char proximity(void)
{   
	apdsSend(configTwoReg,0x01);
	apdsSend(configThreeReg,0x10);
	apdsSend(controlReg1,0x00);
	apdsSend(persReg,0x10);
	apdsSend(proxPulsCountReg,0x41);
	apdsSend(proxIntThresReg1,0x50);
	apdsSend(proxIntThresReg2,0xC8);
	apdsSend(enableReg,0x25);
	return 0;
}

unsigned char apdsCalibrate(unsigned char caliBit)
{
	//unsigned char caliBit;
	unsigned char Bit;
	Bit = caliBit;
	switch (Bit) {
		case 1:proximity();//for proximity calibration
					break;
		case 2:gesture();//for gesture calibration
					break;
		case 3:als();//for ALS calibration
					break;
		default: proximity();//already taken care of
					break;
	}
	return 0;
}
unsigned char apdsHandler(void)
{
	//unsigned char bitNum[3]={1,2,3};
	unsigned char i;
	apdsInit();

	for(i=1;i<=3; i++)
	{
		apdsCalibrate(i);
	}
	if ((!apdsInit()) && (!apdsCalibrate(4)))//4 will be default for apdsCalibrate, thus return 0
	{
		systemGo();
		apdsSend(enableReg,0x25);
	}
	else{
		;systemNoGo();
	}
	return 0;
}

//Interrupt
/*unsigned char int0Setup(void)
{
 		DDRD &= ~(1<<2);
 		PORTD |= (1<<2);
		EICRA |=(0x00);//logic low
		EIMSK |= (1<<INT0); // interrupt mask register to interrupt 0
    	//MCUCR  |=(0<<ISC01); //preset conditions to enable interrupt for logic low
    	//MCUCR  |=(0<<ISC00);//""""""""""""""""""""""""""""""""""""""""""""""""""""
		//cli();
		return 0;
}*/
