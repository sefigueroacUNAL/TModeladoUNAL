//Conexiones

//Bicolor lED -  GND
//Bicolor lED - 
#include "mylib.h"

unsigned long timeMark1;
unsigned long timeMark2;
int state1;
int state2;




void setup() {
  // put your setup code here, to run once:
pinMode(9,OUTPUT);
pinMode(10,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  FadeInOut(9,&timeMark1,100,100,100,&state1,200);
  FadeInOut(10,&timeMark2,200,0,100,&state2,200);
  //analogWrite(10,128);

}







