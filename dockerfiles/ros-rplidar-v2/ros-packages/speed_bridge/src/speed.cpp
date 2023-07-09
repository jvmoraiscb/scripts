#include "ros/ros.h"
#include "std_msgs/Float32.h"

#include <sstream>

void speedCallback(const std_msgs::Float32::ConstPtr& msg);

float speed = 0;

int main(int argc, char **argv)
{
  ros::init(argc, argv, "speed_node");

  ros::NodeHandle n;
  ros::Publisher speed_pub = n.advertise<std_msgs::Float32>("speed_pub", 1000);
  ros::Subscriber speed_sub = n.subscribe("speed_sub", 1000, speedCallback);
  ros::Rate loop_rate(10);

  while (ros::ok())
  {
    std_msgs::Float32 msg;
    msg.data = speed;
    speed_pub.publish(msg);
    ros::spinOnce();
    loop_rate.sleep();
  }
  return 0;
}

void speedCallback(const std_msgs::Float32::ConstPtr& msg){
  speed = msg->data;
}