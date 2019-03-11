
//#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

#if 0

//命名空间---解决命名冲突（名字污染）
//命名空间定义：
//1.普通命名空间
//2.嵌套
//3.同一个文件中可以包含多个相同名称的命名空间，编译器会将其合并成一个

//命名空间的使用：
//1.场景：命名空间中某个成员在文件中偶尔被用到  N::成员
//2.命名空间中某个成员在文件中多次被使用到using N::成员； N命名空间中的成员就相当于文件中的全局变量，可能会冲突
//3.命名空间中许多成员都要在当前文件中使用，using namespace N;冲突概率比较高

//在C++中一种新的作用域

namespace N1
{
	int a = 10;
	int b = 20;

	int Add(int left, int right)
	{
		return left + right;
	}
}

//嵌套
namespace N2
{
	int a = 30;
	int b = 40;

	int Sub(int left, int right)
	{
		return left - right;
	}

	namespace N3
	{
		int a = 10;
		int b = 20;

		int Mul(int left, int right)
		{
			return left * right;
		}
	}
}

//同名命名空间
namespace N1
{
	int c = 21;
	int d = 12;

	int Div(int left, int right)
	{
		if (0 == right)
			exit(1);

		return left / right;
	}
}
//方式一:命名空间名字::成员名字
//方式二:using 命名空间名字::成员名字； 可能会造成：命名冲突
//       场景：当前命名空间中个别成员多次在某个文件中被使用

////using N1::a;
//
//int a = 50;
//int main()
//{
//	int a = 60;
//
//	cout << a << endl;
//	cout << ::a << endl;
//
//	cout << N1::a << endl;
//
//	system("pause");
//	return 0;
//}

//方式三：当前命名空间中成员在某个文件中应用的比较多
using namespace N1;

//缺陷：冲突率比较高

int main()
{
	int a;
	cin >> a;
	double d;
	cin >> a >> d;
	cout << a <<" "<< b <<" "<< Add(a, b) << endl;
	system("pause");
	return 0;
}

#endif

//printf缺点：1.格式较为复杂
//            2.不会对参数进行匹配性检测
//            printf("%d,%lf\n", 10,"hehe");


//scanf缺点：对所输变量赋值时必须取地址，如果不取地址,不会崩溃，当程序运行时则崩溃(不取地址，编译器就拿地址为1区域来赋值)
//	           int a = 0;
//             scanf("%d", a);

//c语言中函数无返回类型，会默认返回整形
//2.函数参数没有时，在传参时依旧会压栈，但是不会用
//c++则改进了这种缺陷


//*************************************************************************************************************************************
//缺省参数

#if 0
void TestFunc(int a = 10)
{
	cout << a << endl;
}

int main()
{
	TestFunc(20);
	TestFunc();
	system("pause");
	return 0;
}

#endif

//缺省参数分类

#if 0
//1.全缺省参数
void TestFunc(int a = 1, int b = 2, int c = 3)
{
	cout << a << " " << b << " " << c << endl;
}

int main()
{
	TestFunc(10, 20, 30);
	TestFunc(10, 20);
	TestFunc(10);
	TestFunc();
	system("pause");
	return 0;
}

#endif

//2.半缺省参数
//只能从右往左依次来给，不能跳着给
#if 0
void TestFunc(int a, int b = 2, int c = 3)
{
	cout << a << " " << b << " " << c << endl;
}

int main()
{
	TestFunc(10, 20, 30);
	TestFunc(10, 20);
	TestFunc(10);
	//TestFunc();
	system("pause");
	return 0;
}
#endif

#if 0
//缺省参数不能再函数定义和声明中同时给
//why?
//如果同时给当不传参数时，默认参数冲突
//最好给在声明的位置
//例如在一些文件中函数如何实现是看不见的，只会给你相应接口，和函数头文件。此时如果给在函数定义时将看不到

void TestFunc(int a);

void TestFunc(int a = 2)
{
	cout << a << endl;
}

int main()
{
	TestFunc(10);
	//TestFunc();
	system("pause");
	return 0;
}

#endif

//*******************************************************************************************************************************
//名字修饰规则不同---函数重载
//重载：一词多义

//函数重载的条件：①相同的作用域，②函数名字必须相同，③参数列表必须不同

//在编译期间对函数的参数进行类型推演，根据推演结果去选择合适的调用函数

#if 0
//通用的Add
int Add(int left, int right)
{
	return left + right;
}

double Add(double left, double right)
{
	return left + right;
}

char Add(char left, char right)
{
	return left + right;
}

int main()
{
	Add(10, 2);
	Add(12.2, 13.3);
	Add('1','2');    // char, char  没有字符型加法时，字符可以隐式提升为整形
	Add('1', 2);     // char, int   当函数都有字符型和整形时，编译器不知道该怎么转存在两种转法。
	system("pause");
	return 0;
}

#endif

//参数列表不同：参数的个数，参数类型不同，类型的次序
void TestFunc()
{}

void TestFunc(char)
{}

void TestFunc(int)
{}

void TestFunc(char,int)
{}

void TestFunc(int, char)
{}

//函数重载与函数返回值类型是否相同没有关系
//int TestFunc(int, char)
//{
//	return 0;
//}

int main()
{
	return 0;
}