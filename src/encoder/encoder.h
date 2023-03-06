class encoder{
private:
    const int ENC_K = 32;
    const float GEAR_RATIO = 5/606.34;
    volatile long enc_count = 0;
    volatile float enc_rev;
    volatile float enc_angle;
    volatile float wheel_angle;
public:
    void setEncoders(int count);
    float readAngle();
    float readSpeed();
};