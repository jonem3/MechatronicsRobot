#include <Servo.h>
class ServoMotor
{
private:
    int pin, pulseWidth;
    double angle, maxAngle, minAngle;
    const float pi = 3.142;
    Servo motor;
    double rateLimiting(double newAngle);

public:
    ServoMotor(int servoPin, int pulse, double max, double min);
    void moveTo(double setAngle);
    double getAngle();
};

/*
Note: Servo motors are dumb
Conditional control will be done in the robot arm class
which is clever
*/