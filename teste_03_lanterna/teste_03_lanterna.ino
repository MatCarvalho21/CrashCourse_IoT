// numero das saídas que estão conectados o botão e a LED
int buttonPin = 10; 
int ledPin = 13;  

// variável criada para armazenar o estado do botão e o tempo de pressão
int buttonState = 0; 
int previousButtonState = 1;
int time = 0;
int pressureTime = 0;
int debounceDelay = 25;

// variáveis para controlar os diferentes estados da lanterna
int ledState = -1;
float isLedOn = false;
int ledIntensity = 255;
int ledMode = -1;

void setup() {
  // inicializando o botão e a led
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
}

void loop() {
  // alterando a variável do botão, para o estado real dele (vai alternar entre 0 e 1)
  buttonState = digitalRead(buttonPin);
  
  // toda vez que o botão é apertado, a variável "pressureTime" é atualizada
  if (buttonState == 1){
    pressureTime = millis() - time;
  }

  // vai medir tempos curtos de pressão, com menos de um segundo, e alterar o estado da lanterna
  if (pressureTime > debounceDelay && pressureTime <= 1000 && previousButtonState == 1 && buttonState == 0){
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
  if (buttonState == 1 && pressureTime >= 2000) {
    if (ledState == 0){
      ledState = 1;
    } else{
      ledState = 0;
    }
    // isso faz com que a variável "pressureTime" volte a ser pequena e seja necessários mais 2 segundos para que esse bloco seja acionado novamente
    time = millis();
  } 

  // ->> funcionamento dos diferentes estados da lanterna, com base na variável "ledState"

  // DESLIGADA
  if (ledState == 0){
    analogWrite(ledPin, 0);
    ledIntensity = 255;
  } 

  // 100%
  if (ledState == 1){
    analogWrite(ledPin, 255);
  }

  // ~= 75%
  if (ledState == 2){
    analogWrite(ledPin, 192);
  }

  // ~= 50%
  if (ledState == 3){
    analogWrite(ledPin, 128);
  }

  // ~= 25%
  if (ledState == 4){
    analogWrite(ledPin, 64);
  }

  // PISCANDO (delay de 0,1 segundos)
  if (ledState == 5){
    if (isLedOn){
      analogWrite(ledPin, 0);
      isLedOn = false;
    } else{
      analogWrite(ledPin, 255);
      isLedOn = true;
    }
    delay(100);
  }

  // OCILANDO
  if (ledState == 6){
    analogWrite(ledPin, ledIntensity);
    ledIntensity += ledMode;
    if (ledIntensity == 0){
      ledMode = 1;
    } 
    if (ledIntensity == 255){
      ledMode = -1;
    } 
  }

  // atualizando a variávle de controle
  previousButtonState = buttonState;
}