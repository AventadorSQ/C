#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>

using namespace std;

 class Student 
{
	void SetStudentInfo(char* name, char* gender, int age)
	{
		strcpy(_name, name);
		strcpy(_gender, gender);
		_age = age;
	}
	char _name[1024];
	char _gender[1024];
	int _age;
}Stu;

 //类的定义
 //1.0类的声明与定义全部放在类中
 //2.0类的声明->头文件   类的定义->源文件
int main()
{
	system("pause");
	return 0;
}