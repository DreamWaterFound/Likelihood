#include "DataReader.h"

DataReader::DataReader(const char* path)
{
	//���ڿ϶���û�д��ļ�
	msFile.open(path);

	//�ж��ļ��Ƿ���ȷ��
	if (isFileOn())
	{
		//�����ȷ������ô�ͳ��Զ�ȡ����
		readSamples();
	}
	//û��ȷ�򿪾Ͳ�����
}

DataReader::DataReader()
{
	;
}

DataReader::~DataReader()
{
	//����������Ҫ�ر��ļ���
	msFile.close();
}

//���ļ�
bool DataReader::openFile(const char* path)
{
	//����Ҫ�жϵ�ǰ�Ƿ��Ѿ�����һ���ļ���
	if (msFile.is_open())
	{
		//��ô�͹ر�
		msFile.close();
	}

	//����û�д��ļ�����ʼ�����ڵ����ָ���ļ�
	msFile.open(path);

	//�鿴�ļ��Ƿ��Ѿ�����
	if (msFile.is_open())
	{
		return readSamples();
	}
	else
	{
		//��ʧ��
		return false;
	}
}

bool DataReader::isFileOn(void)
{
	return msFile.is_open();
}

bool DataReader::getData(sampleSet &sample)
{
	if (isFileOn())
	{
		//�ļ��Ѿ�����˵��������Ч
		sample = mmsample;
		return true;
	}
	else
	{
		return false;
	}
}

bool DataReader::getMean(mean2d &mean)
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

bool DataReader::getCov(cov2dMatrix &cov)
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

//��ȡ���ݵĺ��ĺ���
bool DataReader::readSamples(void)
{
	//��ȡ���ݸ���
	msFile >> mnNum;
	//��ȡ��ֵ
	msFile >> mvMu(0) >> mvMu(1);
	//��ȡЭ�������
	msFile >> mmCov(0, 0) >> mmCov(0, 1) >>
		mmCov(1, 0) >> mmCov(1, 1);
	//��ȡ��������

	
	for (int i = 0; i < mnNum; i++)
	{
		msFile >> mmsample(i, 0) >> mmsample(i, 1);
	}
	
	

	//������֤��
	return true;
}












