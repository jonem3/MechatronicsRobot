#include "encoder.h"
#include <Arduino.h>

void encoder::setEncoders(int count){
    enc_count += count;
    enc_rev = enc_count/ENC_K;
    enc_angle = enc_rev*360;
    wheel_angle = enc_angle*GEAR_RATIO;
}

float encoder::readAngle(){
    return wheel_angle;
}

float encoder::readSpeed(){
    return 0;
}

float encoder::getSpeed()
{
    int currentTime = millis();
    int lastTime = 0;
    float angleDifference = readAngle() - lastAngle;
    dist_covered = circumference * (angleDifference / 360);
    float elapsedTime_Sec = (currentTime - lastTime) / 60;
    speed_robot = dist_covered / elapsedTime_Sec;
    lastTime = currentTime;
    lastAngle = readAngle();
    return speed_robot;
}