#include <Servo.h>
class ServoMotor
{
private:
    int pin, pulseWidth;
    float angle, maxAngle, minAngle;
    Servo motor;
    float rateLimiting(double newAngle);

public:
void setup();
    ServoMotor(int servoPin, int pulse, float max, float min, int initialPos);
    void moveTo(float setAngle);
    float getAngle();
};

/*
Note: Servo motors are dumb
Conditional control will be done in the robot arm class
which is clever
*/