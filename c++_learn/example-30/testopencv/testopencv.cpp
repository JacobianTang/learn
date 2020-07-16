
#include "testopencv.h"
#include <opencv2/opencv.hpp>

void test_fun(){
	cv::Mat image(300,400,CV_8UC3);
	cv::imshow("img",image);
	cv::waitKey(0);

}
