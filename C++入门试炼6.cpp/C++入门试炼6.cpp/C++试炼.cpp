#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

//编译器认识类
//1. 识别类名
//2. 识别类的成员变量
//3. 识别类的成员函数并对成员函数进行改写（成员函数参数有一个隐藏参数是相应类变量的地址(Student* const this)）
//


//类中的成员变量在类中具有全局属性
//想在类外使用类中的私有变量可以在类中使用公有的方法
//类对象模型：类对象在内存中的布局形式
//类大小的计算方式：将类中的成员变量相加+内存对齐

class Test
{
public:
	void Set_t(int t);
private:
	int _t;
};

class Test1
{
public:
	void SetNum()
	{
		cout << "TestSetNum()" << endl;
	}
};
class Test3
{};

void Test::Set_t(int t)
{
	_t = t;
}
int _a = 6;

int main()
{
	//int _t = 5;
	//cout << ::_a << endl;//作用限定符
	//在C++中，一般空类的大小占一个字节

	//内存对齐默认值
	//vs： 8
	//Linux：4

	cout << sizeof(Test) << endl;//4
	cout << sizeof(Test1) << endl;//1
	cout << sizeof(Test3) << endl;//1
	system("pause");
	return 0;
}
