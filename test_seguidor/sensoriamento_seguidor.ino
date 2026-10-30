//Nessa versão adicionei o terceiro sensor que ficará no meio

#define PIN_SENSORLINHA_ESQ A0
#define PIN_SENSORLINHA_DIR A1
#define PIN_SENSORLINHA_MEIO A2

const bool NALINHA = true;
const int LIMITE_BORDA = 266;

// TESTELIMITE está como true mas servirá somente para testarmos se o valor do LIMITE_BORDA está correto, no fim dos testes pode só alterar pra false

const bool TESTELIMITE = true;

void configurarSensoresLinha(){
  //Função para realizar teste dos sensores.
  if(TESTELIMITE == true){
    Serial.begin(9600);
  }
  pinMode(PIN_SENSORLINHA_ESQ, INPUT);
  pinMode(PIN_SENSORLINHA_DIR, INPUT);
  pinMode(PIN_SENSORLINHA_MEIO, INPUT);
}

//Recebe a leitura de UM sensor e responde se ele está sobre a linha (true) ou fora dela (false)
bool sensorNaLinha(int leitura){
  bool naLinha;

  if(NALINHA == true){
    if (leitura <= LIMITE_BORDA){
      naLinha = true;
    } else{
      naLinha = false;
    }
  }
  else{
    if(leitura > LIMITE_BORDA){
      naLinha = true;
    } else{
      naLinha = false;
    }
  }
  return naLinha;
}

bool linhaEsq(){
  int leitura = analogRead(PIN_SENSORLINHA_ESQ);
  if (TESTELIMITE == true){
    //Teste p verificar o valor do LIMITE_BORDA, caso necessário.
    Serial.print(F("Esq: "));
    Serial.println(leitura);
  }
  return sensorNaLinha(leitura);
}

bool linhaDir(){
  int leitura = analogRead(PIN_SENSORLINHA_DIR);
  if (TESTELIMITE == true){
    Serial.print(F("Dir: "));
    Serial.println(leitura);
  }
  return sensorNaLinha(leitura);
}

bool linhaMeio(){
  int leitura = analogRead(PIN_SENSORLINHA_MEIO);
  if (TESTELIMITE == true){
    Serial.print(F("Meio: "));
    Serial.println(leitura);
  }
  return sensorNaLinha(leitura);
}
