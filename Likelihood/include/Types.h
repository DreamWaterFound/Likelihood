#pragma once

#include <Eigen/Core>

//数据的长度
#define DATA_LEN	200


//这个文件中主要是定义一些常用的但是又比较难写的类型

typedef Eigen::Vector2d					mean2d;
typedef Eigen::Matrix<double, 2, 2>		cov2dMatrix;
typedef Eigen::Matrix<int, DATA_LEN, 2>	sampleSet;



