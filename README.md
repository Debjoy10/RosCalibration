# RosCalibration

Code to use the ROS Calibration package for calibration of camera.

Imgpub.cpp file is for taking camera feed using VideoCapture and publishing it into required ROS-topic for running the ROS-calibration node.

Instructions For Usage:

1. Clone this repo in a ROS workspace

2. Replace the 0 in VideoCapture(0) with the channel in which your camera outputs feed as in VideoCapture(0)/VideoCapture(1) etc in Imgpub.cpp.

3. Run this node in a terminal: rosrun RosCalibration Imgpub

4. In another terminal, run the following command:

For Stereo Camera:

rosrun camera_calibration cameracalibrator.py --approximate 0.1 --size WxH --square A right:=/camera/right/image_raw left:=/camera/left/image_raw right_camera:=/camera/right left_camera:=/camera/left --no-service-check

For Monocular Camera:

rosrun camera_calibration cameracalibrator.py --size WxH --square A image:=/camera/image_raw camera:=/camera --no-service-check

Replace W, H with the dimensions of the checkerboard and A with the size of checkerboard squares in mm.

5. Calibration window will open. Tilt and move your checkerboard until green signal. Voila! You will get the camera matrix and other parameters in your terminal which can also be rendered in a file.

Note:
Make sure to run roscore and source your terminals.
