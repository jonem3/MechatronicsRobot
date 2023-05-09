#include <Arduino.h>
class encoder
{
private:
    const int ENC_K = 32;
    const float GEAR_RATIO = 5 / 606.34;
    volatile long enc_count = 0;
    volatile double enc_rev;
    volatile double enc_angle;
    volatile double wheel_angle;
    int lastTime = 0;
    int currentTime;
    int elapsedTime;
    const float circumference = 68*PI;
    double lastAngle = 0;
    double dist_covered;
    double speed_robot;

public:
    void setEncoders(int count);
    double getSpeed();
    double readAngle();
    double readSpeed();
    void resetEncCount();
};