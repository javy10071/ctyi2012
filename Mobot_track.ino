int motor1 = 5;
int motor_1 = 6;
int motor2 = 9;
int motor_2 = 10;
int ProxSens_1 = 13;
int ProxSens_2 = 7;
int ProxSens_3 = 4;
int ProxSens_4 = 3;
int ProxSens_5 = 2;
int a = 0;
int b = 0;
int c = 0;
int d = 0;
int e = 0;

void setup()
{
  Serial.begin(9600); 
  pinMode (motor1, OUTPUT);
  pinMode(motor_1, OUTPUT);
  pinMode (motor2, OUTPUT);
  pinMode(motor_2, OUTPUT);
  pinMode(ProxSens_1, INPUT); 
  pinMode(ProxSens_2, INPUT); 
  pinMode(ProxSens_3, INPUT);
  pinMode(ProxSens_4, INPUT); 
  pinMode(ProxSens_5, INPUT);   
}
void forward()
{
   analogWrite(motor2, 150);
   analogWrite(motor_2, 0);
   analogWrite(motor1, 150);
   analogWrite(motor_1, 0);
}

void stop(void)
{
   analogWrite(motor1, 0);
   analogWrite(motor_1, 0);
   analogWrite(motor2, 0);
   analogWrite(motor_2, 0);
   delay(1000);
}
void turn_Right()
{
  analogWrite(motor1, 255);
  analogWrite(motor_1, 0);
  delay(100);

}
void turn_Left()
{
  analogWrite(motor2, 255);
  analogWrite(motor_2, 0);
  delay(100);
}

void sharp_Right()
{
  analogWrite(motor1, 100);
  analogWrite(motor_1, 0);
  analogWrite(motor2, 0);
  analogWrite(motor_2, 100);
  delay(200);  
}

void sharp_Left()
{
  analogWrite(motor2, 100);
  analogWrite(motor_2, 0);
  analogWrite(motor1, 0);
  analogWrite(motor_1, 100);
  delay(200);
}


void loop()
{
  a = digitalRead(ProxSens_5);
  b = digitalRead(ProxSens_4);
  c = digitalRead(ProxSens_3);
  d = digitalRead(ProxSens_2);
  e = digitalRead(ProxSens_1);
  
  Serial.println("Readings");
  Serial.println(a);
  Serial.println(b);
  Serial.println(c);
  Serial.println(d);
  Serial.println(e);
  
  delay(1000);
  
  if(a == 1 && b == 1 && c == 0 && d == 1 && e == 1)
  {
    
    forward();
   /* digitalWrite(led_1, HIGH);
    digitalWrite(led_2, LOW);
    digitalWrite(led_3, HIGH);*/
  }
  
  if(a == 1 && b == 1 && c == 1 && d == 0 && e == 1)
  {
    turn_Left();
   /* digitalWrite(led_1, LOW);
    digitalWrite(led_2, HIGH);
    digitalWrite(led_3, HIGH);*/
  }
  
  if(a == 1 && b == 0 && c == 1 && d == 1 && e == 1)
  {
    turn_Right();
   /* digitalWrite(led_1, HIGH);
    digitalWrite(led_2, HIGH);
    digitalWrite(led_3, LOW);*/
  }
  
  if(a == 1 && b == 1 && c == 0 && d == 0 && e == 1)
  {
    turn_Left();
  }
  
  if(a == 1 && b == 0 && c == 0 && d == 1 && e == 1)
  {
    turn_Right();
  }
  
 if(a == 1 && b == 1 && c == 1 && d == 1 && e == 0)
  {
    sharp_Left();
  }
  
  if(a == 0 && b == 1 && c == 1 && d == 1 && e == 1)
  {
    sharp_Right();
   /*digitalWrite(led_1, HIGH);
    digitalWrite(led_2, LOW);
    digitalWrite(led_3, LOW);*/
  }
  
 if(a == 1 && b == 1 && c == 1 && d == 0 && e == 0)
  {
    sharp_Left();
  }
  
 if(a == 0 && b == 0 && c == 1 && d == 1 && e == 1)
  {
    sharp_Right();
  }
  
 if(a == 1 && b == 1 && c == 0 && d == 0 && e == 0)
  {
    sharp_Left();
  }
  
 if(a == 0 && b == 0 && c == 0 && d == 1 && e == 1)
  {
    sharp_Right();
  }
  
  
  //If there is a junction
  if(a == 0 && b == 0 && c == 0 && d == 0 && e == 0)
  {
    stop();
  }
   if(a == 1 && b == 1 && c == 1 && d == 1 && e == 1)
  {
    forward();
    /*digitalWrite(led_1, HIGH);
    digitalWrite(led_2, HIGH);
    digitalWrite(led_3, HIGH);*/
  }
}
