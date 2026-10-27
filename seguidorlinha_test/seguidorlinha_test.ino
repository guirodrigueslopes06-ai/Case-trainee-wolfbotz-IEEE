//Alguns valores ainda podem acabar alterando, fiz o código de forma que seja mais simples se precisarmos alterar esses valores
// Tentei usar os mesmos nomes que ja estão nos outros arquivos (Ex: LIMITE_BORDA) se tiver algm coisa q notar nome diferente pode falar q faço alteração

#define PIN_SENSORBORD_ESQ A0
#define PIN_SENSORBORD_DIR A1

// Pinagem sujeita a alteração, fiz p evitar conflito usando como referência a última versão do código do sumô disponível no GitHub

#define velmotorE 3
#define velmotorD 5
#define PIN_MOTOR_A1 2
#define PIN_MOTOR_B1 12
#define PIN_MOTOR_A2 4
#define PIN_MOTOR_B2 13
#define PIN_STBY 6

#define PIN_MODO 10

// Aqui fiz algumas constantes para ficar mais fácil de alterar os valores nas funções caso necessário após os testes, sem ter q mudar uma por uma
// Alguns dos valores estarão menores do que no arquivo de locomoção só pra tentar fazer aquele movimento mais "suave" no modo seguidor

const bool NALINHA = true;
const int LIMITE_BORDA = 266;
const int VEL_RETA = 140;
const int VEL_CURVA_EXTERNA = 140;
const int VEL_CURVA_INTERNA = 70;

// TESTELIMITE está como true mas servirá somente para testarmos se o valor do LIMITE_BORDA está correto, no fim dos testes pode só alterar pra false

const bool TESTELIMITE = true;

bool modoLinha = false;

void setup(){
  if(TESTELIMITE == true){
    Serial.begin(9600);
  }
  //Igual o void configurarmotores() do arquivo de locomoção, coloquei dentro do setup
  pinMode(velmotorE, OUTPUT);
  pinMode(velmotorD, OUTPUT);
  pinMode(PIN_MOTOR_A1, OUTPUT);
  pinMode(PIN_MOTOR_B1, OUTPUT);
  pinMode(PIN_MOTOR_A2, OUTPUT);
  pinMode(PIN_MOTOR_B2, OUTPUT);
  pinMode(PIN_STBY, OUTPUT);
  digitalWrite(PIN_STBY, HIGH);

  //Fiz assim pra caso a gente use a chave pull up
  pinMode(PIN_MODO, INPUT_PULLUP);

  modoLinha = (digitalRead(PIN_MODO) == LOW);

  //Garante q vai começar parado antes de qualquer interação.
  moverMotores(0, 0);

}

// Funções de movimento

void moverMotores(int velEsq, int velDir){

  velEsq = constrain(velEsq, -255, 255);
  velDir = constrain(velDir, -255, 255);

  if (velEsq > 0){
    //frente
    digitalWrite(PIN_MOTOR_A1, HIGH);
    digitalWrite(PIN_MOTOR_A2, LOW);
  }
  else if (velEsq < 0) {
    //ré
    digitalWrite(PIN_MOTOR_A1, LOW);
    digitalWrite(PIN_MOTOR_A2, HIGH);
  }
  else {
    //parado
    digitalWrite(PIN_MOTOR_A1, LOW);
    digitalWrite(PIN_MOTOR_A2, LOW);
  }
  analogWrite(velmotorE, abs(velEsq));

  if (velDir > 0) {
    //frente
    digitalWrite(PIN_MOTOR_B1, HIGH);
    digitalWrite(PIN_MOTOR_B2, LOW);
  }
  else if (velDir < 0) {
    //ré
    digitalWrite(PIN_MOTOR_B1, LOW);
    digitalWrite(PIN_MOTOR_B2, HIGH);
  }
  else {
    //parado
    digitalWrite(PIN_MOTOR_B1, LOW);
    digitalWrite(PIN_MOTOR_B2, LOW);
  }
  analogWrite(velmotorD, abs(velDir));
}

void frente(){
  moverMotores(VEL_RETA, VEL_RETA);
}

void curvaEsq(){
   moverMotores(VEL_CURVA_INTERNA, VEL_CURVA_EXTERNA);
}

void curvaDir(){
  moverMotores(VEL_CURVA_EXTERNA, VEL_CURVA_INTERNA);
}

void frear(){
  //todos os pinos em HIGH os dois motores param
  digitalWrite(PIN_MOTOR_A1,HIGH);
  digitalWrite(PIN_MOTOR_B1,HIGH);
  digitalWrite(PIN_MOTOR_A2,HIGH);
  digitalWrite(PIN_MOTOR_B2,HIGH);
  }

void loop(){
  //dps podemos chamar de void loopLinha num programa q inclua os dois modos em um só
  //leitura dos sensores
  int leituraEsq = analogRead(PIN_SENSORBORD_ESQ);
  int leituraDir = analogRead(PIN_SENSORBORD_DIR);

  if (TESTELIMITE == true){
    //Teste p verificar o valor LIMITE_LINHA, caso necessário.
    Serial.print(F("Esq: "));
    Serial.print(leituraEsq);
    Serial.print(F("/ Dir: "));
    Serial.println(leituraDir);
  }

  bool esqNaLinha;
  bool dirNaLinha;
  
  if(NALINHA == true){
    if (leituraEsq <= LIMITE_BORDA){
      esqNaLinha = true;
    } else{
      esqNaLinha = false;
    }

    if (leituraDir <= LIMITE_BORDA){
      dirNaLinha = true;
    } else{
      dirNaLinha = false;
    }
  }
  else{

    if(leituraEsq > LIMITE_BORDA){
      esqNaLinha = true;
    } else{
      esqNaLinha = false;
    }

    if(leituraDir > LIMITE_BORDA){
      dirNaLinha = true;
    } else{
      dirNaLinha = false;
    }
  }

  if(esqNaLinha == false && dirNaLinha == false){
    frente();
  }
  else if(esqNaLinha == true && dirNaLinha == false){
    curvaEsq();
  }
  else if(esqNaLinha == false && dirNaLinha == true){
    curvaDir();
  }
  else{
    frear();
  }
}