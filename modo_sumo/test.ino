/*OBS:ESSE ARQUIVO É SÓ UM ARQUIVO DE TESTE PARA TESTAR O MODO SUMO(NÃO É O ARQUIVO FINAL)
*/

void setup(){
 configurarMotores();
 configurarSensores_sumo(); 
 Serial.begin(9600);
 delay(5000);
}
void loop(){
  modoSumo();
}
