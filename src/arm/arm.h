#include "../servo/servomotor.h"
class arm
{
private:
    float L0 = 11;
    float L1 = 102;
    float L2 = 79;
    float L3 = 136; // NEEDS TO BE UPDATED WHEN PEN END EFFECTOR ADDED
    ServoMotor Base = ServoMotor(4, 1488, 1.571, -1.571);
    ServoMotor Shoulder = ServoMotor(3, 1488, 1.571, -1.571);
    ServoMotor Wrist = ServoMotor(2, 1481, 1.571, -1.571);
};
