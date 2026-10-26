/*OBS:OS VALORES DE DELAY DA FUNÇÃO fugirBorda() SÃO DE TESTE E PODERAM SER MODIFICADOS*/

// sensores do adversário
#define PIN_SENSORADV_FRT 7
#define PIN_SENSORADV_ESQ 8
#define PIN_SENSORADV_DIR 9
//sensores de borda 
#define PIN_SENSORBORD_ESQ A0
#define PIN_SENSORBORD_DIR A1
#define RX0 0
#define TX0 1 
const int LIMITE_BORDA=266;//valor arbitrário,precisamos testar o modulo TCRT5000 para definir um limite
#define DETECTADO LOW

void configurarSensores_sumo() {
    pinMode(PIN_SENSORADV_FRT, INPUT);
    pinMode(PIN_SENSORADV_ESQ,INPUT);
    pinMode(PIN_SENSORADV_DIR,INPUT);
    pinMode(PIN_SENSORBORD_ESQ,INPUT);
    pinMode(PIN_SENSORBORD_DIR,INPUT);
    
}
bool bordaEsq(){
    int BORDA_ESQ=analogRead(PIN_SENSORBORD_ESQ);
     Serial.println(BORDA_ESQ);
    return (BORDA_ESQ<=LIMITE_BORDA);
}
bool bordaDir(){
    int BORDA_DIR=analogRead(PIN_SENSORBORD_DIR);
    Serial.println(BORDA_DIR);
    return(BORDA_DIR<=LIMITE_BORDA);
}

void fugirBorda(bool borda_esq,bool borda_dir){
      frear();
    delay(500);
    recuar();
    delay(500);
    if (borda_esq && borda_dir){
    girarDireita();
    delay(1000);
    frear();
    delay(30);
    }
    else if(borda_dir){
    girarEsquerda();
    delay(500);
    frear();
    delay(30);
    }
    else{
    girarDireita();
    delay(500);
    frear();
    delay(30);
    }
}
void sensorAdversario(){
    int FRT=digitalRead(PIN_SENSORADV_FRT);
    int ESQ=digitalRead(PIN_SENSORADV_ESQ);
    int DIR=digitalRead(PIN_SENSORADV_DIR);
    /* if(FRT==DETECTADO && ESQ==DETECTADO && DIR==DETECTADO){
        frenteTurbo();
    }
    else if(FRT==DETECTADO && ESQ==DETECTADO){
        curvaEsquerda();
        
    }
    else if (FRT==DETECTADO && DIR==DETECTADO){
        curvaDireita();
        
    }*/
    
      if (FRT==DETECTADO){
        
            frenteTurbo(); //para atacar o adversário

    }
    else if (ESQ==DETECTADO){
        
        girarEsquerda();//virar em direção ao adversário
        
    }
    else if (DIR==DETECTADO){
        
        girarDireita();
       
    }
 
    else{
        buscaAdversario();//ação para procurar adversário na arena 
    }
    delay(20);
    
    

}


  


  
  

