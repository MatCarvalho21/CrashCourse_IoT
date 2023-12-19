int led_vermelha = 13;

void setup() {
  pinMode(led_vermelha, OUTPUT);

}

int delay_ = 1000;

void loop() {
  digitalWrite(led_vermelha, HIGH);
  delay(delay_); 

  digitalWrite(led_vermelha, LOW);
  delay(delay_);
}
