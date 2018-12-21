#pragma once

#include <iostream>
#include <fstream>
#include <Eigen/Core>
#include <cstring>

#include "Types.h"


#define DEFAULT_PATH_1 "J:\\sample1.txt"
#define DEFAULT_PATH_2 "J:\\sample2.txt"

/*
#define DEFAULT_PATH_1 "D:\\Code\\Likelihood\\Likelihood\\sample1.txt"
#define DEFAULT_PATH_2 "D:\\Code\\Likelihood\\Likelihood\\sample2.txt"
*/

using namespace std;

//����һ���������ļ��ж�ȡ���ݵ���
class DataReader
{
public:
	DataReader(const char* path);
	DataReader::DataReader();
	~DataReader(void);

	bool openFile(const char* path);
	
public:
	bool getData(sampleSet &sample);
	bool getMean(mean2d &mean);
	bool getCov(cov2dMatrix &cov);

public:
	inline bool isFileOn(void);
	
private:
	//��ȡ���ݣ���ȷ���ļ����ڵ�ʱ�����
	bool readSamples(void);
private:	
	sampleSet	mmsample;	//�������ݵľ���200x2����С�̶�
	int			mnNum;		//���ݸ���
	mean2d		mvMu;		//�����ֵ
	cov2dMatrix mmCov;		//����Э�������

	ifstream	msFile;		//�����ļ���
	
};
