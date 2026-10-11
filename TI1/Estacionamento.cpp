// C++ code
//

long dura;
int dist;



void setup()
{
  pinMode(12, INPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(5, INPUT);
  pinMode(4, OUTPUT);
  digitalWrite(10, LOW);
  digitalWrite(9,LOW);
  digitalWrite(11,LOW);
  Serial.begin(9600);
}

void loop()
{
  bool Sen=digitalRead(7);
	
  
    digitalWrite(4,LOW);
    delay(5);
 	digitalWrite(4, HIGH);
 	delay(10);
 	digitalWrite(4,LOW);
    
  
 	dura=pulseIn(5, HIGH);
 
 	dist=0.0343 * dura/2;
  
    Serial.print("distancia: ");
 	Serial.println(dist);
  
    
  if(dist>100){
    digitalWrite(9,LOW);
    digitalWrite(10,LOW);
    digitalWrite(11,LOW);
    digitalWrite(6,LOW);
  } else if(dist<=100 && dist>70){
    digitalWrite(9, HIGH);
    digitalWrite(10, LOW);
    digitalWrite(6, LOW);
    digitalWrite(11, LOW);
  } else if (dist<=70 && dist>30){
   	digitalWrite(10, HIGH);
    digitalWrite(6, LOW);
    digitalWrite(11, LOW);
    digitalWrite(9, LOW);
    tone(6,400,300);
  } else if (dist<30){
   	digitalWrite(9, LOW);
    digitalWrite(11,HIGH); 
    tone(6,3000,300);
  } 
}
