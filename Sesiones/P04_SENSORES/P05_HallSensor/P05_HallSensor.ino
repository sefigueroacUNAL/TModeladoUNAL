//This code reads the value of Hall Magnetic sensor
#define READ_PIN A0
const int threshold = 900;

void setup(){
 
  Serial.begin(9600);
  
}

void loop(){

  int value = analogRead(READ_PIN);

  Serial.print("V:");
  Serial.print(value);
  Serial.print("|");

  if ( value > threshold ){
    Serial.println("No magnetic field");
  }else{
    Serial.println("Magnetic field detected");
  }
        
}
