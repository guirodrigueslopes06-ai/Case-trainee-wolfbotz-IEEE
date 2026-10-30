//ESSE NÃO É O ARQUIVO A SER INTEGRADO, SOMENTE O ARQUIVO COM A PINAGEM CASO NECESSÁRIA UMA TESTAGEM "INDEPENDENTE" DO CÓDIGO.
//modoLinha se trata somente da leitura do PIN_MODO, modoSeguidor é a função com a lógica do seguidor de linha.
#define PIN_MODO 10

bool modoLinha = false;

void setup(){
  configurarMotoresLinha();
  configurarSensoresLinha();

  //Fiz assim pra caso a gente use a chave pull up
  pinMode(PIN_MODO, INPUT_PULLUP);

  modoLinha = (digitalRead(PIN_MODO) == LOW);

  //Garante q vai começar parado antes de qualquer interação.
  moverMotores(0, 0);
}

void loop(){
  //dps o modoSeguidor() pode ser chamado num programa q inclua os dois modos em um só
  modoSeguidor();
}
