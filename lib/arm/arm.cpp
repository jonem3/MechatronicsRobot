#include <arm.h>
void arm::setArmPosition(int x, int y)
{
    x = x + L2 + L3;
    getAngles(x, y);
    bool isPossible = checkAngles(x, y);
    if(isPossible){
        Elbow.setAngle(S3);
        Shoulder.setAngle(-S2);
    }
    else{
        Serial.print("Angle Not Possible: ");
        Serial.print("X: ");
        Serial.print(x - L2 - L3);
        Serial.print(" | Y: ");
        Serial.println(y);
    }
    
    
}

void arm::attachArm(){
    Shoulder.attach();
    Elbow.attach();
}

void arm::detachArm(){
    Shoulder.detach();
    Elbow.detach();
}

void arm::setup(){
    Shoulder.setup();
    Elbow.setup();
}

void arm::goHome(){
    S2 = 1.571; S3 = 0;
    Elbow.setAngle(S3);
    Shoulder.setAngle(S2);
}

void arm::drivingPosition(){
    S2 = 0; S3 = 0;
        Elbow.setAngle(S3);
        Shoulder.setAngle(S2);
}

bool arm::checkAngles(int oldX, int oldY){
    int x = L2*cos(S2) + L3*cos(S2+S3);
    int y = L2*sin(S2) + L3*sin(S2+S3);
    if (x == oldX){
        return true;
    }
    else{
        Serial.print("POSITION ACHIEVED: ");
        Serial.print("X: ");
        Serial.print(x - L2 - L3);
        Serial.print(" | Y: ");
        Serial.println(y);
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
    delay(1000);
    setArmPosition(-45, top);
    delay(1000);
    int i = top;
    do{
        setArmPosition(-35, i);
        i++;
    }while(i <= bottom);

    do{
        setArmPosition(-45, i);
        i--;
    }
    while(i >= horizontalHeight);
}


void arm::drawHoriz(float angle){
    // Angle should be relative to middle position i.e. from centre of horizontal line to robot rotate 90 degrees left should be -90
    int horiz = -36*cos(angle*(PI/180));
    setArmPosition(horiz, horizontalHeight);

}

