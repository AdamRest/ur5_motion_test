
(cl:in-package :asdf)

(defsystem "ur5_test-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :geometry_msgs-msg
               :std_msgs-msg
)
  :components ((:file "_package")
    (:file "target_pose" :depends-on ("_package_target_pose"))
    (:file "_package_target_pose" :depends-on ("_package"))
  ))