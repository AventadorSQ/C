#include<iostream>
using namespace std;

#if 0
//C不支持函数重载而C++不支持？
//函数修饰规则不同

//  ?Add@@YAHHH@Z      H--->int
//预处理--->编译--->汇编--->链接--->可执行程序
int Add(int left, int right);
//  ?Add@@YANNN@Z      N--->double
double Add(double left, double right);
//C++命名修饰规则:参数类型编译到名字中
//  ?Add@@YANHN@Z    
//vs
// ?代表函数开始，Add源函数名，@代表函数名结束，@YA代表紧跟参数类型，NHN代表参数类型，@Z代表参数列表结束
double Add(int left, double right);

//仅仅函数返回值类型不同为什么不构成重载？
//    vs在此不严格将返回值类型放了进去
//    存在二义性编译器不知道该调哪一个，除非用一只值来接收返回值（C++并没有明确规定一定要用一个值来接收）

int main()
{
	Add(1, 2);
	Add(1.0, 2.0);
	Add(1, 2.0);
	return 0;
}

#endif

#if 0
//在C++工程中如何将一个函数按照C语言的风格进行编译
//前面加上extern "C"
extern "C" int Add(int left, int right);
{
	return left + right;
}

int main()
{
	Add(1, 3);
	return 0;
}
#endif

//******************************************************************

#if 0
//传值
//缺点：不能通过函数形参改变外部实参
//优点：不会改变外部实参

//传址
//缺点：1.容易忽略判空
//      2.格式较为繁琐

//传引用
//
//

//传值
void Swap(int left, int right)
{
	int temp = left;
	left = right;
	right = temp;
}
//传指针
void Swap(int* left, int* right)
{
	int temp = *left;
	*left = *right;
	*right = temp;
}

//传引用
void Swap(int& left, int& right)
{
	int temp = left;
	left = right;
	right = temp;
}


int main()
{
	//引用在概念上是给一个实体取别名
	//1.引用变量的类型必须与其实体的类型一致
	//2.必须初始化
	//3.类型后面加上&标记
	int b = 2;
	int a = 10;
	int& ra = a;
	int& rra = a;
	//ra = b;
	rra = 12;

	cout << &ra << " " << ra << endl;
	cout << &rra << " " << a << endl;
	system("pause");
	return 0;
}

//const类型引用---万能引用---变量&常量
const int& ra = 10;

const int b = 20;
const int& rb = b;

double c = 16.6;
const int& rc = c;
//此时rc不再是c的引用
//而是将c的整数部分拿出来重新找一块空间放进去，用ra来指向它，由于这是编译器自己做的，
//此刻该块空间就存着一个临时变量，我们又无法得知该空间的地址，又无法得知它的名字。具有常性所以它无法改变，所以加const

//引用应用场景
//    1.直接给一个变量取别名
//    2.交换数

#endif

#if 0

// 注意：如果按照引用的方式作为函数的返回值，不要返回栈上的空间
//不受函数的影响---返回实体的生命周期比函数的生命周期长
//堆上变量
//全局变量
//静态变量
//引用类型变量

int& Add(int& left, int& right)
{
	int ret = left + right;
	return ret;
}

int main()
{
	int a = 1;
	int b = 2;
	int& rAdd = Add(a, b);
	//cout << "rAdd" << " " << rAdd << endl;
	//cout << "&rAdd" << " " << &rAdd << endl;
	int c = 3;
	int d = 7;
	int num = Add(c, d);
	cout << "num" << " " << num << endl;
	cout << "&num" << " " << &num << endl;
	cout << "rAdd" << " " << rAdd << endl;
	cout << "&rAdd" << " " << &rAdd << endl;
	system("pause");
	return 0;
}

//栈帧与栈的区别：
//栈帧是利用栈的特性的一块内存空间
//栈则是一种特殊的数据结构

//***调用约定（_cdecl）
//         ：约 定传参的顺序以及传参机制
//传参压栈方式和函数接收参数进栈方式

#endif

#if 0
//*****指针和引用的区别?
//
//效率
#include<ctime>
struct A
{
	int array[10000];
};

void TestFunc1(A a)
{}
void TestFunc2(A& a)
{}
void TestFunc3(A* a)
{}

void TestTime()
{
	A a;
	size_t begin1 = clock();
	for (size_t i = 0; i < 100000; i++)
	{
		TestFunc1(a);
	}
	size_t end1 = clock();
	cout << "传值 " << end1 - begin1 << endl;

	size_t begin2 = clock();
	for (size_t i = 0; i < 100000; i++)
	{
		TestFunc3(&a);
	}
	size_t end2 = clock();
	cout << "传址 " << end2 - begin2 << endl;

	size_t begin3 = clock();
	for (size_t i = 0; i < 100000; i++)
	{
		TestFunc3(&a);
	}
	size_t end3 = clock();
	cout << "传引用 " << end3 - begin3 << endl;
}

int main()
{
	TestTime();
	int a = 10;
	const int& ra = a;
	system("pause");
	return 0;
}

#endif


#if 0
int main()
{
	char ch = 'c';
	char& rc = ch;
	char* ptr = &ch;

	//sizeof

	//右值引用 ---C++11
	const char&& rrc = 'c';
	return 0;
}

#endif


#if 0
//const修饰的常量，具有宏常量替换的特性
//宏替换发生在预处理阶段
//const修饰的变量替换发生在编译阶段

//宏函数：
//   优点：①提高代码运行效率--在预处理阶段：用宏函数体替换调用位置，没有函数调用开销
//   缺点：①在预处理阶段进行替换，不会进行参数类型检测
//         ②代码的复用性不好，代码膨胀。
//         ③无法调试
//         ④有副作用（括号严格使用，最好所有变量都加括号，每一部分也要加括号）
//         即便如此也可能会有副作用就是遇到类似（++b这种，一旦宏中替换后有多个就会导致b被多次计算）
int main()
{
	const int a = 10;
	int* ptr = (int*)&a;
	*ptr = 100;
	cout << "a " << a << endl;
	cout << "&a " << &a << endl;
	cout << "*ptr " << *ptr << endl;
	cout << "ptr " << ptr << endl;
	system("pause");
	return 0;
}

#endif

//*******************************************************************************************************************
#if 0
//加inline不一定当内联函数来处理
//没有循环，递归，才可能当成内联函数来处理（不同编译器处理不同）

//内联函数处理：在编译器编译阶段，用函数体替换函数调用的位置
//              少了函数调用参数压栈以及栈帧创建的时间开销
//              提高了代码的运行效率
//使用内联函数不能使声明和定义分开，否则会产生链接错误

#define MaxS(a, b) (((a) >(b))?(a):(b)) 
inline int Max(int a, int b)
{
	return a > b ? a : b;
}

int main()
{
	int a = 2;
	int b = 10;
	int b1 = 10;
	cout << MaxS(++b1, a) << endl;
	cout << Max(++b, a) << endl;
	system("pause");
	return 0;
}

#endif

#if 0
//****************************************************************************************************************
//auto
//早期在C中auto修饰的变量，是具有自动存储器的局部变量
//现今：根据赋值的类型来判断变量的类型（类型占位符）
//     由于这个特性必须初始化

int main()
{
	auto a = 10;
	auto b = 12.03;
	auto c = '01';
	auto d = "hehe";
	auto e = a + b;
	cout << "a " << typeid(a).name() << endl;
	cout << "b " << typeid(b).name() << endl;
	cout << "c " << typeid(c).name() << endl;
	cout << "d " << typeid(d).name() << endl;
	cout << "e " << typeid(e).name() << endl;

	//auto 声明指针类型加不加*都一样
	//auto 声明引用则一定要&
	//声明多个变量类型必须一样
	//不能作为函数参数（带缺省值也不行）
	//不能推演数组

	//优势：简化代码
	int tmp = 10;
	int* ptr = &tmp;

	auto ptr1 = ptr;
	auto* ptr2 = ptr;
	cout << "&tmp " << &tmp << endl;
	cout << "&ptr1 " << &ptr1 << endl;
	cout << "&ptr2 " << &ptr2 << endl;

	auto rtmp = tmp;
	auto& rtmp1 = tmp;
	cout << "&tmp " << &tmp << endl;
	cout << "&rtmp " << &rtmp << endl;
	cout << "&rtmp1 " << &rtmp1 << endl;

	system("pause");
	return 0;
}
#endif

#if 0
//*************************************************************
//范围for
//对于一个确定数组范围，还要给定显得多余，还容易出错
//范围for注意是将数组元素拷贝到临时变量e中


//使用范围for两个条件：
//                   ①范围必须确定
//                   ②迭代对象实现++或==操作
//注意问题：将数组元素拷贝到临时变量e中
int main()
{
	int arr[] = { 1,2,3,4,5,6 };
	for (auto e : arr)
	{
		cout << e << " ";
	}
	cout << endl;
	for (auto e : arr)
	{
		e *= 2;
	}
	for (auto e : arr)
	{
		cout << e << " ";
	}
	cout << endl;
	for (auto& e : arr)
	{
		e *= 2;
	}
	for (auto e : arr)
	{
		cout << e << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}

#endif

//***************************************
//nullptr  关键字
//NULL 宏常量
//nullptr_t   类型