
// definindo a entrada de cada uma das LEDs
int red_led = 13;
int blue_led = 12;
int green_led = 11;

// inicializando elas como elementos externos
void setup() {
  
  // taxa de transmissão bits/seg
  Serial.begin(9600);
  pinMode(red_led, OUTPUT);
  pinMode(blue_led, OUTPUT);
  pinMode(green_led, OUTPUT);

}

// definindo variáveis que serão usadas durante o loop
int time_ = 0;
int delay_ = 1000;
int list_of_leds[3] = {red_led, blue_led, green_led};
int RED_TIME = 1;
int BLUE_TIME = 2;
int GREEN_TIME = 3;


void loop() {
  // configurando as condições para que os LED sejam acesos
  if (time_ % RED_TIME == 0){
    digitalWrite(red_led, HIGH);
  }
  if (time_ % BLUE_TIME == 0){
    digitalWrite(blue_led, HIGH);
  }
  if (time_ % GREEN_TIME == 0){
    digitalWrite(green_led, HIGH);
  }

  // tempo que a luz permanecerá acesa
  delay(delay_);

  // como criar um for para iterar sobre um array com arduino, para acessar os diferentes leds
  for (int indice = 0; indice < 3; indice++){
    digitalWrite(list_of_leds[indice], LOW);
  }

  // tempo que a luz permanecerá apagada
  delay(delay_);
  time_ += 1;
}
