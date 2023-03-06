#include "../motor/motor.h"
#include "../encoder/encoder.h"
class motion{
private:
    motor leftMot = motor(7, 8, 5, 9, 0);
    motor rightMot = motor(2, 3, 4, 9, 1);
    encoder leftEnc;
    encoder rightEnc;
    const float Kp = 5;
    public:
    void setup();
    void setEncoders(int counts[2]);
    void moveToAngle(int leftMotAng, int rightMotAng);
};
