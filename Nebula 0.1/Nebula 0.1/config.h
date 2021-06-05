#ifndef config_H_INCLUDED
#define config_H_INCLUDED
#include "i2c.h"
#include "apds9960.h"
#include "drv8836.h"

/* Defines the various processes/ indicators used on the PCB */
unsigned char unUsed(void);//unused ports
unsigned char solOn(void);//solenoid on
unsigned char solOff(void);//solenoid off
unsigned char idle(void);// Return from sleep state
unsigned char powerSave(void);//normal powersave sleep
unsigned char hibernate(void);//deep powersave
unsigned char distance(char range);//distance data to sensor
unsigned char gestureDuration(unsigned char t);//gesture timer duration
unsigned char proxDuration(unsigned char t);//Proximity timer duration
unsigned char ledInit(void);//initialize led to zero
unsigned char systemGo(void);//green led on
unsigned char systemNoGo(void);//red led on
unsigned char flashy(void);//blue led for general purpose operation
unsigned char batteryLow(void);//low batter1!!y indicator
unsigned char charging(void);//charge indictor
unsigned char systemSetup(void);// blue light displays during calibration
unsigned char boostEnable(void);//enables boost converter
unsigned char boostDisable(void);//disable
unsigned char ledInit(void);//init led/ turns off led
unsigned char apds9960_prox_write(void);//unused ports
unsigned char checkBattery(void);//initializes and checks the battery status
unsigned char portSetup(void);// port setup
unsigned char buttonPress(void);//button press actions
unsigned char comparator(void);// retruns status of comparator
unsigned char i2c_check(void);//led flash for i2c test
unsigned char reboot(void);//reboot
unsigned char drvIN_IN(void);//configuration for drv8836 in in mode
unsigned char drvPhase_En(void);//configuration for drv8836 Phase / Enable mode
unsigned char drvActuate(unsigned char mode);// determines actuation depending on the mode selected
///////////////////////////////////////////////////////////////////////////

#define redPort 5 //red led
#define bluePort 6 // blue led
#define greenPort 7 // green led
#define button 2 //push button
#define drv1A 6 //drv8837 motor control 1
#define drv1B 7 //drv8837 motor control 1
#define drv2A 1 //drv8837 motor control 2
#define drv2B 0 //drv8837 motor control 2
#define drvSleep 3 //drv8837 motor sleep
#define gpioPin 3 //external gpio for peripheral module
#define compPower 1 //comparator power
#define compOutput 2 //comparator input
#define unused1 1 //unused port B1
#define unused2 4 //^ D4
#define unused3 0 // E0
#define boostEn 2 //boost converter enable
#define batteryStatusPort 0 //battery port
#define rebootpin 3 //reboot pin
#define drvMode 1 //drv8837 motor mode ow = in/in high = ph/en, pulldown internally
#define proxInt 1 //proximity interrupt port


///////////////////////////////////////////////////////////////////////////








#endif
