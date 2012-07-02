#include <Servo.h>

Servo myServo;

int motor1 = 5;
int motor_1 = 6;
int motor2 = 9;
int motor_2 = 10;
int pin = 0;
int distance = 0;
int i = 0;
int j = 0;

void setup()
{
  Serial.begin(9600); 
  pinMode (motor1, OUTPUT);
  pinMode(motor_1, OUTPUT);
  pinMode (motor2, OUTPUT);
  pinMode(motor_2, OUTPUT);
  myServo.attach(11);
 
}
void forward()
{
   analogWrite(motor1, 240);
   analogWrite(motor_1, 0);
   analogWrite(motor2, 255);
   analogWrite(motor_2, 0);
}
void reverse()
{
  analogWrite(motor1, 0);
  analogWrite(motor_1, 255);
  analogWrite(motor2, 0);
  analogWrite(motor_2, 255);
  delay(300);
}
void stop(void)
{
   analogWrite(motor1, 0);
   analogWrite(motor_1, 0);
   analogWrite(motor2, 0);
   analogWrite(motor_2, 0);
   delay(1000);
}
void turn_Left()
{
  analogWrite(motor2, 255);
  analogWrite(motor_2, 0);
  delay(500);
}
void turn_Right()
{
  analogWrite(motor1, 255);
  analogWrite(motor_1, 0);
  delay(500);
}
//Reverse to the left
void reverse_L()
{
  analogWrite(motor2, 0);
  analogWrite(motor_2, 255);
  delay(500);
}
//Reverse to the right
void reverse_R()
{
  analogWrite(motor1, 0);
  analogWrite(motor_1, 255);
  delay(500);
}

void loop()
{
    float distance = analogRead(pin);
  Serial.print("\nDistance for far away objects: ");
  Serial.print(distance);
    forward();
   
 if(distance>400)
  {    
    //robot measures 2 different points on the left and on the right. This way if 
    //the sensor is out of range for one point it will be ok for the other.
    
    stop();
    myServo.write(165);
    Serial.print("\nServo engage");
    delay(1000);
    int left_a = analogRead(pin);
    myServo.write(120);
    delay(1000);
    int left_b = analogRead(pin);
    
    myServo.write(0);
    Serial.print("\nServo engage");
    delay(1000);
    int right_a = analogRead(pin);
    myServo.write(60);
    delay(1000);
    int right_b = analogRead(pin);
    myServo.write(90);
    stop();
    
   if(left_a > 500 && left_b > 400)
    {
      reverse();
      reverse_R();
      i++;
    }
    if(right_a > 500 && right_b > 400)
    {
      reverse();
      reverse_L();
      j++;
    }
    
    if(left_b <= right_b && i!=1)
    {
       turn_Left();
    }
    
     if(left_b > right_b && j!=1)
    {
       turn_Right();
    }
    i=0;
    j=0;
  }
}

