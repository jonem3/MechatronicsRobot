class encoder
{
private:
    const int ENC_K = 32;
    const float GEAR_RATIO = 5 / 606.34;
    volatile long enc_count = 0;
    volatile float enc_rev;
    volatile float enc_angle;
    volatile float wheel_angle;
    int lastTime;
    int currentTime;
    int elapsedTime;
    const float radius = 1;
    const float circumference = 6.2;
    float lastAngle;
    float dist_covered;
    float speed_robot;

public:
    void setEncoders(int count);
    float getSpeed();
    float readAngle();
    float readSpeed();
};