/*
 * A code that is combination of all the privious codes, including operating motor driver.
 * pins D0 and D1 are internally connected with motordriver's A- and A+ pins.
 * pins D4 and D5 are connected with encoder's c1 and c2.
 * 
 * type values between 0 to 255 on serial monitor and see the angular velocity printed.
 */

#include <Encoder.h>
Encoder myEnc(D4, D5);

#define A0 D0
#define A1 D1
void setup() {
  // put your setup code here, to run once:
  pinMode(A1, OUTPUT);
  pinMode(A0, OUTPUT);
  Serial.begin(9600);

}

long oldPosition=0;
long newPosition=0;
long pulse_count=0;
long t0=0;
long t1=0;
int interval=1000;                  //in milliseconds
float omega=0;                      //in rpm
int pulse_count_per_rotation=8350;  //found by rotating the motor at slow speed and counting the total number of pulses for a full roatation.

int a=0;
String read="";

void loop() {
  digitalWrite(A0,0);
  t1 = millis();
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0)
  {
    read = Serial.readString();
    a=read.toInt();
    analogWrite(A1, a);
  }
  
  newPosition = myEnc.read();

  if (t1-t0>interval)
  {
    pulse_count=newPosition-oldPosition;
    omega=(float)pulse_count/pulse_count_per_rotation*60;
    t0=t1;
    oldPosition=newPosition;
    Serial.print("omega: ");
    Serial.println(omega);
  }
}
