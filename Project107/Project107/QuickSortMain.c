#include"QuickSort.h"
#include<stdlib.h>

int main()
{
	int array[] = { 5,6,3,8,9,7};
	int size = sizeof(array) / sizeof(array[0]);
	int left = 0;
	int right = size - 1;
	PrintArray(array, size);
	//进行快速排序
	QuickSort(array, left , right);
	printf("快速排序：");
	PrintArray(array, size);
	system("pause");
	return 0;
}