#include "DataReader.h"

DataReader::DataReader(const char* path)
{
	//现在肯定是没有打开文件
	msFile.open(path);

	//判断文件是否正确打开
	if (isFileOn())
	{
		strcpy((char*)path, msfilename);
		//如果正确打开了那么就尝试读取数据
		readSamples();
	}
	//没正确打开就不管了
}

DataReader::DataReader()
{
	;
}

DataReader::~DataReader()
{
	//析构函数中要关闭文件流
	msFile.close();
}

//打开文件
bool DataReader::openFile(const char* path)
{
	//首先要判断当前是否已经打开了一个文件了
	if (msFile.is_open())
	{
		//那么就关闭
		msFile.close();
	}

	//现在没有打开文件，开始打开现在的这个指定文件
	msFile.open(path);

	//查看文件是否已经打开了
	if (msFile.is_open())
	{
		return readSamples();
	}
	else
	{
		//打开失败
		return false;
	}
}

bool DataReader::isFileOn(void)
{
	return msFile.is_open();
}

bool DataReader::getData(Eigen::Matrix<int, 200, 2> &sample)
{
	if (isFileOn())
	{
		//文件已经打开了说明数据有效
		sample = mmsample;
		return true;
	}
	else
	{
		return false;
	}
}

bool DataReader::getMean(Eigen::Vector2d &mean)
{
	if (isFileOn())
	{
		mean = mvMu;
		return true;
	}
	else
	{
		return false;
	}
}

bool DataReader::getCov(Eigen::Matrix<double, 2, 2> &cov)
{
	if (isFileOn())
	{
		cov = mmCov;
		return true;
	}
	else
	{
		return false;
	}
}

//读取数据的核心函数
bool DataReader::readSamples(void)
{
	//读取数据个数
	msFile >> mnNum;
	//读取均值
	msFile >> mvMu(0) >> mvMu(1);
	//读取协方差矩阵
	msFile >> mmCov(0, 0) >> mmCov(0, 1) >>
		mmCov(1, 0) >> mmCov(1, 1);
	//读取样本数据

	
	for (int i = 0; i < mnNum; i++)
	{
		msFile >> mmsample(i, 0) >> mmsample(i, 1);
	}
	

	//不做验证了
	return true;
}












