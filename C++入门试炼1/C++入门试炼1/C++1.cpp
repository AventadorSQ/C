#include<iostream>

using namespace std;


//传值
void Swap(int left, int right)
{
	int temp = left;
	left = right;
	right = temp;
}

//优点：函数的副作用不会影响实参
//缺点：函数的形参再怎么变也不会改变外部的实参

//传址
void Swap1(int* pLeft, int* pRight)
{
	int temp = *pLeft;
	*pLeft = *pRight;
	*pRight = temp;
}

//优点：可通过修改函数的形参来改变外部的实参
//缺点：函数的副作用


//传引用
void Swap2(int& left, int& right)
{
	int temp = left;
	left = right;
	right = temp;
}

//如果是引用类型的参数，但是在函数中不需要改变形参，最好传递const型参数
void Test(const int& a)
{

}

//如果以引用的方式作为函数的返回值类型，不能返回栈上的空间
//返回的变量的生命周期一定要比函数的生命周期长
int& TestRet()
{
	int ret = 10;//ret是栈上的空间，会随函数的的结束就会被操作系统收回
	return ret;
}
int main()
{
	//int a = 50;
	//int b = 20;
	//Swap(a, b);
	//Swap1(&a, &b);

	//int a = 10;
	//int& ra = a;
	//ra = 20;
	//cout << &a << endl;
	//cout << &ra << endl;

	//引用的周期较实体短

	//int a = 66;
	//int b = 22;
	//Swap2(a, b);
	//cout << a << endl;
	//cout << b << endl;

	int& temp = TestRet();//temp所引用一段无效空间
	cout << temp << endl;//此时在函数体中的临时空间还没有被覆盖
	cout << temp << endl;//已经被覆盖，所以是随机值
	cout << temp << endl;
	system("pause");
	return 0;
}