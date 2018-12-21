#pragma once

#include <Eigen/Core>

//数据的长度
#define DATA_LEN	200

//预定义的图像长宽
#define IMG_WIDTH	300
#define IMG_HIGHT	300

//95%时的卡方常量
#define SQURE_CONST	5.991

//圆周率
#define M_PI		3.141592654

//这个文件中主要是定义一些常用的但是又比较难写的类型

typedef Eigen::Vector2d					mean2d;
typedef Eigen::Matrix<double, 2, 2>		cov2dMatrix;
typedef Eigen::Matrix<int, DATA_LEN, 2>	sampleSet;



