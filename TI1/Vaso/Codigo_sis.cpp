// C++ code
#include <Servo.h>
int TimerT=0, TimerC=0, MedicoesT[3]={0}, MedicoesC[3]={0}, clock=1;//definição das variaveis
float mediaT=0,mediaC=0;
int pos=0;
Servo servo_9;


//
void setup()
{
  pinMode(6,OUTPUT);
  pinMode(A1,INPUT);
  pinMode(A2,INPUT);
  pinMode(13,OUTPUT);
  pinMode(12,INPUT);
  pinMode(4,OUTPUT);
  servo_9.attach(6, 500, 2500);
  Serial.begin(9600);
  servo_9.write(0);
}

void loop(){
  int readT=analogRead(A1), readC=analogRead(A2), but=digitalRead(12);
  
 
  if(but==HIGH && clock==1){//modulo para invertar a variavel que liga o sistema
  	clock=0;
    
    while(digitalRead(12)==HIGH){}//buffer para a entrada do botão
  }else if(but==HIGH && clock==0){
  	clock=1;
    while(digitalRead(12)==HIGH){}//buffer para a entrada do botão
  }
  
  if(clock==0){//variavel para funcionar de chave do sistema
  digitalWrite(4,HIGH);//led de aviso se o sistema liga
  //versão ligada
    if(TimerT==0){//filtro de media movel da terra
      MedicoesT[TimerT]=readT;
      TimerT++;
    }else if(TimerT==1){
      MedicoesT[TimerT]=readT;
      TimerT++;
    }else if(TimerT==2){
      MedicoesT[TimerT]=readT;
      TimerT++;
    }else if(TimerT==3){
  	  TimerT=0;
    }
             
    mediaT=(MedicoesT[0]+MedicoesT[1]+MedicoesT[2])/3;
    if(TimerC==0){//filtro de media movel do cantil
      MedicoesC[TimerC]=readC;
      TimerC++;
    }else if(TimerC==1){
      MedicoesC[TimerC]=readC;
      TimerC++;
    }else if(TimerC==2){
      MedicoesC[TimerC]=readC;
      TimerC++;
    }else if(TimerC==3){
      TimerC=0;            
    }
             
    mediaC=(MedicoesC[0]+MedicoesC[1]+MedicoesC[2])/3;
    
    if(mediaT<50 && (pos>90|| pos==0)){//modulo de aviso para quando o chao secar
      while(pos<=90){//modulo para liberar a agua usando o servo
      servo_9.write(pos);
      pos++;
  	}
      tone(13,1200,20);//alarme para avisar que esta molhando
  	}else if(mediaT>=50 && (pos<=0 || pos==91)){
      while(pos>0){//modulo para fechar a agua depois de molhar
    	servo_9.write(pos);
        pos--;
  	}
    }
  	if(mediaC<50){//modulo para quando a agua acabar
      tone(13,300,20);
  	}
    
    Serial.println(mediaT);
    Serial.println(mediaC);
    Serial.println(pos);
    Serial.println("LIGADO");
  }else{
    digitalWrite(4,LOW);//led de aviso de sistema ligado
    Serial.println(clock);
    Serial.println(pos);
    Serial.println("DESLIGADO");
    
    if(pos>0){
    for(pos;pos>0;pos--){
      servo_9.write(pos);
  	}
    }
    //versão de desligar
  }
}

