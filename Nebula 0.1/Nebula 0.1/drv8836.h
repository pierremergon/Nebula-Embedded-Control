#ifndef drv8836_H_INCLUDED
#define drv8836_H_INCLUDED

#define drvSlp 3
#define drvMode 1
#define ain1 7
#define ain2 8
#define bin1 1
#define bin2 0

unsigned char waterOn(void); // Turn on water solenoid
unsigned char waterOff(void); // Turn off water solenoid
unsigned char moduleOn(void); // Turn on peripheral
unsigned char moduleOff(void); // Turn off peripheral
unsigned char drvSleep(unsigned char sleepBit); // drv8826 powersave
unsigned char drvMode(unsigned char bit); // 1 = mode 1 2 = mode 2

#endif
