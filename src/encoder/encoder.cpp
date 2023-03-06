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