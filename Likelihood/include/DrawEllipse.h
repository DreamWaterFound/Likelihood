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
	static cv::Mat createNewImg(void);
	static void drawErrorEllipse(cov2dMatrix cov, mean2d mu, cv::Mat src);
	static void drawSamples(cv::Mat &src, sampleSet samples);
private:
	static cv::RotatedRect computeParams(cov2dMatrix cov, mean2d mean);
	
};