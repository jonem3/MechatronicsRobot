#include "arm.h"
void arm::setArmPosition(int x, int y){
    getAngles(x, y);
    while (Shoulder.getAngle() != S2 && Wrist.getAngle() != S3){
        Wrist.moveTo(S3);
        Shoulder.moveTo(-S2);
    }
}