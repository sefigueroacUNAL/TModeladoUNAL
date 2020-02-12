#include <SPI.h>

//int MISO = 12;
volatile bool received = false;
volatile int LAST_REC = 0x00;
volatile int total=2;
volatile int sended;
byte buff[100];
volatile int READ_VAL;
volatile byte first;
volatile byte second;



void setup() {

  Serial.begin(9600);
  
  pinMode(MISO,OUTPUT); //Configurar MISO
  SPCR |= _BV(SPE); //Activar modo slave
  SPI.attachInterrupt();

}

void loop() {
  // put your main code here, to run repeatedly:
 
 if(LAST_REC == 0x01){
 // Serial.println("Rec 0X01");
  
 //   String s = String("F:") + first + "S:" + second;
 //   Serial.println(s);
  
  }

  if( sended >= total){
    READ_VAL = analogRead(A0);
    Serial.println(A0);
    }

}

ISR (SPI_STC_vect){

  LAST_REC = SPDR;
  

  if(LAST_REC == 0x01){
    sended = 0;
  while(sended < total){
   first = (byte)READ_VAL>>8;
   second = (byte)READ_VAL;
     delayMicroseconds(5);
      SPDR  = first;
       sended++;
     delayMicroseconds(20);
      SPDR  = second;
       sended++;
   
    }
    sended = 3;
  }
  
}
