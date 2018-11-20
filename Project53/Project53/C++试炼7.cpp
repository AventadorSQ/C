#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdlib>
using namespace std;

class Student
{
public:
	void SetStudentInfo(char* name, char* gender, int age)
	{
		strcpy(_name, name);
		strcpy(_gender, gender);
		_age = age;
	}
	void PrintStudentInfo()
	{
		cout << _name << " " << _gender << " " << endl;
	}
	int GetAge()
	{
		return _age;
	}
public:
	char _name[1024];
	char _gender[1024];
	int _age;
};
class Stu
{};
//小结：
//在C++中，空类在vs上占一个字节
//封装实现：类+访问限定符

//public：在类外可以直接被访问
//protected：
//private：不能在类外直接被访问
//class：默认访问权限private
//struct：默认访问权限public，兼容C语言
//2.类的作用域
//       定义了一个类，定义了一个新的作用
//           1.尽量不要将成员函数参数的名字和类中变量名字一样
//           2.类中的成员变量在类中具有全局的属性
//3.类的实例化
// 类——>实例化——>对象
//4.类对象的模型
//   1.直接看：包含了成员函数+成员变量
//   2.调用：调用同一个成员函数——指针——>存储类中的成员函数
//                                 类中的成员变量
//   3.实际对象模型（类和对象）：包含类中的“成员变量
//   4.如何求一个类的大小？
//    只把类中的成员变量相加（注意内存对齐）
//    空类：主流编译器中，空类大小1，为区分不同的对象
//   5.this指针
//       1.C方式：函数如何操作一个结构体：需要结构体的地址

int main()
{
	Stu s2;
	Student s1;
	cout << sizeof(s2) << endl;
	cout << sizeof(s1) << endl;
	system("pause");
	return 0;
}