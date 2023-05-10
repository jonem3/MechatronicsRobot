#include <motor.h>

motor::motor(int I1, int I2, int PWM, int StandBy, bool mirror)
{
   pinI1 = I1;
   pinI2 = I2;
   pinPWM = PWM;
   pinStandBy = StandBy;
   isMirrored = mirror;
}

void motor::setup()
{
   pinMode(pinI1, OUTPUT);
   pinMode(pinI2, OUTPUT);
   pinMode(pinPWM, OUTPUT);
   pinMode(pinStandBy, OUTPUT);

   standBy = 0;
   digitalWrite(pinStandBy, standBy);
}

void motor::moveMotor(int velocity)
{
   setDirection(velocity);
   pwmValue = velocityLimiter(velocity);
   standBy = 1;
   digitalWrite(pinStandBy, standBy);
   digitalWrite(pinI1, I1);
   digitalWrite(pinI2, I2);
   analogWrite(pinPWM, pwmValue);
}

int motor::velocityLimiter(int velocity)
{

   if (abs(velocity) > 100)
   {
      return 100;
   }
   else
   {
      return abs(velocity);
   }
}

void motor::setDirection(int velocity)
{
   if ((velocity < 0 && !isMirrored) || (velocity > 0 && isMirrored))
   {
      I1 = 0;
      I2 = 1;
   }
   else
   {
      I1 = 1;
      I2 = 0;
   }
}

void motor::motorStandBy()
{
   I1 = 0;
   I2 = 0;
   standBy = 0;
   pwmValue = 0;
   digitalWrite(pinI1, I1);
   digitalWrite(pinI2, I2);
   analogWrite(pinPWM, pwmValue);
   digitalWrite(pinStandBy, standBy);
}

void motor::brake()
{
   I1 = 1;
   I2 = 1;
   standBy = 1;
   pwmValue = 0;
   digitalWrite(pinI1, I1);
   digitalWrite(pinI2, I2);
   analogWrite(pinPWM, pwmValue);
   digitalWrite(pinStandBy, standBy);
}