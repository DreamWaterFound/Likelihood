#pragma once

#include <Eigen/Core>

//���ݵĳ���
#define DATA_LEN	200


//����ļ�����Ҫ�Ƕ���һЩ���õĵ����ֱȽ���д������

typedef Eigen::Vector2d					mean2d;
typedef Eigen::Matrix<double, 2, 2>		cov2dMatrix;
typedef Eigen::Matrix<int, DATA_LEN, 2>	sampleSet;



