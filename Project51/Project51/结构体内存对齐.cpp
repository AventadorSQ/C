#include<stdio.h>
#include<stdlib.h>

typedef struct student1
{
	char name[1020];
	double score;
	int num;
	long long ShenFenZheng;
}student1;

typedef struct student2
{
	char name[1020];
	int num;
	double score;
	long long ShenFenZheng;
}student2;

typedef struct student3
{
	char name[1024];
	double score;
	int num;
	long long ShenFenZheng;
}student3;

typedef struct Stu1
{
	char C1;
	int num1;
	short S1;

}Stu1;

typedef struct student4
{
	Stu1 S1;
	char name[1024];
	int num;
	double score;
	long long ShenFenZheng;
}student4;

typedef struct Stu2
{
	char C1;
	short S1;
	int num1;

}Stu2;


typedef struct Stu3
{
	student2 stu;
	char C1;
	int num1;
	short S1;

}Stu3;

typedef struct Stu4
{
	student2 stu;
	char C1;
	short S1;
	int num1;

}Stu4;

void Mysizeof()
{
	printf("%d\n", sizeof(Stu1));//12
	printf("%d\n", sizeof(Stu2));//8
	printf("%d\n", sizeof(Stu3));//1056
	printf("%d\n", sizeof(Stu4));//1048
	printf("%d\n", sizeof(student1));//1048
	printf("%d\n", sizeof(student2));//1040
	printf("%d\n", sizeof(student3));//1048
	printf("%d\n", sizeof(student4));//1056
}

//存在嵌套结构体，先按
int main()
{
	Mysizeof();
	system("pause");
	return 0;
}
