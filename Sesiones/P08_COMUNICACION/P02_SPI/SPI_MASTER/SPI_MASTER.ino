#include <SPI.h>

//int SS = 10;
int first = 0;
int second = 0;
int value = 0;

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  digitalWrite(SS,HIGH);
  SPI.begin();
  SPI.setClockDivider(SPI_CLOCK_DIV16);

}

void loop() {
  // put your main code here, to run repeatedly:

  digitalWrite(SS,LOW);
  SPI.transfer(0x01);
  delayMicroseconds(10);
  first = SPI.transfer(0);
  delayMicroseconds(20);
  second = SPI.transfer(0);

  value = (first << 8) + second;

  Serial.println(value);
  delay(100);

}
