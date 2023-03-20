#include <Arduino.h>

class linesensor
{
    private:
        int leftSensorPin;
        int centreSensorPin;
        int rightSensorPin;

    public:
        linesensor(int LSP, int CSP, int RSP);
        void setup();
        float getLeftSReading();
        float getCentreSReading();
        float getRightSReading();
};