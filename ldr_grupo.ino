#include <Stepper.h>

#define e1 13
#define e2 12
#define e3 11
#define e4 10

const int passosPorGiro=64;
Stepper meu(passosPorGiro, e1, e3, e4, e2);

void setup() {
  Serial.begin(9600);
  meu.setSpeed(500);
}
void loop() {
 Serial.print("LDR - Luz do ambiente: ");
 Serial.println(analogRead(A0));

 //if(analogRead(A0) < 100){}
  meu.step(-2048);
  delay(500);
  meu.step(2048);
 
}
