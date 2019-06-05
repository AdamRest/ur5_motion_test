#!/usr/bin/env python

import rospy, sys, numpy as np
import moveit_commander
from copy import deepcopy
from geometry_msgs.msg import Pose
import moveit_msgs.msg
from std_msgs.msg import Header
from trajectory_msgs.msg import JointTrajectory
from trajectory_msgs.msg import JointTrajectoryPoint

from time import sleep

class ur5_path_planner:
    def __init__(self):
        rospy.init_node("ur5_path_planner", anonymous=False)
        self.pose_sub = rospy.Subscriber('target_pose', Pose, self.tracking_callback, queue_size=1)
        self.default_pose_flag = False
        self.transition_pose = [0,0,0,0,0,0,0]
        self.target_pose = [0,0,0,0,0,0,0]
        self.home_pose = [0,0,0,0,0,0,0]
        self.points=[]
        self.state_change_time = rospy.Time.now()

        rospy.loginfo("Starting node moveit_cartesian_path")

        rospy.on_shutdown(self.cleanup)

        moveit_commander.roscpp_initialize(sys.argv)
        self.arm = moveit_commander.MoveGroupCommander('manipulator')
        self.end_effector_link = self.arm.get_end_effector_link()
        reference_frame = "base_link"
        self.arm.set_pose_reference_frame(reference_frame)
        self.arm.allow_replanning(True)
        self.arm.set_goal_position_tolerance(0.01)
        self.arm.set_goal_orientation_tolerance(0.01)
        self.arm.set_planning_time(0.25)
        self.arm.set_max_acceleration_scaling_factor(.5)
        self.arm.set_max_velocity_scaling_factor(.5)

        self.waypoints= []

        # Specify default (idle) joint states
        self.default_joint_states = self.arm.get_current_joint_values()
        self.default_joint_states[0] = -1.57691
        self.default_joint_states[1] = -1.71667
        self.default_joint_states[2] = 1.79266
        self.default_joint_states[3] = -1.67721
        self.default_joint_states[4] = -1.5705
        self.default_joint_states[5] = 0.0

        self.arm.set_joint_value_target(self.default_joint_states)
        self.arm.set_start_state_to_current_state() # Set the internal state to the current state

        plan = self.arm.plan()
        self.arm.execute(plan)
        self.home_pose = self.arm.get_current_pose()

        self.end_joint_states = deepcopy(self.default_joint_states) # Specify end states (home)
        self.transition_pose = deepcopy(self.default_joint_states) # Transition pose?

    def cleanup(self):
        rospy.loginfo("Stopping the robot")

        # Stop arm movement
        self.arm.stop()

        #Shut down MoveIt cleanly
        rospy.loginfo("Shutting down Moveit!")
        moveit_commander.roscpp_shutdown()
        moveit_commander.os._exit(0)

    def tracking_callback(self, msg):
        self.target_pose = msg
        #rospy.loginfo("\n# Target Pose \n# "+str(self.target_pose))

        self.transition_pose = deepcopy(self.target_pose)
        self.transition_pose.position.x = deepcopy(self.transition_pose.position.x) - 0.1
        #rospy.loginfo("\n# Transition Pose \n# "+str(self.transition_pose))

        if (self.default_pose_flag):
            #rospy.loginfo("\n# Execute to target pose \n# "+str(self.target_pose))
            self.execute()
        else:
            if not self.default_pose_flag:
                rospy.loginfo("\n# Moving Home")
                self.execute()
                self.default_pose_flag = True

    def execute(self):
        if not self.default_pose_flag:
            self.arm.set_start_state_to_current_state()
            self.arm.set_pose_target(self.home_pose)
            plan = self.arm.plan()
            self.arm.execute(plan)
            self.default_pose_flag = True
        else:
            self.arm.set_start_state_to_current_state()
            self.arm.set_pose_target(self.transition_pose)
            plan = self.arm.plan()
            self.arm.execute(plan)

            # self.waypoints= []  # Init waypoints list
            # self.waypoints.append(deepcopy(self.arm.get_current_pose(self.end_effector_link).pose))
            # self.waypoints.append(deepcopy(self.target_pose))
            # plan, fraction = self.arm.compute_cartesian_path(self.waypoints, 0.02, 0.0, True)
            # plan = self.arm.plan()
            # self.arm.execute(plan)

            self.arm.set_start_state_to_current_state()
            self.arm.set_pose_target(self.target_pose)
            plan = self.arm.plan()
            self.arm.execute(plan)

            self.arm.set_start_state_to_current_state()
            self.arm.set_pose_target(self.transition_pose)
            plan = self.arm.plan()
            self.arm.execute(plan)

            # self.waypoints= []  # Init waypoints list
            # self.waypoints.append(deepcopy(self.arm.get_current_pose(self.end_effector_link).pose))
            # self.waypoints.append(deepcopy(self.transition_pose))
            # plan, fraction = self.arm.compute_cartesian_path(self.waypoints, 0.02, 0.0, True)
            # plan = self.arm.plan()
            # self.arm.execute(plan)

            self.default_pose_flag = False


mp=ur5_path_planner()
rospy.spin()
