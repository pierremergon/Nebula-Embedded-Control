#include "vcnl36826s.h"
#include <avr/sleep.h>

unsigned char vcnlBegin(unsigned char vcnladdr)
{
	unsigned char i2cStatus;
	i2c_init();

	i2cStatus = i2c_start(vcnladdr);
	if (i2cStatus != 0)
	{
		idle();
	}

	return 0;
}


unsigned char vcnlSend(unsigned char address, unsigned char value)
{
	i2c_write(address);
	i2c_write(value);
	return 0;
}
unsigned char vcnlReceive(void)
{	unsigned char value;
	value=i2c_readNak();
	return value;

}
unsigned char vcnlTransceive(void)
{   
	unsigned char data;
	vcnlBegin(0x60);
	vcnlSend(0xFA,0x00);
	//i2c_start(vcnlSend);
	//i2c_write(proxDataReg);
	//i2c_write(id_reg);
	//i2c_start(nebula_read);
	//data = i2c_readAck();
	//data = i2c_readNak();
	vcnlStop();
	//i2c_start(nebula_write);
	//i2c_write(0xE5);
	//vcnlStop();

/*
	if (data == 0xFF)//A0
	{
		flashy();
		//systemNoGo();
	}
	else
	{
		//i2c_check();
		;

	}
*/
	//i2c_start(nebula_write);
	///i2c_write(0xE5);
	//vcnlStop();
	//i2c_start(nebula_write);
	//vcnlSend(enableReg,0x25);
	//vcnlStop();
	/*
	i2c_start(nebula_write);
	i2c_write(0xE5);
	vcnlStop();*/
	//sleep_mode();
	return 0;

}
unsigned char vcnlStop(void)
{
	i2c_stop();
	return 0;
}

unsigned char vcnlInit(void)
{	unsigned char data;
	//i2c_init();
	vcnlBegin(nebula_write);
    i2c_write(id_reg);
	vcnlBegin(nebula_read);
	i2c_readNak();
	i2c_stop();
	data = TWDR0;
	if ((data = 0x92))
	{
		batteryLow();
		return 0;
	}
	else{
		return 1;
	}

}
//##########################################################################
unsigned char proximity(void)
{   i2c_start(nebula_write);
	vcnlSend(configTwoReg,0x31);//01
	vcnlStop();
	i2c_start(nebula_write);
	vcnlSend(0x90,0x00);
	vcnlStop();
	i2c_start(nebula_write);
	vcnlSend(configThreeReg,0x3c);//up down diode disabled, gain compensation = 1, sleep after interrupt//3c
	vcnlStop();
	i2c_start(nebula_write);
	vcnlSend(controlReg1,0x0C);//0c
	vcnlStop();
	i2c_start(nebula_write);
	vcnlSend(persReg,0xAF);//5F
	vcnlStop();
	i2c_start(nebula_write);
	vcnlSend(proxPulsCountReg,0x7C);//7c//c3
	vcnlStop();
	i2c_start(nebula_write);
	vcnlSend(proxIntThresReg1,0x09);
	vcnlStop();
	i2c_start(nebula_write);
	vcnlSend(proxIntThresReg2,0xFE);
	vcnlStop();
	i2c_start(nebula_write);
	vcnlSend(0x83,0x00);
	vcnlStop();
	i2c_start(nebula_write);
	i2c_write(0xE5);
	i2c_stop();
	i2c_start(nebula_write);
	vcnlSend(waitTimeReg,0xE6);//E6
	vcnlStop();
	i2c_start(nebula_write);
	vcnlSend(enableReg,0x00);//2D
	vcnlStop();
	//i2c_write(0xE7);
	//i2c_write(0xE4);
	//vcnlStop();

	return 0;
}

unsigned char vcnlCalibrate(unsigned char caliBit)
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
unsigned char vcnlHandler(void)
{
	//unsigned char bitNum[3]={1,2,3};
	unsigned char i;
	vcnlInit();

	for(i=1;i<=3; i++)
	{
		vcnlCalibrate(i);
	}
	if ((!vcnlInit()) && (!vcnlCalibrate(4)))//4 will be default for vcnlCalibrate, thus return 0
	{
		systemGo();
		vcnlSend(enableReg,0x25);
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
