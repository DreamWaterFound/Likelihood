#include <iostream>
#include "dataReader.h"

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
	Eigen::Vector2d mu;
	Eigen::Matrix<double, 2, 2> cov;
	Eigen::Matrix<int, 200, 2> data;
	reader1.getMean(mu);
	reader1.getCov(cov);
	reader1.getData(data);

	cout << "����������ֵΪ " << endl << mu << endl;
	cout << "Э�������Ϊ " << endl << cov << endl;
	cout << "����Ϊ��" << endl;
	cout << data << endl;
	cout << "������ֹ��" << endl;

	

	return 0;
}
