#include <Servo.h>

Servo myServo;

  int motor1 = 5;
  int motor_1 = 6;
  int motor2 = 9;
  int motor_2 = 10;
int pin = A0;
int distance = 0;

void setup()
{
  pinMode (motor1, OUTPUT);
  pinMode(motor_1, OUTPUT);
  pinMode (motor2, OUTPUT);
  pinMode(motor_2, OUTPUT);
  myServo.attach(11);
  myServo.write(90);
}
void forward()
{
   analogWrite(motor1, 255);
   analogWrite(motor_1, 0);
   analogWrite(motor2, 255);
   analogWrite(motor_2, 0);
   delay(300);
}
void reverse()
{
  stopCar();
  analogWrite(motor1, 0);
  analogWrite(motor_1, 255);
  analogWrite(motor2, 0);
  analogWrite(motor_2, 255);
  delay(300);
}
void stopCar(void)
{
   analogWrite(motor1, 0);
   analogWrite(motor_1, 0);
   analogWrite(motor2, 0);
   analogWrite(motor_2, 0);
   delay(300);
}
void turn_Left()
{
  stopCar();
  analogWrite(motor2, 255);
  analogWrite(motor_2, 0);
  delay(500);
}
void turn_Right()
{
  stopCar();
  analogWrite(motor1, 255);
  analogWrite(motor_1, 0);
  delay(500);
}
//Reverse to the left
void reverse_L()
{
  stopCar();
  analogWrite(motor2, 0);
  analogWrite(motor_2, 255);
  delay(500);
}
//Reverse to the right
void reverse_R()
{
  stopCar();
  analogWrite(motor1, 0);
  analogWrite(motor_1, 255);
  delay(500);
}

void loop()
{
    float distance = analogRead(pin);
    forward();
   
 if(distance>390)
  {    
    //robot measures 2 different points on the left and on the right. This way if 
    //the sensor is out of range for one point it will be ok for the other.
    
    stopCar();

    myServo.write(180);
    delay(1000);
    int left_a = analogRead(pin);

    myServo.write(120);
    delay(1000);
    int left_b = analogRead(pin);
    
    myServo.write(0);
    delay(1000);
    int right_a = analogRead(pin);

    myServo.write(60);
    delay(1000);
    int right_b = analogRead(pin);

    myServo.write(90);
//    stopCar();
    
//   if(left_a > 500 && left_b > 400)
//    {
//      reverse();
//      reverse_R();
//    }
//    else if(right_a > 500 && right_b > 400)
//    {
//      reverse();
//      reverse_L();
//    } 
//    else if(left_b <= right_b)
//    {
//       turn_Left();
//    }
//    else if(left_b > right_b)
//    {
//       turn_Right();
//    }
//    else
//    {
//       reverse();
//       reverse_L();
//    }
   if(left_a > 450 && left_b > 400)
    {
      reverse();
      reverse_R();
    }
    if(right_a > 450 && right_b > 400)
    {
      reverse();
      reverse_L();
    }
    
    if(left_b <= right_b)
    {
       reverse_L();
    }
    else if(left_b > right_b)
    {
       reverse_R();
    }

     //end else if
  } //end if
} //end loop()

