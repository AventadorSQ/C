//******************************************
//1.一个数组中只有两个数字是出现一次，
//其他所有数字都出现了两次。
//找出这两个数字，编程实现。
//******************************************
//#include<Aventador_SQ.h>
//
//void IsOneNum(int arr[], int num)
//{
//	int i = 0, j = 0;
//	for (i = 0; i < num; i++)
//	{
//		for (j = 0; j < num; j++)		
//		{
//			if (j != i)
//			{
//				if (arr[i] == arr[j])
//				{
//					break;
//				}
//				else if(arr[i] != arr[j])
//				{
//					if (j == num - 1)
//					{
//						printf("%d ", arr[i]);
//					}
//					if ((i == num - 1) && (j == num - 2))//用于判断最后一个数是否唯一
//					{
//						printf("%d\n", arr[i]);
//					}
//				}
//			}
//		}
//	}
//
//}
//int main()
//{
//	int num = 0;
//	int arr[] = { 2,2,5,6,7,8,9,6,7,9,10};
//	num = sizeof(arr) / sizeof(arr[0]);
//	IsOneNum(arr,num);
//	system("pause");
//	return 0;
//}
//
//************************************************
//2.喝汽水，1瓶汽水1元，2个空瓶可以换一瓶汽水，
//给20元，可以多少汽水。
//编程实现。
//************************************************
//
#include<Aventador_SQ.h>
int SodaWater(int money)
{
	int bottle = money;
	static int yu = 0;
	if ((money % 2 == 0) && (money != 0))
	{
		return bottle + SodaWater(bottle / 2);
	}
	else if ((money % 2 == 1) && (yu == 0))
	{
		yu = 1;
		return bottle + SodaWater(bottle / 2);
	}
	else if ((money % 2 == 1) && (yu == 1))
	{
		yu = 0;
		return bottle + SodaWater(bottle / 2 + 1);
	}
	return bottle;
}
int main()
{
	int Money = 20;
	int num = 0;
	num = SodaWater(Money);
	printf("可以喝%d瓶汽水\n", num);
	system("pause");
	return 0;
}
//
//************************************************
//3.模拟实现strcpy 
//************************************************
//
//#include<Aventador_SQ.h>
//
//void Strcopy(char arr1[], const char arr[])
//{
//	int i = 0;
//	int num=strlen(arr);
//	printf("num=%d\n", num);
//	for (i = 0; i <= num; i++)
//	{
//		arr1[i] = arr[i];
//	}
//}
//int main()
//{
//	char arr[1024];
//	char arr1[1024];
//	printf("请输入将要拷贝的字符串(arr)：");
//	scanf("%s", arr);
//	Strcopy(arr1,arr);
//	printf("字符串arr1=%s\n", arr1);
//	int num1 = strlen(arr1);
//	printf("num1=%d\n", num1);
//	system("pause");
//	return 0;
//}
//
//*****************************************
//4.模拟实现strcat 
//*****************************************
//#include<Aventador_SQ.h>
//void Strcat(char arr1[], const char arr[])
//{
//	int Arr1Len = 0;
//	int ArrLen = 0;
//	Arr1Len = strlen(arr1);
//	printf("%d\n", Arr1Len);
//	ArrLen = strlen(arr);
//	printf("%d\n", ArrLen);
//	for (int i = Arr1Len; i <= ( Arr1Len + ArrLen); i++)
//	{
//		arr1[i] = arr[i - Arr1Len];
//	}
//}
//int main()
//{
//	char arr[1024];
//	char arr1[1024];
//	printf("请输入字符串(arr1)：");
//	scanf("%s%*c", arr1);
//	printf("请输入字符串(arr)：");
//	scanf("%s%*c", arr);
//    Strcat(arr1,arr);
//	printf("拼接到arr1上的字符串arr1=%s\n", arr1);
//	system("pause");
//	return 0;
//}