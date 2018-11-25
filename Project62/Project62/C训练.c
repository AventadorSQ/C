#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//void Test()
//{
//	const int num = 20;
//	int* ptr = &num;
//	*ptr = 100;
//	printf("%d %d\n", num,*ptr);
//}

void Test1()
{
	typedef struct stu
	{
		char* name;
		int score;
	}stu;
	stu student, *ptr;

	strcpy(student.name, "Jack");//name指针没有指向一块合法的内存，Jack存向了name指针所存的乱码所指向的内存，而name就无权访问。
	student.score = 90;
}


void Test1_1()
{
	typedef struct stu
	{
		char* name;
		int score;
	}stu;
	stu student, *ptr;

	ptr = (stu*)malloc(sizeof(stu));//为结构体分配一块内存空间
	strcpy(ptr->name, "Jack");//问题与上相同（没有给结构体指针name分配内存空间）
	student.score = 90;
	printf(ptr->name);
	free(ptr);
	ptr=NULL;
}



//解决上述问题
void Test1_2()
{
	typedef struct stu
	{
		char* name;
		int score;
	}stu;
	stu student, *ptr;

	ptr = (stu*)malloc(sizeof(stu));//为结构体分配一块内存空间
	ptr->name = (char*)malloc(sizeof(stu));//为结构体指针name分配一块内存空间
	strcpy(ptr->name, "Jack");
	student.score = 90;
	printf(ptr->name);
	free(ptr);
	free(ptr->name);
}

char* Test2()
{
	char arr[] = "abcdef";
	char* ptr = &arr;
	return ptr;
}
int main()
{
	//Test();
	//Test1();
	//Test1_1();
	//Test1_2();

	char* ptr = Test2();//地址可以找到，但是该地址所指向的内存已经被释放，不在属于ptr指针。（ptr野指针）
	printf("%s\n", ptr);
	system("pause");
	return 0;
}
