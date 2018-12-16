#include"BucketSort.h"

int main()
{
	DataType arr[] = { 2,6,88,9999999,99,75,546,986,13486,2021,15,365,1314,520,646,666 };
	int size = sizeof(arr) / sizeof(arr[0]);
	BucketSort(arr,size);
	PrintArr(arr, size);
	system("pause");
	return 0;
}