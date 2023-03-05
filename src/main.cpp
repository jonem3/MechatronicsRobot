#include <Arduino.h>
#include "arm/arm.h"
#include "encoder/encoder.h"

#define TOP -90
#define BOTTOM 36

// NOTE: Coordinate system is upside down on Y Axis
void moveArm();
encoder* enc;

void setup()
{
  Serial.begin(9600);
  enc = new encoder(3, 2, 0);
  attachInterrupt(digitalPinToInterrupt(3), enc.channelA, CHANGE);
  attachInterrupt(digitalPinToInterrupt(2), enc.channelB, CHANGE);
}


void loop()
{
  // put your main code here, to run repeatedly:
}

void moveArm()
{
  // Function for Task 1 of the Mechatronics Project
  arm RobotArm;
  delay(1000);
  RobotArm.setArmPosition(-45, TOP);
  delay(1000);
  int i = TOP;
  do{
    RobotArm.setArmPosition(-37, i);
    i++;
  }while(i <= BOTTOM);

  RobotArm.setArmPosition(-50, BOTTOM);

do{
  RobotArm.setArmPosition(-50, i);
  i = i - 10;
}while(i >= TOP);
RobotArm.goHome();
}
