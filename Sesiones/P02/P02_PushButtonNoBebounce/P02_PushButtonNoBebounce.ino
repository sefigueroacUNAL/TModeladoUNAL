
//int //Tamaño depende del compilador 16 bits
//byte, // 8 bits
//char, 
//float, 
//double tipos de variables
//String

byte oldValue = HIGH;
byte newValue = HIGH;
int cnt = 0; //Counter;
unsigned long lastTime = 0; //Variable to save time
const int pushButton = 2; //Can not use pin 0 nor 1
int debounceTime = 50; //Time in milisecons to receive measure


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); //Comunicación serial al computador 9600 Baudios
  pinMode(pushButton, INPUT_PULLUP);

  
  
 
}

void loop() {
  // put your main code here, to run repeatedly:

  //Lectura del botón
  //digitalRead(pushButton);

  if( oldValue == HIGH && newValue == LOW){   
    cnt++;
    }

     oldValue = newValue;
  
  String str =  String("El valor del contador es: ") + cnt;
  Serial.println(str);
  byte value = digitalRead(pushButton);
  
}
