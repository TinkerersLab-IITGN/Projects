/*
 * simple code that reads the two signal from encoder using pins D4 and D5
 * open Serial plotter to see the output wave.
 */

void setup() {
  pinMode(D4, INPUT);
  pinMode(D5, INPUT);
  Serial.begin(9600);
  Serial.println();
  delay(1);
}
void loop() {
  int c1=digitalRead(D4);
  int c2=digitalRead(D5)+3;   //added 3 just to seperate both waves on y-axis, to see them clearly.
  
  Serial.print("c1: ");
  Serial.print(c1);
  Serial.print(", c2: ");
  Serial.print(c2);
  Serial.println();
  delay(1);
} 
