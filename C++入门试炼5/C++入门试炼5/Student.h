#pragma once

//类的声明
class Student
{
public:
	void SetStudentInfo(const char* name, const char* gender, const int age);
	void PrintStudentInfo();
	int Getage();//获取私有属性
private:
	char _name[1024];
	char _gender[1024];
	int _age;
};

struct Ints
{
	int x;
	int y;
	int z;
};