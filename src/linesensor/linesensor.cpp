#include "linesensor.h"

linesensor::linesensor(int LSP, int CSP, int RSP)
{
    leftSensorPin = LSP;
    centreSensorPin = CSP;
    rightSensorPin = RSP;
}

void linesensor::setup()
{
    pinMode(leftSensorPin, INPUT);
    pinMode(centreSensorPin, INPUT);
    pinMode(rightSensorPin, INPUT);
}

float linesensor::getLeftSReading()
{
    float Reading;
    Reading = analogRead(leftSensorPin);
    return Reading;
}

float linesensor::getCentreSReading()
{
    float Reading;
    Reading = analogRead(centreSensorPin);
    return Reading;
}

float linesensor::getRightSReading()
{
    float Reading;
    Reading = analogRead(rightSensorPin);
    return Reading;
}