int delay_ = 500;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);

}

void loop() {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(delay_); 

  digitalWrite(LED_BUILTIN, LOW);
  delay(delay_);
}
