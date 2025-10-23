//Exemplo de leitura do sensor capacitivo (TOUCH) no ESP32
//Prof. Filippo Valiante Filho - out.2025
//https://prof.valiante.info

const int sensor = T5;  //GPIO 12 (pode usar o nº da GPIO também)
const int pinoLED = 33;
int controle = 0;
int limiar = 500;  //este valor ficou coerente com a leitura do meu dispositivo,
                   //pode ser necessário ajustar.
                   //No teste usei apenas um jumper conectado ao pino.
void setup() {
  Serial.begin(115200);
  pinMode(pinoLED, OUTPUT);
}

void loop() {
  controle = touchRead(sensor);  //Lê o sensor
  Serial.print(controle);        //Imprime o valor no monitor serial
  if (controle < limiar) {       //Avalia se acende o LED ou não
    digitalWrite(pinoLED, HIGH);
    Serial.println("\t* LED ACESO *");
  } else {
    digitalWrite(pinoLED, LOW);
    Serial.println("\tled apagado");
  }
  delay(500);
}
