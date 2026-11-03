
const int LIMITE_LINHA = 266;
const bool TESTELIMITE = false;

void configurarSensores_seguidor(){
  pinMode(PIN_SENSORLINHA_MEIO, INPUT);
}

//Recebe a leitura de UM sensor e responde se ele está sobre a linha (true) ou fora dela (false)
bool sensorNaLinha(int leitura){
  bool naLinha;

    if (leitura <= LIMITE_LINHA){
      naLinha = true;
    } 
    else{
      naLinha = false;
    }
  return naLinha;
}

bool linhaEsq(){
  int leitura = analogRead(PIN_SENSORLINHA_ESQ);
  if (TESTELIMITE == true){
    //Teste p verificar o valor do LIMITE_BORDA, caso necessário.
    Serial.println(F("Esq: "));
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