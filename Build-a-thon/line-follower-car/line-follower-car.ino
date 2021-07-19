#include <Servo.h>

Servo s1;
Servo s2;
Servo s3;
Servo s4;

int M_A1 = 2; //motor a = +
int M_A2 = 3; //motor a = -
int M_B1 = 4; //motor b = -
int M_B2 = 5; //motor b = +

int S_A=11;
int S_B=10;

int R_S = A0; //sincer R
int S_S = A1; //sincer S
int L_S = A3; //sincer L

int distance;
long duration;

void setup() 
{
pinMode(M_B1, OUTPUT);
pinMode(M_B2, OUTPUT);
pinMode(M_A1, OUTPUT);
pinMode(M_A2, OUTPUT);



pinMode(L_S, INPUT);
pinMode(S_S, INPUT);
pinMode(R_S, INPUT);

pinMode(6,OUTPUT);//eyes trig
pinMode(7,INPUT);//eyes echo
s1.attach(9);

pinMode(8,OUTPUT);//IR

Serial.begin(9600);

s2.attach(13);
s3.attach(A5);
s4.attach(12);

s1.write(175);
s2.write(0);
s3.write(0);
s4.write(50);

analogWrite(S_A,1000);
analogWrite(S_B,1000);

}
void loop()
{  
if ((digitalRead(L_S) == 0)&&(digitalRead(S_S) == 1)&&(digitalRead(R_S) == 0)){forword();}

if ((digitalRead(L_S) == 1)&&(digitalRead(S_S) == 1)&&(digitalRead(R_S) == 0)){turnLeft();}
if ((digitalRead(L_S) == 1)&&(digitalRead(S_S) == 0)&&(digitalRead(R_S) == 0)){turnLeft();}

if ((digitalRead(L_S) == 0)&&(digitalRead(S_S) == 1)&&(digitalRead(R_S) == 1)){turnRight();}
if ((digitalRead(L_S) == 0)&&(digitalRead(S_S) == 0)&&(digitalRead(R_S) == 1)){turnRight();}

if ((digitalRead(L_S) == 1)&&(digitalRead(S_S) == 1)&&(digitalRead(R_S) == 1)){Stop();
s2.write(90);
  delay(1000);
  s3.write(45);
  s4.write(5);
  delay(5000);
  s3.write(0);
  s4.write(50);
  delay(1000);
  s2.write(0);
}
if ((digitalRead(L_S) == 0)&&(digitalRead(S_S) == 0)&&(digitalRead(R_S) == 0)){Stop();}


digitalWrite(6, LOW);
delay(2);

digitalWrite(6, HIGH);
delay(10);
digitalWrite(6, LOW);
duration = pulseIn(7, HIGH);
distance= duration*0.034/2;
Serial.println(distance);

if (distance<=5)
{
  s1.write(80);
  delay(5000);
  s1.write(175);
}


if (Serial.read()>0)
{
  digitalWrite(8,HIGH);
}

}

void forword(){
digitalWrite(M_A1, LOW);
digitalWrite(M_A2, HIGH);
digitalWrite(M_B1, HIGH);
digitalWrite(M_B2, LOW);
analogWrite(S_A,1000);
analogWrite(S_B,1000);
  
}


void turnRight(){
digitalWrite(M_A1, LOW);
digitalWrite(M_A2, LOW);
digitalWrite(M_B1, HIGH);
digitalWrite(M_B2, LOW); 
analogWrite(S_A,1000);
analogWrite(S_B,1000);
 
}

void turnLeft(){
digitalWrite(M_A1, LOW);
digitalWrite(M_A2, HIGH);
digitalWrite(M_B1, LOW);
digitalWrite(M_B2, LOW);
analogWrite(S_A,1000);
analogWrite(S_B,1000);

}

void Stop(){
digitalWrite(M_A1, LOW);
digitalWrite(M_A2, LOW);
digitalWrite(M_B1, LOW);
digitalWrite(M_B2, LOW);
}
