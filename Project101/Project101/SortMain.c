#include<stdlib.h>
#include"Sort.h"

int main()
{
	int array[] = { 5,6,1,2,3,7,4,9,6 };
	int k = sizeof(array) / sizeof(array[0]);
	//ShellSort(array, k);
	//SelectSort(array, k);
	HeapSort(array, k);
	system("pause");
	return 0;
}