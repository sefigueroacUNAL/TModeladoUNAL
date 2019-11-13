#include "src/DHT/dht.h"
#define dht_apin A0 // Analog Pin sensor is connected to
 
dht DHT;
 
void setup(){
 
  Serial.begin(9600);
  delay(500);//Delay to let system boot
  Serial.println("DHT11 Humidity & temperature Sensor\n\n");
  delay(1000);//Wait before accessing Sensor
 
}//end "setup()"

int state = 0;
unsigned long timeMark = 0;
 
void loop(){
  //Start of Program 
    

  if(state == 0){
    timeMark = millis();
     int  val = DHT.read11(dht_apin);
    
    Serial.print("Current humidity = ");
    Serial.print(DHT.humidity);
    Serial.print("%  ");
    Serial.print("temperature = ");
    Serial.print(DHT.temperature); 
    Serial.println("C  ");
    state = 1;
    }

   if(state == 1){
    if(millis() - timeMark > 100)
      state = 0;
    }
    
  
    
  
    
   // delay(100);//Wait 5 seconds before accessing sensor again.
 
  //Fastest should be once every two seconds.
 
}// end loop() 
