#include<iostream>
#include<cstdlib>

using namespace std;

//int main()
//{
//	//double a = 1.0;
//	//const int& ra = a;
//	const int b = 10;
//	int* pb = (int*)&b;
//	*pb = 100;
//	cout << b << endl;
//	cout << *pb << endl;
//	cout << pb << endl;
//	system("pause");
//	return 0;
//}

////宏定义函数，比较出两个较大的数并输出
////好处：1.在预编译阶段对函数进行处理，减少代码运行时间（提高性能） 2.增强代码复用性
////缺陷：不方便调试宏。（因为预编译阶段进行了替换）2.导致代码可读性差，可维护性差
//#define MAX(a,b) ((a) > (b) ? (a) : (b))
//int main()
//{
//	int a = 10;
//	int b = 20;
//	cout << MAX(a, b) << endl;//20
//	cout << MAX(a, ++b) << endl;//22
//	system("pause");
//	return 0;
//}

////内联函数
////被inline修饰的函数
////inline是一种以时间换空间的做法，省去调用函数额开销
//
//inline int Add(int left, int right)
//{
//	Add(left, right);
//	return left + right;
//}


