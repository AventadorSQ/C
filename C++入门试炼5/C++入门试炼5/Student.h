#pragma once

//�������
class Student
{
public:
	void SetStudentInfo(const char* name, const char* gender, const int age);
	void PrintStudentInfo();
	int Getage();//��ȡ˽������
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