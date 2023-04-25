#include <distanceIR.h>

Distanceir :: Distanceir (int pin) 
{
    Analogpin = pin ; 
}

int Distanceir :: FindDistance ()
{
    int irDistance = analogRead(Analogpin);
    distance = 0.0001*(irDistance*irDistance) - 0.1439*(irDistance) + 49.9653 ;// replace x as irDistance 
    return distance ;
}

