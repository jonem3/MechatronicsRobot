#include <Arduino.h>
#include "arm/arm.h"

// NOTE: Coordinate system is upside down on Y Axis
void moveArm();
void setup()
{
  Serial.begin(9600);
  moveArm();
}

void moveArm()
{
  arm RobotArm;
  RobotArm.setArmPosition(-30, -50);
  delay(1000);
  int i = -50;
  do{
    RobotArm.setArmPosition(-30, i);
    i = i+5;
  }while(i <= 50);
}

void loop()
{
  // put your main code here, to run repeatedly:
}