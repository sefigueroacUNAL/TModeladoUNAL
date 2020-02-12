#include "ButtonDebounce.h"
#include "Arduino.h"

ButtonDebounce::ButtonDebounce(int pinIn,bool pullUP){
   
  pin = pinIn;
  if(pullUP)
    pinMode(pinIn,INPUT_PULLUP);
  else
    pinMode(pinIn,INPUT);
   

}

void ButtonDebounce::setLowCallback(Function fn){
  lowCallback = fn; 
  }
void ButtonDebounce::setHighCallback(Function fn){
  highCallback = fn;
  
  }

void ButtonDebounce::poll(){

  int newValue = digitalRead(pin);
  switch(state){
    case BHIGH:
      if (newValue == LOW){
        lastTime = millis();
        state = DOWN;
        }
    break;
    case DOWN:
      if(millis() - lastTime > debounceTime){
        if(newValue == LOW){
          state = BLOW;
         
          if(lowCallback) lowCallback(pin);
         
          }else{
          state = BHIGH;
          } 
        }
    break;
    case BLOW:
      if (newValue == HIGH){
        lastTime = millis();
        state = UP;
        }
    break;
    case UP:
      if(millis() - lastTime > debounceTime){
        if(newValue == HIGH){
          state = BHIGH;
           if(highCallback) highCallback(pin);
          
          }else{
          state = BLOW;
          } 
        }      
  }
  
}
