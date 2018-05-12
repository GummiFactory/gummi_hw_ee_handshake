
#include <ros.h>
#include <std_msgs/UInt16.h>

ros::NodeHandle nh;

int LHS_pin = 23;
int RHS_pin = 24;
int LHS_reading;
int RHS_reading;

std_msgs::UInt16 msg;
ros::Publisher pub("gummi/palm_touch", &msg);

void setup() {
  pinMode(LHS_pin, INPUT);
  pinMode(RHS_pin, INPUT);

  Serial.begin(57600);

  nh.initNode();
  nh.advertise(pub);  
}

void loop() {
  LHS_reading = analogRead(LHS_pin);
  RHS_reading = analogRead(RHS_pin);

  msg.data = LHS_reading + RHS_reading;
  pub.publish(&msg);

  //Serial.println(FSRReading);
  
  nh.spinOnce(); 
  //delay(150);
}

