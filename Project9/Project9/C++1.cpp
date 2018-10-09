#include<iostream>
#include<cstdlib>
using namespace std;

#if 0
int main()
{
	cout << "hello world!!!" << endl;
	system("pause");
	return 0;
}
#endif

////函数重载
//int Add(int left, int right)
//{
//	return left + right;
//}
//double Add(double left, double right)
//{ 
//	return left + right;
//}
// 
//int main()
//{
//	cout << Add(1, 2) << endl;
//	cout << Add(2.1, 5.1) << endl;
//	system("pause");
//	return 0;
//}

//C++中取别名
//引用类型必须和实体类型相同
//int main()
//{
//	int x = 0;
//	int& weizhi = x;
//
//	//常引用
//	const int a = 10;
//	const int& as = a;
//
//	//此时ry将不是指向y的内存空间，而将12取出来重新分配一块内存空间，所以
//	//y改变时ry不会变
//	double y = 12.34;
//	const int& ry = y;
//
//	//数组的引用
//	int arr[10];
//	int(&rarr)[10] = arr;
//
//	cout << &y << endl;
//	cout << &ry << endl;
//	//cout << &x << endl;
//	//cout << &weizhi << endl;
//	system("pause");
//	return 0;
//}

//void PrintArray(int(&array)[10])
//{
//	for (size_t i = 0; i < 10; ++i)
//		cout << array[i] << " ";
//	cout<< endl;
//}
//
//int main()
//{
//	int array[] = { 1,2,3,4,5,6,7,8,9,0 };
//	PrintArray(array);
//	system("pause");
//	return 0;
//}

//c++传值与传引用
void Swap(int& left, int& right)
{
	int temp = left;
	left = right;
	right = temp;
}

void Swap(int* pLeft, int* pRight)
{
	int temp = *pLeft;
	*pLeft = *pRight;
	*pRight = temp;
}

int main()
{
	int a = 2;
	int b = 6;
	Swap(a, b);
	cout << a <<" "<< b << endl;
	Swap(&a, &b);
	cout << a << " " << b << endl;
	system("pause");
	return 0;
} 