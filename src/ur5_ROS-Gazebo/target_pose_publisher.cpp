#include "ros/ros.h"
#include "std_msgs/String.h"
#include "geometry_msgs/Pose.h"

int main(int argc, char **argv)
{
  ros::init(argc, argv, "target_pose_publisher");
  ros::NodeHandle nh;

  ros::Publisher target_pose_publisher = nh.advertise<geometry_msgs::Pose>("target_pose", 1);

  ros::Rate loop_rate(1);

  geometry_msgs::Pose pose;
  pose.position.x = 0.4; //-0.6
  pose.position.y = 0.1; //0.2
  pose.position.z = 0.5;
  pose.orientation.x = 0.49388;
  pose.orientation.y = 0.49072;
  pose.orientation.z = -0.50905;
  pose.orientation.w = 0.50610;

  ROS_INFO("Starting target_pose_publisher");

  while (ros::ok())
  {
    target_pose_publisher.publish(pose);
    ros::spinOnce();
    loop_rate.sleep();
  }
  return 0;
}
