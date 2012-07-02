int motor1 = 5;
int motor_1 = 6;
int motor2 = 9;
int motor_2 = 10;

void setup()
{
  pinMode(motor1, OUTPUT);
  pinMode(motor_1, OUTPUT);
  pinMode(motor2, OUTPUT);
  pinMode(motor_2, OUTPUT);
}

void loop()
{
  turnRight();
  delay(1000);
  turnLeft();
  delay(1000);
}


void forward()
{
  analogWrite(motor1, 200);
  analogWrite(motor_1, 0);
  analogWrite(motor2, 200);
  analogWrite(motor_2, 0);
  delay(300);
}

void reverse()
{
  analogWrite(motor1, 0);
  analogWrite(motor_1, 200);
  analogWrite(motor2, 0);
  analogWrite(motor_2, 200);
  delay(300);
}

void turnLeft()
{
  analogWrite(motor1, 0);
  analogWrite(motor_1, 0);
  analogWrite(motor2, 200);
  analogWrite(motor_2, 0);
  delay(300);
}

void turnRight()
{
  analogWrite(motor1, 200);
  analogWrite(motor_1, 0);
  analogWrite(motor2, 0);
  analogWrite(motor_2, 0);
  delay(300);
}
