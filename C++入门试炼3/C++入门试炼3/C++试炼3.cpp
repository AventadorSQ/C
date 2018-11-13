#include<iostream>

using namespace std;

//宏优点：1.增强代码的复用性
//        2.提高性能
//缺点：1.不方便调试宏。（预处理已替换）
//      2.导致代码可读性差，可维护性差，容易误用
//      3.没有类型安全的检查
//C++中可以替代宏的方法：
//                      1.常量定义 换用const
//                                              const修饰---常量&具有宏的属性---替换(C++)

//                      2.函数定义 换用内联函数

//宏定义（不安全）
//预处理阶段

#define MAX(a,b) ((a)>(b) ? (a):(b))

void Hong_Const()
{
	const int a = 10;
	//int arr[a];
	int* p = (int*)&a;
	*p = 110;
	cout << a << endl;//a是被替换成10
	cout << &a << endl;
	cout << *p << endl;
	cout << &*p << endl;
}
//编译阶段
//内联函数（加inline）建议编译器优化该函数
//加inline不一定是内联函数
//当该函数体有循环或递归编译器就会忽略关键字
inline int Add(int left, int right)
{
	return left + right;
}

//auto  C++11
//auto 定义的变量必须初始化
//     自然也不能当函数参数类型来给
//     不能声明数组

void Auto()
{
	//auto修饰的变量中是指针时可以省略*
	//                是引用时不可以省略&
	               
	auto/*占位符*/ num = 12;
	auto p = &num;
	*p = 50;

	auto num1 = 5;
	auto* p1 = &num1;
	*p1 = 21;

	auto num2 = 'a';
	auto* num3 = "abcdef";
	auto& p2 = num3;
	p2 = "zhen";

	//不是引用而成为了直接改值（普通变量）
	auto p3 = num2;
	p3 = '5';
	cout << typeid(num).name() << endl;
	cout << typeid(num1).name() << endl;
	cout << typeid(num2).name() << endl;

}

void TestAuto()
{
	const double num = 3.14;
	int num1 = 15;
	auto c = num * num1;
	cout << c << endl;
	cout << typeid(c).name() << endl;
}

void Arr()
{
	int arr[] = { 1,2,3,4,5,6,7,8,0 };
	//int temp = sizeof(arr) / sizeof(arr[0]);
	//for (int i = 0; i < temp; i++)
	//{
	//	arr[i] *= 2;
	//}
	//for (int i = 0; i < temp; i++)
	//{
	//	cout << arr[i] <<" ";
	//}
	//cout << endl;

	//范围for（范围确定）
	for (auto& e : arr)
	{
		e *= 2;
	}
	for (auto& e : arr)
	{
		cout << e << " ";
	}
	cout << endl;
}

void ZhiZhen()
{
	int* p1 = NULL;
	int * p2 = 0;

}

void TestPrint(int a)
{
	cout << "TestPrint(int)" << endl;
}
void TestPrint(int* p)
{
	cout << "TestPrint(int*)" << endl;
}
int main()
{
	//int* p = NULL;
	//TestPrint(0);
	//TestPrint(NULL);
	//TestPrint(nullptr);
	//Arr();
	//TestAuto();
	//Auto();
	//Hong_Const();
	//int a = 22;
	//int b = 33;
	//cout << MAX(a, b++) << endl;
	//Add(1, 2);

	system("pause");
	return 0;
}