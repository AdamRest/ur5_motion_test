# CMake generated Testfile for 
# Source directory: /home/amr/ur_ws/src/universal_robot/ur_bringup
# Build directory: /home/amr/ur_ws/build/ur_bringup
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(_ctest_ur_bringup_roslaunch-check_tests_roslaunch_test.xml "/home/amr/ur_ws/build/ur_bringup/catkin_generated/env_cached.sh" "/usr/bin/python2" "/opt/ros/melodic/share/catkin/cmake/test/run_tests.py" "/home/amr/ur_ws/build/ur_bringup/test_results/ur_bringup/roslaunch-check_tests_roslaunch_test.xml.xml" "--return-code" "/usr/bin/cmake -E make_directory /home/amr/ur_ws/build/ur_bringup/test_results/ur_bringup" "/opt/ros/melodic/share/roslaunch/cmake/../scripts/roslaunch-check -o '/home/amr/ur_ws/build/ur_bringup/test_results/ur_bringup/roslaunch-check_tests_roslaunch_test.xml.xml' '/home/amr/ur_ws/src/universal_robot/ur_bringup/tests/roslaunch_test.xml' ")
subdirs("gtest")
