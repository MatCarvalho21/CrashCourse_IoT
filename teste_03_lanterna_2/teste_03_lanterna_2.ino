// definindo as variáveis globais
const int buttonPin = 10; 
const int ledPin = 13;  

int buttonState = 0; 
int previousButtonState = 1;
int time = 0;
int pressureTime = 0;
const int debounceDelay = 25;
const int controlTime = 2000;

int ledState = -1;
bool isLedOn = false;
float ledIntensity = 255;
int ledMode = -1;

void setup() {
  // inicializando o led, o botão e definindo a taxa de bits/seg
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
}

void loop() {
  // lendo o estado do botão (0 ou 1)
  buttonState = digitalRead(buttonPin);

  // chama a função definida externamente para alterar o ledState
  updateLedState(buttonState);
  
  // série de comportamentos da lanterna, todos tendo como parâmentro a variável ledState
  switch(ledState){

    case 0: // 100%
      analogWrite(ledPin, ledIntensity);
      break;

    case 1: // 75%
      analogWrite(ledPin, ledIntensity*0.75);
      break;

    case 2: // 50%
      analogWrite(ledPin, ledIntensity*0.5);
      break;

    case 3: // 25%
      analogWrite(ledPin, ledIntensity*0.25);
      break;

    case 4: // PISCANDO
      if (isLedOn){
        analogWrite(ledPin, ledIntensity*0);
        isLedOn = false;
      } else{
        analogWrite(ledPin, ledIntensity);
        isLedOn = true;
      }
      break;

    case 5: // OSCILANDO
      analogWrite(ledPin, ledIntensity);
      ledIntensity += ledMode;
      if (ledIntensity == 0){
        ledMode = 1;
      } 
      if (ledIntensity == 255){
        ledMode = -1;
      } 
      break;

    default: // DESLIGADA
      analogWrite(ledPin, ledIntensity*0);
      ledIntensity = 255;
      break;
  }

  previousButtonState = buttonState;
}

void updateLedState(int buttonState){
  // toda vez que o botão é apertado, a variável "pressureTime" é atualizada
  if (buttonState == 1){
    pressureTime = millis() - time;
  }

  // vai medir tempos curtos de pressão, com menos de um segundo, e alterar o estado da lanterna
  if (pressureTime > debounceDelay && pressureTime < controlTime && previousButtonState == 1 && buttonState == 0){
    ledState += 1;

    if (ledState > 6){
      ledState = 0;
    }
    
    // foi necessário começar com -1 para fazer funcionar, por isso o "<= 0"
    if (ledState <= 0){
      isLedOn = false;
    } else{
      isLedOn = true;
    }
  }

  // a atualização constante da variável time é importante para que, quando o botão não esteja pressionado, a variável "pressureTime" permaneça pequena
  if (buttonState == 0){
    time = millis();
  }

  // se o botão for pressionado por mais de dois segundos, a led vai alternar entre ligada e desligada e o time vai ser atualizado 
  if (buttonState == 1 && pressureTime >= controlTime) {
    if (ledState == 0){
      ledState = 1;
    } else{
      ledState = 0;
    }
    // isso faz com que a variável "pressureTime" volte a ser pequena e seja necessários mais 2 segundos para que esse bloco seja acionado novamente
    time = millis();
  } 
}