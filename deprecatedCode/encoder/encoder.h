#include <Arduino.h>
class encoderOld{
    private:
    int pinA;
    int pinB;
    
    const int ENC_K = 32;
    const float GEAR_RATIO = 5/606.34;

    volatile long enc_count;
    volatile float enc_rev;
    volatile float enc_angle;
    volatile float wheel_angle;

    bool isMirrored;

    void calcData();
    

    public:
    void channelA();
    void channelB();
    float getWheelAngle();
    void setup();
    encoderOld(int A, int B, bool mirror);
    int getPinA();
    int getPinB();
    
};