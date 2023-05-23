void setup() {
  Serial.begin(9600);
  pinMode(A0, INPUT);
  pinMode(6, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
}
void loop() {

 for(int contador = 0; contador < 20; contador++){
  digitalWrite(LED_BUILTIN, HIGH);
  delay(100);
  digitalWrite(LED_BUILTIN, LOW);
  delay(100); 
 }
 
 Serial.print("LDR - Luz do ambiente: ");
 Serial.println(analogRead(A0));

 if(analogRead(A0) > 100){
  digitalWrite(6, HIGH);
 }
 else {
  digitalWrite(6, LOW);
 }
  digitalWrite(LED_BUILTIN, LOW);
 delay(60000);
}
