#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;

//class Student
//{
//public:
//	void SetStudentInfo(const char* name, const char* gender, int age)
//	{
//		strcpy(_name, name);
//		strcpy(_gender, gender);
//		_age = age;
//	}
//
//	void PrintfStudentInfo()
//	{
//		cout << _name << " " << _gender << " " << _age << endl;
//	}
//
//	char _name[20];
//	char _gender[3];
//	int _age;
//};
//
//int main()
//{
//	//Student._age = 19;
//
//	Student s;
//	s.SetStudentInfo("Peter", "Ů", 18);
//	s.PrintfStudentInfo();
//
//	Student s2;
//	s2.SetStudentInfo("�ܶ�", "��", 6);
//	s2.PrintfStudentInfo();
//	system("pause");
//	return 0;
//}

//#include "Person.h"
//int main()
//{
//	Person p1;
//	return 0;
//}

//�����޶���
//private��˽�У�
//protected
//public

//class Student
//{
//public:
//	void SetStudentInfo(const char* name, const char* gender, int age)
//	{
//		strcpy(_name, name);
//		strcpy(_gender, gender);
//		_age = age;
//	}
//
//	void PrintfStudentInfo()
//	{
//		cout << _name << " " << _gender << " " << _age << endl;
//	}
//
//	void SetStuAge(int age)
//	{
//		_age = age;
//	}
//private:
//	char _name[20];
//	char _gender[3];
//	int _age;
//};
//
//int main()
//{
//	Student s;
//	s.SetStudentInfo("Peter", "Ů", 18);
//
//	//���������������һ�����˽�г�Ա����
//	//s.SetStuAge(20);//���ù��з���SetStuAge
//
//	int* p = (int*)((char*)&s + 24);//ͨ��ָ�뷽ʽ
//	*p = 20;
//	s.PrintfStudentInfo();
//	//s._age = 20;
//	system("pause");
//	return 0;
//}
////��װ�����ض�������Ժ�ʵ��ϸ�ڣ������⹫���ӿںͶ�����н����������ݺͲ������ݵķ��������л����
////�������ⶨ���Ա����Ҫʹ��::�����������ָ����Ա�����ĸ�����
namespace N1
{
	int a = 10;
}
int a = 20;
void TestFun()
{
	cout << "FunTest()" << endl;
}

//��������ǰ�᣺������ͬһ������
class Test
{
public:
	void SetA(int a)
	{
		_a = a;
	}

	void PrintA()
	{
		cout << _a << endl;
	}
private:
	int _a;
};

int main()
{
	Test S;
	S.SetA(30);
	cout << N1::a << endl;
	cout << a << endl;
	S.PrintA();
	system("pause");
	return 0;
}