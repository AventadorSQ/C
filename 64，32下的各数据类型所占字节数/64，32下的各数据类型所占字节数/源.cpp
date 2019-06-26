#include<iostream>
using namespace std;

int main()
{
	cout << "整形：" << endl;
	cout << "size(char) = " << sizeof(char) << endl;
	cout << "size(short) = " << sizeof(short) << endl;
	cout << "size(int) = " << sizeof(int) << endl;
	cout << "size(long) = " << sizeof(long) << endl;
	cout << "size(long long) = " << sizeof(long long) << endl;
	cout << "浮点型：" << endl;
	cout << "size(float) = " << sizeof(float) << endl;
	cout << "size(double) = " << sizeof(double) << endl;
	cout << "指针类型：" << endl;
	cout << "size(char*) = " << sizeof(char*) << endl;
	cout << "size(int*) = " << sizeof(int*) << endl;
	cout << "---------------------------------------->说明：<<VS2017 Win10 64系统>>" << endl;
	system("pause");
	return 0;
}