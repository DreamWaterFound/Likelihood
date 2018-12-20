#include <iostream>
#include "dataReader.h"

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
	Eigen::Vector2d mu;
	Eigen::Matrix<double, 2, 2> cov;
	Eigen::Matrix<int, 200, 2> data;
	reader1.getMean(mu);
	reader1.getCov(cov);
	reader1.getData(data);

	cout << "数据样本均值为 " << endl << mu << endl;
	cout << "协方差矩阵为 " << endl << cov << endl;
	cout << "数据为：" << endl;
	cout << data << endl;
	cout << "程序终止。" << endl;

	

	return 0;
}
