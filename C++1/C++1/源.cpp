
//#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

#if 0

//�����ռ�---���������ͻ��������Ⱦ��
//�����ռ䶨�壺
//1.��ͨ�����ռ�
//2.Ƕ��
//3.ͬһ���ļ��п��԰��������ͬ���Ƶ������ռ䣬�������Ὣ��ϲ���һ��

//�����ռ��ʹ�ã�
//1.�����������ռ���ĳ����Ա���ļ���ż�����õ�  N::��Ա
//2.�����ռ���ĳ����Ա���ļ��ж�α�ʹ�õ�using N::��Ա�� N�����ռ��еĳ�Ա���൱���ļ��е�ȫ�ֱ��������ܻ��ͻ
//3.�����ռ�������Ա��Ҫ�ڵ�ǰ�ļ���ʹ�ã�using namespace N;��ͻ���ʱȽϸ�

//��C++��һ���µ�������

namespace N1
{
	int a = 10;
	int b = 20;

	int Add(int left, int right)
	{
		return left + right;
	}
}

//Ƕ��
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

//ͬ�������ռ�
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
//��ʽһ:�����ռ�����::��Ա����
//��ʽ��:using �����ռ�����::��Ա���֣� ���ܻ���ɣ�������ͻ
//       ��������ǰ�����ռ��и����Ա�����ĳ���ļ��б�ʹ��

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

//��ʽ������ǰ�����ռ��г�Ա��ĳ���ļ���Ӧ�õıȽ϶�
using namespace N1;

//ȱ�ݣ���ͻ�ʱȽϸ�

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

//printfȱ�㣺1.��ʽ��Ϊ����
//            2.����Բ�������ƥ���Լ��
//            printf("%d,%lf\n", 10,"hehe");


//scanfȱ�㣺�����������ֵʱ����ȡ��ַ�������ȡ��ַ,�������������������ʱ�����(��ȡ��ַ�����������õ�ַΪ1��������ֵ)
//	           int a = 0;
//             scanf("%d", a);

//c�����к����޷������ͣ���Ĭ�Ϸ�������
//2.��������û��ʱ���ڴ���ʱ���ɻ�ѹջ�����ǲ�����
//c++��Ľ�������ȱ��


//*************************************************************************************************************************************
//ȱʡ����

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

//ȱʡ��������

#if 0
//1.ȫȱʡ����
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

//2.��ȱʡ����
//ֻ�ܴ������������������������Ÿ�
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
//ȱʡ���������ٺ��������������ͬʱ��
//why?
//���ͬʱ������������ʱ��Ĭ�ϲ�����ͻ
//��ø���������λ��
//������һЩ�ļ��к������ʵ���ǿ������ģ�ֻ�������Ӧ�ӿڣ��ͺ���ͷ�ļ�����ʱ������ں�������ʱ��������

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
//�������ι���ͬ---��������
//���أ�һ�ʶ���

//�������ص�����������ͬ�������򣬢ں������ֱ�����ͬ���۲����б���벻ͬ

//�ڱ����ڼ�Ժ����Ĳ��������������ݣ��������ݽ��ȥѡ����ʵĵ��ú���

#if 0
//ͨ�õ�Add
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
	Add('1','2');    // char, char  û���ַ��ͼӷ�ʱ���ַ�������ʽ����Ϊ����
	Add('1', 2);     // char, int   �����������ַ��ͺ�����ʱ����������֪������ôת��������ת����
	system("pause");
	return 0;
}

#endif

//�����б�ͬ�������ĸ������������Ͳ�ͬ�����͵Ĵ���
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

//���������뺯������ֵ�����Ƿ���ͬû�й�ϵ
//int TestFunc(int, char)
//{
//	return 0;
//}

int main()
{
	return 0;
}