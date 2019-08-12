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
