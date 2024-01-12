// importando a biblioteca wire (serve para estabelecer comunicação usando o protocolo I2C) - usando os pinos SDA e SCL 
#include<Wire.h> 

// definindo variáveis globais
const int MPU=0x68;  // endereço do MPU
int AcX,AcY,AcZ,Tmp,GyX,GyY,GyZ; // dados que serão fornecidos pelo sensor

void setup() {
  Serial.begin(9600);

  // inicializa a biblioteca Wire
  Wire.begin();
  Wire.beginTransmission(MPU);
  Wire.write(0x6B);
  Wire.write(0); 
  Wire.endTransmission(true);
}

void loop() {
  // faz uma leitura a cada passagem no loop
  Wire.beginTransmission(MPU);
  Wire.write(0x3B);  // começa com o registro 0x3B (ACCEL_XOUT_H)
  Wire.endTransmission(false);

  // fazendo a leitura do sensor e salvando os dados en variáveis já declaradas
  Wire.requestFrom(MPU, 14, true);  
  AcX=Wire.read()<<8|Wire.read();  // aceleração eixo X
  AcY=Wire.read()<<8|Wire.read();  // aceleração eixo Y
  AcZ=Wire.read()<<8|Wire.read();  // aceleração eixo Z
  Tmp=Wire.read()<<8|Wire.read();  // temperatura interna do chip
  GyX=Wire.read()<<8|Wire.read();  // orientação eixo X
  GyY=Wire.read()<<8|Wire.read();  // orientação eixo Y
  GyZ=Wire.read()<<8|Wire.read();  // orientação eixo Z

  // as medidas de acelerção estão em metros/segundo ao quadrado
  Serial.print("AcX = "); Serial.print(AcX); Serial.print(" m/s²");
  Serial.print(" | AcY = "); Serial.print(AcY); Serial.print(" m/s²");
  Serial.print(" | AcZ = "); Serial.print(AcZ); Serial.print(" m/s²");
  // convertendo a temperatura bruta em graus celsius
  Serial.print(" | Tmp = "); Serial.print(Tmp/340.00+36.53); Serial.print(" Cº");
  // as medidas de rotação estão em radianos por segundo
  Serial.print(" | GyX = "); Serial.print(GyX); Serial.print(" rad/s");
  Serial.print(" | GyY = "); Serial.print(GyY); Serial.print(" rad/s");
  Serial.print(" | GyZ = "); Serial.print(GyZ); Serial.println(" rad/s");

}
