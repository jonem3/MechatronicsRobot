#include <Arduino.h>
class encoder
{
private:
    const int ENC_K = 32;
    const float GEAR_RATIO = 5 / 606.34;
    volatile long enc_count = 0;
    volatile float enc_rev;
    volatile float enc_angle;
    volatile float wheel_angle;
    int lastTime = 0;
    int currentTime;
    int elapsedTime;
    const float circumference = 68*PI;
    float lastAngle = 0;
    float dist_covered;
    double speed_robot;

public:
    void setEncoders(int count);
    double getSpeed();
    float readAngle();
    float readSpeed();
};