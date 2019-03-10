#include"QuickSort.h"

//����������
void SwapNum(int* num1, int* num2)
{
	int temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}

//��ӡ����
void PrintArray(int array[], int size)
{
	int i = 0;
	while (i < size)
	{
		printf("%d ", array[i]);
		i++;
	}
	printf("\n");
}

//��������1��׼ֵ���м�
//left �����һ��Ԫ���±꣬right�������һ��Ԫ���±�
void QuickSort(int array[], int left, int right)
{
	if (left >= right)
	{
		return;
	}
	///����һ������
	int mid = right;
	int i = left, j = right;
	while (i < j)
	{
		while (i < j&&array[i] <= array[mid])
		{
			i++;
		}
		while (i < j&&array[j] >= array[mid])
		{
			j--;
		}
		SwapNum(&array[i], &array[j]);
	}
	SwapNum(&array[i], &array[mid]);
	mid = i;
	//β�ݹ�ʵ��
	QuickSort(array, left, mid - 1);
	QuickSort(array, mid + 1, right);
}

//��������2�ڿӷ���׼ֵ���м�
//left �����һ��Ԫ���±꣬right�������һ��Ԫ���±�
void QuickSort2(int array[], int left, int right)
{
	if (left >= right)
	{
		return;
	}
	///����һ������
	int mid = array[right];
	int i = left, j = right;
	while (i < j)
	{
		while (i < j&&array[i] <= mid)
		{
			i++;
		}
		array[j] = array[i];
		while (i < j&&array[j] >= mid)
		{
			j--;
		}
		array[i] = array[j];
	}
	//����׼ֵ�ŵ����Ŀ���
	array[i] = mid;
	//β�ݹ�ʵ��
	QuickSort(array, left, i - 1);
	QuickSort(array, i + 1, right);
}

//��������3��׼ֵ�ں��i��j����ͷ��ʼ
//left �����һ��Ԫ���±꣬right�������һ��Ԫ���±�
void QuickSort3(int array[], int left, int right)
{
	if (left >= right)
	{
		return;
	}
	///����һ������
	int mid = right;
	int i = left, j = left;
	for (i = left; i <= right; i++)
	{
		if (array[i] < array[mid])
		{
			SwapNum(&array[i], &array[j]);
			j++;
		}
	}
	SwapNum(&array[j], &array[mid]);
	mid = j;
	//β�ݹ�ʵ��
	QuickSort(array, left, mid - 1);
	QuickSort(array, mid + 1, right);
}