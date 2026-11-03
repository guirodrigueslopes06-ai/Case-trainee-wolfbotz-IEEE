const int LADO_NENHUM = 0;   // ainda não viu a linha em nenhum dos lados
const int LADO_ESQ = 1;      // a linha foi vista pela última vez do lado esquerdo
const int LADO_DIR = 2;      // a linha foi vista pela última vez do lado direito

int ultimoLado = LADO_NENHUM;

const int PASSO_MS = 10;           // cada passo dura 10 ms
const int PASSOS_VARREDURA = 40;   // 40 passos x 10 ms = 400 ms girando para um lado
const int PASSOS_RE = 30;          // 30 passos x 10 ms = 300 ms de ré
const int TENTATIVAS = 3;          // quantas vezes repete antes de desistir



void modoSeguidor(){
  bool esqNaLinha = linhaEsq();
  bool dirNaLinha = linhaDir();
  bool meioNaLinha = linhaMeio();

  if(esqNaLinha == true && dirNaLinha == true){
    frear();
  }
  else if(esqNaLinha == true && dirNaLinha == false){
    ultimoLado = LADO_ESQ;
    curvaEsq();
  }
  else if(esqNaLinha == false && dirNaLinha == true){
    ultimoLado = LADO_DIR;
    curvaDir();
  }
  else if(meioNaLinha == true && esqNaLinha == false && dirNaLinha == false){
    frente();
  }
  else{
    procurarLinha();
  }
}
bool girarProcurandoMeio(int lado, int passos){
  for(int i = 0; i < passos; i++){

    if(linhaMeio() == true){
      frear();         
      return true;
    }

    if(lado == LADO_ESQ){
      girarEsqLinha();
    }
    else{
      girarDirLinha();
    }
    delay(PASSO_MS);
  }

  return false;
}

bool recuarProcurandoMeio(int passos){
  for(int i = 0; i < passos; i++){

    if(linhaMeio() == true){
      frear();
      return true;
    }

    recuarLinha();
    delay(PASSO_MS);
  }

  return false;
}

void procurarLinha(){

  int lado;
  int outroLado;

  if(ultimoLado == LADO_ESQ){
    lado = LADO_ESQ;
    outroLado = LADO_DIR;
  }
  else if(ultimoLado == LADO_DIR){
    lado = LADO_DIR;
    outroLado = LADO_ESQ;
  }
  else{
    // Sem memória ainda ent começa pela direita. É só uma escolha, porque a busca passa pelos dois lados.
    lado = LADO_DIR;
    outroLado = LADO_ESQ;
  }

  for(int tentativa = 0; tentativa < TENTATIVAS; tentativa++){
    if(girarProcurandoMeio(lado, PASSOS_VARREDURA) == true){
      return;
    }
    //Gira * 2 para compensar o que ele ja girou pro outro lado.
    if(girarProcurandoMeio(outroLado, PASSOS_VARREDURA * 2) == true){
      return;
    }
    if(girarProcurandoMeio(lado, PASSOS_VARREDURA) == true){
      return;
    }
    if(recuarProcurandoMeio(PASSOS_RE) == true){
      return;
    }
  }

  // Passou por todas as tentativas e não achou a linha ent desiste, enquanto o sensor do meio não ver a linha
  frear();
  while(linhaMeio() == false){
  }
}