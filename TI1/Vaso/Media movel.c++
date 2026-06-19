if(Timer==0){
   MedicoesT[Timer]=read;
  	Timer++;
 }else if(Timer==1){
    MedicoesT[Timer]=read;
  	Timer++;
 }else if(Timer==2){
  	MedicoesT[Timer]=read;
  	Timer++;
 }else if(Timer==3){
 	Timer=0;            
 }
             
  mediaT=(MedicoesT[0]+MedicoesT[1]+MedicoesT[2])/3;
  
  if(Timer==0){
   MedicoesC[Timer]=read;
  	Timer++;
 }else if(Timer==1){
    MedicoesC[Timer]=read;
  	Timer++;
 }else if(Timer==2){
  	MedicoesC[Timer]=read;
  	Timer++;
 }else if(Timer==3){
 	Timer=0;            
 }
             
  mediaC=(MedicoesC[0]+MedicoesC[1]+MedicoesC[2])/3;
  
