#include <distanceIR.h>

Distanceir :: Distanceir (int pin) 
{
    analogPin = pin ; 
}

int Distanceir :: FindDistance (float irDistance)
{
    // Why input irDistance? Just read the ir sensor here like: int irDistance = analogRead(analogPin);
    distance = 0.0001*(irDistance*irDistance) - 0.1439*(irDistance) + 49.9653 ;// replace x as irDistance 
    return distance ;
}

