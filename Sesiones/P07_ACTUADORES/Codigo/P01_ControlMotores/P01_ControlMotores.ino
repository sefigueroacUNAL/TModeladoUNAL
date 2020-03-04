#include "Motor.h"
#include "ButtonDebounce.h"
#include "Joystick.h"
#include "SerialComm.h"

int VEL = 200;

Motor MI(13,10),MD(8,9);
ButtonDebounce button(7,true);
Joystick J1(A4,A5,0);
SerialComm serial;

//Prototipos
void onButtonPressed(int pin);
void onJoystickPosMoved(int id, Joystick::JPOS pos);
void onSerialReceived(String str);



void setup() {
  // put your setup code here, to run once:
 
  
  MI.Init();
  MD.Init();

  button.setLowCallback(&onButtonPressed);
  J1.setCallback(&onJoystickPosMoved); 
  serial.Init(9600);
  serial.setCallback(&onSerialReceived);

   

}

void loop() {

  button.poll();
  J1.poll();
  serial.poll();

 

}

void onButtonPressed(int pin){
  String s = String("Pin") + pin + " has been pressed";
  Serial.println(s);
  MI.Stop();
  MD.Stop();
 
}

void onSerialReceived(String s){
  
  Serial.print("Serial has been received:");
  Serial.println(s);

  if(s == "W"){
    
      MI.Forward(VEL);
      MD.Forward(VEL);
    }

   if(s == "S"){
    
      MI.Backward(VEL);
      MD.Backward(VEL);
    }

    if(s == "A"){
      MI.Backward(VEL);
      MD.Forward(VEL);
    }

     if(s == "D"){
      MI.Forward(VEL);
      MD.Backward(VEL);
    }

    if(s == "X"){
      
      MI.Stop();
      MD.Stop();
    }

}


void onJoystickPosMoved(int id, Joystick::JPOS pos){

      switch(pos){
        
        case Joystick::LEFT:
        Serial.println("LEFT");
        MI.Forward(VEL);
        MD.Forward(VEL);
        break;
        case Joystick::RIGHT:
        Serial.println("RIGHT");
        MI.Forward(VEL);
        MD.Forward(VEL);
        break;
        case Joystick::UP:
        Serial.println("UP");
        MI.Forward(VEL);
        MD.Forward(VEL);
        break;
        case Joystick::DOWN:
        Serial.println("DOWN");
         MI.Backward(VEL);
         MD.Backward(VEL);

        break;
        }

}
