
#ifndef MOTOR_H
#define MOTOR_H

#include "Arduino.h"
#include "Motor.h"

Motor::Motor(int DIR_PIN, int ENABLE_PIN){
  
  PIN_DIR = DIR_PIN;
  PIN_ENABLE = ENABLE_PIN;
  
}

void Motor::Init(){
  
  pinMode(PIN_DIR,OUTPUT);
  pinMode(PIN_ENABLE,OUTPUT);

  dir = LOW;
  vel = 0;   
}

void Motor::SetSpeed(int velIn){
  vel = velIn;
  analogWrite(PIN_ENABLE, vel);
}

void Motor::SetDir(int dirIn){
    dir = dirIn;
    digitalWrite(PIN_DIR,dir);
}

void Motor::Forward(int velIn){
    SetDir(HIGH);
    SetSpeed(velIn);
}

void Motor::Backward(int velIn){
    SetDir(LOW);
    SetSpeed(velIn);
}

void Motor::Stop(){
    analogWrite(PIN_ENABLE, 0);
    digitalWrite(PIN_DIR,dir);
}

#endif
