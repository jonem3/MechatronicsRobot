#include <Arduino.h>

class rigthmotor
{
    private:
        const int pinAI1 = 7;       // Pin allocation for AI1
        const int pinAI2 = 8;       // Pin allocation for AI2
        const int pinPWM = 5;       // Pin allocation for the PWM pin
        const int pinStandBy = 9;   // Pin allocation for the standby pin
        boolean AI1 = 0;            // AI1 pin value
        boolean AI2 = 0;            // AI2 pin value
        boolean standBy = 0;        // standBy pin Value
        unsigned char pwmValue = 0; // PWM value to be written to the output

    public:
        rigthmotor(int speed, bool ai1, bool ai2);
};