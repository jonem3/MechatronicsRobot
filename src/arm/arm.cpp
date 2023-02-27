#include "arm.h"
void arm::setArmPosition(int x, int y)
{
    x = x + L2 + L3;
    getAngles(x, y);
    bool isPossible = checkAngles(x, y);
    if(isPossible){
        Serial.print("X: ");
        Serial.print(x - L2 - L3);
        Serial.print(" | Y: ");
        Serial.println(y);
        Serial.println();
        while (Shoulder.getAngle() != S2 && Wrist.getAngle() != S3)
    {
        
        Wrist.moveTo(S3);
        Shoulder.moveTo(-S2);
    }
    }
    
    
}

void arm::goHome(){
    S2 = 1.571; S3 = 0;
    while(Shoulder.getAngle() != S2 && Wrist.getAngle() != S3){
        Wrist.moveTo(S3);
        Shoulder.moveTo(S2);
    }
}

bool arm::checkAngles(int oldX, int oldY){
    int x = L2*cos(S2) + L3*cos(S2+S3);
    int y = L2*sin(S2) + L3*sin(S2+S3);
    if (x == oldX){
        return true;
    }
    else{
        Serial.print("MISMATCH: ");
        Serial.print("Expected X: ");
        Serial.print(oldX);
        Serial.print(" Expected Y: ");
        Serial.print(oldY);
        Serial.print(" | X: ");
        Serial.print(x);
        Serial.print(" Y: ");
        Serial.println(y);
        Serial.println();
        return false;
    }
}

void arm::getAngles(int x, int y)
{
    float num = pow(x, 2) + pow(y, 2) - pow(L2, 2) - pow(L3, 2);
    float den = 2 * L2 * L3;
    S3 = acos(num/den); // Wrist Angle
    S2 = atan2(y, x) - atan2(L3*sin(S3), L2 + L3*cos(S3)); // Shoulder Angle
}
