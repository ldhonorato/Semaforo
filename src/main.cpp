#include <Arduino.h>

// Pinos de saída para os LEDs
#define LED_VERDE 2
#define LED_AMARELO 3
#define LED_VERMELHO 4

#define BOTAO_PEDESTRE 5

#define ESTADO_VERDE 0
#define ESTADO_AMARELO 1
#define ESTADO_VERMELHO 2

// Tempos configuráveis (em milissegundos)
unsigned long tempoVerde;
const unsigned long tempoVerde_pedestre = 3000;
const unsigned long tempoVerde_regular = 5000;

const unsigned long tempoAmarelo = 2000;
const unsigned long tempoVermelho = 5000;

unsigned long timestamp;

uint8_t u8EstadoAtual;

void mostrarSemaforo() {
  switch(u8EstadoAtual){
    case ESTADO_VERDE:
      if(digitalRead(BOTAO_PEDESTRE) == LOW){
        tempoVerde = tempoVerde_pedestre;
      }
      if(millis() - timestamp >= tempoVerde){
        u8EstadoAtual = ESTADO_AMARELO;
        digitalWrite(LED_VERDE, LOW);
        digitalWrite(LED_AMARELO, HIGH);
        timestamp = millis();
      }
      break;
    case ESTADO_AMARELO:
      if(millis() - timestamp >= tempoAmarelo){
        u8EstadoAtual = ESTADO_VERMELHO;
        digitalWrite(LED_AMARELO, LOW);
        digitalWrite(LED_VERMELHO, HIGH);
        timestamp = millis();
      }
      break;
    case ESTADO_VERMELHO:
      if(millis() - timestamp >= tempoVermelho){
        u8EstadoAtual = ESTADO_VERDE;
        tempoVerde = tempoVerde_regular;
        digitalWrite(LED_VERMELHO, LOW);
        digitalWrite(LED_VERDE, HIGH);
        timestamp = millis();
      }
      break;
  }
}

void setup() {
  pinMode(LED_VERDE, OUTPUT);
  pinMode(LED_AMARELO, OUTPUT);
  pinMode(LED_VERMELHO, OUTPUT);

  pinMode(BOTAO_PEDESTRE, INPUT_PULLUP);

  digitalWrite(LED_VERDE, HIGH);
  digitalWrite(LED_AMARELO, LOW);
  digitalWrite(LED_VERMELHO, LOW);
  timestamp = millis();
  tempoVerde = tempoVerde_regular;
  u8EstadoAtual = ESTADO_VERDE;
}

void loop() {
  mostrarSemaforo();
}
