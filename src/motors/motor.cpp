#include "motor.h"
#include <Arduino.h>

motor::motor(int ai1Pin, int ai2Pin, int pwmPin, int stdbyPin)
{
   pinMode(pinAI1, OUTPUT);
   pinMode(pinAI2, OUTPUT);
   pinMode(pinPWM, OUTPUT);
   pinMode(pinStandBy, OUTPUT);

   standBy = standby;
   AI1 = ai1;
   AI2 = ai2;
   pwmValue = speed;

   digitalWrite(pinStandBy, standBy);
   digitalWrite(pinAI1, AI1);
   digitalWrite(pinAI2, AI2);
   analogWrite(pinPWM, pwmValue);
}

void motor::stop()
{
   pwmValue = 0;
   analogWrite(pinPWM, pwmValue);
}

void motor::reverse()
{
   if (AI1 == true && AI2 == false)
   {
      AI1 = true;
      AI2 = false;
   }
   else
   {
      AI1 = false;
      AI2 = true;
   }

   digitalWrite(pinAI1, AI1);
   digitalWrite(pinAI2, AI2);
}

void motor::adjustspeed(int pwm)
{
   pwmValue = pwm;
   analogWrite(pinPWM, pwmValue);
}
