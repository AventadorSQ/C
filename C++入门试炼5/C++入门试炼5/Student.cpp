#define _CRT_SECURE_NO_WARNINGS
#include"Student.h"
#include<iostream>

using namespace std;

//类的定义
void Student::SetStudentInfo(const char* name, const char* gender, const int age)
{
	strcpy(_name, name);
	strcpy(_gender, gender);
	_age = age;
}

void Student::PrintStudentInfo()
{
	cout << _name << " " << _gender << " " << _age << endl;
}

int Student::Getage()
{
	return _age;
}