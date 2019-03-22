#include "ros/ros.h"
#include "std_msgs/String.h"

int main(int argc, char **argv)
{
  ros::init(argc, argv, "talker");
  ros::NodeHandle n;
  ros::Publisher chatter_pub = n.advertise<std_msgs::String>("chatter", 1000);

  ros::Rate loop_rate(10);
  while(ros::ok())
  {
    std_msgs::String msg;
    msg.data = "hello";
    chatter_pub.publish(msg);
    ROS_INFO("Published hello");
    ros::spinOnce();
    loop_rate.sleep();
  }

  return 0;
}