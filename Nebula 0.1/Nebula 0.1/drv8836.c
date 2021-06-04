#include "drv8836.h"
#include "config.h"
#include <util/delay.h>

unsigned char waterOn(void)
{
  DDRx |= (1<<ain1) & ~(1<<ain2);
  return 0;
}

unsigned char waterOff(void)
{
  DDRx |= (1<<ain2) & ~(1<<ain1);
  return 0;
}
