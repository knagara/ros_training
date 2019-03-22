#include <ros/ros.h>
#include <gtest/gtest.h>
#include <ros_training/AddTwoInts.h>
#include <cstdlib>

TEST(ServiceNodeTest, serviceNodeTest)
{
  int a = 1;
  int b = 2;
  int expect = 3;

  ros::NodeHandle n;
  ros::ServiceClient client = n.serviceClient<ros_training::AddTwoInts>("add_two_ints");

  ros_training::AddTwoInts srv;
  srv.request.a = a;
  srv.request.b = b;

  bool result = client.call(srv);
  ASSERT_TRUE(result);
  EXPECT_EQ(srv.response.sum, expect);
}

int main(int argc, char **argv)
{
  testing::InitGoogleTest(&argc, argv);
  ros::init(argc, argv, "service_node_rostest");

  ros::AsyncSpinner spinner(1);
  spinner.start();
  int result = RUN_ALL_TESTS();
  spinner.stop();
  ros::shutdown();

  return result;
}