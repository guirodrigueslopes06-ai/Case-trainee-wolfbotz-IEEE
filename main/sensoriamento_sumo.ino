/*OBS:OS VALORES DE DELAY DA FUNÇÃO fugirBorda() SÃO DE TESTE E PODERAM SER MODIFICADOS*/

const int LIMITE_BORDA=266;

//tempos para o robo frear,recuar e girar  na função fugirBorda();
const int temp_freio=100;
const int temp_recuo=300;
const int temp_giro90=400;
const int temp_giro180=800;

void configurarSensores_sumo() {//é como a setup desse arquivo(essas função vai ser chamada no setup do arquivo principal,para configurar os pinos dos sensores)
    pinMode(PIN_SENSORADV_FRT, INPUT);
    pinMode(PIN_SENSORADV_ESQ,INPUT);
    pinMode(PIN_SENSORADV_DIR,INPUT);
    pinMode(PIN_SENSORBORD_ESQ,INPUT);
    pinMode(PIN_SENSORBORD_DIR,INPUT);
    
}
bool bordaEsq(){//função que faz o sensoriameto do sensor de borda esquerdo e retorna true(borda localizada),false(borda não localizada)
    int BORDA_ESQ=analogRead(PIN_SENSORBORD_ESQ);
    return (BORDA_ESQ<=LIMITE_BORDA);
}
bool bordaDir(){//função que faz o sensoriameto do sensor de borda direito e retorna true(borda localizada),false(borda não localizada)
    int BORDA_DIR=analogRead(PIN_SENSORBORD_DIR);
    return(BORDA_DIR<=LIMITE_BORDA);
}

void fugirBorda(bool borda_esq,bool borda_dir){//essa função recebe os valores de bordaDir() e bordaEsq() e executa os movimentos para fugir da borda.
      frear();
    delay(temp_freio);
    recuar();
    delay(temp_recuo);
    if (borda_esq && borda_dir){
    girarDireita();
    delay(temp_giro180);
    frear();
    delay(30);
    }
    else if(borda_dir){
    girarEsquerda();
    delay(temp_giro90);
    frear();
    delay(30);
    }
    else{//isso só acontece quando só a borda esquerda detecta algo.
    girarDireita();
    delay(temp_giro90);
    frear();
    delay(30);
    }
}
void sensorAdversario(){//função para detetar o adversário e executar uma determinada ação 
    int FRT=digitalRead(PIN_SENSORADV_FRT);
    int ESQ=digitalRead(PIN_SENSORADV_ESQ);
    int DIR=digitalRead(PIN_SENSORADV_DIR);
  
    
      if (FRT==DETECTADO){
            frenteTurbo(); //para atacar o adversário

    }
    else if (ESQ==DETECTADO){
        
        girarEsquerda();// se o adversario estiver na esquerda:virar em direção ao adversário
        
    }
    else if (DIR==DETECTADO){
        
        girarDireita();//se o adversario estiver na direita:virar em direção ao adversário
       
    }
 
    else{
        buscaAdversario();//ação para procurar adversário na arena,caso não encontre-o 
    }
    delay(20);
    
    

}


  


  
  

