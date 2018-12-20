#pragma once

#include <iostream>
#include <fstream>
#include <Eigen/Core>
#include <cstring>


#define DEFAULT_PATH_1 "J:\sample1.txt"
#define DEFAULT_PATH_2 "J:\sample2.txt"

using namespace std;

//����һ���������ļ��ж�ȡ���ݵ���
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
	//��ȡ���ݣ���ȷ���ļ����ڵ�ʱ�����
	bool readSamples(void);
private:	
	Eigen::Matrix<int, 200, 2>	mmsample;	//�������ݵľ���200x2����С�̶�
	int mnNum;								//���ݸ���
	Eigen::Vector2d mvMu;					//�����ֵ
	Eigen::Matrix<double, 2, 2> mmCov;		//����Э�������

	ifstream msFile;						//�����ļ���
	char msfilename[1024];						//�洢�ļ�·��




};
