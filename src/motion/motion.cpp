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
        float errorL = leftMotAngle - leftAngle;
        float errorR = rightMotAngle - rightAngle;
        leftMot.moveMotor(errorL*AngleKp);
        rightMot.moveMotor(errorR*AngleKp);
    }while(leftAngle != leftMotAngle && rightAngle != rightMotAngle);
}

float motion::speedController(float currentSpeed, float targetSpeed, int motor){
    float error = targetSpeed - currentSpeed;
    float input = error*Kp + cumError[motor]*Ki;
    cumError[motor]+=error;
    if(cumError[motor] > (100/Ki)){
        cumError[motor] = (100/Ki);
    }
    else if(cumError[motor] < -(100/Ki)){
        cumError[motor] = -(100/Ki);
    }

    return input;
}

void motion::setMotorSpeed(float left, float right){
    double leftSpeed = leftEnc.getSpeed();
    double rightSpeed = rightEnc.getSpeed();
    Serial.println();
    float leftInput = speedController(leftSpeed, left, 0);
    float rightInput = speedController(rightSpeed, right, 1);
    
    leftMot.moveMotor(leftInput);
    rightMot.moveMotor(rightInput);
}

void motion::rotateAngle(float degrees){
    Serial.println(degrees);
    float rotationPercentage = degrees/360; // How many rotations of the robot
    Serial.println(rotationPercentage);
    float toTravel = robotCir*rotationPercentage; // How far a wheel needs to travel to acheive this
    Serial.println(toTravel);
    float numRotations = toTravel/wheelCircumference; // Number of rotations of a wheel needed
    Serial.println(numRotations);
    float rotationDegrees = numRotations*360; // Conversion to degrees
    Serial.println(rotationDegrees);
    float leftAngle = leftEnc.readAngle();
    float rightAngle = rightEnc.readAngle();
    moveToAngle(leftAngle+rotationDegrees, rightAngle-rotationDegrees);
}