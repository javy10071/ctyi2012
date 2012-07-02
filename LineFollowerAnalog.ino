/*
* 2/7/12
* Eoin Muldowney
*/

// motor1, motor_1 pins connect to the left motor control
// motor2_ motor_2 pins connect to the right motor control
// Line sensor
// A0 - brown
// A1 - red
// A2 - orange
// A3 - yellow
// A4 - green
// GND - blue
// 5V - white

// Threshold value can be modified as required
// Lower the value for a more reflective black background (min: approx 100)
// Raise the value if the background is not very reflective to ensure definitive results (approx 400)
// The height of the sensor also affects this value, more clearance means higher value

int motor1 = 5;
int motor_1 = 6;
int motor2 = 9;
int motor_2 = 10;

int rawSens[5] = {0,0,0,0,0};
int binarySens[5] = {0,0,0,0,0};
int leds[5] = {13,7,4,3,2};
int sensPins[5] = {A0,A1,A2,A3,A4};

int threshold = 200;

int black = 1;
int white = 0;

void setup()
{
  Serial.begin(9600); 
  pinMode (motor1, OUTPUT);
  pinMode(motor_1, OUTPUT);
  pinMode (motor2, OUTPUT);
  pinMode(motor_2, OUTPUT);
  
  for(int i=0;i<5;i++)
  {
    pinMode(leds[i], OUTPUT);
  }
}

void forward()
{
   analogWrite(motor2, 100);
   analogWrite(motor_2, 0);
   analogWrite(motor1, 120);
   analogWrite(motor_1, 0);
}

void stopCar()
{
   analogWrite(motor1, 0);
   analogWrite(motor_1, 0);
   analogWrite(motor2, 0);
   analogWrite(motor_2, 0);
   delay(500);
}
void turn_Right()
{
  analogWrite(motor1, 100);
  analogWrite(motor_1, 0);
  analogWrite(motor2, 0);
  analogWrite(motor_2, 0);
  delay(150);

}
void turn_Left()
{
  analogWrite(motor2, 100);
  analogWrite(motor_2, 0);
  analogWrite(motor1, 0);
  analogWrite(motor_1, 0);
  delay(150);
}

void sharp_Right()
{
  analogWrite(motor1, 100);
  analogWrite(motor_1, 0);
  analogWrite(motor2, 0);
  analogWrite(motor_2, 100);
  delay(150);  
}

void sharp_Left()
{
  analogWrite(motor2, 100);
  analogWrite(motor_2, 0);
  analogWrite(motor1, 0);
  analogWrite(motor_1, 100);
  delay(150);
}


void loop()
{
  checkLineSensor();
  forward();
  if(binarySens[0] == white && binarySens[4] == white){stopCar();}
  else if(binarySens[4] == white){sharp_Left();}
  else if(binarySens[0] == white){sharp_Right();}
  else if(binarySens[3] == white){turn_Left();}
  else if(binarySens[1] == white){turn_Right();} 
}


void checkLineSensor()
{
  int i;
  for (i=0;i<5;i++)
  {
    rawSens[i]=analogRead(sensPins[i]);
    if (rawSens[i]<threshold)
    {
      binarySens[i]=0;
      digitalWrite(HIGH, leds[i]);
    }
    else{
      binarySens[i]=1; 
      digitalWrite(LOW, leds[i]);
    }
    
    Serial.print(binarySens[i]);
    Serial.print("   ");
  }
  Serial.println();
}

