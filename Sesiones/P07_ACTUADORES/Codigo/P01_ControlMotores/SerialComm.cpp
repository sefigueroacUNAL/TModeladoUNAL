#include "SerialComm.h"
#include "Arduino.h"

//class SerialComm{
//
//  const char** commands;
//  typedef void (*Function)(int id,char *command);
//  Function* callbacks;
//  int BAUDIOS = 9600;
//
//  public: 
//    SerialComm();
//    SerialComm(int BAUDIOS);
//    SetCommands(Function callbacks[], char** commands);
//    poll();
//  
//};

#ifndef S_BUFF
char BUFF[100];
#define S_BUFF
#endif


SerialComm::SerialComm(){  
  
  }


void SerialComm::Init(int _BAUDIOS){
  BAUDIOS = _BAUDIOS;
  Serial.begin(BAUDIOS);
  }

void SerialComm::SetCommands(Function  _callbacks[],const char** _commands, int len = 1){

  commands = _commands;
  callbacks = _callbacks;
 
 }

void SerialComm::poll(){

  while(Serial.available()){
    char rec = Serial.read();
    if(rec == '\n'){
      //We got a line
      if(BUFF[buffCount-1]=='\r'){
        BUFF[buffCount -1]=0;
        }
        BUFF[buffCount] = 0; //En String
        if(callback) callback(String(BUFF));
        buffCount = 0;          
      }else{
        if(buffCount< 100){
           BUFF[buffCount++] = rec;
        }
    }
}
}
  
  

  void SerialComm::setCallback(FunctionString fn){
      callback = fn;
}
