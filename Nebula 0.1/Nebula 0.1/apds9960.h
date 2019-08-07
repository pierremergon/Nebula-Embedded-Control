#ifndef apds9960_H_INCLUDED
#define apds9960_H_INCLUDED
#define nebula_write 0x72
#define nebula_read 0x73
#define  id_reg 0x92

#define proxEnable 0x8
//unsigned char gesturee[9]={0x83,1, 2};
unsigned char apdsBegin(unsigned char apdsaddr);
unsigned char apdsSend(unsigned char address,unsigned char value);
unsigned char apdsReceive(void);
unsigned char apdsStop(void);
unsigned char apdsTransceive(unsigned char address);

	
#endif 