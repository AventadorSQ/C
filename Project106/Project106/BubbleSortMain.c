#include"BubbleSort.h"
#include<stdlib.h>

int main()
{
	int array[] = { 5,6,3,8,9,7,3 };
	//size指数组的实际长度
	int size = sizeof(array) / sizeof(array[0]);
	//调用打印函数先将未排序数组打印一遍
	PrintArray(array, size);
	//进行冒泡排序
	BubbleSortS(array, size);
	//将排序的结果打印出来
	printf("冒泡排序：");
	PrintArray(array, size);
	system("pause");
	return 0;
}