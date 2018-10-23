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

//4.
#include<Aventador_SQ.h>

#define SIZE 50
void reverse_string(char* arr)
{
	int right=0;
	while (1)
	{
		if (*arr != '\0')
		{
			right++;
			arr++;
		}
		else
		{
			break;
		}
	}

	if (*arr)
	{
		char c;
		c = arr[0];
		arr[0] = arr[right - 1];
		arr[right - 1] = '\0';
		reverse_string(arr+1);
		arr[right - 1] = c;
	}
	printf("%s", *arr);
}
int main(void)
{
	char arr[20] = { 0 };
	scanf("%s", arr);

	reverse_string(arr);
	//printf("%s\n", *arr);
	system("pause");
	return 0;
}

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

//递归和非递归实现n的阶乘