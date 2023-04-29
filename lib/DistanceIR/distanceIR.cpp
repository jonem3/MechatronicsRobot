#include <distanceIR.h>

Distanceir :: Distanceir (int pin) 
{
    Analogpin = pin ; 
}

int Distanceir :: FindDistance ()
{
    int irDistance = analogRead(Analogpin);
    //distance = 0.0001*(irDistance*irDistance) - 0.1439*(irDistance) + 49.9653 ;// replace x as irDistance 
    distance = 4.6695481E-5*(pow(irDistance, 2)) - 0.074790736*irDistance + 35.3618442; // Correct sensor calibration curve
    return distance ;
}

