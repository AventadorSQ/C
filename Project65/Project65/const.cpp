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

//���ۣ�C++�в�����ָ�����ı�const���εĳ�����C++��const���������䣬C�����������ָ�����ı�congst���ε�ֻ��������