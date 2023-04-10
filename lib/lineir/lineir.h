#include <Arduino.h>
class lineir{
    private:
    int irPIN;
    int reading;
    int minimumVal;
    int maximumVal;
    int mapIR(int rawReading);
    public:
    lineir(int pin, int min, int max);
    int getReading();
};