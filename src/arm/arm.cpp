#include "arm.h"
void arm::setArmPosition(int x, int y)
{
    x = x + L2 + L3;
    getAngles(x, y);
    Serial.print("S2: ");
    Serial.print(S2);
    Serial.print(" S3: ");
    Serial.print(S3);
    int count = 0;
    bool isPossible = checkAngles(x, y);
    if(isPossible){
        while (Shoulder.getAngle() != S2 && Wrist.getAngle() != S3)
    {
        Serial.print(" CURRENT S2: ");
        Serial.print(S2);
        Serial.print(" CURRENT S3: ");
        Serial.println(S3);
        Wrist.moveTo(S3);
        Shoulder.moveTo(-S2);
    }
    }
    
    
}

bool arm::checkAngles(int oldX, int oldY){
    int x = L2*cos(S2) + L3*cos(S2+S3);
    int y = L2*sin(S2) + L3*sin(S2+S3);
    if (x == oldX && y == oldY){
        return true;
    }
    else{
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

void arm::rotateBase(int angleDeg){
    float angleRad = angleDeg*(PI/180);
    while(Base.getAngle() != angleRad){
        Base.moveTo(angleDeg);
    }
}