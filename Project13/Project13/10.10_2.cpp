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
//	s.SetStudentInfo("Peter", "女", 18);
//	s.PrintfStudentInfo();
//
//	Student s2;
//	s2.SetStudentInfo("熊二", "公", 6);
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

//访问限定符
//private（私有）
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
//	s.SetStudentInfo("Peter", "女", 18);
//
//	//解决如何在类外访问一个类的私有成员变量
//	//s.SetStuAge(20);//设置公有方法SetStuAge
//
//	int* p = (int*)((char*)&s + 24);//通过指针方式
//	*p = 20;
//	s.PrintfStudentInfo();
//	//s._age = 20;
//	system("pause");
//	return 0;
//}
////封装：隐藏对象的属性和实现细节，仅对外公开接口和对象进行交互，将数据和操作数据的方法进行有机结合
////在类体外定义成员，需要使用::作用域解析符指明成员属于哪个类域
namespace N1
{
	int a = 10;
}
int a = 20;
void TestFun()
{
	cout << "FunTest()" << endl;
}

//函数重载前提：必须在同一作用域
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