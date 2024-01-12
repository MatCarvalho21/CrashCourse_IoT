// definindo as variáveis globais
const int delay_ = 1000;

void setup() {
  // inicializando o led da própria placa
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  // ligando e desligando o led, com um delay entre os estados
  digitalWrite(LED_BUILTIN, HIGH);
  delay(delay_); 

  digitalWrite(LED_BUILTIN, LOW);
  delay(delay_);
}
