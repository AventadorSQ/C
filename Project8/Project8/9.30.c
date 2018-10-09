//#include<Aventador_SQ.h>
//
//void Jieti_Print(char arr[],int len)
//{
//	int i = 0;
//	for (i = 0; i < len; i += 2)
//	{
//		for (int j = 0; j <= i; j++)
//		{
//			printf("%c", arr[j]);
//		}
//		Sleep(1000);
//		printf("\n");
//	}
//	for (i = len-3; i >=0; i-=2)
//	{
//		for (int j = 0; j <= i; j++)
//		{
//			printf("%c", arr[j]);
//		}
//		Sleep(1000);
//		printf("\n");
//	}
//}
//int main()
//{
//	int len = 0;
//	char arr[] = {"*************"};
//	len = strlen(arr);
//	//printf("%d\n", len);
//	Jieti_Print(arr, len);
//	system("pause");
//	return 0;
//}

//#include<Aventador_SQ.h>
//
//void Wat_Flower(int num)
//{
//	int i = 0;
//	int a, b, c;
//	int sum = 0;
//	for (i = 0; i <= num; i++)
//	{
//		a = i % 10;
//		b = i / 10 % 10;
//		c = i / 100;
//		if (i == a * a * a + b * b * b + c * c * c)
//		{
//			printf("%d ", i);
//		}
//	}
//}
//int main()
//{
//	int num = 999;
//	Wat_Flower(num);
//	system("pause");
//	return 0;
//}

#include<Aventador_SQ.h>

int FiveNum(int x)
{
	int num = x;
	int num1 = x;
	int sum = x;
	int i;
	for (i = 0; i < 4; i++)
	{

		num1 = num1 * 10;
		//printf("num1=%d ", num1);
		num = num + num1;
		sum = sum + num;
	}
	return sum;
}
int main()
{
	int sum = 0;
	int x = 0;
	printf("请输入1-9中任意一个数字:");
	scanf("%d", &x);
	sum = FiveNum(x);
	printf("sum=%d\n", sum);
	system("pause");
	return 0;
}