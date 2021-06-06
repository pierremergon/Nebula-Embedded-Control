#include "vcnl36826s.h"
#include <avr/sleep.h>

unsigned char valueLow;//low bit Data
unsigned char valueHigh;//high bit Data

unsigned char vcnlBegin(void)
{
	i2c_init();
	return 0;
}


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
}



unsigned char vcnlReceive(unsigned char writeAddress, unsigned char readAddress, unsigned char readReg)
{
	//i2c_init();
    i2c_start(writeAddress);//write address
	i2c_write(readReg);//register
	i2c_start(readAddress);//read address
	valueLow = i2c_readAck();//first byte low and acknowledge
	valueHigh = i2c_readNak();//second byte high bytes, and not acknowledge
	i2c_stop();
	return 0;
}

unsigned char vcnlSetup(unsigned char type)//1 for proximity sensor, 0 for gesture
{
	if(type = 1)
	{
		vcnlSend(vcnlSendBit,ps_Config1_Low,0x83,0x02);
		vcnlSend(vcnlSendBit,ps_Config2_Low,0x2A,0x14);
		vcnlSend(vcnlSendBit,ps_Config3,0x1E,0xF2);
		vcnlSend(vcnlSendBit,ps_THDL,0xA0,0x00);
		vcnlSend(vcnlSendBit,ps_THDH,0xF0,0x00);
		vcnlSend(vcnlSendBit,ps_AC_L,0x5D,0x03);
	}

	else
	{
		;

	}
		return 0;
}
//TODO
