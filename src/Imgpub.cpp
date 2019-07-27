#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include "zbar.h"
#include <iostream>
#include <iomanip>
#include <ros/ros.h>
#include <image_transport/image_transport.h>
#include <cv_bridge/cv_bridge.h>
#include "std_msgs/String.h"
#include "geometry_msgs/Polygon.h"
#include "geometry_msgs/Point32.h"


using namespace std;
using namespace cv;


cv::Mat frame;
cv_bridge::CvImage img_bridge;
sensor_msgs::Image img_msg;

int main(int argc, char **argv) {
	VideoCapture Video(0);
	int counter = 0;
	
	ros::init(argc, argv, "image_publisher");
	ros::NodeHandle nh;
	image_transport::ImageTransport it(nh);
	image_transport::Publisher pub = it.advertise("/camera/image_raw", 1);
	//image_transport::Publisher pub2 = it.advertise("/camera/camera_info", 1);
	while(1)
	{
		counter++;
		Video >> frame;
		imshow("win", frame);
		waitKey(1);
		std_msgs::Header header;
	    header.seq = counter; 
	    header.stamp = ros::Time::now(); 
	    img_bridge = cv_bridge::CvImage(header, sensor_msgs::image_encodings::RGB8, frame);
	    img_bridge.toImageMsg(img_msg); 
        
		pub.publish(img_msg);
	}
	
	return 0;
}
