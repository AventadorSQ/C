#include"QuickSort.h"


void Swap(int* num1, int* num2)
{
	int temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}
//快速排序
//left左下标 right右下标
void QuickSort(int array[], int left, int right)
{
	//有一个数或者没有
	if (right - left <= 0)
	{
		return;
	}

	int i = left;
	int j = right;
	int mid = (j + i) / 2;

	//有两个数
	if (right - left == 1)
	{
		if (array[mid] > array[mid + 1])
		{
			Swap(&array[mid + 1], &array[mid]);
			mid = mid + 1;
			return;
		}
		return;
	}

	//取三数中值为基准
	//至少有三个数
	//3 6 2
	if (right - left > 1)
	{
		if (array[mid] > array[j])
		{
			Swap(&array[mid], &array[j]);
		}
		if (array[i] > array[j])
		{
			Swap(&array[i], &array[j]);
		}
		if (array[i] > array[mid])
		{
			Swap(&array[i], &array[mid]);
		}
	}

	//至少有四个数
	if (right - left > 2)
	{
		//将中值和倒数第二个值进行交换并且记录中值所在下标
		Swap(&array[mid], &array[right - 1]);
		mid = right - 1;

		//最右边j开始的下标
		j = right - 2;
		i = left + 1;
		while (i < j)
		{
			if (array[i] > array[mid])
			{
				while (i < j)
				{
					if (array[j] < array[mid])
					{
						Swap(&array[i], &array[j]);
						break;
					}
					j--;
				}
			}
			if (i < j)
			{
				i++;
			}
		}
		//将一趟交换后第一个大于中值的元素进行交换并且记录中值下标
		if (array[i] > array[mid])
		{
			Swap(&array[i], &array[mid]);
			mid = i;
		}
		QuickSort(array, left, mid - 1);
		QuickSort(array, mid + 1, right);
	}
}


//int Sma = 0;
//int Big = 0;
//while(1)
//{
//	if (array[Big] < array[size - 1])
//	{
//		Big++;
//	}
//	if (array[Sma] > array[size - 1])
//	{
//		Sma++;
//	}
//	Swap(&array[Big], &array[Sma]);
//}

