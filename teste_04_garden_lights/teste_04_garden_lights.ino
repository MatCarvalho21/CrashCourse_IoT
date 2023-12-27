int ldrPin = A0;
int ledPin = 13;
int LIGHT_THRESHOLD = 50;

int ledIntensity = 0;
int previousLedIntensity = 1;

int initialTime = 0;
int time = 0;
int timeDiference = 0;

void setup() {
  // inicializando o LED e o sensor LDR
  pinMode(ldrPin,INPUT);
  pinMode(ledPin,OUTPUT);

  Serial.begin(9600);
}

void loop() {
  // obtendo a intensidade luminosa
  int sensorRead = analogRead(ldrPin);

  // configurando a intensidade do LED com base no mapeamento das leituras do sensor
  ledIntensity = 255 - map(sensorRead, 0, 1000, 255, 0);

  // faz a medição do tempo e a cada 2 segundos chama a função que atualiza a luminosidade do LED
  time = millis();
  timeDiference = time - initialTime;

  if (timeDiference >= 2000){
    // verifica se a variação na luminosidade, durante os dois segundos anteriores, foi maior do que 30, caso seja verdade. altera a intensidade do LED
    if (abs(ledIntensity - previousLedIntensity) >= 30){
      updateLightBrightness(ledIntensity);
    }
    initialTime = millis();
    previousLedIntensity = ledIntensity;
  }

}

void updateLightBrightness(int ledIntensity){
  if (ledIntensity <= LIGHT_THRESHOLD) {
    digitalWrite(ledPin, LOW);
  } else {
    analogWrite(ledPin, ledIntensity);
  }
}