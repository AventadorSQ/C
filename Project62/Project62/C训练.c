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

	strcpy(student.name, "Jack");//nameָ��û��ָ��һ��Ϸ����ڴ棬Jack������nameָ�������������ָ����ڴ棬��name����Ȩ���ʡ�
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

	ptr = (stu*)malloc(sizeof(stu));//Ϊ�ṹ�����һ���ڴ�ռ�
	strcpy(ptr->name, "Jack");//����������ͬ��û�и��ṹ��ָ��name�����ڴ�ռ䣩
	student.score = 90;
	printf(ptr->name);
	free(ptr);
	ptr=NULL;
}



//�����������
void Test1_2()
{
	typedef struct stu
	{
		char* name;
		int score;
	}stu;
	stu student, *ptr;

	ptr = (stu*)malloc(sizeof(stu));//Ϊ�ṹ�����һ���ڴ�ռ�
	ptr->name = (char*)malloc(sizeof(stu));//Ϊ�ṹ��ָ��name����һ���ڴ�ռ�
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

	char* ptr = Test2();//��ַ�����ҵ������Ǹõ�ַ��ָ����ڴ��Ѿ����ͷţ���������ptrָ�롣��ptrҰָ�룩
	printf("%s\n", ptr);
	system("pause");
	return 0;
}
