#include<stdio.h>
#include<stdlib.h>


void Test()
{
	int* ptr = (int*)malloc(0);
	int size1 = sizeof(*ptr);
	int size2 = sizeof(ptr);
	//*ptr = 123;
	//int Size = *ptr;
	//printf("Size = %d\n", Size);
	printf("size1 = %d\n", size1);
	printf("size2 = %d\n", size2);
	size_t size0 =_msize(ptr);
	printf("size0 = %d\n", size0);
	free(ptr);
	ptr = nullptr;
}
int main()
{
	Test();
	system("pause");
	return 0;
}