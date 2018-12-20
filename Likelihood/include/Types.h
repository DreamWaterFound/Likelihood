#pragma once

#include <Eigen/Core>

//���ݵĳ���
#define DATA_LEN	200

//Ԥ�����ͼ�񳤿�
#define IMG_WIDTH	300
#define IMG_HIGHT	300

//95%ʱ�Ŀ�������
#define SQURE_CONST	5.991

//Բ����
#define M_PI		3.141592654

//����ļ�����Ҫ�Ƕ���һЩ���õĵ����ֱȽ���д������

typedef Eigen::Vector2d					mean2d;
typedef Eigen::Matrix<double, 2, 2>		cov2dMatrix;
typedef Eigen::Matrix<int, DATA_LEN, 2>	sampleSet;



