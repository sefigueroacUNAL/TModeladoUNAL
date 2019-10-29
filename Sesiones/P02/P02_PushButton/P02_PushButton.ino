
//int //Tamaño depende del compilador 16 bits
//byte, // 8 bits
//char, 
//float, 
//double tipos de variables
//String
enum BSTATE{UP,DOWN,BLOW,BHIGH};
BSTATE state = BHIGH;
byte oldValue = HIGH;
byte newValue = HIGH;
int cnt = 0;
const int pushButton = 2; //No se puede conectar al pin 0 ni 1
int debounceTime = 50; //Time in milliseconds
unsigned long lastTime;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); //Comunicación serial al computador 9600 Baudios
  pinMode(pushButton, INPUT_PULLUP);
  
}

void loop() {
  // put your main code here, to run repeatedly
  DoReadings();

}

void DoReadings(){
  newValue = digitalRead(pushButton);
  switch(state){
    case BHIGH:
      if (newValue == LOW){
        lastTime = millis();
        state = DOWN;
        }
    break;
    case DOWN:
      if(millis() - lastTime > debounceTime){
        if(newValue == LOW){
          state = BLOW;
          OnButtonLOW();
          }
        }
    break;
    case BLOW:
      if (newValue == HIGH){
        lastTime = millis();
        state = UP;
        }
    break;
    case UP:
      if(millis() - lastTime > debounceTime){
        if(newValue == HIGH){
          state = BHIGH;
          OnButtonHIGH();
          }
        }      
  }
}

void OnButtonLOW(){
  String a = String("El boton se ha presionado ") + (++cnt) + " veces";
  Serial.println(a);
}

void OnButtonHIGH(){
  Serial.println("We are high");
 }
