// definindo os pins que vamos trabalhar
// descobri que usar o const antes previne o que essas variáveis mudem no decorrer do código
const int trigPin = 7;
const int echoPin = 8;
long milimetros;
long centimetros;
long metros;
long duracao;

#define metersConveter 1/100
// pelo que eu consegui encontrar, a conversão usada é essa abaixo para converter os milisegundos para centimetros
#define centimetersConveter 29 / 2
#define millimetersConveter 10

void setup() {
  Serial.begin(9600);

  // inicializando os pins
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  // vai criar um intervalo em que o sensor ficará ligado e nesse intervalo ele vai fazer a medição
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // extração da duração entre os pulsos
  duracao = pulseIn(echoPin, HIGH);

  // usando as variáveis definidas no início para converter a medição em milisegundos para unidades de distância
  centimetros = duracao/centimetersConveter;
  metros = centimetros * metersConveter;
  milimetros = centimetros * millimetersConveter;

  Serial.println(centimetros);
}
