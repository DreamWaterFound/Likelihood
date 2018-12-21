#include <iostream>

#include "dataReader.h"
#include "Types.h"
#include "Compute.h"
#include "DrawEllipse.h"

using namespace std;


void proc(DataReader &reader,cv::Mat src);

int main(void)
{
	cout << "Hello world!" << endl;

	DataReader reader1(DEFAULT_PATH_1);
	DataReader reader2(DEFAULT_PATH_2);

	if (!reader1.isFileOn())
	{
		cout << "�ļ� " << DEFAULT_PATH_1 << "��ʧ�ܣ�������ֹ��" << endl;
		return 0;
	}
	if (!reader2.isFileOn())
	{
		cout << "�ļ� " << DEFAULT_PATH_2 << "��ʧ�ܣ�������ֹ��" << endl;
		return 0;
	}
	
	cv::Mat img = DrawEllipse::createNewImg();

	//���������ļ�������ȷ�򿪵���
	cout << "�ļ� " << DEFAULT_PATH_1 << "�򿪳ɹ���" << endl;
	proc(reader1, img);
	cout << endl << endl;
	proc(reader2, img);

	cv::imshow("ͼ��", img);
	cv::waitKey(0);

	cout << "������ֹ��" << endl;
}


void proc(DataReader &reader, cv::Mat src)
{
	mean2d mu;
	cov2dMatrix cov;
	sampleSet data;
	reader.getMean(mu);
	reader.getCov(cov);
	reader.getData(data);

	cout << "�����������Ӿ�ֵΪ " << endl << mu << endl;
	cout << "����Э�������Ϊ " << endl << cov << endl;
	cout << "����Ϊ��" << endl;
	cout << data << endl;
	
	mu = Compute::getMean(data);
	cov = Compute::getCov(data);

	cout << "�������������ֵΪ��" << endl <<
	Compute::getMean(data) << endl;

	cout << "����Э�������Ϊ " << endl <<
	Compute::getCov(data) << endl;

	DrawEllipse::drawSamples(src, data);
	DrawEllipse::drawErrorEllipse(cov, mu, src);
}
