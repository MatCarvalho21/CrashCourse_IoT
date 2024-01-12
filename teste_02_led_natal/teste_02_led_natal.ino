// definindo variáveis globais
const int redPin = 13;
const int bluePin = 12;
const int greenPin = 11;

int time_ = 0;
const int delay_ = 1000;
const int listOfLeds[3] = {redPin, bluePin, greenPin};
const int RED_TIME = 1;
const int BLUE_TIME = 2;
const int GREEN_TIME = 3;

void setup() {
  // inicializando os leds e definindo a taxa de bits/seg
  Serial.begin(9600);
  pinMode(redPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(greenPin, OUTPUT);
}

void loop() {
  // verificando condições para que cada um dos leds sejam acesos
  if (time_ % RED_TIME == 0){
    digitalWrite(redPin, HIGH);
  }

  if (time_ % BLUE_TIME == 0){
    digitalWrite(bluePin, HIGH);
  }

  if (time_ % GREEN_TIME == 0){
    digitalWrite(greenPin, HIGH);
  }

  delay(delay_);

  // vai iterar dentro do array de leds e desligar todos
  for (int indice = 0; indice < 3; indice++){
    digitalWrite(listOfLeds[indice], LOW);
  }

  delay(delay_);
  time_ += 1;
}
