#include "lineir.h"

lineir::lineir(int pin, int min, int max){
    irPIN = pin;
    minimumVal = min;
    maximumVal = max;
}

int lineir::mapIR(int rawReading){
    int mappedVal = map(rawReading, minimumVal, maximumVal, 0, 10);
    if (mappedVal < 0){
        mappedVal = 0;
    }
    else if (mappedVal > 10){
        mappedVal = 10;
    }
    return mappedVal;
}

int lineir::getReading(){
    int rawReading = analogRead(irPIN);
    return mapIR(rawReading);
}