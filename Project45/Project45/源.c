////打印100到200之间的素数
//#include<stdio.h>
//#include<stdlib.h>
//#include<math.h>
//
//void prime(int num1,int num2)
//{
//	int i = 0;
//	int j = 0;
//	int gen1 = 0;
//	for (i = num1; i <= num2; i++)
//	{
//		gen1 =(int) sqrt(i);
//		for (j = 2; j <= gen1; j++)
//		{
//			if (i%j == 0)
//			{
//				break;
//			}
//			else if (j == gen1)
//			{
//				printf("%d ", i);
//			}
//		}
//
//	}
//	printf("\n");
//}
//int main()
//{
//	int x = 0;
//	int y = 0;
//	x = 100;
//	y = 200;
//	prime(x, y);
//	system("pause");
//	return 0;
//}

////打印乘法口诀表
//#include<stdio.h>
//#include<stdlib.h>
//
//void mult(int x,int y)
//{
//	int i = 0;
//	int j = 0;
//	for (i = 1; i <= x; i++)
//	{
//		for (j = 1; j <= i; j++)
//		{
//			printf("%d*%d=%2d\t", i, j, i*j);
//		}
//		printf("\n");
//	}
//}
//int main()
//{
//	int x = 9;
//	int y = 9;
//	mult(x,y);
//	system("pause");
//	return 0;
//}

//打印1000到2000之中的闰年
#include<stdio.h>
#include<stdlib.h>

void LeapYear(int x, int y)
{
	int i = 0;
	for (i = x; i <= y; i++)
	{
		if (((i % 4 == 0) && (i % 100 != 0)) || (i % 400 == 0))
		{
			printf("%d\t", i);//打印闰年
		}
	}
}
int main()
{
	int year1 = 0;
	int year2 = 0;
	year1 = 1000;
	year2 = 2000;
	LeapYear(year1, year2);
	system("pause");
	return 0;
}