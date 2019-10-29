#include "mylib.h"
#include "Arduino.h"

void FadeInOut(
  int pin,
  unsigned long *timeMark, 
  unsigned long duration,
  unsigned long offsetTime,
  byte maxvalue,
  int *state,
  unsigned long setTime
  ){
    unsigned long elapsed;
    switch (*state){
      case 0: //Init
        *timeMark = millis();
        *state = 1;
        break;
      case 1: //Waiting
        if( millis() - *timeMark > offsetTime){
          *state = 2;
          *timeMark = millis();
          }
          break;
      case 2: //UP
        elapsed = millis() - *timeMark;
        if( elapsed < duration){
          analogWrite(pin,map( elapsed, 0, duration, 0, maxvalue));
          }else{
            *state = 3;
            *timeMark = millis();
            analogWrite(pin,maxvalue);
          }
          break;
       case 3: //SET
         if( millis() - *timeMark > setTime){
          *state = 4;
          *timeMark = millis();
          }
          break;
       case 4: //DOWN
         elapsed = millis() - *timeMark;
          if( elapsed < duration){
          analogWrite(pin,map( elapsed, 0, duration, maxvalue, 0));
          }else{
            *state = 5;
            *timeMark = millis();
             analogWrite(pin,0);
          }
          break;
       case 5: //SET
         if( millis() - *timeMark > setTime){
          *state = 2;
          *timeMark = millis();
          }
          break;
     
       
        
      
      }
    
}
