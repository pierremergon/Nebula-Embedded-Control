#include "i2c.h"
#include "apds9960.h"
#include "interrupt.h"
#include "config.h"

unsigned char apdsBegin(unsigned char apdsaddr)
{
	i2c_start(apdsaddr);
	return 0;
}

unsigned char apdsSend(unsigned char address, unsigned char value)
{
	i2c_start(address);
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
	i2c_write(id_reg);
	apdsBegin(nebula_read);
	data=TWDR;
	return data;
}
unsigned char apdsStop(void)
{
	i2c_stop();
	return 0;
}

unsigned char apdsInit(void)
{	unsigned char data;
	i2c_init();
	apdsSend(nebula_write,id_reg);
	apdsBegin(nebula_read);
	data=TWDR;
	if ((data=0x92))
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
	return 0;
}

unsigned char apdsCalibrate(unsigned char caliBit)
{
	//unsigned char caliBit;
	unsigned char Bit;
	Bit=caliBit;
	switch (Bit) {
		case 1:proximity();//for proximity calibration
					break;
		case 2://for gesture calibration
					break;
		case 3://for ALS calibration
					break;
		default:proximity();
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
	if ((apdsInit && apdsCalibrate)==0)
	{
		;//systemGo
		apdsSend(enableReg,0x25);
	}
	else{
		;//systemNoGo
	}
	return 0;
}
