// numero das saídas que estão conectados o botão e a LED
int buttonPin = 10; 
int ledPin = 13;  

// variável criada para armazenar o estado do botão e o tempo de pressão
int buttonState = 0; 
int previousButtonState = 1;
int time = 0;
int pressureTime = 0;
int debounceDelay = 25;
int controlTime = 2000;

// variáveis para controlar os diferentes estados da lanterna
int ledState = -1;
bool isLedOn = false;
float ledIntensity = 255;
int ledMode = -1;

void setup() {
  Serial.begin(9600);
  // inicializando o botão e a led
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
}

void loop() {
  // alterando a variável do botão, para o estado real dele (vai alternar entre 0 e 1)
  buttonState = digitalRead(buttonPin);

  // ->> funcionamento dos diferentes estados da lanterna, com base na variável "ledState"
  updateLedState(buttonState);
  
  switch(ledState){
    case 0:
    Serial.println("100%");
      analogWrite(ledPin, ledIntensity);
      break;

    case 1:
    Serial.println("75%");
      analogWrite(ledPin, ledIntensity*0.75);
      break;

    case 2:
    Serial.println("50%");
      analogWrite(ledPin, ledIntensity*0.5);
      break;

    case 3:
    Serial.println("25%");
      analogWrite(ledPin, ledIntensity*0.25);
      break;

    case 4:
    Serial.println("Piscando");
      if (isLedOn){
        analogWrite(ledPin, ledIntensity*0);
        isLedOn = false;
      } else{
        analogWrite(ledPin, ledIntensity);
        isLedOn = true;
      }
      break;

    case 5:
    Serial.println("Ocilando");
      analogWrite(ledPin, ledIntensity);
      ledIntensity += ledMode;
      if (ledIntensity == 0){
        ledMode = 1;
      } 
      if (ledIntensity == 255){
        ledMode = -1;
      } 
      break;

    default:
    Serial.println("Desligada");
      analogWrite(ledPin, ledIntensity*0);
      ledIntensity = 255;
      break;
  }

  // atualizando a variávle de controle
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