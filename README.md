# ur5_motion_test
Simple pose publisher with motion planner + Rviz + Gazebo visualization

Ros-melodic

******************
# Install ros-industrial ur_robots
******************

mkdir ur5_ws/src

cd ur5_ws/src

git clone -b melodic-devel https://github.com/ros-industrial/universal_robot.git

cd ~/ur5_ws

rosdep install --from-paths src --ignore-src --rosdistro melodic

catkin build

cd ~/ur5_ws

source devel/setup.bash

******************
# Install MoveIt
******************
sudo apt-get install ros-melodic-moveit

******************
# Run with commands:
******************
catkin build

source devel/setup.bash

roslaunch ur5_test initialize.launch

******************
