// importando bibliotecas
#include <LiquidCrystal_I2C.h>
#include <Wire.h>

// definindo variáveis globais
const int fsrPin = A0;
const int threshold = 75; // uma variável bem mequetrefe com base no datasheet e na tabela do rapaz do yt 
int medicao;

#define endereco 0x27
#define numColunas 16
#define numLinhas 2

LiquidCrystal_I2C lcd(endereco, numColunas, numLinhas);

void setup() {
  // inicializando o sensor e definindo a taxa de bits/seg
  Serial.begin(9600);
  pinMode(fsrPin, INPUT);

  lcd.init(); //inicializa
  lcd.backlight(); //liga a luz
  lcd.clear(); //limpa o conteúdo do display
}

void loop() {
  // leitura do sensor
  medicao = analogRead(fsrPin);

  // verificação da intensidade para deifinir qual mensagem será exibida
  if (medicao < threshold){
    lcd.setCursor(2,0);
    lcd.print("SEM PRESSAO");

  } else if (medicao < 100){  
    lcd.setCursor(1,0);
    lcd.print("A PRESSAO E DE:");
    lcd.setCursor(7, 1);

  } else{
    lcd.setCursor(1,0);
    lcd.print("A PRESSAO E DE:");
    lcd.setCursor(6, 1);
  }

  lcd.print(medicao);
  lcd.clear();
}
