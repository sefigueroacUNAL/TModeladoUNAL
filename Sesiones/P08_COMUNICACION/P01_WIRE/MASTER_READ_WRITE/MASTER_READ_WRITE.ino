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

char BUFF[100];
char BUFF_I2C[100];
int buffCount = 0;

void setup() {
  // put your setup code here, to run once:
  
  Wire.begin(MASTER_ADDR); // join i2c bus with address #8
  Serial.begin(9600);



  
  

}

void loop() {
  // put your main code here, to run repeatedly:
  //Wire.beginTransmission(SLAVE_1_ADDR);


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

void OnLineReceived(String rec){

rec.toUpperCase();

  //rec cannnot be compare with switch so we use if
  
  if(rec == "HOLA"){
    
    Serial.println("Hola, ¿Cómo estás");
    
  }else if ( rec == "ADIOS"){
    
    Serial.println("Fue un gusto");  
    
  }else if( rec.startsWith("**") ){
    String out = "We will send: " + rec.substring(2);
     String s = rec.substring(2) + "\n";
     s.toCharArray(BUFF_I2C,100);

  Wire.beginTransmission(SLAVE_1_ADDR); // transmit to device #8
  Wire.write(BUFF_I2C);        // sends five bytes
                    // sends one byte
  Wire.endTransmission(); 


     
    Serial.println(out);
    
    }
  {
     Serial.println("No entiendo");
  }
}

//Function to read serial depending on events
void serialEvent(){
  while(Serial.available()){
    char rec = Serial.read();
    if(rec == '\n'){
      //We got a line
      if(BUFF[buffCount-1]=='\r'){
        BUFF[buffCount -1]=0;
        }
        BUFF[buffCount] = 0; //En String
        OnLineReceived(String(BUFF));
        buffCount = 0;          
      }else{
        if(buffCount< 100){
           BUFF[buffCount++] = rec;
        }
    }
}
}
