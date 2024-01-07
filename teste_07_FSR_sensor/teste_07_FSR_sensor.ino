#include <LiquidCrystal_I2C.h>
#include <Wire.h>

const int fsrPin = A0;
const int threshold = 75; // uma variável bem mequetrefe com base no datasheet e na tabela do rapaz do yt 
int medicao;

#define endereco 0x27
#define numColunas 16
#define numLinhas 2

LiquidCrystal_I2C lcd(endereco, numColunas, numLinhas);

void setup() {
  pinMode(fsrPin, INPUT);
  Serial.begin(9600);

  lcd.init(); //inicializa
  lcd.backlight(); //liga a luz
  lcd.clear(); //limpa o conteúdo do display
}

void loop() {
  medicao = analogRead(fsrPin);

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
