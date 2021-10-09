/*
 * simple code that sends PWM signal to pin D4 and pin D5 reads that signal.
 * open Serial plotter to see the wave and type a number between 0 to 255 to change the duty cycle.
 */
void setup() {
  // put your setup code here, to run once:
  pinMode(D4, INPUT);
  pinMode(D5, OUTPUT);
  Serial.begin(9600);

}
int a=0;
String read="";

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0)
  {
    read = Serial.readString();
    a=read.toInt();
    analogWrite(D5, a);
  }
  int out=digitalRead(D4);
  Serial.print("out: ");
  Serial.println(out);
}
