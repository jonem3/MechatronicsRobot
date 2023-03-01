#include <Arduino.h>
#include "motors/motor1.h"

motor rightmotor(250, true, false, true);

void setup()
{
    Serial.begin(9600);
    rightmotor.pinmode();
}

void loop()
{
    rightmotor.execute();
}
