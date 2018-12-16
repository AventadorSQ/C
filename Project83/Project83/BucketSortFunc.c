#include"BucketSort.h"

//��ʼ��
void InitArray(BucSort* SortArr, DataType arr[], int size)
{
	DataType Max = arr[0];
	for (int i = 1; i < size; i++)
	{
		if (Max < arr[i])
		{
			Max = arr[i];
		}
	}
	SortArr->capacity = Max + 1;
	SortArr->arr = (DataType*)malloc(sizeof(DataType)*SortArr->capacity);
	for (int i = 0; i < SortArr->capacity; i++)
	{
		SortArr->arr[i] = 0;
	}
}

//Ͱ����
void BucketSort(DataType arr[], int size)
{
	BucSort* SortArr = (BucSort*)malloc(sizeof(BucSort));
	InitArray(SortArr, arr, size);
	for (int i = 0; i < size; i++)
	{
		SortArr->arr[arr[i]] += 1;
	}
	
	int j = 0;
	for (int i = 0; i < SortArr->capacity; i++)
	{
		if (SortArr->arr[i] != 0)
		{
			arr[j] = i;
			j++;
		}
	}
}

//
//��ӡ���
void PrintArr(DataType arr[], int size)
{
	printf("���������С��%d\n", size);
	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}