//modoLinha se trata somente da leitura do PIN_MODO, modoSeguidor é a função com a lógica do seguidor de linha.
#include "pinos.h"

bool modoLinha = false;

void setupLinha(){
  configurarMotoresLinha();
  configurarSensoresLinha();

  //Fiz assim pra caso a gente use a chave pull up
  pinMode(PIN_MODO, INPUT_PULLUP);

  modoLinha = (digitalRead(PIN_MODO) == LOW);

  //Garante q vai começar parado antes de qualquer interação.
  moverMotores(0, 0);
}

void loopSeguidor(){
  //dps o modoSeguidor() pode ser chamado num programa q inclua os dois modos em um só
  modoSeguidor();
}
