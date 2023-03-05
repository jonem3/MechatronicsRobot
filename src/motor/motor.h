
#include <Arduino.h>
class motor
{
private:
    int pinI1;
    int pinI2;
    int pinPWM;
    int pinStandBy;

    bool I1;
    bool I2;
    bool standBy;
    bool isMirrored;

    unsigned char pwmValue;

    int velocityLimiter(int velocity);
    void setDirection(int velocity);

public:
    motor(int I1, int I2, int PWM, int StandBy, bool mirror);
    void moveMotor(int velocity);
    void motorStandBy();
    void brake();
    void setup();
};