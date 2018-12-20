#pragma once

#include <Eigen/Core>

#include "dataReader.h"

using namespace std;

//是一个静态类
//不过这里的均值其实是计算了两次，计算量有待优化
class Compute
{
public:
	static mean2d getMean(const sampleSet samples);
	static cov2dMatrix getCov(const sampleSet samples,
		const mean2d mu);
	static cov2dMatrix getCov(const sampleSet samples);
};
