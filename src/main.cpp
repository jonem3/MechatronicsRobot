#include <Arduino.h>
#include "arm/arm.h"
#include "encoder/encoder.h"
#include "motor/motor.h"

#define TOP -90
#define BOTTOM 36

// NOTE: Coordinate system is upside down on Y Axis
void moveArm();
encoder enc = encoder(3, 2, 0);
motor mot = motor(7, 8, 5, 9, 0);

void encHandlerA(){
  enc.channelA();
}

void encHandlerB(){
  enc.channelB();
}

void setup()
{
  Serial.begin(9600);
  enc.setup();
  mot.setup();
  attachInterrupt(digitalPinToInterrupt(enc.getPinA()), encHandlerA, CHANGE);
  attachInterrupt(digitalPinToInterrupt(enc.getPinB()), encHandlerB, CHANGE);
}


void loop()
{
  // put your main code here, to run repeatedly:
  float error = 180-enc.getWheelAngle();
  if(error < 0.1 && error > -0.1){
    mot.motorStandBy();
  }
  else{
float velo = 5*error;
  mot.moveMotor(velo);
  }
  
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
