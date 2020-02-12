#ifndef JOYSTICK_H
#define JOYSTICK_H


class Joystick{

  
  
  

  
  public:

  enum JPOS{UP,RIGHT,DOWN,LEFT,CENTER};
  typedef void (*Function)(int id,JPOS);


    int Ax, Ay;
    int MIN=30;
    int MAX=994;
    int id=0;
     bool DEBUG = false;
    
    Function callback;
  
    Joystick(int,int,int);
    
    void poll();
    void setCallback(Function fn);
    void setLimits(int,int);
    int GetX();
    int GetY();

      private:

  JPOS lastPos;
  JPOS pos;
    
    
};



#endif
