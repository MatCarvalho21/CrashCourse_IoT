int led_vermelha = 13;
int botao = 2;



void setup() {
  pinMode(led_vermelha, OUTPUT);
  pinMode(botao, INPUT);
  int initialTime = millis();
}


void loop() {
  // vai retornar o estado do botão, se está pressionado ou não
  estadoBotao = digitalRead(botao);

  while(estadoBotao == HIGH){
  }

  while(estadoBotao == LOW){
    int pressedTime = millis();
    timeDiference = pressedTime - initialTime;
    if (timeDiference >= 2000){
      Serial.println("Deu certo!");
      estadoBotao = HIGH;
      initialTime = pressedTime;
    }
  }
}

