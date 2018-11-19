#include<stdio.h>
#include<stdlib.h>

int main()
{
	int arr[] = { 4,5,6 };
	int* p = arr;
	printf("%d%d%d\n",*p++,*p++,*p++);
	system("pause");
	return 0;
}