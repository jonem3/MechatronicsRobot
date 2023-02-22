#include <Servo.h>
class ServoMotor
{
private:
    int pin, pulseWidth;
    float angle, maxAngle, minAngle;
    Servo motor;
    float rateLimiting(double newAngle);

public:
    ServoMotor(int servoPin, int pulse, float max, float min);
    void moveTo(float setAngle);
    float getAngle();
};

/*
Note: Servo motors are dumb
Conditional control will be done in the robot arm class
which is clever
*/