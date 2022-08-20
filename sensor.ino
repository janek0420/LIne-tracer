#include <SoftwareSerial.h>
#include <AFMotor.h>

AF_DCMotor motor_1(1);
AF_DCMotor motor_2(4);

int sensor1=A5;
int sensor2=A0;

void setup()
{
  Serial.begin(9600);
  pinMode(sensor1,INPUT);
  pinMode(sensor2,INPUT);
  motor_1.setSpeed(230);
  motor_2.setSpeed(230);
  motor_1.run(RELEASE);
  motor_2.run(RELEASE);
}

void loop()
{
  int val1=digitalRead(sensor1);
  int val2=digitalRead(sensor2);
  if(val1==0 && val2==0)
  {
    motor_1.run(FORWARD);
    motor_2.run(FORWARD);
   
  }
  else if(val1==1 && val2==0)
  {
    motor_1.run(FORWARD);
    motor_2.run(RELEASE);
    
  }
  else if(val1==0 && val2==1)
  {
    
    motor_1.run(RELEASE);
    motor_2.run(FORWARD);
    
  }
  else
  {
    motor_1.run(RELEASE);
    motor_2.run(RELEASE);
  }
}
