#pragma once

#include <Eigen/Core>

#include "dataReader.h"

using namespace std;

//��һ����̬��
//��������ľ�ֵ��ʵ�Ǽ��������Σ��������д��Ż�
class Compute
{
public:
	static mean2d getMean(const sampleSet samples);
	static cov2dMatrix getCov(const sampleSet samples,
		const mean2d mu);
	static cov2dMatrix getCov(const sampleSet samples);
};
