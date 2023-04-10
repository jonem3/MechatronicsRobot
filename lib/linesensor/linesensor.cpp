#include <linesensor.h>

void linesensor::getSensors(){
    for (int i = 0; i<6;i++){
        readings[i] = Sensors[i].getReading();
    }
}

int linesensor::getAngle(){
    getSensors();
    int greatestVal = 0;
    int indexVal = -1;
    for (int i = 0; i<6; i++){
        if(readings[i] > 5 && readings[i] > greatestVal){
            greatestVal = readings[i];
            indexVal = i;
        }
    }
    if (indexVal != -1){
        return angle[indexVal];
    }
    else if(lastAngle == -5 || lastAngle == 5){
        return 0;
    }
    else{
        return lastAngle;
    }

}

bool linesensor::lineDetected(){
    int count = 0;
    getSensors();
    for(int i = 0; i<6; i++){
        if(readings[i] > 5){
            count++;
        }
    }
        return count > 3;

}