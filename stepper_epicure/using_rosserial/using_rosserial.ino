#if (ARDUINO >= 100)
 #include <Arduino.h>
#else
 #include <WProgram.h>
#endif

#include <Servo.h>
#include <ros.h>
#include <std_msgs/UInt16.h>

ros::NodeHandle  nh;

Servo servolin;
Servo servoadj;

void servo_cb( const std_msgs::UInt16& cmd_msg){
  servo.write(cmd_msg.data); //set servo angle, should be from 0-180   
}

ros::Subscriber<std_msgs::UInt16> sublin("servolin", servo_cb);
ros::Subscriber<std_msgs::UInt16> subadj("servoadj", servo_cb);

const int stepPin = 7 ; 
const int dirPin = 5; 

int poslin = 0;
int posadj = 0;

void setup() {
  pinMode(stepPin,OUTPUT); 
  pinMode(dirPin,OUTPUT);

  nh.initNode();
  nh.subscribe(sublin);
  nh.subscribe(subadj);
  
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
  nh.spinOnce();
  delay(1);
}                                        
