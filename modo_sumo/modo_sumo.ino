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

