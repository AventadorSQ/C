#include<iostream>

using namespace std;

//���ŵ㣺1.��ǿ����ĸ�����
//        2.�������
//ȱ�㣺1.��������Ժꡣ��Ԥ�������滻��
//      2.���´���ɶ��Բ��ά���Բ��������
//      3.û�����Ͱ�ȫ�ļ��
//C++�п��������ķ�����
//                      1.�������� ����const
//                                              const����---����&���к������---�滻(C++)

//                      2.�������� ������������

//�궨�壨����ȫ��
//Ԥ����׶�

#define MAX(a,b) ((a)>(b) ? (a):(b))

void Hong_Const()
{
	const int a = 10;
	//int arr[a];
	int* p = (int*)&a;
	*p = 110;
	cout << a << endl;//a�Ǳ��滻��10
	cout << &a << endl;
	cout << *p << endl;
	cout << &*p << endl;
}
//����׶�
//������������inline������������Ż��ú���
//��inline��һ������������
//���ú�������ѭ����ݹ�������ͻ���Թؼ���
inline int Add(int left, int right)
{
	return left + right;
}

//auto  C++11
//auto ����ı��������ʼ��
//     ��ȻҲ���ܵ�����������������
//     ������������

void Auto()
{
	//auto���εı�������ָ��ʱ����ʡ��*
	//                ������ʱ������ʡ��&
	               
	auto/*ռλ��*/ num = 12;
	auto p = &num;
	*p = 50;

	auto num1 = 5;
	auto* p1 = &num1;
	*p1 = 21;

	auto num2 = 'a';
	auto* num3 = "abcdef";
	auto& p2 = num3;
	p2 = "zhen";

	//�������ö���Ϊ��ֱ�Ӹ�ֵ����ͨ������
	auto p3 = num2;
	p3 = '5';
	cout << typeid(num).name() << endl;
	cout << typeid(num1).name() << endl;
	cout << typeid(num2).name() << endl;

}

void TestAuto()
{
	const double num = 3.14;
	int num1 = 15;
	auto c = num * num1;
	cout << c << endl;
	cout << typeid(c).name() << endl;
}

void Arr()
{
	int arr[] = { 1,2,3,4,5,6,7,8,0 };
	//int temp = sizeof(arr) / sizeof(arr[0]);
	//for (int i = 0; i < temp; i++)
	//{
	//	arr[i] *= 2;
	//}
	//for (int i = 0; i < temp; i++)
	//{
	//	cout << arr[i] <<" ";
	//}
	//cout << endl;

	//��Χfor����Χȷ����
	for (auto& e : arr)
	{
		e *= 2;
	}
	for (auto& e : arr)
	{
		cout << e << " ";
	}
	cout << endl;
}

void ZhiZhen()
{
	int* p1 = NULL;
	int * p2 = 0;

}

void TestPrint(int a)
{
	cout << "TestPrint(int)" << endl;
}
void TestPrint(int* p)
{
	cout << "TestPrint(int*)" << endl;
}
int main()
{
	//int* p = NULL;
	//TestPrint(0);
	//TestPrint(NULL);
	//TestPrint(nullptr);
	//Arr();
	//TestAuto();
	//Auto();
	//Hong_Const();
	//int a = 22;
	//int b = 33;
	//cout << MAX(a, b++) << endl;
	//Add(1, 2);

	system("pause");
	return 0;
}