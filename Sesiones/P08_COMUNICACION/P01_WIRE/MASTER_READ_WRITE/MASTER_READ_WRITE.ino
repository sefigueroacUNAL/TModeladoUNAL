#include <Wire.h>

//Addresses
#define MASTER_ADDR 8
#define SLAVE_1_ADDR 9


//Request Codes
#define STRING_REQ

byte isNew;
int first;
int second;
int value;

void setup() {
  // put your setup code here, to run once:
  
  Wire.begin(MASTER_ADDR); // join i2c bus with address #8
  Serial.begin(9600);



  
  

}

void loop() {
  // put your main code here, to run repeatedly:
  Wire.beginTransmission(SLAVE_1_ADDR);


  //READ
  Wire.requestFrom(SLAVE_1_ADDR,3);
  delayMicroseconds(10);
  while(Wire.available()){
    isNew = Wire.read();
    first = Wire.read();
    second = Wire.read();
    value = (first << 8) + second;
    }

 if (isNew){
  String s = String("Value:");
  Serial.println(s + value);
  
  isNew = 0;
  }
  //Serial.println(String("Requested") + "isN" + isNew + " first:" + first + " second:" + second);

  

  
  
  
  

}
