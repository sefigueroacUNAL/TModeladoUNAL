
//int //Tamaño depende del compilador 16 bits
//byte, // 8 bits
//char, 
//float, 
//double tipos de variables
//String
enum BSTATE{UP,DOWN,BLOW,BHIGH};
BSTATE states[12];
int cnts[12] ;
int pushButtons[12]; //No se puede conectar al pin 0 ni 1
int debounceTime = 50; //Time in milliseconds
unsigned long lastTimes[12];


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); //Comunicación serial al computador 9600 Baudios
 
 for( int i = 2; i < 13 ; i++){ //Initialize
    pinMode(i,INPUT_PULLUP);
    pushButtons[i - 2] = i;
    cnts[i-2] = 0;
    states[i-2] = BHIGH;
    lastTimes[i-2] = millis();
  } 
  
}

void loop() {
  // put your main code here, to run repeatedly
  for(int i = 2; i < 13; i++){
    //This functions reads each pin.
    // Arguments are passed by reference (&) instead of value
  DoReadings(&lastTimes[i-2],&states[i-2],&pushButtons[i-2]);
  }

}

void DoReadings(unsigned long * lastTime, BSTATE* state, int *pushButton){
  int newValue = digitalRead(*pushButton);
  switch(*state){
    case BHIGH:
      if (newValue == LOW){
        *lastTime = millis();
        *state = DOWN;
        }
    break;
    case DOWN:
      if(millis() - *lastTime > debounceTime){
        if(newValue == LOW){
          *state = BLOW;
          OnButtonLOW(*pushButton);
          }
        }
    break;
    case BLOW:
      if (newValue == HIGH){
        *lastTime = millis();
        *state = UP;
        }
    break;
    case UP:
      if(millis() - *lastTime > debounceTime){
        if(newValue == HIGH){
          *state = BHIGH;
          OnButtonHIGH(*pushButton);
          }
        }      
  }
}

void OnButtonLOW(int pushButton){
  String str = String("El boton ") + pushButton + " se ha presionado " + (++cnts[pushButton-2]) + " veces";
  Serial.println(str);
}

void OnButtonHIGH(int pushButton){
  Serial.println("We are high");
 }
