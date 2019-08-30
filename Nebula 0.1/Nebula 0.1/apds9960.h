#ifndef apds9960_H_INCLUDED
#define apds9960_H_INCLUDED
#define nebula_write 0x72
#define nebula_read 0x73
#define proxEnable 0x8
//i2c processes*****************************************************************

//unsigned char gesturee[9]={0x83,1, 2};
unsigned char apdsBegin(unsigned char apdsaddr);
unsigned char apdsSend(unsigned char address,unsigned char value);
unsigned char apdsReceive(void);
unsigned char apdsStop(void);
unsigned char apdsTransceive(void);
unsigned char apdsInit(void);
unsigned char apdsCalibrate(unsigned char caliBit);
unsigned char apdsHandler(void);//coordinates with the apds to ensure it has
                                //been setup, and configuration bits were sent

//******************************************************************************
//******************************************************************************
//Registers
#define enableReg 0x80
#define ADCIntTimeReg  0x81
#define waitTimeReg 0x83
#define ALSIntThrReg 0x84
#define proxIntThresReg1 0x89 //Low Threshold
#define proxIntThresReg2 0x8B //High Threshold
#define persReg 0x8C
#define configOneReg 0x8D
#define configTwoReg 0x90
#define configThreeReg 0x9F
#define proxPulsCountReg 0x8E
#define controlReg1 0x8F
#define id_reg 0x92
#define statusReg 0x93
#define RGBCDataReg 0x94//94-9B
#define proxDataReg 0x9C
#define gestureProxEnter 0xA0
#define gestureProxExit 0xA1
#define gestureConfig1Reg 0xA2
#define gestureConfig2Reg 0xA3
#define gestureConfig3Reg 0xAA
#define gestureConfig4Reg 0xAB
#define gesturePulsLenReg 0xA6
#define gestureFIFOLvlReg 0xAE
#define gestureStatReg 0xAF
#define forceIntReg 0xE4
#define clrProxIntReg 0xE5
#define clrALSIntReg 0xE6
#define clrIntReg
#define FIFOU 0xFC
#define FIFOD 0xFD
#define FIFOL 0xFE
#define FIFOR 0xFF
//******************************************************************************
//Proximity Opperation
#endif
