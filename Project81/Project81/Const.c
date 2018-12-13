#include<stdio.h>
#include<stdlib.h>

//void ConstTest()
//{
//	const int a = 10;
//	int b = 1;
//	int arr[a];
//	int array[5];
//}
int main()
{
	const int a = 10;
	int* ptr;
	ptr = &a;
	*ptr = 100;
	printf("a = %d\n", a);
	printf("*ptr = %d", *ptr);
	system("pause");
	return 0;
}