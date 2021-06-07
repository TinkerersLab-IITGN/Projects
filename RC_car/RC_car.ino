char t;
#include <Servo.h>
Servo s1;
Servo s2;
Servo s3;
Servo s4;
int b1=0;
int b2=0;
int b3=0;
int b4=0;

 
void setup() {
pinMode(13,OUTPUT);   //left motors forward
pinMode(12,OUTPUT);   //left motors reverse
pinMode(11,OUTPUT);   //right motors forward
pinMode(10,OUTPUT);   //right motors reverse
  s1.attach(8);
  s2.attach(9);
  s3.attach(6);
  s4.attach(7);
Serial.begin(9600);
 
}
 
void loop() {
if(Serial.available()){
  t = Serial.read();
  Serial.println(t);
}
 
if(t == 'F' ){            //move forward(all motors rotate in forward direction)
  digitalWrite(13,HIGH);
  digitalWrite(11,HIGH);
}
 
else if(t == 'B'){      //move reverse (all motors rotate in reverse direction)
  digitalWrite(12,HIGH);
  digitalWrite(10,HIGH);
}
 
else if(t == 'L'){      //turn right (left side motors rotate in forward direction, right side motors doesn't rotate)
  digitalWrite(11,HIGH);
}
 
else if(t == 'R'){      //turn left (right side motors rotate in forward direction, left side motors doesn't rotate)
  digitalWrite(13,HIGH);
}

else if(t == 'S'){      //STOP (all motors stop)
  digitalWrite(13,LOW);
  digitalWrite(12,LOW);
  digitalWrite(11,LOW);
  digitalWrite(10,LOW);
}
delay(100);

if (Serial.available()>0)
{
char a = Serial.read();
Serial.print(a);
}
char a = Serial.read();
if (a=='a')
{
while(a!='o')
{
  a = Serial.read();

  b1=b1+1;
s1.write(b1);
delay(10);
}
}

if (a=='b')
{
while(a!='o')
{
a = Serial.read();

  b2=b2+1;
s2.write(b2);
delay(10);
}
}

if (a=='c')
{
while(a!='o')
{
  a = Serial.read();

  b3=b3+1;
s3.write(b3);
delay(10);
}
}

if (a=='d')
{
while(a!='o')
{
  a = Serial.read();

  b4=b4+1;
s4.write(b4);
delay(10);
}
}

if (a=='e')
{
while(a!='0')
{
  a = Serial.read();

  b1=b1-1;
s1.write(b1);
delay(10);
}
}

if (a=='f')
{
while(a!='0')
{
  a = Serial.read();

  b2=b2-1;
s2.write(b2);
delay(10);
}
}

if (a=='g')
{
while(a!='0')
{
  a = Serial.read();

  b3=b3-1;
s3.write(b3);
delay(10);
}
}

if (a=='h')
{
while(a!='0')
{
  a = Serial.read();

  b4=b4-1;
s4.write(b4);
delay(10);
}
}
}
