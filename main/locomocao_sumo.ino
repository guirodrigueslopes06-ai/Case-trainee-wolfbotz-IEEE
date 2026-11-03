/*OBS:ADOTEI COMO MOTOR ESQUERDO O A E O MOTOR DIREITO O B. 
SENTIDO HORARIO A1 E B1 E ANTI-HORARIO A2 E B2*/

//variaveis da velocidade
 const int velmed=128;
const int velmax=200;
const int velmin=90; 
void configurarMotores(){//é como a setup desse arquivo(essa função é chamada no arquivo principal,para configurar os pinos que executam o controle do motor)
  pinMode(velmotorE,OUTPUT);
  pinMode(velmotorD,OUTPUT);
  pinMode(PIN_MOTOR_A1,OUTPUT);
  pinMode(PIN_MOTOR_B1,OUTPUT);
  pinMode(PIN_MOTOR_A2,OUTPUT);
  pinMode(PIN_MOTOR_B2,OUTPUT);
  pinMode(PIN_STBY,OUTPUT);
  //manter o pino standby do driver desabilitado(habilita-lo para o robo dar partida)
  digitalWrite(PIN_STBY,LOW);
  //incializando os motores desligados 
  digitalWrite(PIN_MOTOR_A1,LOW);
  digitalWrite(PIN_MOTOR_B1,LOW);
  digitalWrite(PIN_MOTOR_A2,LOW);
  digitalWrite(PIN_MOTOR_B2,LOW);
  

}
void frear(){
  //todos os pinos em HIGH os dois motores param
  digitalWrite(PIN_MOTOR_A1,HIGH);
  digitalWrite(PIN_MOTOR_B1,HIGH);
  digitalWrite(PIN_MOTOR_A2,HIGH);
  digitalWrite(PIN_MOTOR_B2,HIGH);
  //manter os pinos pwm em HIGH para habilitar os canais dos motores
  analogWrite(velmotorE,255);
  analogWrite(velmotorD,255);
}
void recuar(){//função para o robô recuar
//controle do sentido de recuar()
digitalWrite(PIN_MOTOR_A1,LOW);
digitalWrite(PIN_MOTOR_B1,LOW);
digitalWrite(PIN_MOTOR_A2,HIGH);
digitalWrite(PIN_MOTOR_B2,HIGH);
//controle da velocidade de recuar()
analogWrite(velmotorE,velmed);
analogWrite(velmotorD,velmed);
}

void girarDireita(){
  //controle do sentido de girarDireita()
digitalWrite(PIN_MOTOR_A1,HIGH);
digitalWrite(PIN_MOTOR_B1,LOW);
digitalWrite(PIN_MOTOR_A2,LOW);
digitalWrite(PIN_MOTOR_B2,HIGH);

//controle da velocidade de girarDireita()
analogWrite(velmotorE,velmed);
analogWrite(velmotorD,velmed);
}
void girarEsquerda(){
    //controle do sentido de girarEsquerda()
digitalWrite(PIN_MOTOR_A1,LOW);
digitalWrite(PIN_MOTOR_B1,HIGH);
digitalWrite(PIN_MOTOR_A2,HIGH);
digitalWrite(PIN_MOTOR_B2,LOW);
//controle da velocidade de  girarEsqueda()
analogWrite(velmotorE,velmed);
analogWrite(velmotorD,velmed);

}
void frenteTurbo(){
   //controle do sentido de frenteTurbo()
digitalWrite(PIN_MOTOR_A1,HIGH);
digitalWrite(PIN_MOTOR_B1,HIGH);
digitalWrite(PIN_MOTOR_A2,LOW);
digitalWrite(PIN_MOTOR_B2,LOW);
//controle da velocidade de frenteTurbo()
analogWrite(velmotorE,velmax);
analogWrite(velmotorD,velmax);
}


void buscaAdversario(){
//controle do sentido de buscaAdversario()
digitalWrite(PIN_MOTOR_B1,LOW);
digitalWrite(PIN_MOTOR_B2,HIGH); 
digitalWrite(PIN_MOTOR_A1,HIGH);
digitalWrite(PIN_MOTOR_A2,LOW);
//controlando a velocidade de buscaAdversario()
analogWrite(velmotorE,velmin);
analogWrite(velmotorD,velmin);
}


  

  



