#include "pinos.h"
bool modo;


void setup(){
  configurarMotores();
  configurarSensores_sumo();
  configurarSensores_seguidor();
  Serial.begin(9600);
  Serial.println("Robô aguardando partida.....");
  delay(5000);
  digitalWrite(PIN_STBY,HIGH);
  Serial.println("Sistema iniciado");
  pinMode(PIN_MODO,INPUT_PULLUP);
  modo=digitalRead(PIN_MODO);

}
void loop(){
  if(modo){
    modoSumo();
  }
  else{
    modoSeguidor();
  }





}