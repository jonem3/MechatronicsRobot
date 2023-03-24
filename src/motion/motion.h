#include "../motor/motor.h"
#include "../encoder/encoder.h"
class motion
{
private:
    motor leftMot = motor(7, 8, 5, 9, 1);
    motor rightMot = motor(2, 3, 4, 9, 0);
    encoder leftEnc;
    encoder rightEnc;
    const float AngleKp = 5;
    const float Kp = 60 ;
    const float Ki = 40;
    const float robotCir = 250*PI;
    const float wheelCircumference = 68*PI;

    float cumError[2] = {0, 0};

    float speedController(float currentSpeed, float targetSpeed, int motor);
    

public:
    void setup();
    void setEncoders(int countL, int countR);
    void moveToAngle(int leftMotAng, int rightMotAng);
    void setMotorSpeed(float left, float right);
    void rotateAngle(float degrees);
    float getDistanceTravelled();
};
