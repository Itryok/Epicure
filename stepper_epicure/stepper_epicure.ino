#include <Servo.h>
const int stepPin = 5; 
const int dirPin = 2; 
//const int enPin = 8;

Servo servolin;
Servo servoadj;

int poslin = 0;
int posadj = 0;

void setup() {
  pinMode(stepPin,OUTPUT); 
  pinMode(dirPin,OUTPUT);
  //pinMode(enPin,OUTPUT);
  //digitalWrite(enPin,LOW);
  servolin.attach(9);
  servoadj.attach(10);  
}

void loop() {
  for (poslin=0; poslin <= 90; poslin += 1) {
      servolin.write(poslin); 
      delay(15);                                            
      }
  digitalWrite(dirPin,HIGH); // Enables the motor to move in a particular direction
      for(int x = 0; x < 800; x++) {
        digitalWrite(stepPin,HIGH); 
        delayMicroseconds(500); 
        digitalWrite(stepPin,LOW); 
        delayMicroseconds(500); 
      }
      delay(5); 
  for (posadj=0; posadj <= 90; posadj += 1) {
      servolin.write(posadj); 
      delay(15);                                            
      }
  for (poslin=90; poslin <= 180; poslin += 1) {
      servolin.write(poslin); 
      delay(15);                                            
      }
  digitalWrite(dirPin,LOW); // Enables the motor to move in a particular direction
      for(int x = 0; x < 800; x++) {
        digitalWrite(stepPin,HIGH); 
        delayMicroseconds(500); 
        digitalWrite(stepPin,LOW); 
        delayMicroseconds(500); 
      }
      delay(5); 
  for (posadj=90; posadj <= 180; posadj += 1) {
      servolin.write(posadj); 
      delay(15);                                            
      }
 
}                              
