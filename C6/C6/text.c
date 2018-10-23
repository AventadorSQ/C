//1.0
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

//1.1
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

////2.计算n^k
//#include<Aventador_SQ.h>
//
//int PowerNum(int x, int y)
//{
//	if (x != 0)
//	{
//		if (y < 0)
//		{
//			printf("输入错误!!!\n");
//			return 0;
//		}
//		if (y == 0)
//		{
//			return 1;
//		}
//		if (y == 1)
//		{
//			return x;
//		}
//		else
//		{
//			return x * PowerNum(x, (y - 1));
//		}
//	}
//}
//int main(void)
//{
//	int n = 0;
//	int k = 0;
//	int num = 0;
//	printf("计算n的k次方\n请分别输入n k:");
//	scanf("%d %d", &n, &k);
//	num=PowerNum(n, k);
//	if (num)
//	{
//		printf("%d\n", num);
//	}
//	//printf("%d\n", num);
//	system("pause");
//	return 0;
//}

////3.
//#include<Aventador_SQ.h>
//int DigitSum(int num)
//{
//	int sum = 0;
//	if (num < 10)
//	{
//		sum = num;
//		return sum;
//	}
//	else
//	{
//		sum = num % 10;
//		return sum + DigitSum(num / 10);
//	}
//}
//
//int main(void)
//{
//	int num = 0;
//	int SumNum = 0;
//	scanf("%d", &num);
//	SumNum = DigitSum(num);
//	printf("SunNum=%d\n", SumNum);
//	system("pause");
//	return 0;
//
//}

////4.递归使得字符串反转
//#include<Aventador_SQ.h>
//
//char reverse_string(char* arr,int num)
//{
//	if (num == 0)
//	{
//		return *arr;
//	}
//	else
//	{
//		if (num > 0)
//		{
//			char ch = arr[0];
//			arr[0] = arr[num - 1];
//			arr[num - 1] = ch;
//			reverse_string(arr + 1, num - 2);
//			return *arr;
//		}
//		else
//		{
//			return *arr;
//		}
//	}
//}
//int main(void)
//{
//	int num = 0;
//	char arr[50] = { '0' };
//	scanf("%s", arr);
//	while (1)
//	{
//		if (arr[num] != '\0')
//		{
//			num++;
//		}
//		else
//		{
//			break;
//		}
//	}
//	reverse_string(arr, num);
//	printf("%s\n",arr);
//	system("pause");
//	return 0;
//}

////5.递归和非递归实现strlen
//
//#include<Aventador_SQ.h>
//int Strlen(char* str)
//{
//	if (*str != '\0')
//	{
//		str++;
//		return 1 + Strlen(str);
//	}
//	else
//	{
//		return 0;
//	}
//}
//
//int main()
//{
//	int num;
//	char* arr = "ABCDEF";
//	//scanf("%s", *arr);
//	num = Strlen(arr);
//	printf("%d\n", num);
//	system("pause");
//	return 0;
//}

////5.2非递归实现strlen
//
//#include<Aventador_SQ.h>
//
//int Strlen(char* arr)
//{
//	int num = 0;
//	while (1)
//	{
//		if (arr[num] != '\0')
//		{
//			num++;
//		}
//		else
//		{
//			return num;
//		}
//	}
//}
//int main(void)
//{
//	char arr[50] = { '0' };
//	scanf("%s", arr);
//	printf("%d\n", Strlen(arr));
//	system("pause");
//	return 0;
//}

////6.1递归和非递归实现n的阶乘
//#include<Aventador_SQ.h>
//
//int DiguiJiecheng(int n)
//{
//	if (n < 0)
//	{
//		printf("输入错误!!!\n");
//		return 0;
//	}
//	else
//	{
//		if (n == 0 || n == 1)
//		{
//			return 1;
//		}
//		else
//		{
//			return n * DiguiJiecheng(n - 1);
//		}
//	}
//}
//
//int NoDiguiJiecheng(int n)
//{
//	int sum = 1;
//	for (; n > 0; n--)
//	{
//		sum = n * sum;
//	}
//	return sum;
//}
//int main()
//{
//	int n = 0;
//	int n1 = 1;
//	int n2 = 1;
//	scanf("%d", &n);
//	n1 = DiguiJiecheng(n);
//	n2 = NoDiguiJiecheng(n);
//	printf("%d %d\n", n1, n2);
//	system("pause");
//	return 0;
//}

//7.递归方式打印整数的每一位
#include<Aventador_SQ.h>
void DiGuiPrint(int n)
{
	if (n < 0)
	{
		printf("输入错误！！！\n");
	}
	else
	{
		if (n < 10)
		{
			printf("%d ", n);
		}
		else
		{
			//printf("%d ", n % 10);
			DiGuiPrint(n / 10);
			printf("%d ", n % 10);

		}
	}
}

int main()
{
	int n = 0;
	scanf("%d", &n);
	DiGuiPrint(n);
	system("pause");
	return 0;
}