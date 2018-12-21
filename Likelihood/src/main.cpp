#include <iostream>

#include "dataReader.h"
#include "Types.h"
#include "Compute.h"
#include "DrawEllipse.h"

using namespace std;


int main(void)
{
	cout << "Hello world!" << endl;

	DataReader reader1(DEFAULT_PATH_1);

	if (!reader1.isFileOn())
	{
		cout << "�ļ� " << DEFAULT_PATH_1 << "��ʧ�ܣ�������ֹ��" << endl;
		return 0;
	}

	
	//���������ļ�������ȷ�򿪵���
	cout << "�ļ� " << DEFAULT_PATH_1 << "�򿪳ɹ���" << endl;
	mean2d mu;
	cov2dMatrix cov;
	sampleSet data;
	reader1.getMean(mu);
	reader1.getCov(cov);
	reader1.getData(data);

	cout << "�����������Ӿ�ֵΪ " << endl << mu << endl;
	cout << "����Э�������Ϊ " << endl << cov << endl;
	//cout << "����Ϊ��" << endl;
	//cout << data << endl;
	/*
	mu = Compute::getMean(data);
	cov = Compute::getCov(data);

	cout << "�������������ֵΪ��" << endl <<
	Compute::getMean(data) << endl;

	cout << "����Э�������Ϊ " << endl <<
	Compute::getCov(data) << endl;

	*/
	DrawEllipse::draw(mu, cov, data);

	cout << "������ֹ��" << endl;
	//TODO 
	



	DrawEllipse::drawErrorEllipse(mu, cov, src);
}
