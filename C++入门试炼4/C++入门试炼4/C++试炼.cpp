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

 //��Ķ���
 //1.0��������붨��ȫ����������
 //2.0�������->ͷ�ļ�   ��Ķ���->Դ�ļ�
int main()
{
	system("pause");
	return 0;
}