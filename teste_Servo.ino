#include <Servo.h>

Servo servo1;
int angle = 90;
int i = -1;
int pot = 15;

void setup() {
  pinMode(9, INPUT_PULLUP);
  pinMode(11, INPUT_PULLUP);
  Serial.begin(9600);
  servo1.attach(6);

}
void loop() {
  while ((angle > (i * pot)) && (angle < (180 + pot))) {
    if (digitalRead(11) == 0) angle += pot;
    if (digitalRead(9) == 0) angle -= pot;
    // servo1.write(angle);
    if (angle == (i * pot)) angle += pot;
    if (angle == (180 + pot)) angle -= pot;
    Serial.println(angle);
    delay(100);
  }

}
