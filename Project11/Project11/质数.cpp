#include<iostream>
#include<cstdlib>
#include<cmath>

using namespace std;

#define num 100

int main()
{
	int i, j;
	int count=0;
	//int temp = (int)sqrt(num);
	//cout << temp << endl;
	for (i = 1; i <= num; i++)
	{
		int temp = (int)sqrt(i);
		//cout << temp << endl;
		if (i == 2)
		{
			cout << i << " ";
			count++;
		}
		if (i == 3)
		{
			cout << i << " ";
			count++;
		}
		for (j = 2; j <= temp; j++)
		{
			if (i%j == 0)
			{
				//cout << i << endl;
				break;
			}
			else if (j == temp)
			{
				cout << i << " ";
				count++;
			}
			if (count % 10 == 0)
			{
				//换行
				cout << endl;
			}
		}
	}
	system("pause");
	return 0;
}
//#include<iostream>
//#include<cstdlib>
//using namespace std;
////设计程序找到1-100间的质数
//void Prime()
//{
//	int i, j;
//	cout << "1-100间的质数有：";
//	for (i = 1; i <= 100; i++)
//	{
//		if (i == 1)
//		{
//			continue;
//		}
//		if (i == 2)
//		{
//			cout << i << " ";
//			continue;
//		}
//		for (j = 2; j<i; j++)
//		{
//			if (i%j == 0)
//			{
//				break;
//			}
//		}
//		if (j == i)
//		{
//			cout << i << " ";
//		}
//	}
//	cout << endl;
//}