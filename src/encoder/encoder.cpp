#include "encoder.h"
void encoder::calcData()
{
    enc_rev = enc_count / ENC_K;
    enc_angle = enc_rev * 360;
    wheel_angle = enc_angle * GEAR_RATIO;
}

void encoder::channelA()
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

void encoder::channelB()
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

float encoder::getWheelAngle(){
    return wheel_angle;
}

void encoder::setup(){
    pinMode(pinA, INPUT);
    pinMode(pinB, INPUT);
}
int encoder::getPinA(){
    return pinA;
}

int encoder::getPinB(){
    return pinB;
}

encoder::encoder(int A, int B, bool mirror){
    pinA = A;
    pinB = B;
    isMirrored = mirror;
    
    
}

