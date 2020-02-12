#include <Wire.h>
#define MASTER_ADDR 8
#define SLAVE_1_ADDR 9

int READ_VAL;
byte isNew;

void setup() {
  // put your setup code here, to run once:
  Wire.begin(SLAVE_1_ADDR);
  Wire.onRequest(requestEvent);
  Wire.onReceive(receiveEvent);
//  Serial.begin(9600);

  

}

void loop() {
  // put your main code here, to run repeatedly:
  READ_VAL = analogRead(A0);
  Serial.println(READ_VAL);
  isNew = 0xFF;
  //delay(500);
  

}

void requestEvent(){
  
  byte first = (byte) (READ_VAL>>8);
  byte second = (byte)READ_VAL;

  Wire.write(isNew);
  Wire.write(first);
  Wire.write(second);



   // Serial.println(String("Requested") + "isN" + isNew + " first:" + first + " second:" + second);
  if (isNew){
    isNew = 0x00;
    }  
}

void receiveEvent(int total){ 
  String s = String("Rec:");
  String rec = "";
  while(Wire.available() > 0){
    char c = Wire.read();
    rec = rec + c;
    }
    Serial.print(s + rec);
}
