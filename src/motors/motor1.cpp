#include "motor1.h"
#include <Arduino.h>

motor::motor(int pinai1, int pinai2, int pinpwm, int pinstandby)
{
   pinAI1 = pinai1;
   pinAI2 = pinai2;
   pinPWM = pinpwm;
   pinStandBy = pinstandby;
   
   pinMode(pinAI1, OUTPUT);
   pinMode(pinAI2, OUTPUT);
   pinMode(pinPWM, OUTPUT);
   pinMode(pinStandBy, OUTPUT);

}

void motor::stop()
{
   pwmValue = 0;
   analogWrite(pinPWM, pwmValue);
}

void motor::adjustspeedanddirection(int pwm, bool a, bool b)
{
   AI1 = a;
   AI2 = b;
   pwmValue = pwm;

   digitalWrite(pinStandBy, standBy);
   digitalWrite(pinAI1, AI1);
   digitalWrite(pinAI2, AI2);
   analogWrite(pinPWM, pwmValue);
}
