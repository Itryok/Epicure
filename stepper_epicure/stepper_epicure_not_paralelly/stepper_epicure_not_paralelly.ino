#include <Servo.h>
const int stepPin = 7 ; 
const int dirPin = 5; 
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
  servolin.attach(4);
  servoadj.attach(3);  
}

void loop() {
  digitalWrite(dirPin,HIGH); // Enables the motor to move in a particular direction
      for(int x = 0; x < 800; x++) {
        digitalWrite(stepPin,HIGH); 
        delayMicroseconds(500); 
        digitalWrite(stepPin,LOW); 
        delayMicroseconds(500); 
      }
      delay(5);     
    digitalWrite(dirPin,LOW); //Changes the direction of rotation
    for(int x = 0; x < 800; x++) {
      digitalWrite(stepPin,HIGH);
      delayMicroseconds(500);
      digitalWrite(stepPin,LOW);
      delayMicroseconds(500);
    }         
    delay(5);  
  for (poslin=0; poslin <= 180; poslin += 1) {
      servolin.write(poslin); 
      delay(15);                                            
      }
  for (posadj=0; posadj <= 180; posadj += 1) {
      servolin.write(posadj); 
      delay(15);                                            
      }
}                                        
