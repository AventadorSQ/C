#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

void ConstTest()
{
	const int num = 20;
	int arr[num];
	int* ptr = &num;

	*ptr = 50;
	printf("%d,*ptr");
}
int main()
{
	ConstTest();
	system("pause");
	return 0;
}

//结论：C++中不能用指针来改变const修饰的常量（C++对const进行了扩充，C语言则可以用指针来改变congst修饰的只读变量）