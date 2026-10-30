//ESSE ARQUIVO CONTÉM A LOCOMOÇÃO DO MODO SEGUIDOR DE LINHA.
//ESSA VERSÃO NÃO FUNCIONARÁ SE NÃO FOR INTEGRADA

#include "pinos.h"

//Consts de movimento

const int VEL_RETA = 140;
const int VEL_CURVA_EXTERNA = 140;
const int VEL_CURVA_INTERNA = 70;

void configurarMotoresLinha(){
  //Igual o void configurarMotores() do arquivo de locomoção do sumô
  pinMode(velmotorE, OUTPUT);
  pinMode(velmotorD, OUTPUT);
  pinMode(PIN_MOTOR_A1, OUTPUT);
  pinMode(PIN_MOTOR_B1, OUTPUT);
  pinMode(PIN_MOTOR_A2, OUTPUT);
  pinMode(PIN_MOTOR_B2, OUTPUT);
  pinMode(PIN_STBY, OUTPUT);
  digitalWrite(PIN_STBY, HIGH);
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
  
  digitalWrite(PIN_MOTOR_A1,HIGH);
  digitalWrite(PIN_MOTOR_B1,HIGH);
  digitalWrite(PIN_MOTOR_A2,HIGH);
  digitalWrite(PIN_MOTOR_B2,HIGH);
  }
