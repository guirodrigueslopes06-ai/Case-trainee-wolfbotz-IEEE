/*OBS:ESSE ARQUIVO É SÓ UM ARQUIVO DE TESTE PARA TESTAR O MODO SUMO(NÃO É O ARQUIVO FINAL)
*/
#include "pinos.h"
void setup(){
 configurarMotores();
 configurarSensores_sumo(); 
 Serial.begin(9600);
 Serial.println("Robô aguardando partida.....");
 delay(5000);
 digitalWrite(PIN_STBY,HIGH);
 Serial.println("Sistema ininciado");

}
void loop(){
  modoSumo();
}
