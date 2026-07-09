// C++ code
//

/*
Projeto: Sistema de iluminação inteligente gamificado

Sensores:
A0 - LDR externo
A1 - LDR interno
A2 - potenciômetro

Saídas:
10,11,12 - LEDs
13 - buzzer
2 - botão
*/
int caso=0, cont=0, ligou=0, pont=0, luzes[3]={0}, tempo=0, somaf[3]={0},somad[3]={0};
float mediaf=0, mediad=0, percent=1, limiar=0;

void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(A1,INPUT);
  pinMode(2,INPUT);
  pinMode(A0,INPUT);
  pinMode(13,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);
  Serial.begin(9600);
}

float mediaMovel(int leitura, int vetor[], int *indice){//função de media movel
  vetor[*indice]=leitura;//recebe cada leitura e atualiza baseado no tempo

  *indice=*indice+1;//atualiza o tempo
  if(*indice>=3)//reseta o tempo caso chegue a 3
    *indice=0;

  return (vetor[0]+vetor[1]+vetor[2])/3.0;//retorna a media
}

int vitoria(int *ligou, int luzes[], int pont){//retorna a pontuação
    if(*ligou==1){//verifica se a luz foi acessa
        int led=pont%3;//determina o led a ser ligado

        if(luzes[led]==0){//liga o led caso tenha ganhado com o led apagado
            luzes[led]=1;
            digitalWrite(12-led,HIGH);
        }else{//desliga o led caso tenha ganhado com o led desligado
            luzes[led]=0;
            digitalWrite(12-led,LOW);
        }

        *ligou=2;
        return pont+1;//retorna a pontuação incrementada
    }else if(*ligou==0){//verifica se a luz não foi acessa
        for(int i=12;i>9;i--){//desliga todas as luzes
            digitalWrite(i,LOW);
            luzes[i-10]=0;
        }
		return 0;//reseta a pontuação
    }
  	
  	return pont;
}

void loop(){
  int rep=digitalRead(2), LuzFora=analogRead(A0),Luzdentro=analogRead(A1);
  float potencia=analogRead(A2);
  
  if(potencia/1023.0!=0){//calcula o limiar do sistema baseado no potenciometro
  percent=potencia/1023.0;
  }else{
  percent=1;
  }
  
  Serial.println(percent);
  
  limiar=202.0*percent;
  
  //realiza a soma da media movel de ate 3 medições e sobreescreve os valores anteriores
mediaf = mediaMovel(LuzFora, somaf, &tempo);
mediad = mediaMovel(Luzdentro, somad, &tempo);

  if(rep==HIGH && caso==0){//realiza a ligação do sistema
    caso=1;
    
    while(rep==HIGH){
	    rep=digitalRead(2);//buffer para impedir a troca rapida dos valores do sistema
    } 
  }else if(rep==HIGH && caso==1){
  	caso=0;
    
    while(rep==HIGH){
	    rep=digitalRead(2);
    }
  }
  
  if(caso==1){//sistema ligado do jogo
    if(mediaf>limiar && mediad>limiar){//realiza o sistema de alerta ate que a luz seja apagada
      cont=13;
      while(cont>0){
        tone(13, 1300,100);//avisa que do lado de fora esta claro
        
        LuzFora=analogRead(A0);
        Luzdentro=analogRead(A1);
        
        mediaf = mediaMovel(LuzFora, somaf, &tempo);//pega leituras da luz para não travar o loop
		mediad = mediaMovel(Luzdentro, somad, &tempo);
        
        if(mediad<=limiar){//observa se a luz apagou
        	ligou=1;//liga a condição vitoria
          	tone(13, 3300,1000);//som de vitoria por apagar
          	break;
        }
        cont--;
        delay(1000);//delay para que o codigo rode exatamente 10 segundos
        
        if(ligou==2){//alteração para impedir que sempre perca a pontuação ao seguir para a proxima rodada
    	ligou=0;
    	}
        
      }
    }
      pont = vitoria(&ligou, luzes, pont);//chama a condição de vitoria
}
  Serial.print("Fora: ");
	Serial.print(mediaf);
  	Serial.print(" Dentro: ");
  	Serial.print(mediad);
  	Serial.print(" Botao: ");
  	Serial.println(caso);
  	Serial.println(limiar);
  
}
