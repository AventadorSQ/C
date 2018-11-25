#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//解决上述问题
void Test1_2()
{
	typedef struct stu
	{
		char* name;
		int score;
	}stu;
	stu *ptr;

	ptr = (stu*)malloc(sizeof(stu));//为结构体分配一块内存空间
	ptr->name = (char*)malloc(sizeof(stu));//为结构体指针name分配一块内存空间
	strcpy(ptr->name, "Jack");
	printf(ptr->name);
	free(ptr->name);
	ptr->name = NULL;
	free(ptr);
	ptr = NULL;
}

int main()
{
	Test1_2();
	system("pause");
	return 0;
}

//void Test1()
//{
//	typedef struct stu
//	{
//		char* name;
//		int score;
//	}stu;
//	stu student, *ptr;
//
//	strcpy(student.name, "Jack");
//	student.score = 90;
//}
//
//void Test()
//{
//	char* ptr = (char*)malloc(1024);
//	strcpy(ptr, "hello C");
//	free(ptr);
//
//	if (NULL != ptr)
//	{
//		strcpy(ptr, "C NiuBi");
//	}
//	printf(ptr);
//}