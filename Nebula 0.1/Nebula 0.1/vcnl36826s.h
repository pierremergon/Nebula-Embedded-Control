#ifndef vcnl36826s_H_INCLUDED
#define vcnl36826s_H_INCLUDED
#include "i2c.h"



#define vcnlSendBit 0x60 //write
#define vcnlRecvBit 0x61 //read
#define vcnlID 0xFA //id register
#define vcnlPower 0x00;//on/off
#define  


unsigned char vcnlInit(unsigned char type); // gesture or proximity sensor

unsigned char transmit(unsigned char data); // transmit data

unsigned char receive(unsigned char data); // receive data
unsigned char proximity(); // Proximity sensor
unsigned char gesture();  // Gesture Sensor




#endif
