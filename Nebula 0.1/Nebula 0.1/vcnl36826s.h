#ifndef vcnl36826s_H_INCLUDED
#define vcnl36826s_H_INCLUDED
#include "i2c.h"



#define vcnlSend 0x60 //write
#define vcnlRecv 0x61 //read


unsigned char vcnlInit(unsigned char type); // gesture or proximity sensor

unsigned char transmit(unsigned char data); // transmit data

unsigned char receive(unsigned char data); // receive data
unsigned char proximity(); // Proximity sensor
unsigned char gesture();  // Gesture Sensor




#endif
