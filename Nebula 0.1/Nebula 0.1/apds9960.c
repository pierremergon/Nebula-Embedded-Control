#include "apds9960.h"
#include <avr/sleep.h>

unsigned char apdsBegin(unsigned char apdsaddr)
{
	unsigned char i2cStatus;
	i2c_init();
	
	i2cStatus = i2c_start(apdsaddr);
	/*if (i2cStatus != 0)
	{
		idle();
	}
	*/
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
	i2c_start(nebula_write);
	i2c_write(proxDataReg);
	//i2c_write(id_reg);
	i2c_start(nebula_read);
	//data = i2c_readAck();
	data = i2c_readNak();
	apdsStop();
	i2c_start(nebula_write);
	i2c_write(0xE5);
	apdsStop();

	
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
	
	//i2c_start(nebula_write);
	///i2c_write(0xE5);
	//apdsStop();
	//i2c_start(nebula_write);
	//apdsSend(enableReg,0x25);
	//apdsStop();
	/*
	i2c_start(nebula_write);
	i2c_write(0xE5);
	apdsStop();*/
	//sleep_mode();
	return 0;
	
}
unsigned char apdsStop(void)
{
	i2c_stop();
	return 0;
}

unsigned char apdsInit(void)
{	unsigned char data;
	//i2c_init();
	apdsBegin(nebula_write);
    i2c_write(id_reg);
	apdsBegin(nebula_read);
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
	apdsSend(configTwoReg,0x31);//01
	apdsStop();
	i2c_start(nebula_write);
	apdsSend(0x90,0x00);
	apdsStop();
	i2c_start(nebula_write);
	apdsSend(configThreeReg,0x3c);//up down diode disabled, gain compensation = 1, sleep after interrupt//3c
	apdsStop();
	i2c_start(nebula_write);
	apdsSend(controlReg1,0x0C);//0c
	apdsStop();
	i2c_start(nebula_write);
	apdsSend(persReg,0xAF);//5F
	apdsStop();
	i2c_start(nebula_write);
	apdsSend(proxPulsCountReg,0x7C);//7c//c3
	apdsStop();
	i2c_start(nebula_write);
	apdsSend(proxIntThresReg1,0x09);
	apdsStop();
	i2c_start(nebula_write);
	apdsSend(proxIntThresReg2,0xFE);
	apdsStop();
	i2c_start(nebula_write);
	apdsSend(0x83,0x00);
	apdsStop();
	i2c_start(nebula_write);
	i2c_write(0xE5);
	i2c_stop();
	i2c_start(nebula_write);
	apdsSend(waitTimeReg,0xE6);//E6
	apdsStop();
	i2c_start(nebula_write);
	apdsSend(enableReg,0x00);//2D
	apdsStop();
	//i2c_write(0xE7);
	//i2c_write(0xE4);
	//apdsStop();
	
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
