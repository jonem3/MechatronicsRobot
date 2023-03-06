#include "motion.h"

void motion::setEncoders(int counts[2]){
    leftEnc.setEncoders(counts[0]);
    rightEnc.setEncoders(counts[1]);
}

void motion::setup(){
    leftMot.setup();
    rightMot.setup();
}

void motion::moveToAngle(int leftMotAngle, int rightMotAngle){
    float leftAngle, rightAngle;
    do{
        leftAngle = leftEnc.readAngle();
        rightAngle = rightEnc.readAngle();
        float errorL = leftMotAngle - leftAngle;
        float errorR = rightMotAngle - rightAngle;
        leftMot.moveMotor(errorL*Kp);
        rightMot.moveMotor(errorR*Kp);
    }while(leftAngle != leftMotAngle && rightAngle != rightMotAngle);
}