//This code reads the value of Hall Magnetic sensor
#define READ_PIN A0
const int threshold = 500;

void setup(){
 
  Serial.begin(9600);
  
}

void loop(){

  int value = analogRead(READ_PIN);

  Serial.print("V:");
  Serial.print(value);
  Serial.print("|");

  if ( value > threshold ){
    Serial.println("Low light");
  }else{
    Serial.println("High light");
  }
        
}
