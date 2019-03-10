#include"BubbleSort.h"

//交换两个数
void SwapNum(int* ptr1, int* ptr2)
{
	int temp = *ptr1;
	*ptr1 = *ptr2;
	*ptr2 = temp;
}

//冒泡排序
void BubbleSort(int array[], int size)
{
	//冒泡排序走过的趟数
	for (int i = 0; i < size; i++)
	{
		//每趟排序
		for (int j = 0; j < size - 1; j++)
		{
			//大的数往后走，最终将最大的数排在最后
			if (array[j] > array[j + 1])
			{
				//交换两个数
				SwapNum(&array[j], &array[j + 1]);
			}
		}
	}
}


//打印数组
void PrintArray(int array[], int size)
{
	int i = 0;
	while(i < size)
	{
		printf("%d ", array[i]);
		i++;
	}
	printf("\n");
}

//冒泡排序
void BubbleSortS(int array[], int size)
{
	//冒泡排序走过的趟数
	for (int i = 0; i < size - 1; i++)
	{
		int k = 1;
		//每趟排序
		for (int j = 0; j < size - 1 - i; j++)
		{
			//大的数往后走，最终将最大的数排在最后
			if (array[j] > array[j + 1])
			{
				//交换两个数
				SwapNum(&array[j], &array[j + 1]);
				k = 0;
			}
		}

		//判断是否已经有序
		if (k == 1)
		{
			break;
		}
	}
}