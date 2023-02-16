#include "arm.h"
void arm::setArmPosition(int x, int y)
{
    if (y < -L1)
    {
        y = -L1;
    }
    else if (x == -(L2 + L3) && y < 0)
    {
        y = 0;
    }
    getAngles(x, y);
    while (Shoulder.getAngle() != S2 && Wrist.getAngle() != S3)
    {
        Wrist.moveTo(S3);
        Shoulder.moveTo(-S2);
    }
}