#include"QuickSort.h"

//交换两个数
void SwapNum(int* num1, int* num2)
{
	int temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}

//打印数组
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

//快速排序1基准值在中间
//left 数组第一个元素下标，right数组最后一个元素下标
void QuickSort(int array[], int left, int right)
{
	if (left >= right)
	{
		return;
	}
	///进行一趟排序
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
	//尾递归实现
	QuickSort(array, left, mid - 1);
	QuickSort(array, mid + 1, right);
}

//快速排序2挖坑法基准值在中间
//left 数组第一个元素下标，right数组最后一个元素下标
void QuickSort2(int array[], int left, int right)
{
	if (left >= right)
	{
		return;
	}
	///进行一趟排序
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
	//将基准值放到最后的坑中
	array[i] = mid;
	//尾递归实现
	QuickSort(array, left, i - 1);
	QuickSort(array, i + 1, right);
}

//快速排序3基准值在后边i，j都从头开始
//left 数组第一个元素下标，right数组最后一个元素下标
void QuickSort3(int array[], int left, int right)
{
	if (left >= right)
	{
		return;
	}
	///进行一趟排序
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
	//尾递归实现
	QuickSort(array, left, mid - 1);
	QuickSort(array, mid + 1, right);
}