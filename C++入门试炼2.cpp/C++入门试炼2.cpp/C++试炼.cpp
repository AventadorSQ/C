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
//******   ��ͬ�㣺���ú�ָ���ڵײ㴦��ʽ��ͬ��������ָ�뷽ʽ����   ******
//**************************************************************************

//**************************************************************************
//******                     ָ������õ�����                       ******
//**************************************************************************

//1.����ֻ�ܰ�һ��ʵ�壬��ָ�����ָ��ͬʵ��
//2.ʹ��ָ��ʱҪ�пգ������ò���Ҫ��˸���ȫ
//3.�����ڶ���ʱ�����ʼ����ָ�벻��Ҫ��
//4.��sizeof�У����ý�����������͵Ĵ�С����ָ��ʼ���ǵ�ַ�ռ���ռ�ֽڸ���
//5.�����ԼӼ����õ�ʵ������1��ָ���ԼӼ�ָ����ƫ��һ�����͵Ĵ�С
//6.�ж༶ָ�룬��û�ж༶����    // const int&& ra=10;(��ֵ����)C++11
//7.����ʵ��ʱ��ָ����Ҫ��ʽ�����ã������ã�����������
//8.û��null���ã�����nullָ��

//���ñ������д洢�ռ��
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

//5.�����ԼӼ����õ�ʵ������1��ָ���ԼӼ�ָ����ƫ��һ�����͵Ĵ�С
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

//4.��sizeof�У����ý�����������͵Ĵ�С����ָ��ʼ���ǵ�ַ�ռ���ռ�ֽڸ���
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