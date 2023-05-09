#include <servomotor.h>
#include <Arduino.h>
#include <Servo.h>

ServoMotor::ServoMotor(int servoPin, int pulse, float max, float min, int initialPos)
{
    pin = servoPin;
    angle = 0;
    pulseWidth = pulse;
    angle = initialPos;
    maxAngle = max;
    minAngle = min;
}

void ServoMotor::attach(){
    motor.attach(pin);
}

void ServoMotor::detach(){
    motor.detach();
}

void ServoMotor::setup()
{
    float minPulseWidth = float(pulseWidth) - 1000.0;
    int cmdSignal = (angle + (PI / 2)) * (2000.0 / PI) + minPulseWidth;
    motor.writeMicroseconds(cmdSignal);
    motor.attach(pin);
}

void ServoMotor::setAngle(float Angle){
    float minPulseWidth = float(pulseWidth) - 1000.0;
    int cmdSignal = (Angle + (PI / 2)) * (2000.0 / PI) + minPulseWidth;
    motor.writeMicroseconds(cmdSignal);
}

void ServoMotor::moveTo(float setAngle)
{
    setAngle = rateLimiting(setAngle);
    if (setAngle > maxAngle)
    {
        setAngle = maxAngle;
    }
    else if (setAngle < minAngle)
    {
        setAngle = minAngle;
    }

    float minPulseWidth = float(pulseWidth) - 1000.0;
    int cmdSignal = (setAngle + (PI / 2)) * (2000.0 / PI) + minPulseWidth;
    motor.writeMicroseconds(cmdSignal);
    angle = setAngle;
}

float ServoMotor::getAngle()
{
    return angle;
}

float ServoMotor::rateLimiting(double newAngle)
{
    float increment = 0.017;
    float positionCommand;
    if (newAngle > angle)
    {
        positionCommand = min(newAngle, angle + increment);
    }
    else if (newAngle < angle)
    {
        positionCommand = max(newAngle, angle - increment);
    }
    else
    {
        positionCommand = newAngle;
    }
    delay(10);
    return positionCommand;

    // Current angle is variable "angle"
    // new angle as above
    // return ratelimited angle
}