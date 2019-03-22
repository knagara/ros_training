#include <ros/ros.h>
#include <gtest/gtest.h>
#include <ros_training/math_for_test.h>
#include <std_msgs/String.h>

class TestSubscriber
{
  ros::Subscriber sub_;

public:
  bool isReceived;
  std::string receivedText;

  TestSubscriber() : isReceived(false)
  {
    ros::NodeHandle n;
    sub_ = n.subscribe("chatter", 1000, &TestSubscriber::chatterCallback, this);
  }

private:
  void chatterCallback(const std_msgs::String::ConstPtr& msg)
  {
    isReceived = true;
    receivedText = msg->data;
  }
};

TEST(NodeTest, nodeTest){

  TestSubscriber testSubscriber;

  ros::Rate loop_rate(10);
  while(ros::ok() && !testSubscriber.isReceived)
  {
    ros::spinOnce();
    loop_rate.sleep();
  }

  std::string expect = "hello";
  EXPECT_EQ(testSubscriber.receivedText, expect);
}

int main(int argc, char** argv)
{
  testing::InitGoogleTest(&argc, argv);
  ros::init(argc, argv, "talker_node_rostest");
  return RUN_ALL_TESTS();
}