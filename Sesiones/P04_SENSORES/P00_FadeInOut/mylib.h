#include "Arduino.h"

void FadeInOut(
  int pin,
  unsigned long *timeMark, 
  unsigned long duration,
  unsigned long offsetTime,
  byte maxvalue,
  int *state,
  unsigned long setTime
  );