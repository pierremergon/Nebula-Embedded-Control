#ifndef vcnl36826s_H_INCLUDED
#define vcnl36826s_H_INCLUDED
#include "i2c.h"

#define vcnlSendBit 0xC0 //write 60
#define vcnlRecvBit 0xC1 //read 61
#define ps_Config1_Low 0x00//on/off
#define ps_Config1_High 0x00
#define ps_Config2_Low 0x03
#define ps_Config2_High 0x03
#define ps_Config3 0x04//force mode/sunlight light ptotect int
#define ps_Config4 0x04 //Proximity VCSEL(laser) current
#define ps_THDL 0x05//proximity low interrupt threshold, send two times for 16 bits
#define ps_THDH 0x06//proximity high interrupt threshold, send two times for 16 bits
#define ps_Canc_L 0x07 //PS cancellation LSB
#define ps_Canc_M 0x07//PS cancellation MSB
#define ps_AC_L 0x08//Auto calibration
#define ps_LPPERI 0x08 //low power mode setting
#define ps_DATA_L 0xF8//LSB Proximity Data
#define ps_DATA_H 0xF8//MSB Proximity Data
#define reserved_register 0xF9//reserved register write 0x00
#define ps_INT_Flag 0xF9//interrupt flag Register
#define ps_ID_L 0xFA//LSB ID Data
#define ps_ID_M 0xFA//MSB ID Data
#define ps_AC_Data_L 0xFB//Auto-calibration LSB Data
#define ps_AC_Data_M 0xFB//Auto-calibration MSB Data


unsigned char vcnlBegin(void);
unsigned char vcnlSend(unsigned char writeAddress, unsigned char writeReg, unsigned char value1, unsigned char value2);//send bits
unsigned char vcnlReceive(unsigned char writeAddress, unsigned char readAddress, unsigned char readReg);//receive bits
unsigned char proximity(); // Proximity sensor
unsigned char gesture();  // Gesture Sensor




#endif
