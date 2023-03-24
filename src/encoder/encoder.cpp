#include "encoder.h"
#include <Arduino.h>

void encoder::setEncoders(int count){
    enc_count += count;
    enc_rev = enc_count/ENC_K;
    enc_angle = (enc_rev*360);
    wheel_angle = enc_angle*GEAR_RATIO;
}

float encoder::readAngle(){
    return wheel_angle;
}

float encoder::readSpeed(){
    return 0;
}

double encoder::getSpeed()
{

    currentTime = millis();
    float currentAngle = wheel_angle;
    float angleDifference = currentAngle - lastAngle;
    int timeDifference = currentTime - lastTime;

    
    dist_covered = circumference * (angleDifference / 360);
    speed_robot = (dist_covered / timeDifference);

    if(isnan(speed_robot)){
        speed_robot = 0;
    }

    lastTime = currentTime;
    lastAngle = currentAngle;
    return speed_robot;
}