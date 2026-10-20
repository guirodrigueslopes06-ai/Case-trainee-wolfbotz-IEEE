// pinos de controle de velocidade
#define velmotorE 3
#define velmotorD 5
//pinos do sentido de rotação do motor 
#define PIN_MOTOR_A1 2
#define PIN_MOTOR_B1 12
#define PIN_MOTOR_A2 4
#define PIN_MOTOR_B2 13
//variaveis da velocidade
 int velmed=128;
int velmax=255;
int velmin=90; 
//pino standby do tb6612fng
#define PIN_STBY 6
void configurarmotores(){
  pinMode(velmotorE,OUTPUT);
  pinMode(velmotorD,OUTPUT);
  pinMode(PIN_MOTOR_A1,OUTPUT);
  pinMode(PIN_MOTOR_B1,OUTPUT);
  pinMode(PIN_MOTOR_A2,OUTPUT);
  pinMode(PIN_MOTOR_B2,OUTPUT);
  pinMode(PIN_STBY,OUTPUT);
  digitalWrite(PIN_STBY,HIGH);

}
void frear(){
  //todos os pinos em HIGH os dois motores param
  digitalWrite(PIN_MOTOR_A1,HIGH);
  digitalWrite(PIN_MOTOR_B1,HIGH);
  digitalWrite(PIN_MOTOR_A2,HIGH);
  digitalWrite(PIN_MOTOR_B2,HIGH);
}
void recuar(){
//controle do sentido
digitalWrite(PIN_MOTOR_A1,LOW);
digitalWrite(PIN_MOTOR_B1,LOW);
digitalWrite(PIN_MOTOR_A2,HIGH);
digitalWrite(PIN_MOTOR_B2,HIGH);
//controle da velocidade
analogWrite(velmotorE,velmed);
analogWrite(velmotorD,velmed);
}

void girarDireita(){
  //controle do sentido
digitalWrite(PIN_MOTOR_A1,HIGH);
digitalWrite(PIN_MOTOR_B1,LOW);
digitalWrite(PIN_MOTOR_A2,LOW);
digitalWrite(PIN_MOTOR_B2,HIGH);

//controle da velocidade
analogWrite(velmotorE,velmed);
analogWrite(velmotorD,velmed);
}
void girarEsquerda(){
    //controle do sentido
digitalWrite(PIN_MOTOR_A1,LOW);
digitalWrite(PIN_MOTOR_B1,HIGH);
digitalWrite(PIN_MOTOR_A2,HIGH);
digitalWrite(PIN_MOTOR_B2,LOW);
//controle da velocidade
analogWrite(velmotorE,velmed);
analogWrite(velmotorD,velmed);

}
void frenteTurbo(){
   //controle do sentido
digitalWrite(PIN_MOTOR_A1,HIGH);
digitalWrite(PIN_MOTOR_B1,HIGH);
digitalWrite(PIN_MOTOR_A2,LOW);
digitalWrite(PIN_MOTOR_B2,LOW);
//controle da velocidade
analogWrite(velmotorE,velmax);
analogWrite(velmotorD,velmax);
}

void buscaAdversario(){
//acionando o motor B para um dos sentidos
digitalWrite(PIN_MOTOR_B1,LOW);
digitalWrite(PIN_MOTOR_B2,HIGH);
//acionando o motor A  para o outro  sentido 
digitalWrite(PIN_MOTOR_A1,HIGH);
digitalWrite(PIN_MOTOR_A2,LOW);
//controlando a velocidade do giro
analogWrite(velmotorE,velmin);
analogWrite(velmotorD,velmin);
}
void curvaEsquerda(){
    //controle do sentido
digitalWrite(PIN_MOTOR_A1,HIGH);
digitalWrite(PIN_MOTOR_B1,HIGH);
digitalWrite(PIN_MOTOR_A2,LOW);
digitalWrite(PIN_MOTOR_B2,LOW);
  //controle da velocidade
analogWrite(velmotorE,velmed);
analogWrite(velmotorD,velmax);

}
void curvaDireita(){
     //controle do sentido
digitalWrite(PIN_MOTOR_A1,HIGH);
digitalWrite(PIN_MOTOR_B1,HIGH);
digitalWrite(PIN_MOTOR_A2,LOW);
digitalWrite(PIN_MOTOR_B2,LOW);
 //controle da velocidade
analogWrite(velmotorE,velmax);
analogWrite(velmotorD,velmed);
}


void loop(){

  
 

  }
  



