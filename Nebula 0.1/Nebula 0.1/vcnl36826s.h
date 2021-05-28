#ifndef vcnl4010_H_INCLUDED
#define vcnl4010_H_INCLUDED
#define vcnl_write 0x26
#define vcnl_read 0x27
#define vcnl_proxEnable 0x07
#define stdProxRate 0x01
#define stdpledCurrent 0x0A
#define intProx 0x0E
//i2c processes*****************************************************************

//unsigned char gesturee[9]={0x83,1, 2};
unsigned char vcnlBegin(unsigned char apdsaddr);
unsigned char vcnlSend(unsigned char address,unsigned char value);
unsigned char vcnlReceive(void);
unsigned char vcnlStop(void);
unsigned char vcnlTransceive(void);
unsigned char vcnlInit(void);
unsigned char vcnlCalibrate(unsigned char caliBit);
unsigned char vcnlHandler(void);//coordinates with the apds to ensure it has
//been setup, and configuration bits were sent
unsigned char vcnlAls(void);//als calibration
unsigned char vcnlProximity(void);//proximity calibration
unsigned char vcnlGesture(void);//gesture calibration

//******************************************************************************
//******************************************************************************
//Registers
#define commandReg 0x80
#define idReg 0x81
#define proxRateReg 0x82
#define pLedCurrentReg 0x83
#define ALS_reg 0x84
#define ALS_data1 0x85
#define ALS_data2 0x86
#define prox_data1 0x87
#define prox_data2 0x88
#define vcnlInt 0x89
#define lowThreshold1 0x8A
#define lowThreshold2 0x8B
#define highThreshold1 0x8C
#define highThreshold2 0x8D
#define intStat 0x8E
#define proxModulator 0x8F 

#endif