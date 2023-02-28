#include "motor1.h"
#include <Arduino.h>

motor::motor(int speed, bool ai1, bool ai2, bool standby)
{
   standBy = standby;
   AI1 = ai1;
   AI2 = ai2;
   pwmValue = speed;
}

void motor::pinmode()
{  
   pinMode(pinAI1, OUTPUT);
   pinMode(pinAI2, OUTPUT);
   pinMode(pinPWM, OUTPUT);
   pinMode(pinStandBy, OUTPUT);
}

void motor::execute()
{
   digitalWrite(pinStandBy, standBy);
   digitalWrite(pinAI1, AI1);
   digitalWrite(pinAI2, AI2);
   analogWrite(pinPWM, pwmValue);
}