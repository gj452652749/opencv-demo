#include "stdafx.h"
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>//cvtColor
#include <iostream>
#include <string>
using namespace cv;
using namespace std;
void getHSV() {
	Mat srcImage;
	Mat hsvImage;
	Mat imageROI;
	vector<Mat> channels;
	srcImage = cv::imread("C:\\Users\\gaojun\\Pictures\\Camera Roll\\e.jpg");
	cvtColor(srcImage, hsvImage, CV_RGB2HLS_FULL);
	// 把一个3通道图像转换成3个单通道图像  
	split(hsvImage, channels);//分离色彩通道  
	imageROI = channels.at(0);
	int i = 0;
	for(Mat channel:channels)
		imshow("channel"+(i++), channel);
	vector<Mat> HSchannels;
	Mat hsImage;
	Mat lImage= channels.at(0).clone();
	for (int i = 0; i <= lImage.rows - 1; i++)
		for (int j = 0; j <= lImage.cols - 1; j++)
			lImage.at< uchar >(i, j) = 50;
	HSchannels.push_back(channels.at(0));
	HSchannels.push_back(lImage);
	HSchannels.push_back(channels.at(2));
	merge(channels,hsImage);
	imshow("hsImage", hsImage);
}
int main()
{
	String imageName("C:\\Users\\gaojun\\Pictures\\Camera Roll\\e.jpg"); // by default
	Mat image;
	image = imread(imageName, IMREAD_COLOR); // Read the file
	if (image.empty())                      // Check for invalid input
	{
		cout << "Could not open or find the image" << std::endl;
		return -1;
	}
	//namedWindow("Display window", WINDOW_AUTOSIZE); // Create a window for display.
	getHSV();
	imshow("Display window", image);                // Show our image inside it.
	waitKey(0); // Wait for a keystroke in the window
	return 0;
}