#include <servomotor.h>
#include <math.h>
#include <Arduino.h>
class arm
{
    private:
        const float L0 = 11;
        const float L1 = 102;
        const float L2 = 79;
        const float L3 = 144; //Updated
        const int top = -90;
        const int bottom = -27;
        const int horizontalHeight = (top+bottom)/2;
        float S2, S3;
        
        ServoMotor Shoulder = ServoMotor(7, 1478, 1.571, -1.571, 1.571);
        ServoMotor Elbow = ServoMotor(8, 1484, 1.571, -1.571, 0);

        void getAngles(int x, int y);
        bool checkAngles(int oldX, int oldY);

    public:
    void setup();
        void drawLine();
        void setArmPosition(int x, int y);
        void goHome();
        void drawHoriz(float angle);
        void drivingPosition();
        void attachArm();
        void detachArm();
};
