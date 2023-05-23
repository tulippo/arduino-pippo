bool continuar = true;
const int passosPorGiro=64;
const int sensorMin = 0;
const int sensorMax = 400;
int range;
int retroceder;

#include <Stepper.h>

#define e1 13
#define e2 12
#define e3 11
#define e4 10

Stepper mp(passosPorGiro, e1, e3, e2, e4);

void setup() {
 Serial.begin(9600);
 pinMode(A0, INPUT);
 pinMode(2,OUTPUT);
 pinMode(3,INPUT);
}

void loop() {
  range = map(analogRead(A0), sensorMin, sensorMax, 0, 3);
  monitorar();
  manual();
  posNormal();
  Serial.println(retroceder);
  verificar();
}

//------------------------------------------------------------------------
//funcoes extras ---------------------------------------------------------
//------------------------------------------------------------------------

void motor(int vel, int sentido, int voltas, int temp){
  mp.setSpeed(vel);
  for(int i=0;i<(1*voltas);i++){
    mp.step(passosPorGiro*sentido);
    delay(temp);
  }
  delay(temp*2);
}
void motor2(){
  for(int i=0;i<16;i++){
    mp.step(passosPorGiro);
  }
  delay(1000);
}

void monitorar(){
    Serial.print("sinal especial: ");
    Serial.println(analogRead(A0));
    delay(200);
}
  
void manual(){
  if(digitalRead(3) != 0){
      switch(range){
      case 0:
              motor(500, -1, 1, 100);
              break;
      case 1: 
              motor(500, -1, 1, 100);
              break;
      case 2: 
              motor(500, -1, 1, 100);
              break;
      case 3: 
              motor(500, -1, 1, 100);
              break;
      break;
      }
    delay(100);
    } 
}

void posNormal(){
    switch(range){
        case 0:
                Serial.println("Pouca luminosidade para reconhecer");
                digitalWrite(2, 1);
                break;
        case 1: 
                motor(500, 1, 1, 100);
                retroceder++;
                digitalWrite(2, 0);
                break;
        case 2: 
                motor(500, 1, 1, 100);
                retroceder++;
                digitalWrite(2, 0);
                break;
        case 3: Serial.println("Sem necessidade de girar");
                digitalWrite(2, 1);
                break;
        break;
      } 
     delay(200);
}
void verificar(){
  if (retroceder == 16){
    retorno();
    retroceder = 0;
    delay(2000);
  }
}

void retorno(){
  motor(500, -1, retroceder, 100);
  delay(100);
}
