#include "../servo/servomotor.h"
#include <math.h>
#include <Arduino.h>
class arm
{
    private:
        float L0 = 11;
        float L1 = 102;
        float L2 = 79;
        float L3 = 205; //Updated
        float S1, S2, S3;

        ServoMotor Base = ServoMotor(10, 1515, 1.571, -1.571);
        ServoMotor Shoulder = ServoMotor(7, 1478, 1.571, -1.571);
        ServoMotor Wrist = ServoMotor(2, 1484, 1.571, -1.571);

        void getAngles(int x, int y);
        bool checkAngles(int oldX, int oldY);

    public:
        void setArmPosition(int x, int y);
        void rotateBase(int angleDeg);
};
