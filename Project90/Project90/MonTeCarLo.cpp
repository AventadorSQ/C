#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void PrintPi(int Num)
{
	int count = 0;
	for (int i = 1; i < Num; i++)
	{
		double x = (double)((rand() % 1000) + 1) / 1000;
		double y = (double)((rand() % 1000) + 1) / 1000;
		if (x*x + y * y <= 1)
		{
			count++;
		}
	}
	double Pi = ((double)count / Num)*4.0;
	printf("กว=%f\n", Pi);
}

int main()
{
	srand((unsigned int)time(NULL));
	int RandNum = 10000000;
	PrintPi(RandNum);
	system("pause");
	return 0;
}