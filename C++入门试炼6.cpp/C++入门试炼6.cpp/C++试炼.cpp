#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

//��������ʶ��
//1. ʶ������
//2. ʶ����ĳ�Ա����
//3. ʶ����ĳ�Ա�������Գ�Ա�������и�д����Ա����������һ�����ز�������Ӧ������ĵ�ַ(Student* const this)��
//


//���еĳ�Ա���������о���ȫ������
//��������ʹ�����е�˽�б�������������ʹ�ù��еķ���
//�����ģ�ͣ���������ڴ��еĲ�����ʽ
//���С�ļ��㷽ʽ�������еĳ�Ա�������+�ڴ����

class Test
{
public:
	void Set_t(int t);
private:
	int _t;
};

class Test1
{
public:
	void SetNum()
	{
		cout << "TestSetNum()" << endl;
	}
};
class Test3
{};

void Test::Set_t(int t)
{
	_t = t;
}
int _a = 6;

int main()
{
	//int _t = 5;
	//cout << ::_a << endl;//�����޶���
	//��C++�У�һ�����Ĵ�Сռһ���ֽ�

	//�ڴ����Ĭ��ֵ
	//vs�� 8
	//Linux��4

	cout << sizeof(Test) << endl;//4
	cout << sizeof(Test1) << endl;//1
	cout << sizeof(Test3) << endl;//1
	system("pause");
	return 0;
}
