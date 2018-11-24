#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

void Test1()
{
	int num = 9;
	float* pfloat = (float*)&num;
	printf("num=%d\n", num);
	printf("*pfloat=%f\n", *pfloat);

	*pfloat = 9.0;
	printf("num=%d\n", num);
	printf("*pfloat=%f\n", *pfloat);
}

//回调函数是一个通过函数指针调用的函数。如果你把函数的指针（地址）作为参数传递给另一个函数，当这个指针被用来调用其所指向的函数
//回调函数不是由该函数的实现方直接调用，而是在特定的事件或条件发生时由另外一方调用，用于对该事件或条件进行响应
int int_cmp(const void* p1, const void* p2)
{
	return (*(int*)p1 > *(int*)p2);
}
void Test2()
{
	int arr[] = { 1,3,5,7,9,2,4,6,8,0 };
	int i = 0;
	qsort(arr, sizeof(arr) / sizeof(arr[0]), sizeof(int), int_cmp);
	for (i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
int main()
{
	Test1();
	//回调函数
	Test2();
	system("pause");
	return 0;
}