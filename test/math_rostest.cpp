#include <ros/ros.h>
#include <gtest/gtest.h>
#include <ros_training/math_for_test.h>

TEST(MathTest, mathTest){
  int a = 1;
  int b = 2;
  int expect = 3;
  int result = add_for_test(a, b);
  EXPECT_EQ(result, expect);
}

int main(int argc, char** argv)
{
  testing::InitGoogleTest(&argc, argv);
  ros::init(argc, argv, "math_rostest");

  ros::AsyncSpinner spinner(1);
  spinner.start();
  int result = RUN_ALL_TESTS();
  spinner.stop();
  ros::shutdown();

  return result;
}