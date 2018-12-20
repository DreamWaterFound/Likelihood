#pragma once

#include <opencv2\core\core.hpp>
#include <opencv2\highgui\highgui.hpp>
#include <opencv2\imgproc\imgproc.hpp>

#include <Eigen\Core>

#include "Types.h"



using namespace std;

//这个也是个静态类
class DrawEllipse
{
public:
	//static void draw(mean2d mean, cov2dMatrix cov, sampleSet samples);
	static void drawSamples(cv::Mat &src, sampleSet samples);
	//这里其实用指针来传输数据的话，会更加高效
	static cv::Mat createNewImg(void);
	static void drawErrorEllipse(cov2dMatrix cov, mean2d mean, cv::Mat &src);
	

private:
	static cv::RotatedRect computeParams(cov2dMatrix cov, mean2d mean);
	
};