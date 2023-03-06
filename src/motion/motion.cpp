#include "motion.h"

void motion::setEncoders(int countL, int countR){
    leftEnc.setEncoders(countL);
    rightEnc.setEncoders(countR);
}

void motion::setup(){
    Serial.begin(115200);
    leftMot.setup();
    rightMot.setup();
}

void motion::moveToAngle(int leftMotAngle, int rightMotAngle){
    float leftAngle, rightAngle;
    do{
        leftAngle = leftEnc.readAngle();
        rightAngle = rightEnc.readAngle();
        Serial.print("L ANGLE: ");
        Serial.print(leftAngle);
        Serial.print("\tR ANGLE: ");
        Serial.println(rightAngle);
        float errorL = leftMotAngle - leftAngle;
        float errorR = rightMotAngle - rightAngle;
        leftMot.moveMotor(errorL*Kp);
        rightMot.moveMotor(errorR*Kp);
    }while(leftAngle != leftMotAngle && rightAngle != rightMotAngle);
}