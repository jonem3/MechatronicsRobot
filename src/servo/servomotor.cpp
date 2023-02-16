#include "servomotor.h"
#include <Arduino.h>
#include <Servo.h>

ServoMotor::ServoMotor(int servoPin, int pulse, double max, double min)
{
    pin = servoPin;
    angle = 0;
    pulseWidth = pulse;
    motor.attach(pin);
    maxAngle = max;
    minAngle = min;
}

void ServoMotor::moveTo(double setAngle)
{
    if (setAngle > maxAngle)
    {
        setAngle = maxAngle;
    }
    else if (setAngle < minAngle)
    {
        setAngle = minAngle;
    }

    int minPulseWidth = pulseWidth - 1000;
    int cmdSignal = (setAngle + (pi / 2)) * (2000 / pi) + minPulseWidth;
    motor.writeMicroseconds(cmdSignal);
    angle = setAngle;
}

float ServoMotor::getAngle()
{
    return angle;
}

float ServoMotor::rateLimiting(double newAngle){
    float targetAngle ;
    float angle ; 
    float increment ; 
    float positionCommand ;
    if (targetAngle > angle){
        positionCommand = min(targetAngle , angle + increment) ;
    }
    else if (targetAngle < angle){
        positionCommand = max(targetAngle , angle - increment) ;
    }
    else {
        positionCommand = targetAngle ;
    }
    
    //Current angle is variable "angle"
    //new angle as above
    //return ratelimited angle

}