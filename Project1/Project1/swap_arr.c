//***********************************************************************//
//*******1. ������A�е����ݺ�����B�е����ݽ��н�����������һ����*******//
//***********************************************************************//
//#include<stdio.h>
//#include<stdlib.h>
#include<Aventador_SQ.h>
#define ROW 10

//void swap(int arr1[], int arr2[])//(����������԰�)
//{
//	int arr[ROW] = { 0 };
//	int i = 0;
//	for (i = 0; i < ROW; i++)//����һ�����鸳����ʱ����
//	{
//		arr[i] = arr1[i];
//	}
//	for (i = 0; i < ROW; i++)//���ڶ������鸳����һ������
//	{
//		arr1[i] = arr2[i];
//	}
//	for (i = 0; i < ROW; i++)//���洢����ʱ����ĵ�һ�����鸳���ڶ������飬��ɽ���
//	{
//		arr2[i] = arr[i];
//	}
//	printf("��ӡarr1���飺");
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
void swap(char arr1[], char arr2[])//�ַ�����
{
	char arr[ROW] = { 0 };
	int i = 0;
	for (i = 0; i < ROW; i++)//����һ�����鸳����ʱ����
	{
		arr[i] = arr1[i];
	}
	for (i = 0; i < ROW; i++)//���ڶ������鸳����һ������
	{
		arr1[i] = arr2[i];
	}
	for (i = 0; i < ROW; i++)//���洢����ʱ����ĵ�һ�����鸳���ڶ������飬��ɽ���
	{
		arr2[i] = arr[i];
	}
	printf("��ӡarr1���飺");
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
	printf("�������һ������%d���ַ���\n",ROW);
	for (hang = 0; hang < ROW; hang++)
	{
		printf("������arr1[%d]:",hang);
		//fflush(stdout);
		scanf("%c%*c", &arr1[hang]);
	}

	printf("������ڶ�������%d���ַ���\n",ROW);
	for (hang = 0; hang < ROW; hang++)
	{
		printf("������arr2[%d]:",hang);
		scanf("%c%*c",&arr2[hang]);
	}
	swap(arr1, arr2);//������������
	system("pause");
	return 0;
}
//int main()
//{
//	int hang = 0;
//	int arr1[ROW] = { 0 };
//	int arr2[ROW] = { 0 };
//	printf("�������һ������%d���ַ���\n", ROW);
//	for (hang = 0; hang < ROW; hang++)
//	{
//		printf("������arr1[%d]:", hang);
//		scanf("%d", &arr1[hang]);
//	}
//
//	printf("������ڶ�������%d���ַ���\n", ROW);
//	for (hang = 0; hang < ROW; hang++)
//	{
//		printf("������arr2[%d]:", hang);
//		scanf("%d", &arr2[hang]);
//	}
//	swap(arr1, arr2);//������������
//	system("pause");
//	return 0;
//}