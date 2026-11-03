//função modoSumo.Executa a lógica do robô de sumo,dando preferência a verificação de borda sempre.

void modoSumo(){
  bool esq= bordaEsq();
  bool dir=bordaDir();
if (esq||dir){
  fugirBorda(esq,dir);
}
else{
  sensorAdversario();
}
}

