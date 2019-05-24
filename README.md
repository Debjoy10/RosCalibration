# RosCalibration
Code to use ROS Calibration
.cpp file is for publishing camera feed into required topic for calibration
RUN for stereo cam:
rosrun camera_calibration cameracalibrator.py --approximate 0.1 --size 8x6 --square 0.024 right:=/camera/right/image_raw left:=/camera/left/image_raw right_camera:=/camera/right left_camera:=/camera/left --no-service-check
