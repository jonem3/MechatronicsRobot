#include <Arduino.h>
#include <string.h>

class Distanceir 
{
    private :
    
    float distance ; 
    int irDistance ; 
    int Analogpin ; 

    public :

    Distanceir(int pin) ;

    float FindDistance () ;


};