#include<iostream>
#include<cstdlib>

using namespace std;

//1.识别类名
//2.识别类中的成员变量
//3.识别类中的成员函数&进行改写
//    给类的成员函数增加一个默认的参数——this指针
//    在成员函数中通过this指针去访问“成员变量”

class Date
{
public:
	//在类中定义的成员函数，编译器可能当成内联函数来处理 
	Date(int year,int month,int data)
	{
		_year = year;
		_month = month;
		_data = data;
	}
	// 显式定义了构造函数
	//只要用户显示定义，默认的构造函数将不会合成
	//带全缺省的构造函数---缺省的构造函数
	//无参的和带有全缺省的构造函数只能存在一个

	Date()
	{
		_year = 2019;
		_month = 1;
		_data = 1;
	}

	//析构函数
	//与构造函数功能相反，在对象被销毁时，由编译器自动调用，完成类的一些资源清理工作
	//2.特性：
	//       1.析构函数名是在类名前加上字符~。
	//       2.无参数无返回值。
	//       3.一个类且只有一个析构函数。若为显示定义，系统会自动生成默认的析构函数
	//       4.对象生命周期结束时，C++编译系统自动调用析构函数
	// 析构函数体内不是删除对象，而是做一些对象删除前的相关清理工作
	~Date()
	{
		//可以及时释放内存资源
	}
	void SetDataInfo(int year, int month, int data)
	{
		_year = year; 
		_month = month;
		_data = data;
	}

	void TestFunc(...)//不定参数
	{
		cout << this << endl;
	}

	void PrintData()
	{
		cout << _year << " " << _month << " " << _data << endl;
	}

private:
	int _year;
	int _month;
	int _data;
};

//this 类类型* const==引用

//类的六个默认成员函数（C++98）
//    1.构造函数
//    2.拷贝构造函数
//    3.析构函数
//    4.赋值操作符重载
//    5.取地址操作符重载
//    6.const修饰的取地址操作符重载

//一、构造函数：
//             构造函数是一个特殊的成员函数，名字与类名相同，创建类类型对象时由编译器自动调用，保证每个数据成员都有一个合适的初始值，
//             并且在对象的生命周期内只调用一次。
//             特性：
//                   1.函数名与类名相同
//                   2.无返回值
//                   3.对象构造（对象实例化）时编译器自动调用对应的构造函数
//                   4.构造函数可以重载
int main()
{
	Date dt(2018, 11, 25);//调Date::Date 
	dt.PrintData();
	//Date d1, d2, d3;
	//d1.SetDataInfo(2018, 11, 20);
	//d2.SetDataInfo(2018, 11, 21);
	//d3.SetDataInfo(2018, 11, 22);
	//int a(20);
	//Date data;
	//data.SetDataInfo(2018, 11, 20);
	//Date* p = &data;
	//p->SetDataInfo(2018, 11, 21);

	//p = nullptr;
	//p->TestFunc();
	//p->SetDataInfo(2018, 11, 22);
	//p->_year = 2019;
	system("pause");
	return 0;
}

//#include<stdio.h>
//#include<stdlib.h>
//int main()
//{
//	int i, arr[10];
//	for (i = 1; i <= 10; i++)
//	{
//		arr[i] = 0;
//		printf("%d\n",arr[i]);
//	}
//	system("pause");
//	return 0;
//}