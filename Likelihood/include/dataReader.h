#pragma once

#include <iostream>
#include <fstream>
#include <Eigen/Core>
#include <cstring>


#define DEFAULT_PATH_1 "J:\sample1.txt"
#define DEFAULT_PATH_2 "J:\sample2.txt"

using namespace std;

//定义一个从数据文件中读取数据的类
class DataReader
{
public:
	DataReader(const char* path);
	~DataReader(void);

	bool openFile(const char* path);
	
public:
	bool getData(Eigen::Matrix<int, 200, 2> &sample);
	bool getMean(Eigen::Vector2d &mean);
	bool getCov(Eigen::Matrix<double, 2, 2> &cov);

public:
	inline bool isFileOn(void);
	
private:
	//读取数据，当确认文件存在的时候调用
	bool readSamples(void);
private:	
	Eigen::Matrix<int, 200, 2>	mmsample;	//缓存数据的矩阵，200x2，大小固定
	int mnNum;								//数据个数
	Eigen::Vector2d mvMu;					//先验均值
	Eigen::Matrix<double, 2, 2> mmCov;		//先验协方差矩阵

	ifstream msFile;						//输入文件流
	char msfilename[1024];						//存储文件路径




};
