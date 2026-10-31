void modoSeguidor(){
  
  bool esqNaLinha = linhaEsq();
  bool dirNaLinha = linhaDir();
  bool meioNaLinha = linhaMeio();

  // A ORDEM dos if é importante para o funcionamento apropriado.

  if(esqNaLinha == true && dirNaLinha == true){
    // Se os dois sensores laterais detectarem a linha, indica que está numa faixa e então ele para.
    frear();
  }
  else if(esqNaLinha == true && dirNaLinha == false){
    curvaEsq();
  }
  else if(esqNaLinha == false && dirNaLinha == true){
    curvaDir();
  }
  else if(meioNaLinha == true && esqNaLinha == false && dirNaLinha == false){
    // Só o do meio na linha: robô alinhado
    frente();
  }
  else{
    // Nenhum sensor na linha, presume-se que o robô perdeu a linha.
    while(meioNaLinha == false){
      recuarLinha();
      meioNaLinha = linhaMeio();
    }  
  }
}
