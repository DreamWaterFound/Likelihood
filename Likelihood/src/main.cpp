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
		cout << "文件 " << DEFAULT_PATH_1 << "打开失败，程序终止。" << endl;
		return 0;
	}

	
	//现在数据文件都是正确打开的了
	cout << "文件 " << DEFAULT_PATH_1 << "打开成功。" << endl;
	mean2d mu;
	cov2dMatrix cov;
	sampleSet data;
	reader1.getMean(mu);
	reader1.getCov(cov);
	reader1.getData(data);

	cout << "数据样本种子均值为 " << endl << mu << endl;
	cout << "种子协方差矩阵为 " << endl << cov << endl;
	//cout << "数据为：" << endl;
	//cout << data << endl;
	/*
	mu = Compute::getMean(data);
	cov = Compute::getCov(data);

	cout << "数据样本计算均值为：" << endl <<
	Compute::getMean(data) << endl;

	cout << "计算协方差矩阵为 " << endl <<
	Compute::getCov(data) << endl;

	*/
	DrawEllipse::draw(mu, cov, data);

	cout << "程序终止。" << endl;
	//TODO 
	



	DrawEllipse::drawErrorEllipse(mu, cov, src);
}
