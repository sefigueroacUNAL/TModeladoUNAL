
/*
 * SIMPLE SERIAL READ
 * 
 */
char BUFF[100];
int buffCount = 0;

void setup() {

  Serial.begin(9600); //Init serial communication

}


void loop() {
  

}

void OnLineReceived(String rec){

rec.toUpperCase();

  //rec cannnot be compare with switch so we use if
  if(rec == "HOLA"){
    
    Serial.println("Hola, ¿Cómo estás");
    
  }else if ( rec == "ADIOS"){
    
    Serial.println("Fue un gusto");  
    
  }else if( rec.startsWith("**") ){
    String out = "We will write: " + rec.substring(2);
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
