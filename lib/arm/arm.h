#include <servomotor.h>
#include <math.h>
#include <Arduino.h>
class arm
{
    private:
        float L0 = 11;
        float L1 = 102;
        float L2 = 79;
        float L3 = 144; //Updated
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
