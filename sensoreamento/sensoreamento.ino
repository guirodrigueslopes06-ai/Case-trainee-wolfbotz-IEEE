// sensores do adversário
#define PIN_SENSORADV_FRT 2
#define PIN_SENSORADV_ESQ 4
#define PIN_SENSORADV_DIR 7
//sensores de borda 
#define PIN_SENSORBORD_ESQ A0
#define PIN_SENSORBORD_DIR A1
#define RX0 0
#define TX0 1 
const int limiteborda=600;//valor arbitrário,precisamos testar o modulo TCRT5000 para definir um limite
#define DETECTADO LOW

void setup() {
    pinMode(PIN_SENSORADV_FRT, INPUT);
    pinMode(PIN_SENSORADV_ESQ,INPUT);
    pinMode(PIN_SENSORADV_DIR,INPUT);
    pinMode(PIN_SENSORBORD_ESQ,INPUT);
    pinMode(PIN_SENSORBORD_DIR,INPUT);
    Serial.begin(9600);
}
void sensorAdversario(){
    int FRT=digitalRead(PIN_SENSORADV_FRT);
    int ESQ=digitalRead(PIN_SENSORADV_ESQ);
    int DIR=digitalRead(PIN_SENSORADV_DIR);
    if (FRT==LOW){
         Serial.println("Adversário detectado!");
        frenteTurbo(); //para atacar o adversário
      

    }
    else if (ESQ==DETECTADO){
        Serial.println("Adversário detectado!");
        virarEsquerda();//virar em direção ao adversário
    }
    else if (DIR==DETECTADO){
        Serial.println("Adversário detectado!");
        virarDireita();//virar em direção ao adversário 
    }
 
    else{
        buscaAdversario();//ação para procurar adversário na arena 
    }
}
bool sensorDeborda(){
    int BORDA_ESQ=analogRead(PIN_SENSORBORD_ESQ);
    int BORDA_DIR=analogRead(PIN_SENSORBORD_DIR);
    return (BORDA_ESQ>limiteborda || BORDA_DIR>limiteborda);
}
void fugirBorda(){

    frear();
    recuar();
    delay(100);
    virarDireita();




}
void loop() {
    if (sensorDeborda){
        fugirBorda();
    }
    else{
        sensorAdversario();

    }


    
}
//funções provisórias (apagar quando a locomoção estiver pronta) 
void frear()            { Serial.println("frear"); }
void recuar()           { Serial.println("recuar"); }
void virarDireita()     { Serial.println("virarDireita"); }
void virarEsquerda()    { Serial.println("virarEsquerda"); }
void frenteTurbo()      { Serial.println("frenteTurbo"); }
void buscaAdversario()  { Serial.println("buscaAdversario"); }

  
  


