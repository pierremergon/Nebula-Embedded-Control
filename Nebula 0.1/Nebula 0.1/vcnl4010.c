#include "i2c.h"
#include "vcnl4010.h"
#include "apds9960.h"
#include "interrupt.h"
#include "config.h"
#include <avr/interrupt.h>

unsigned char vcnlBegin(unsigned char val)
{
	i2c_start(val);
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
{ unsigned char data;

	i2c_write(id_reg);
	vcnlBegin(vcnl_read);
	//i2c_write(proxDataReg);
	//apdsBegin(nebula_read);
	i2c_readNak();
	i2c_stop();
	data=TWDR0;
	return data;
}
unsigned char vcnlStop(void)
{
	i2c_stop();
	return 0;
}

unsigned char vcnlInit(void)
{	unsigned char data;
	i2c_init();
	vcnlSend(vcnl_write,id_reg);
	apdsBegin(vcnl_read);
	data=TWDR0;
	if ((data=0x92))
	{
		return 0;
	}
	else{
		return 1;
	}

}
//##########################################################################
unsigned char vcnlProximity(void)
{
	vcnlSend(commandReg,vcnl_proxEnable);
	vcnlSend(proxRateReg,stdProxRate);
	vcnlSend(pLedCurrentReg,stdpledCurrent);
	vcnlSend(persReg,0x10);
	vcnlSend(proxPulsCountReg,0x41);
	vcnlSend(proxIntThresReg1,0x50);
	vcnlSend(proxIntThresReg2,0xC8);
	vcnlSend(enableReg,0x25);
	return 0;
}

unsigned char vcnlCalibrate(unsigned char caliBit)
{
	//unsigned char caliBit;
	unsigned char Bit;
	Bit=caliBit;
	switch (Bit) {
		case 1:vcnlProximity();//for proximity calibration
		break;
		case 2://for gesture calibration
		break;
		case 3://for ALS calibration
		break;
		default://already taken care of
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
	if ((!vcnlInit()) && (!vcnlCalibrate(4)))//4 will be default for apdsCalibrate, thus return 0
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
/*
unsigned char int0Setup(void)
{
	DDRD &= ~(1<<2);
	PORTD |= (1<<2);
	EICRA |=(0x00);//logic low
	EIMSK |= (1<<INT0); // interrupt mask register to interrupt 0
	//MCUCR  |=(0<<ISC01); //preset conditions to enable interrupt for logic low
	//MCUCR  |=(0<<ISC00);//""""""""""""""""""""""""""""""""""""""""""""""""""""
	//cli();
	return 0;
}
*/