void modoSeguidor(){
  
  bool esqNaLinha = linhaEsq();
  bool dirNaLinha = linhaDir();
  bool meioNaLinha = linhaMeio();

  // A ORDEM dos ifs é importante para o funcionamento apropriado.

  if(esqNaLinha == true && dirNaLinha == true){
    // Se os dois sensores laterais detectarem a linha, indica que está numa faixa
    frear();
  }
  else if(esqNaLinha == true && dirNaLinha == false){
    curvaEsq();
  }
  else if(esqNaLinha == false && dirNaLinha == true){
    curvaDir();
  }
  else if(meioNaLinha == true && esqNaLinha == false && dirNaLinha == false){
    frente();
  }
  else{
    // Nenhum sensor na linha, presume-se que o robô perdeu a linha.
    frear();
  }
}
