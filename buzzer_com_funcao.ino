/*
Este é um exemplo de programa que possui uma função definida pelo usuário
A função toca(nota, duracao) aciona o Buzzer com a nota correspondente por ## ms)
A função possui as notas do4, re4, fa4, sol4, la4 [440 Hz], si4 e d05
A função também possui a opção "pausa" para o valor de nota
Exemplos de chamada: 
  toca(do4, 500);
  toca(pausa, 1500);
Obs.: A função toca() não gera retorno.
Elaborado por Prof. Filippo Valiante Filho
https://prof.valiante.info
Abril/2025
*/

int duracao;
int pinBuzzer = 11;
enum nota {do4, re4, mi4, fa4, sol4, la4, si4, do5, pausa};
//vnota nota;

void setup() {
  pinMode(pinBuzzer, OUTPUT); // configura o pino do buzzer como saída
}

void loop() {
  toca(do4, 500);
  toca(re4, 500);
  toca(mi4, 500);
  toca(fa4, 500);
  toca(sol4, 500);
  toca(la4, 500);
  toca(si4, 500);
  toca(do5, 500);
  toca(pausa, 500);
  toca(do5, 500);
  toca(si4, 500);
  toca(la4, 500);
  toca(sol4, 500);
  toca(fa4, 500);
  toca(mi4, 500);
  toca(re4, 500);
  toca(do4, 500);
  toca(pausa, 1500);
  toca(do4, 500);
  toca(re4, 500);
  toca(mi4, 500);
  toca(fa4, 500);
  toca(pausa, 125);
  toca(fa4, 125);
  toca(pausa, 125);
  toca(fa4, 500);
  toca(pausa, 125);
  toca(do4, 500);
  toca(re4, 500);
  toca(do4, 500);
  toca(re4, 500);
  toca(pausa, 125);
  toca(re4, 125);
  toca(pausa, 125);
  toca(re4, 500);
  toca(pausa, 125);
  toca(do4, 500);
  toca(sol4, 500);
  toca(fa4, 500);
  toca(mi4, 500);
  toca(pausa, 125);
  toca(mi4, 125);
  toca(pausa, 125);
  toca(mi4, 500);
  toca(pausa, 125);
  toca(do4, 500);
  toca(re4, 500);
  toca(mi4, 500);
  toca(fa4, 500);
  toca(pausa, 125);
  toca(fa4, 125);
  toca(pausa, 125);
  toca(fa4, 500);
  toca(pausa, 125);
}

//Função toca()
void toca(int nota, int duracao) {
  switch (nota) {
    case do4 :
      tone(pinBuzzer, 264);
      delay(duracao);
      noTone(pinBuzzer);
      delay(duracao/8);
      break;
    case re4 :
      tone(pinBuzzer, 294);
      delay(duracao);
      noTone(pinBuzzer);
      delay(duracao/8);  
      break;
    case mi4 :
      tone(pinBuzzer, 330);
      delay(duracao);
      noTone(pinBuzzer);
      delay(duracao/8);  
    break;
    case fa4 :
      tone(pinBuzzer, 349);
      delay(duracao);
      noTone(pinBuzzer);
      delay(duracao/8);
      break;
    case sol4 :
      tone(pinBuzzer, 392);
      delay(duracao);
      noTone(pinBuzzer);
      delay(duracao/8);
      break;
    case la4 :
      tone(pinBuzzer, 440);
      delay(duracao);
      noTone(pinBuzzer);
      delay(duracao/8);
      break;
    case si4 :
      tone(pinBuzzer, 494);
      delay(duracao);
      noTone(pinBuzzer);
      delay(duracao/8);
      break;
    case do5 :
      tone(pinBuzzer, 527);
      delay(duracao);
      noTone(pinBuzzer);
      delay(duracao/8);
      break;
    case pausa :
      noTone(pinBuzzer);  
      delay(duracao);
      noTone(pinBuzzer);
      delay(duracao/8);
      break;
    default:
      noTone(pinBuzzer);
      break;
  }
}


