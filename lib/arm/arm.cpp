#include <arm.h>
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
        while (Shoulder.getAngle() != S2 && Elbow.getAngle() != S3)
    {
        
        Elbow.moveTo(S3);
        Shoulder.moveTo(-S2);
    }
    }
    
    
}

void arm::setup(){
    Shoulder.setup();
    Elbow.setup();
}

void arm::goHome(){
    S2 = 1.571; S3 = 0;
    while(Shoulder.getAngle() != S2 && Elbow.getAngle() != S3){
        Elbow.moveTo(S3);
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

void arm::drawLine(){
    const int top = -90;
    const int bottom = 36;
    delay(1000);
    setArmPosition(-45, top);
    delay(1000);
    int i = top;
    do{
        setArmPosition(-37, i);
        i++;
    }while(i <= bottom);

    do{
        setArmPosition(-50, i);
        i--;
    }
    while(i >= (top+bottom)/2);
}


void arm::drawHoriz(int angle){
    // Angle should be relative to middle position i.e. from centre of horizontal line to robot rotate 90 degrees left should be -90
    const int vert = -27;
    int horiz = -37*cos(angle);
    setArmPosition(horiz, vert);

}

