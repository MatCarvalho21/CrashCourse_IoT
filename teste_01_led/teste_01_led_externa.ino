// definindo as variáveis globais
const int ledVermelha = 13;
const int delay_ = 1000;

void setup() {
  // inicializando o led
  pinMode(ledVermelha, OUTPUT);
}

void loop() {
  // ligando e desligando o led, com um delay entre os estados
  digitalWrite(ledVermelha, HIGH);
  delay(delay_); 

  digitalWrite(ledVermelha, LOW);
  delay(delay_);
}
