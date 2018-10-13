//#include<Aventador_SQ.h>
//
//int  Fibonacci(int n)
//{
//	if (1 == n|| 2 == n)
//	{
//		return 1;
//	}
//	else
//	{
//		return Fibonacci(n - 1) + Fibonacci(n - 2);
//	}
//}
//int main()
//{
//	int n = 0;//求取第n个数
//	int	a = 0;//所求的数
//	scanf("%d", &n);
//	a=Fibonacci(n);
//	printf("第%d个数是%d\n",n,a);
//	system("pause");
//	return 0;
//}
//
////#include<Aventador_SQ.h>
////
////int Fibonacci(unsigned int x)
////{
////	if (x <= 0)
////	{
////		return 0;
////	}
////	if (x == 1)
////	{
////		return 1;
////	}
////	else
////	{
////		return Fibonacci(x - 1) + Fibonacci(x - 2);
////	}
////}
////int main()
////{
////	int n = 0;
////	//	scanf("%d", &n);
////	Fibonacci(n);
////	for (; n = n + 1;)
////		printf("第%d个数是%d\n", n, Fibonacci(n));
////	system("pause");
////	return 0;
////}
//
//求该斐波那契的时间复杂度为O(n)=log n

#include<Aventador_SQ.h>

void Fibonacci(int x)
{
	int FFiboZero = 0, FiboZero = 0;
	int FFiboOne = 1, FiboOne = 1;
	int FFiboTwo = 1, FiboTwo = 1;
	int FiboN = 0;

	int i = 0;
	for (i = 2; i <= (x / 2); i++)
	{
		FiboN = FFiboTwo * FiboTwo + FFiboOne * FiboOne;//利用矩阵求出待求得数字
		//进行交换达到移动中间变量
		FFiboZero = FFiboOne;
		FFiboOne = FFiboTwo;
		FFiboTwo = FiboN;
	}
	FiboN = FFiboTwo * FFiboTwo + FFiboOne * FFiboOne;//得到最终的所求取得数
	printf("%d\t%d\n", x, FiboN);
}

void JFibonacci(int x)
{
	int FFiboZero = 0, FiboZero = 0;
	int FFiboOne = 1, FiboOne = 1;
	int FFiboTwo = 1, FiboTwo = 1;
	int FiboN = 0;

	int i = 0;
	for (i = 2; i <= ((x - 1) / 2); i++)
	{
		FiboN = FFiboTwo * FiboTwo + FFiboOne * FiboOne;
		FFiboZero = FFiboOne;
		FFiboOne = FFiboTwo;
		FFiboTwo = FiboN;
	}
	//当所求的位数是奇数时要另外计算第三种情况
	FiboN = FFiboTwo * FFiboTwo + FFiboOne * FFiboOne;
	FFiboTwo = FFiboTwo * FFiboOne + FFiboOne * FFiboZero;
	FiboN = FiboN * FiboTwo + FFiboTwo * FiboOne;
	printf("%d\t%d\n", x, FiboN);
}

int main()
{
	int n = 0;
	printf("n位数:");
	scanf("%d", &n);
	if (n % 2 == 0)
	{
		JFibonacci(n);//n可以被2整除
	}
	else
	{
		Fibonacci(n);//n不能被2整除
	}
	system("pause");
	return 0;
}

//#include<Aventador_SQ.h>
//
//void Fibonacci(int x)
//{
//	if (x < 1)
//	{
//		printf("输入错误!!!\n");
//	}
//	else if (x < 3)
//	{
//		printf("第%d个数是1\n", x );
//	}
//	else
//	{
//		int FiboOne = 1;
//		int FiboTwo = 1;
//		int FiboN = 0;
//		int i=0;
//		for (i = 3; i <= x; i++)
//		{
//			FiboN = FiboOne + FiboTwo;
//			FiboOne = FiboTwo;
//			FiboTwo = FiboN;
//			//printf("%d\t%d\n", i, FiboN);
//		}
//		printf("第%d个数是%d\n", x, FiboN);
//	}
//}
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	Fibonacci(n);
//	system("pause");
//	return 0;
//}
