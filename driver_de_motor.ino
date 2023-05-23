void setup() {
  pinMode(9, INPUT_PULLUP); // pino de comunicação de movimento para a esquerda;
  pinMode(11, INPUT_PULLUP); // pino de comunicação de movimento para a direita;
  pinMode(5, OUTPUT); // pino de comunicação de movimento para a esquerda;
  Serial.begin(9600);
}

void loop() {
  digitalRead(5);
  analogWrite(5,40);

}
