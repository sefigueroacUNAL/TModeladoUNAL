const int ledPin = 13;
const int buttonPin = 2;

void setup() {
  // put your setup code here, to run once:
    pinMode(buttonPin,INPUT_PULLUP);
    Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
    String string =   String("SW:") + digitalRead(buttonPin)
    + " A0:" + analogRead(A0)
    + " A1:" + analogRead(A1);
      
    Serial.println(string);
}
