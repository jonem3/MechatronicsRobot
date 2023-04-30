#include <Arduino.h>
#include <motion.h>
#include <linesensor.h>
#include <arm.h>
#include <distanceIR.h>
#define Kp 0.003 // Proportional Constant for line following

motion robotMotion; // Instantiate a motion object
linesensor lineDetection; // Instantiate a linesensor object
arm roboticArm;
Distanceir left = Distanceir(9);
Distanceir right = Distanceir(8);

float currentSetting = 0; // Initiate floating point value
void task2();

void setup()
{
  PCICR |= 0b00000001; // Interrupt pin setup
  PCMSK0 |= 0b11110000; // Interrupt pin setup
  robotMotion.setup(); // Run setup method of motion object (Arduino does not allow running pinMode etc. outside of setup or loop unless called from within)
  roboticArm.setup();
  // Encoders in Digital Pins 10, 11, 12 & 13
  // Encoder A Wire - Green, Encoder B Wire - Blue
  // 10 - B, 11 - A, 12 - B, 13 - A
  Serial.begin(9600);
  // robotMotion.rotateAngle(90);
  // task2();
  //roboticArm.drawLine();
}

void followLine()
{
  float speed = 0.2; // Speed in ms^-1
  float error = lineDetection.getAngle(); // Retrieve current angle of robot relative to the line (and because Matt is an idiot it's backwards..., but he fixed it)
  // float error = 0;
  float left = speed + (error * Kp); // Here is where it's fixed, its a proportional controller but backwards
  float right = speed - (error * Kp); // And here

  robotMotion.setMotorSpeed(left, right); // Set speed of motors
  
}

void loop()
{
  // put your main code here, to run repeatedly: How about no
  Serial.print(left.FindDistance());
  Serial.print(" ");
  Serial.println(right.FindDistance());
  delay(100);
  //Serial.println(right.FindDistance());
  robotMotion.setMotorSpeed(0, 0); // Robot goes nowhere
}

void task3b(){
  robotMotion.rotateAngle(-90); // Spin the robot by 90 degrees to the ccw
  
  do{
    robotMotion.setMotorSpeed(0.2, 0.2); // Vroom vroom, is a PI loop so needs to keep being called
  }while(!lineDetection.lineDetected()); // Keep zooming until the line is detected
  delay(800); // Keep going a little futher

  robotMotion.setMotorSpeed(0, 0); // Stop
  robotMotion.rotateAngle(-90); // Spin again

  float startDistance = robotMotion.getDistanceTravelled(); // reset distance start point.
  float currentDistanceElapsed = 0; // reset travelled distance

  do
  {
    followLine(); // Follow line controller (See above)
    currentDistanceElapsed = robotMotion.getDistanceTravelled() - startDistance; // Find out how far along the line has been traversed
  } while (currentDistanceElapsed < 800); // Should only go 80cm


  int meanDistance;
  int leftDistance;
  int rightDistance;
  do{
    followLine();
    leftDistance = left.FindDistance();
    rightDistance = right.FindDistance();

    meanDistance = (leftDistance + rightDistance)/2;
  }while(meanDistance > 10); // We need to get an accurate value for this

  roboticArm.drawLine();


  
  // Spinny stuff goes here - Drawing horiz line - Monday Meeting

  robotMotion.setMotorSpeed(0, 0); // Stop
  robotMotion.rotateAngle(-90); // Lets try spinning, that's a good trick

  do{
    robotMotion.setMotorSpeed(0.2, 0.2);
  }while(!lineDetection.lineDetected());
  delay(800);

  robotMotion.setMotorSpeed(0, 0);
  robotMotion.rotateAngle(-90);

  do{
    followLine();
  }while(!lineDetection.lineDetected());
  robotMotion.setMotorSpeed(0, 0);
}

void task2()
{
  robotMotion.rotateAngle(-90); // Spin the robot by 90 degrees to the ccw
  
  do{
    robotMotion.setMotorSpeed(0.2, 0.2); // Vroom vroom, is a PI loop so needs to keep being called
  }while(!lineDetection.lineDetected()); // Keep zooming until the line is detected
  delay(800); // Keep going a little futher

  robotMotion.setMotorSpeed(0, 0); // Stop
  robotMotion.rotateAngle(-90); // Spin again

  float startDistance = robotMotion.getDistanceTravelled(); // reset distance start point.
  float currentDistanceElapsed = 0; // reset travelled distance

  do
  {
    followLine(); // Follow line controller (See above)
    currentDistanceElapsed = robotMotion.getDistanceTravelled() - startDistance; // Find out how far along the line has been traversed
  } while (currentDistanceElapsed < 800); // Should only go 80cm
  robotMotion.setMotorSpeed(0, 0); // Stop
  robotMotion.rotateAngle(-90); // Lets try spinning, that's a good trick

  do{
    robotMotion.setMotorSpeed(0.2, 0.2);
  }while(!lineDetection.lineDetected());
  delay(800);

  robotMotion.setMotorSpeed(0, 0);
  robotMotion.rotateAngle(-90);

  do{
    followLine();
  }while(!lineDetection.lineDetected());
  robotMotion.setMotorSpeed(0, 0);

}

ISR(PCINT0_vect)
{
  /*
  This function is the Interrupt Service Routine,
  it is run whenever one of the specified interrupt pins changes
  */
  static const int8_t lookup_table[] = {0, -1, 1, 0, 1, 0, 0, -1, -1, 0, 0, 1, 0, 1, -1, 0};
  static const int8_t inv_lookup_table[] = {0, 1, -1, 0, -1, 0, 0, 1, 1, 0, 0, -1, 0, -1, 1, 0};

  static uint8_t enc1_val = 0;
  static uint8_t enc2_val = 0;

  int countL, countR;

  enc1_val = enc1_val << 2; // Bit Shift by 2 to the right
  enc1_val = enc1_val | ((PINB & 0b00110000) >> 4); // Bit shift PINB by 4 (& is AND gate to mask all irrelevant values)
  countL = inv_lookup_table[enc1_val & 0b00001111];

  enc2_val = enc2_val << 2; // Bit Shift by 2 to the right
  enc2_val = enc2_val | ((PINB & 0b11000000) >> 6); // Bit shift PINB by 6 (& is AND gate to mask all irrelevant values)
  countR = lookup_table[enc2_val & 0b00001111];
  // Serial.println("UPDATED");
  robotMotion.setEncoders(countL, countR);
}