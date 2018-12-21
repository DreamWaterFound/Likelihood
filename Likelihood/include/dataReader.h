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

//定义一个从数据文件中读取数据的类
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
	//读取数据，当确认文件存在的时候调用
	bool readSamples(void);
private:	
	sampleSet	mmsample;	//缓存数据的矩阵，200x2，大小固定
	int			mnNum;		//数据个数
	mean2d		mvMu;		//先验均值
	cov2dMatrix mmCov;		//先验协方差矩阵

	ifstream	msFile;		//输入文件流
	
};
