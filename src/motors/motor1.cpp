#include "motor1.h"
#include <Arduino.h>

rigthmotor::rigthmotor(int speed, bool ai1, bool ai2)
{
   pinMode(pinAI1, OUTPUT);
   pinMode(pinAI2, OUTPUT);
   pinMode(pinPWM, OUTPUT);
   pinMode(pinStandBy, OUTPUT);
   Serial.begin(9600);
   standBy = true;
   digitalWrite(pinStandBy, standBy);
   AI1 = true;
   AI2 = false;
   pwmValue = 100;
   AI1 = ai1;
   AI2 = ai2;
   pwmValue = speed;
   digitalWrite(pinAI1, AI1);
   digitalWrite(pinAI2, AI2);
   analogWrite(pinPWM, pwmValue);
}