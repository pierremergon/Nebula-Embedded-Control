#ifndef config_H_INCLUDED
#define config_H_INCLUDED
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
unsigned char batteryLow(void);//low battery indicator
unsigned char fullCharge(void);//full charge indictor
unsigned char systemSetup(void);// blue light displays during calibration
unsigned char sleep(void);
unsigned char hibernate(void);
unsigned char ledInit(void);//init asmb/ turns off led
unsigned char apds9960_prox_write(void);//unused ports
unsigned char checkBattery(void);//initializes and checks the battery status
unsigned char portSetup(void);// port setup
unsigned char buttonPress(void);//button press actions
///////////////////////////////////////////////////////////////////////////
#define redPort PORTB0
#define bluePort PORTB1
#define greenPort PORTB2

///////////////////////////////////////////////////////////////////////////








#endif
