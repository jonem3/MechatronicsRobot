#include "encoder.h"

void encoderOld::calcData()
{
    enc_rev = enc_count / ENC_K;
    enc_angle = enc_rev * 360;
    wheel_angle = enc_angle * GEAR_RATIO;
}

void encoderOld::channelA()
{
    if (digitalRead(pinA) == 1)
    {
        if (digitalRead(pinB) == 0)
        {
            if (!isMirrored)
            {
                enc_count++;
            }
            else
            {
                enc_count--;
            }
        }
        else
        {
            if (!isMirrored)
            {
                enc_count--;
            }
            else
            {
                enc_count++;
            }
        }
    }
    else
    {
        if (digitalRead(pinB) == 1)
        {
            if (!isMirrored)
            {
                enc_count++;
            }
            else
            {
                enc_count--;
            }
        }
        else
        {
            if (!isMirrored)
            {
                enc_count--;
            }
            else
            {
                enc_count++;
            }
        }
    }
    calcData();
}

void encoderOld::channelB()
{
    if (digitalRead(pinB) == 1)
    {
        if (digitalRead(pinA) == 1)
        {
            if (!isMirrored)
            {
                enc_count++;
            }
            else
            {
                enc_count--;
            }
        }
        else
        {
            if (!isMirrored)
            {
                enc_count--;
            }
            else
            {
                enc_count++;
            }
        }
    }
    else
    {
        if (digitalRead(pinA) == 0)
        {
            if (!isMirrored)
            {
                enc_count++;
            }
            else
            {
                enc_count--;
            }
        }
        else
        {
            if (!isMirrored)
            {
                enc_count--;
            }
            else
            {
                enc_count++;
            }
        }
    }
    calcData();
}

float encoderOld::getWheelAngle(){
    return wheel_angle;
}

void encoderOld::setup(){
    pinMode(pinA, INPUT);
    pinMode(pinB, INPUT);
}
int encoderOld::getPinA(){
    return pinA;
}

int encoderOld::getPinB(){
    return pinB;
}

encoderOld::encoderOld(int A, int B, bool mirror){
    pinA = A;
    pinB = B;
    isMirrored = mirror;
    
    
}

