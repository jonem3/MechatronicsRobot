#include <Arduino.h>
class motor
{
    private:
        const int pinAI1 = 7;       // Pin allocation for AI1
        const int pinAI2 = 8;       // Pin allocation for AI2
        const int pinPWM = 5;       // Pin allocation for the PWM pin
        const int pinStandBy = 9;   // Pin allocation for the standby pin
        bool AI1 = true;            // AI1 pin value
        bool AI2 = false;            // AI2 pin value
        bool standBy = 0;        // standBy pin Value
        unsigned char pwmValue = 100; // PWM value to be written to the output

    public:
        motor(int speed, bool ai1, bool ai2, bool standby);
        void stop();
        void reverse();
        void adjustspeed(int pwm);
};