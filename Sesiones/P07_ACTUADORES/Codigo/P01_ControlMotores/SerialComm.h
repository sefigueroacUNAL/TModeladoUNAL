#ifndef SERIAL_H
#define SERIAL_H

#include "Arduino.h"

class SerialComm{

  const char** commands;
  public:
  typedef void (*Function)(int id,const char *commands);
  typedef void (*FunctionString)(String string);
  private:
  FunctionString callback;
  Function* callbacks; //Not implemented yaet
  int BAUDIOS = 9600;
  int buffCount = 0;

  public: 
    SerialComm();
    void Init(int BAUDIOS);
    void SetCommands(Function callbacks[], const char** commands, int len);
    void poll();
    void setCallback(FunctionString fs);
  
};

















#endif
