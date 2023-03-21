#include <Arduino.h>
#include "arm/arm.h"
#include "motion/motion.h"
#include "linesensor/linesensor.h"
#define Kp 5

motion robotMotion;
linesensor theSuperGlueMethod;

void setup()
{
  PCICR |= 0b00000001;
  PCMSK0 |= 0b11110000;  
  robotMotion.setup();
  // Encoders in Digital Pins 10, 11, 12 & 13
  // Encoder A Wire - Green, Encoder B Wire - Blue
  // 10 - B, 11 - A, 12 - B, 13 - A
  Serial.begin(9600);

}


void loop()
{
  // put your main code here, to run repeatedly:
  int speed = 50;
  int error = theSuperGlueMethod.getAngle();  
  int left = speed + (error * Kp);
  int right = speed - (error *Kp);
  robotMotion.setMotorSpeed(left, right);
}


ISR(PCINT0_vect){
  static const int8_t lookup_table[] = {0, -1, 1, 0, 1, 0, 0, -1, -1, 0, 0, 1, 0, 1, -1, 0};
  static const int8_t inv_lookup_table[] = {0, 1, -1, 0, -1, 0, 0, 1, 1, 0, 0, -1, 0, -1, 1, 0};

  static uint8_t enc1_val = 0;
  static uint8_t enc2_val = 0;

  int countL, countR;

  enc1_val = enc1_val << 2;
  enc1_val = enc1_val | ((PINB & 0b00110000) >> 4);
  countL = inv_lookup_table[enc1_val & 0b00001111];

  enc2_val = enc2_val << 2;
  enc2_val = enc2_val | ((PINB & 0b11000000) >> 6);
  countR = lookup_table[enc2_val & 0b00001111];
  //Serial.println("UPDATED");
  robotMotion.setEncoders(countL, countR);
}