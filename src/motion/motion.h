#include "../motor/motor.h"
#include "../encoder/encoder.h"
class motion{
private:
    motor leftMot = motor(7, 8, 5, 9, 1);
    motor rightMot = motor(2, 3, 4, 9, 0);
    encoder leftEnc;
    encoder rightEnc;
    const float Kp = 2;
    public:
    void setup();
    void setEncoders(int countL, int countR);
    void moveToAngle(int leftMotAng, int rightMotAng);
};
