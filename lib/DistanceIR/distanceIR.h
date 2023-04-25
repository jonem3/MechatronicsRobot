#include <Arduino.h>
#include <string.h>

class Distanceir 
{
    private :
    
    int distance ; 
    float irDistance ; 
    int analogPin ; 

    public :

    Distanceir(int pin) ;

    int FindDistance (float irDistance) ; // irDistance will never be a float, analogue pins can only read in integers due to the ADC


};