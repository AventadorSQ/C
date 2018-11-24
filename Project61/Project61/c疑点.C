#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void ZhiZhenQuestion()
{
	char* ptr = "abcdef";
	printf("%d\n", strlen(ptr));
	//printf("%d\n", strlen(*ptr));
	printf("%d\n", sizeof(ptr));
	printf("%d\n", sizeof(*ptr));
}
int main()
{
	ZhiZhenQuestion();
	system("pause");
	return 0;
}