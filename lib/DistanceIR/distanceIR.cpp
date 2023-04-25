#include <distanceIR.h>

Distanceir :: Distanceir (int pin) 
{
    analogPin = pin ; 
}

int Distanceir :: FindDistance (float irDistance)
{
    distance = 0.0001*(irDistance*irDistance) - 0.1439*(irDistance) + 49.9653 ;// replace x as irDistance 
    return distance ;
}

