#include"QuickSort.h"
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define SIZE 100000

int main()
{
	srand((unsigned int)time(NULL));
	int array[SIZE];
	for (int i = 0; i < SIZE; i++)
	{
		array[i] = rand() % 100;
	}
	/*int array[] = { 62,62,2,79,0,15};*/
	int Left = 0;
	int Right = sizeof(array) / sizeof(array[0]) - 1;
	printf("Î´ ÅÅ Ðò£º");
	for (int i = 0; i <= Right; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
	QuickSort(array, Left, Right);
	printf("¿ìËÙÅÅÐò£º");
	for (int i = 0; i <= Right; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}