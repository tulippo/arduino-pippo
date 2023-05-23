// ***OTIMIZADO***
#include <Servo.h> // biblioteca de comandos do Servo;
Servo servo1;
int angle=90; // angulo de leitura e execução do Servo;
int ang_inicial = 0;
int ang_limite = 180;
int var = 90; // variação controlada pelo usuário;

void setup()
{
  pinMode(9, INPUT_PULLUP); // pino de comunicação de movimento para a esquerda;
  pinMode(11, INPUT_PULLUP); // pino de comunicação de movimento para a direita;
  Serial.begin(9600);
  servo1.attach(6);
}

void loop() {
  while(angle > (-1 * var) && (angle < ang_limite + var)) // condição de verificação do angulo;
  {
    if(digitalRead(11) == 0) angle += var; 
    if(digitalRead(9) == 0) angle -= var;
    
    if(angle <= ang_inicial) angle = ang_inicial; // limitando um angulo inicial; 
    if(angle >= ang_limite) angle = ang_limite; // limitando um angulo final;
    
    servo1.write(angle); // envia o sinal de atualização angulo para o Servo.
    Serial.println(angle);
    delay(100);
  }
}
