#include "arm.h"
void arm::setArmPosition(int x, int y)
{
    
    x = x + L2 + L3;
    getAngles(x, y);
    Serial.print("S2: ");
    Serial.print(S2);
    Serial.print(" S3: ");
    Serial.print(S3);
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

void arm::getAngles(int x, int y){
    float num = pow(x, 2) + pow(y, 2) - pow(L2, 2) - pow(L3, 2);
    float den = 2 * L2 * L3;
    S3 = acos(num/den); // Wrist Angle

    S2 = atan2(y, x) - atan2(L3*sin(S3), L2 + L3*cos(S3)); // Shoulder Angle

}