#include <Arduino.h>

// Pinos de saída para os LEDs
#define LED_VERDE 2
#define LED_AMARELO 3
#define LED_VERMELHO 4

// Tempos configuráveis (em milissegundos)
const unsigned long tempoVerde = 5000;
const unsigned long tempoAmarelo = 2000;
const unsigned long tempoVermelho = 5000;

void mostrarSemaforo() {
  digitalWrite(LED_VERDE, HIGH);
  digitalWrite(LED_AMARELO, LOW);
  digitalWrite(LED_VERMELHO, LOW);
  delay(tempoVerde);

  digitalWrite(LED_VERDE, LOW);
  digitalWrite(LED_AMARELO, HIGH);
  digitalWrite(LED_VERMELHO, LOW);
  delay(tempoAmarelo);

  digitalWrite(LED_VERDE, LOW);
  digitalWrite(LED_AMARELO, LOW);
  digitalWrite(LED_VERMELHO, HIGH);
  delay(tempoVermelho);
}

void setup() {
  pinMode(LED_VERDE, OUTPUT);
  pinMode(LED_AMARELO, OUTPUT);
  pinMode(LED_VERMELHO, OUTPUT);
}

void loop() {
  mostrarSemaforo();
}
