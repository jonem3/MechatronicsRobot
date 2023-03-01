#include <Arduino.h>
class motor
{
    private:
        int pinAI1 = 0;       // Pin allocation for AI1
        int pinAI2 = 0;       // Pin allocation for AI2
        int pinPWM = 0;       // Pin allocation for the PWM pin
        int pinStandBy = 0;   // Pin allocation for the standby pin
        bool AI1 = true;            // AI1 pin value
        bool AI2 = false;            // AI2 pin value
        bool standBy = true;        // standBy pin Value
        unsigned char pwmValue = 100; // PWM value to be written to the output

    public:
        motor(int pinai1, int pinai2, int pinpwm, int pinstandby);
        void stop();
        void adjustspeedanddirection(int pwm, bool a, bool b);
};