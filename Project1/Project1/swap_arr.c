//***********************************************************************//
//*******1. 将数组A中的内容和数组B中的内容进行交换。（数组一样大）*******//
//***********************************************************************//
//#include<stdio.h>
//#include<stdlib.h>
#include<Aventador_SQ.h>
#define ROW 10

//void swap(int arr1[], int arr2[])//(整形数组测试版)
//{
//	int arr[ROW] = { 0 };
//	int i = 0;
//	for (i = 0; i < ROW; i++)//将第一个数组赋给临时数组
//	{
//		arr[i] = arr1[i];
//	}
//	for (i = 0; i < ROW; i++)//将第二个数组赋给第一个数组
//	{
//		arr1[i] = arr2[i];
//	}
//	for (i = 0; i < ROW; i++)//将存储在临时数组的第一个数组赋给第二个数组，完成交换
//	{
//		arr2[i] = arr[i];
//	}
//	printf("打印arr1数组：");
//	for (i = 0; i < ROW; i++)
//	{
//		printf("arr1[%d]=%d ", i, arr1[i]);
//	}
//	printf("\n");
//	for (i = 0; i < ROW; i++)
//	{
//		printf("arr2[%d]=%d ", i, arr2[i]);
//	}
//	printf("\n");
//}
void swap(char arr1[], char arr2[])//字符数组
{
	char arr[ROW] = { 0 };
	int i = 0;
	for (i = 0; i < ROW; i++)//将第一个数组赋给临时数组
	{
		arr[i] = arr1[i];
	}
	for (i = 0; i < ROW; i++)//将第二个数组赋给第一个数组
	{
		arr1[i] = arr2[i];
	}
	for (i = 0; i < ROW; i++)//将存储在临时数组的第一个数组赋给第二个数组，完成交换
	{
		arr2[i] = arr[i];
	}
	printf("打印arr1数组：");
	for (i = 0; i < ROW; i++)
	{
		printf("arr1[%d]=%c ", i, arr1[i]);
	}
	printf("\n");
	for (i = 0; i < ROW; i++)
	{
		printf("arr2[%d]=%c ", i, arr2[i]);
	}
	printf("\n");
}

int main()
{
	int hang = 0;
	char arr1[ROW] = { 0 };
	char arr2[ROW] = { 0 };
	printf("请输入第一个数组%d个字符。\n",ROW);
	for (hang = 0; hang < ROW; hang++)
	{
		printf("请输入arr1[%d]:",hang);
		//fflush(stdout);
		scanf("%c%*c", &arr1[hang]);
	}

	printf("请输入第二个数组%d个字符。\n",ROW);
	for (hang = 0; hang < ROW; hang++)
	{
		printf("请输入arr2[%d]:",hang);
		scanf("%c%*c",&arr2[hang]);
	}
	swap(arr1, arr2);//交换两个数组
	system("pause");
	return 0;
}
//int main()
//{
//	int hang = 0;
//	int arr1[ROW] = { 0 };
//	int arr2[ROW] = { 0 };
//	printf("请输入第一个数组%d个字符。\n", ROW);
//	for (hang = 0; hang < ROW; hang++)
//	{
//		printf("请输入arr1[%d]:", hang);
//		scanf("%d", &arr1[hang]);
//	}
//
//	printf("请输入第二个数组%d个字符。\n", ROW);
//	for (hang = 0; hang < ROW; hang++)
//	{
//		printf("请输入arr2[%d]:", hang);
//		scanf("%d", &arr2[hang]);
//	}
//	swap(arr1, arr2);//交换两个数组
//	system("pause");
//	return 0;
//}