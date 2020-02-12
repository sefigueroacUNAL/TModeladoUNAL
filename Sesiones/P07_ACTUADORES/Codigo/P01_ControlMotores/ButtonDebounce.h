#ifndef BUTTON_DEB_H
#define BUTTON_DEB_H

class ButtonDebounce{

  private:
  enum BSTATE{UP,DOWN,BLOW,BHIGH};

  typedef void (*Function)(int pin);
  
  BSTATE state =BHIGH;
  Function lowCallback = 0;
  Function highCallback = 0;

 


  public:

   bool DEBUG = false;
   
  ButtonDebounce(int,bool);
  
  
  int debounceTime = 50;
  int pin;
  unsigned long lastTime; 
  void setLowCallback(Function);
  void setHighCallback(Function);
  void poll();

  
   
};


#endif
