
int threshold = 400;

void setup()
{
  Serial.begin(9600);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);  
  pinMode(5, INPUT);
  pinMode(6, INPUT);
  pinMode(7, INPUT);
}

void loop()
{ 
  int a = analogRead(A0);
  int b = analogRead(A1);
  int c = analogRead(A2);
  int d = analogRead(A3);
  int e = analogRead(A4);
  
  Serial.println("Readings");
  Serial.println(a);
  Serial.println(b);
  Serial.println(c);
  Serial.println(d);
  Serial.println(e);
  //delay(2000);
  
  int aa = 0;
  if (a >threshold) aa = 1;
  
  int bb = 0;
  if (b >threshold) bb = 1;
  
  int cc = 0;
  if (c >threshold) cc = 1;
  
  int dd = 0;
  if (d >threshold) dd = 1;
  
  int ee = 0;
  if (e >threshold) ee = 1;  
  /*
  digitalWrite(8, digitalRead(3));
  digitalWrite(9, digitalRead(4));  
  digitalWrite(10, digitalRead(5));
  digitalWrite(11, digitalRead(6));
  digitalWrite(12, digitalRead(7));
  */
  
  digitalWrite(8, aa);
  digitalWrite(9, bb);
  digitalWrite(10, cc);
  digitalWrite(11, dd);
  digitalWrite(12, ee);
}
