#include "Compute.h"

using namespace std;

mean2d Compute::getMean(const sampleSet samples)
{
	mean2d res;

	//计算均值的过程比较简单，在两个维度上求和然后取均值就可以了
	//注意整数除法的问题
	double sumx = 0, sumy = 0;
	for (int i = 0; i < DATA_LEN; i++)
	{
		sumx += samples(i, 0);
		sumy += samples(i, 1);
	}

	res(0) = sumx / (DATA_LEN*1.0f);
	res(1) = sumy / (DATA_LEN*1.0f);
	
	return res;
}

cov2dMatrix Compute::getCov(
	const sampleSet samples,
	const mean2d mu)
{
	cov2dMatrix cov;

	double mux = mu(0), muy = mu(1);

	double sumDeltaXX = 0, sumDeltaYY = 0, sumDeltaXY = 0;

	for (int i = 0; i < DATA_LEN; i++)
	{
		double x = samples(i, 0);
		double y = samples(i, 1);
		
		sumDeltaXX += (x - mux)*(x - mux);
		sumDeltaXY += (x - mux)*(y - muy);
		sumDeltaYY += (y - mux)*(y - muy);
	}

	cov(0, 0) = sumDeltaXX / ((DATA_LEN-1)*1.0f);
	cov(1, 1) = sumDeltaYY / ((DATA_LEN-1)*1.0f);
	cov(0, 1) =	sumDeltaXY / ((DATA_LEN-1)*1.0f);
	cov(1, 0) = cov(0, 1);

	return cov;
}

cov2dMatrix Compute::getCov(const sampleSet samples)
{
	//再次计算一下均值
	mean2d mu = getMean(samples);

	return getCov(samples, mu);
}