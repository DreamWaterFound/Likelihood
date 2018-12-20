#include "DrawEllipse.h"

#include <cmath>

//为了能够使用Eigen库求解矩阵的特征值和特征向量，需要在自己的程序中
//添加如下的头文件：
#include <Eigen/Dense>
#include <Eigen/EigenValues>

using namespace std;

void DrawEllipse::draw(mean2d mean, cov2dMatrix cov, sampleSet samples)
{
	//绘制误差椭圆

	//首先生成一个全黑色的画布
	cv::Mat img(IMG_WIDTH, IMG_HIGHT,
		CV_32SC3, cv::Scalar(0));
	drawSamples(img, samples);

	cv::imshow("D", img);
	cv::waitKey();

	//先做到这里


	
}

cv::RotatedRect DrawEllipse::computeParams(cov2dMatrix cov,
	mean2d mean)
{
	//这里对于我来说是一个难点，使用Eigen库计算协方差矩阵的特征值和
	//特征向量

	//首先要使用一个解算器.由于我们可以保证协方差矩阵的一些性质，
	//因此它是可逆的，并且数学上能够保证求解出来的特征向量都是实根
	Eigen::EigenSolver<Eigen::Matrix2d> es(cov);

	//特征值（的对角矩阵）
	Eigen::Matrix2d D = es.pseudoEigenvalueMatrix();
	//特征向量
	Eigen::Matrix2d V = es.pseudoEigenvectors();

	//找到最大的特征值

	Eigen::Vector2d lamda;	//存储排序后的特征值
	Eigen::Vector2d v1;		//用不到特征向量v2
	if (D(0, 0) > D(1, 1))
	{		
		lamda(0) = D(0, 0);
		lamda(1) = D(1, 1);

		//假定是按照列存放的
		v1(0) = V(0, 0);
		v1(1) = V(1, 0);
	}
	else
	{
		lamda(1) = D(0, 0);
		lamda(0) = D(1, 1);

		//假定是按照列存放的
		v1(0) = V(0, 1);
		v1(1) = V(1, 1);
	}

	//然后计算参数
	double delta1 = cov(0, 0) > cov(1, 1) ? cov(0, 0) : cov(1, 1);
	double delta2 = cov(0, 0) <= cov(1, 1) ? cov(0, 0) : cov(1, 1);

	//长短轴半长度
	double a = delta1*sqrt(SQURE_CONST*lamda(0));
	double b = delta2*sqrt(SQURE_CONST*lamda(1));

	//以及角度
	double angle = atan2(v1(1),v1(0));

	//角度范围的转换,[0,2pi] => [-pi,pi]
	if (angle < 0)
		angle += 2 * M_PI;

	//从弧度转换成为角度
	angle = 180 * angle / M_PI;

	//接下来要转换成为opencv的格式
	cv::Point2d center;
	center.x = mean(0);
	center.y = mean(1);


	return cv::RotatedRect(
		center,
		cv::Size2f(a,b),
		-angle);
}


void DrawEllipse::drawSamples(cv::Mat &src, sampleSet samples)
{
	//绘制样本点。
	//这里假设已经知道画布为300x300
	//暂时先不考虑颜色的问题，这里就画成黄色
	//static int color=0;

	for (int i = 0; i < DATA_LEN; i++)
	{
		int x = floor(3*samples(i, 0));
		int y = floor(samples(i, 1));
		src.at<int>(x, y) = 255;
		src.at<int>(x+1, y) = 255;
		src.at<int>(x+2, y) = 255;
	}

	return ;
}