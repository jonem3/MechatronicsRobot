#include "../servo/servomotor.h"
class arm{
private:
float vertLength; //L1
float upperLength; //L2
float lowerLength; //L3
ServoMotor Base = ServoMotor(1, 1, 1, 1);
ServoMotor Shoulder = ServoMotor(2, 2, 2, 2);
ServoMotor Wrist = ServoMotor(3, 3, 3, 3);
};