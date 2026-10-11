// C++ code
//
int pedestre = 0;

int butao = 0;

int tempo = 0;

int unnamed = 0;

int i = 0;

void setup()
{
  pinMode(2, INPUT);
  pinMode(6, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(3, OUTPUT);
}

void loop()
{
  tempo += 1;
  delay(1000); // Wait for 1000 millisecond(s)
  butao = digitalRead(2);
  if (butao == HIGH) {
    tempo = 99;
  }
  if (tempo == 1) {
    digitalWrite(6, LOW);
    digitalWrite(11, LOW);
    digitalWrite(12, HIGH);
    digitalWrite(8, HIGH);
  }
  if (tempo == 14) {
    digitalWrite(8, LOW);
    digitalWrite(9, HIGH);
  }
  if (tempo == 16) {
    digitalWrite(12, LOW);
    digitalWrite(11, HIGH);
    digitalWrite(9, LOW);
    digitalWrite(6, HIGH);
  }
  if (tempo == 24) {
    tempo = 0;
  }
  if (tempo == 99) {
    digitalWrite(8, LOW);
    digitalWrite(6, LOW);
    digitalWrite(9, HIGH);
    digitalWrite(12, HIGH);
  }
  if (tempo == 100) {
    digitalWrite(9, LOW);
    digitalWrite(12, LOW);
    digitalWrite(11, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(3, HIGH);
  }
  if (tempo == 108) {
    digitalWrite(6, LOW);
    digitalWrite(11, LOW);
    digitalWrite(3, LOW);
    tempo = 0;
  }
}
