#include "../arm/arm.h"
#include <Arduino.h>

#define TOP -90
#define BOTTOM 36
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