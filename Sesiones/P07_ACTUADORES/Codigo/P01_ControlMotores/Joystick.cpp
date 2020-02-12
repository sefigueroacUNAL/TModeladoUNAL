#include "Joystick.h"
#include "Arduino.h"


Joystick::Joystick(int AX,int AY,int ID){
  
  Ax = AX;
  Ay = AY;
  id = ID;
      
}
    
void Joystick::poll(){
  int x = analogRead(Ax);
  int y = analogRead(Ay);

  if(DEBUG){
  String  out = String("X:") + x + " Y:" + y; 
  Serial.println(out);
  }

  

  if ( x < MIN && y > MIN && y < MAX ) 
    pos = LEFT;
  else if ( x > MAX && y > MIN && y < MAX ) 
    pos = RIGHT;
  else if ( y < MIN && x > MIN && x < MAX ) 
    pos = UP;
  else if ( y > MAX && x > MIN && x < MAX ) 
    pos = DOWN;
    else
    pos = CENTER;

    if ( pos != lastPos) {
      if(callback) callback(id,pos);
       
        lastPos = pos;
                
      }
}

void Joystick::setLimits(int minIn,int maxIn){
  MIN = minIn;
  MAX = maxIn;
        
}

void Joystick::setCallback(Function fn){
      callback = fn;
}

int Joystick::GetX(){
  return analogRead(Ax);
}

int Joystick::GetY(){
  return analogRead(Ay);
}
