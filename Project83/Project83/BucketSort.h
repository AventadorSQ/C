#pragma once

#include<stdio.h>
#include<stdlib.h>

typedef int DataType;

//����洢��������
typedef struct BucSort
{
	DataType* arr;
	int capacity;
}BucSort;

//��ʼ��
void InitArray(BucSort* SortArr, DataType arr[], int size);

//Ͱ����
void BucketSort(DataType arr[], int size);

//��ӡ���
void PrintArr(DataType arr[], int size);