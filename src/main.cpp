#include <Arduino.h>
#include "arm/arm.h"

//NOTE: Coordinate system is upside down on Y Axis
void setup()
{
  // put your setup code here, to run once:

  arm RobotArm;
  RobotArm.setArmPosition(0, 0);
  delay(1000);
  for (int i = -50; i < 50; i++)
  {
    RobotArm.setArmPosition(-20, i);
    delay(50);
  }
  RobotArm.setArmPosition(0, 0);
}

void loop()
{
  // put your main code here, to run repeatedly:
}