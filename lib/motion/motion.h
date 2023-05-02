#include <motor.h>
#include <encoder.h>
class motion
{
private:
    motor leftMot = motor(16, 17, 5, 9, 1);
    motor rightMot = motor(14, 15, 4, 9, 0);
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
