#include <Arduino.h>
#include "../lineir/lineir.h"

/*
L SENSOR:
L 408 508
C 368 482
R 495 603

R SENSOR:
L 490 600
C 359 473
R 422 523

5, 10, 17
*/


class linesensor
{
private:
    lineir Sensors[6] = {lineir(2, 408, 508),
                         lineir(1, 368, 482),
                         lineir(0, 495, 603),
                         lineir(5, 490, 600),
                         lineir(4, 359, 473),
                         lineir(3, 422, 523)};

    int readings[6];
    int angle[6] = {-17, -10, -5, 5, 10, 17};
    int lastAngle = 0;
    void getSensors();
public:
    
    int getAngle();
};