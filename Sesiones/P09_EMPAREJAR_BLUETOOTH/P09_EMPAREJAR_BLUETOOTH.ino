#include <EEPROM.h>

/*
 * Los pasos son los siguientes:

1. Cargar el codigo en un arduino,
2. Resetear el Arduino y cuando el Led 13 esté encendido conectar el primer modulo bluetooth así   BTRX-->ARD TX, BTTx--->ARDRx, BTKEY--->DIGITAL2ARDUINO,
3. Esperar hasta el LED 13 se apague. En este momento se debe desconectar el modulo Bluetooth,
4. Resetear el aduino y con el segundo modulo bluetooth volver al paso 2.
5.Resetear el arduion y con el primer modulo bluetooth volver al paso 2. (Este paso es obligatoria, ya que el programa guarda la MAC del primero y lo empareja con el siguiente, peor es necesario que primero se empareje luego con la MAC del segundo.
 
 */


#define SBUFF 100
char BUFF[SBUFF];
String MyStr="";
String Str1="";
String Str2="";
String Str3="";
String Str4="";
int KEY_PIN=2;
int LED_PIN=13;
int FINISH_LED=10;
int Number=0;
int address=0;
int numR=0;
void setup(){
  
  pinMode(KEY_PIN,OUTPUT);
  digitalWrite(KEY_PIN,HIGH);
   pinMode(FINISH_LED,OUTPUT);
    pinMode(LED_PIN,OUTPUT);
  
  digitalWrite(LED_PIN,HIGH);

  Serial.begin(38400);
  Serial.setTimeout(5000);
  Number = EEPROM.read(address);
  
 
  
  
}

void loop(){
  
    {
       //Limpiar el Bufer
       
     
       while(Serial.available()){
       Serial.read();}
       digitalWrite(KEY_PIN,HIGH); //Asegurar el pin de key en bajo;
       digitalWrite(KEY_PIN,HIGH);

       Str1="";
       while(Str1!="OK\r"){
        
       digitalWrite(KEY_PIN,HIGH);
       digitalWrite(LED_PIN,HIGH); 
       while(Serial.available()){
       Serial.read();}
       
       Serial.println("AT");
       numR=Serial.readBytesUntil('\n',BUFF,SBUFF);//Este es un un numero para saber cuantos datos se han recibido
       BUFF[numR]=0; 
       Str1=String(BUFF);
       if(Str1!="OK\r"){
       while(Serial.available()){
       Serial.read();}
       ToggleSerial();}
       
       }
      
       Str2="";
       while(Str2!="OK\r"){
       Serial.println("AT+ORGL");
       numR=Serial.readBytesUntil('\n',BUFF,SBUFF);//Este es un un numero para saber cuantos datos se han recibido
       BUFF[numR]=0; 
       Str2=String(BUFF);
       }
      
       Serial.println("AT+ADDR?");
       numR=Serial.readBytesUntil('\n',BUFF,SBUFF);//Este es un un numero para saber cuantos datos se han recibido
       BUFF[numR]=0; 
       Str2=String(BUFF);
       Serial.println("La direccion es:");
       Serial.print(Str2);
       Serial.print("\n");
      
      delay(2000);
       while(Serial.available()){
       Serial.read();}
       
       Str2="";
       while(Str2!="OK\r"){
       Serial.print("AT+NAME=");
       Serial.print("EXPLORAMOVIL");
       Serial.println(Number);
       numR=Serial.readBytesUntil('\n',BUFF,SBUFF);//Este es un un numero para saber cuantos datos se han recibido
       BUFF[numR]=0; 
       Str2=String(BUFF);
      
       }
       
           
     
           
       Str3="";
       while(Str3!="OK\r"){
         
       Serial.println("AT+PSWD=5472");
       numR=Serial.readBytesUntil('\n',BUFF,SBUFF);//Este es un un numero para saber cuantos datos se han recibido
       BUFF[numR]=0; 
       Str3=String(BUFF);
       }
     
      
      Str3="";
       while(Str3!="OK\r"){ 
       Serial.println("AT+UART=9600,0,0");
       numR=Serial.readBytesUntil('\n',BUFF,SBUFF);//Este es un un numero para saber cuantos datos se han recibido
       BUFF[numR]=0; 
       Str3=String(BUFF);
       }
      
      
      Str3="";
       while(Str3!="OK\r"){ 
       Serial.println("AT+CMODE=1");
       numR=Serial.readBytesUntil('\n',BUFF,SBUFF);//Este es un un numero para saber cuantos datos se han recibido
       BUFF[numR]=0; 
       Str3=String(BUFF);
       }
      
      Str3="";
       while(Str3!="OK\r"){ 
       Serial.print("AT+ROLE=");
       Serial.println(Number%2);
       numR=Serial.readBytesUntil('\n',BUFF,SBUFF);//Este es un un numero para saber cuantos datos se han recibido
       BUFF[numR]=0; 
       Str3=String(BUFF);
       }
      
       
       char c=0;
       int k2=0;
       while(c!='\r'&&k2<20){
       BUFF[k2]=EEPROM.read(k2+2);
       c=(char)BUFF[k2];
       if ((byte)c==255){
       break;}
       k2++;
       }
       
       BUFF[k2]=0;
       Str2=String(BUFF);
       
       
      
    //  Str3="";
    //  while(Str3!="OK\r"){ 
       Serial.print("AT+BIND=");
       Serial.print(Str2);
       Serial.print("\n");
       numR=Serial.readBytesUntil('\n',BUFF,SBUFF);//Este es un un numero para saber cuantos datos se han recibido
       BUFF[numR]=0; 
       Str3=String(BUFF);
      delay(2000); 
    // }
  
       while(Serial.available()){
       Serial.read();}
      
 
      
      Str2=""; 
       Serial.println("AT+ADDR?");
       numR=Serial.readBytesUntil('\n',BUFF,SBUFF);//Este es un un numero para saber cuantos datos se han recibido
       BUFF[numR]=0; 
       Str2=String(BUFF);
       Serial.println("La direccion es:");
       Serial.print(Str2);
       Serial.print("\n");
      
      delay(1000);
       while(Serial.available()){
       Serial.read();}
       
      
       //Save ADDRESS ON EEPROM
       int k=0;
       while(BUFF[k]!=':'&&k<numR){
       k++;}
       Serial.print(k);
       Serial.print("-");
       int i=0;
       for(i=k+1;i<numR;i++){
       
       if (BUFF[i]==':'){
         BUFF[i]=',';
       }
     
       EEPROM.write(i+2-(k+1),(byte)BUFF[i]);
       delay(10);
       Serial.print(BUFF[i]);
       };
       EEPROM.write(i+2,'\r');
       delay(10);
       //----- CHECK ADDRES EEPROM ----
       //numData=EEPROM.read((byte)numR,1);

        c=0;
        k2=0;
       while(c!='\r'){
       BUFF[k2]=EEPROM.read(k2+2);
       c=(char)BUFF[k2];
       Serial.print(c);
       k2++;
       }
       
       BUFF[k2]=0;
       
       Str2=String(BUFF);
       Serial.print("||Se ha guardado en Memoria la direccion=");
       Serial.print(Str2);
       Serial.print("\n");
       //----------------------------
       
       delay(2000);
       while(Serial.available()){
       Serial.read();}
        Str4="";   
       digitalWrite(KEY_PIN,HIGH);
       digitalWrite(LED_PIN,HIGH);
       delay(1000);
       Serial.println("AT+RESET");
       digitalWrite(KEY_PIN,LOW);
       numR=Serial.readBytesUntil('\n',BUFF,SBUFF);//Este es un un numero para saber cuantos datos se han recibido
       BUFF[numR]=0; 
       Str4=String(BUFF);

      Serial.println(Str1);
      Serial.println(Str2);
      Serial.println(Str3);
      Serial.println(Str4);
        while(Serial.available()){
       Serial.read();}
       Number=(Number+1)%2;
       EEPROM.write(address,Number);
       digitalWrite(KEY_PIN,LOW);
       digitalWrite(LED_PIN,LOW);        
       digitalWrite(FINISH_LED,HIGH);
         
       while(1){}
       
     }
}


void ToggleSerial(){
  
  static int FLAG=0;
    Serial.end();
    if(FLAG==0){
    Serial.begin(38400);
    FLAG=1;
    }else{
    Serial.begin(38400);
    FLAG=0;
    }

}

void ReConnectSerial(int baudios){

    Serial.end();
    Serial.begin(baudios);

}
