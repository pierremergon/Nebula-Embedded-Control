#include "vcnl36826s.h"
#include <avr/sleep.h>

unsigned char valueLow;//low bit Data
unsigned char valueHigh;//high bit Data

unsigned char vcnlBegin(unsigned char vcnladdr)
{
	unsigned char i2cStatus;
	i2c_init();
	return 0;
}


unsigned char vcnlSend(unsigned char address; unsigned char writeReg; unsigned char value1; unsigned char value2)
{
	unsigned char i2cStatus;
	//i2c_init();
  i2c_start(address);//write address
	i2c_write(writeReg);//register
	i2c_write(value1);//first 8 bits
	i2c_write(value2);//second 8 bits
	i2c_stop();
	return 0;
}

unsigned char vcnlReceive(unsigned char writeAddress; unsigned char readAddress; unsigned char readReg;)
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
