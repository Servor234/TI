if(Timer==0){
   Medicoes[Timer]=read;
  	Timer++;
 }else if(Timer==1){
    Medicoes[Timer]=read;
  	Timer++;
 }else if(Timer==2){
  	Medicoes[Timer]=read;
  	Timer++;
 }else if(Timer==3){
 	Timer=0;            
 }
             
  media=(Medicoes[0]+Medicoes[1]+Medicoes[2])/3;
