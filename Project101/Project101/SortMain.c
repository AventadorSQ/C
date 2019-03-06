#include<stdlib.h>
#include<time.h>
#include"Sort.h"
#define SIZE 10

int main()
{
	//int array[] = { 5,6,1,2,3,7,4,9,6 };
	//int k = sizeof(array) / sizeof(array[0]);
	////ShellSort(array, k);
	////SelectSort(array, k);
	//HeapSort(array, k);
	srand((unsigned int)time(NULL));
	int array[SIZE];
	for (int i = 0; i < SIZE; i++)
	{
		array[i] = rand() % 100;
	}
	int Left = 0;
	int Right = sizeof(array) / sizeof(array[0]) - 1;
	printf("Î´ ÅÅ Ðò£º");
	for (int i = 0; i <= Right; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
	printf("\n");
	printf("Ï£¶ûÅÅÐò£º");
	SelectMaxMin(array, Right + 1);
	//BubbleSort(array, Right + 1);
	//ShellSort(array, Right + 1);
	printf("\n");
	system("pause");
	return 0;
}