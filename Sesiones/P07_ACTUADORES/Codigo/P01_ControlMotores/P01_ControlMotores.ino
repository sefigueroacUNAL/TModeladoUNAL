#include "Motor.h"
#include "ButtonDebounce.h"
#include "Joystick.h"

int VEL = 200;

Motor MI(13,10),MD(8,9);
ButtonDebounce button(7,true);
Joystick J1(A4,A5,0);

//Prototipos
void onButtonPressed(int pin);
void onJoystickPosMoved(int id, Joystick::JPOS pos);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  MI.Init();
  MD.Init();

  button.setLowCallback(&onButtonPressed);
  J1.setCallback(&onJoystickPosMoved);
 

}

void loop() {

  button.poll();
  J1.poll();
 

}

void onButtonPressed(int pin){
  String s = String("Pin") + pin + " has been pressed";
  Serial.println(s);
  MI.Stop();
  MD.Stop();
}

void onJoystickPosMoved(int id, Joystick::JPOS pos){

      switch(pos){
        case Joystick::LEFT:
        Serial.println("LEFT");
        break;
        case Joystick::RIGHT:
        Serial.println("RIGHT");
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
