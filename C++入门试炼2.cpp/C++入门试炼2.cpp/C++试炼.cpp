#include<iostream>
#include<Windows.h>

using namespace std;

struct st
{
	int arr[10000];
	int _size;
};
void test(st& param)
{}

void test1()
{
	st a;
	size_t begin = GetTickCount();
	for (size_t i = 0; i < 100000000; i++)
	{
		test(a);
	}
	size_t end = GetTickCount();
	cout << end - begin << endl;
}

//**************************************************************************
//******   共同点：引用和指针在底层处理方式相同，都按照指针方式处理   ******
//**************************************************************************

//**************************************************************************
//******                     指针和引用的区别？                       ******
//**************************************************************************

//1.引用只能绑定一个实体，而指针可以指向不同实体
//2.使用指针时要判空，而引用不需要因此更安全
//3.引用在定义时必须初始化，指针不做要求
//4.在sizeof中：引用结果是引用类型的大小，但指针始终是地址空间所占字节个数
//5.引用自加即引用的实体增加1，指针自加即指针向偏移一个类型的大小
//6.有多级指针，但没有多级引用    // const int&& ra=10;(右值引用)C++11
//7.访问实体时，指针需要显式解引用，而引用（编译器处理）
//8.没有null引用，但有null指针

//引用变量是有存储空间的
void Swap(int* left, int* right)
{
	int temp = *left;
	*left = *right;
	*right = temp;
}
void Swap(int& left, int& right)
{
	int temp = left;
	left = right;
	right = temp;
}

//5.引用自加即引用的实体增加1，指针自加即指针向偏移一个类型的大小
void Add()
{
	int num1 = 20;
	int& nu = num1;
	cout << num1 << endl;
	cout << &num1 << endl;
	cout << &nu << endl;
	nu++;
	cout << num1 << endl;
	cout << &num1 << endl;
	cout << &nu << endl;
	int num = 20;
	int* p = &num;
	cout << num << endl;
	cout << &num << endl;
	cout << &*p << endl;
	cout << &p << endl;
	p++;
	cout << num << endl;
	cout << &num << endl;
	cout << &*p << endl;
	cout << &p << endl;
}

//4.在sizeof中：引用结果是引用类型的大小，但指针始终是地址空间所占字节个数
void Size()
{
	long long x = 10;
	long long& a = x;
	long long* p = &x;
	cout << sizeof(a) << endl;
	cout << sizeof(p) << endl;
}
int main()
{
	//Add();
	Size();
	//Swap(&x, &y);
	//Swap(x, y);


	/*test1();*/

	//int a = 10;
	//int* pa = &a;
	//*pa = 20;

	//int& ra = a;
	//ra = a;
	system("pause");
	return 0;
}