#include "DrawEllipse.h"

#include <cmath>

//Ϊ���ܹ�ʹ��Eigen�������������ֵ��������������Ҫ���Լ��ĳ�����
//������µ�ͷ�ļ���
#include <Eigen/Dense>
#include <Eigen/EigenValues>

#include <iostream>

using namespace std;

cv::Mat DrawEllipse::createNewImg(void)
{
	//��������һ��ȫ��ɫ�Ļ���
	return cv::Mat (IMG_WIDTH, IMG_HIGHT,
		CV_8UC3, cv::Scalar(0));
}

cv::RotatedRect DrawEllipse::computeParams(cov2dMatrix cov,
	mean2d mean)
{
	//�����������˵��һ���ѵ㣬ʹ��Eigen�����Э������������ֵ��
	//��������

	//����Ҫʹ��һ��������.�������ǿ��Ա�֤Э��������һЩ���ʣ�
	//������ǿ���ģ�������ѧ���ܹ���֤��������������������ʵ��
	Eigen::EigenSolver<Eigen::Matrix2d> es(cov);

	//����ֵ���ĶԽǾ���
	Eigen::Matrix2d D = es.pseudoEigenvalueMatrix();
	//��������
	Eigen::Matrix2d V = es.pseudoEigenvectors();

	//�ҵ���������ֵ

	Eigen::Vector2d lamda;	//�洢����������ֵ
	Eigen::Vector2d v1;		//�ò�����������v2
	if (D(0, 0) > D(1, 1))
	{		
		lamda(0) = D(0, 0);
		lamda(1) = D(1, 1);

		//�ٶ��ǰ����д�ŵ�
		v1(0) = V(0, 0);
		v1(1) = V(1, 0);
	}
	else
	{
		lamda(1) = D(0, 0);
		lamda(0) = D(1, 1);

		//�ٶ��ǰ����д�ŵ�
		v1(0) = V(0, 1);
		v1(1) = V(1, 1);
	}

	//Ȼ��������
	double delta1 = cov(0, 0) > cov(1, 1) ? cov(0, 0) : cov(1, 1);
	double delta2 = cov(0, 0) <= cov(1, 1) ? cov(0, 0) : cov(1, 1);

	
	//������볤��
	double a = sqrt(SQURE_CONST*lamda(0));
	double b = sqrt(SQURE_CONST*lamda(1));

	//�Լ��Ƕ�
	double angle = atan2(v1(1),v1(0));

	//�Ƕȷ�Χ��ת��,[0,2pi] => [-pi,pi]
	if (angle < 0)
		angle += 2 * M_PI;

	//�ӻ���ת����Ϊ�Ƕ�
	angle = 180 * angle / M_PI;

	//������Ҫת����Ϊopencv�ĸ�ʽ
	cv::Point2d center;
	center.x = mean(0);
	center.y = mean(1);

	return cv::RotatedRect(
		center,
		cv::Size2d(a,b),
		(float)angle);
}


void DrawEllipse::drawSamples(cv::Mat &src, sampleSet samples)
{
	//���������㡣
	//��������Ѿ�֪������Ϊ300x300
	//��ʱ�Ȳ�������ɫ�����⣬����ͻ��ɻ�ɫ
	//static int color=0;

	for (int i = 0; i < DATA_LEN; i++)
	{
		int x = (int)floor(samples(i, 0));
		//int x = (int)floor(samples(i, 0));
		int y = (int)floor(samples(i, 1));
		src.at<unsigned char>(x, 3*y) = 255;
		src.at<unsigned char>(x, 3*y+1) = 255;
		src.at<unsigned char>(x, 3*y+2) = 255;
	}

	return ;
}
