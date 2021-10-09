/* 
 *  This code calculates the anguler velocity using two encoder's output from D1 and D2
 */

#include <Encoder.h>

// Change these two numbers to the pins connected to your encoder.
//   Best Performance: both pins have interrupt capability
//   Good Performance: only the first pin has interrupt capability
//   Low Performance:  neither pin has interrupt capability
Encoder myEnc(D1, D2);
//   avoid using pins with LEDs attached

void setup() {
  Serial.begin(9600);
  Serial.println("Basic Encoder Test:");
}

long oldPosition=0;
long newPosition=0;
long pulse_count=0;
long t0=0;
long t1=0;
int interval=1000;                  //in milliseconds
float omega=0;                      //in rpm
int pulse_count_per_rotation=8350;  //found by rotating the motor at slow speed and counting the total number of pulses for a full roatation.

void loop() {
  t1 = millis();
  newPosition = myEnc.read();
  if (t1-t0>interval)
  {
    pulse_count=newPosition-oldPosition;
    omega=(float)pulse_count/(t1-t0)/pulse_count_per_rotation;
    t0=t1;
    oldPosition=newPosition;
    Serial.println(omega);
  }
}
