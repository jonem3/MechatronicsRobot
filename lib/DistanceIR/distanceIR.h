#include <Arduino.h>
#include <string.h>

class Distanceir 
{
    private :
    
    int distance ; 
    int irDistance ; 
    int Analogpin ; 

    public :

    Distanceir(int pin) ;

    int FindDistance () ;


};