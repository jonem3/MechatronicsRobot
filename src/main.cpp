#include <Arduino.h>
#include "arm/arm.h"

//NOTE: Coordinate system is upside down on Y Axis
void setup()
{
  Serial.begin(9600);
  // put your setup code here, to run once:

  arm RobotArm;
  RobotArm.setArmPosition(0,0);
  delay(1000);
  int i = -50;
  do
  {
    RobotArm.setArmPosition(-35, i);
    //delay(1);
    i = i+5;
    Serial.println(i);
  }while(i < 50);
  Serial.println("RETURNING TO ORIGIN");
  RobotArm.setArmPosition(-1,0);
}

void loop()
{
  // put your main code here, to run repeatedly:
}