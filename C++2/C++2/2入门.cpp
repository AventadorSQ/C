#include<iostream>
using namespace std;

#if 0
//C��֧�ֺ������ض�C++��֧�֣�
//�������ι���ͬ

//  ?Add@@YAHHH@Z      H--->int
//Ԥ����--->����--->���--->����--->��ִ�г���
int Add(int left, int right);
//  ?Add@@YANNN@Z      N--->double
double Add(double left, double right);
//C++�������ι���:�������ͱ��뵽������
//  ?Add@@YANHN@Z    
//vs
// ?��������ʼ��AddԴ��������@��������������@YA��������������ͣ�NHN����������ͣ�@Z��������б����
double Add(int left, double right);

//������������ֵ���Ͳ�ͬΪʲô���������أ�
//    vs�ڴ˲��ϸ񽫷���ֵ���ͷ��˽�ȥ
//    ���ڶ����Ա�������֪���õ���һ����������һֵֻ�����շ���ֵ��C++��û����ȷ�涨һ��Ҫ��һ��ֵ�����գ�

int main()
{
	Add(1, 2);
	Add(1.0, 2.0);
	Add(1, 2.0);
	return 0;
}

#endif

#if 0
//��C++��������ν�һ����������C���Եķ����б���
//ǰ�����extern "C"
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
//��ֵ
//ȱ�㣺����ͨ�������βθı��ⲿʵ��
//�ŵ㣺����ı��ⲿʵ��

//��ַ
//ȱ�㣺1.���׺����п�
//      2.��ʽ��Ϊ����

//������
//
//

//��ֵ
void Swap(int left, int right)
{
	int temp = left;
	left = right;
	right = temp;
}
//��ָ��
void Swap(int* left, int* right)
{
	int temp = *left;
	*left = *right;
	*right = temp;
}

//������
void Swap(int& left, int& right)
{
	int temp = left;
	left = right;
	right = temp;
}


int main()
{
	//�����ڸ������Ǹ�һ��ʵ��ȡ����
	//1.���ñ��������ͱ�������ʵ�������һ��
	//2.�����ʼ��
	//3.���ͺ������&���
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

//const��������---��������---����&����
const int& ra = 10;

const int b = 20;
const int& rb = b;

double c = 16.6;
const int& rc = c;
//��ʱrc������c������
//���ǽ�c�����������ó���������һ��ռ�Ž�ȥ����ra��ָ�������������Ǳ������Լ����ģ�
//�˿̸ÿ�ռ�ʹ���һ����ʱ�������������޷���֪�ÿռ�ĵ�ַ�����޷���֪�������֡����г����������޷��ı䣬���Լ�const

//����Ӧ�ó���
//    1.ֱ�Ӹ�һ������ȡ����
//    2.������

#endif

#if 0

// ע�⣺����������õķ�ʽ��Ϊ�����ķ���ֵ����Ҫ����ջ�ϵĿռ�
//���ܺ�����Ӱ��---����ʵ����������ڱȺ������������ڳ�
//���ϱ���
//ȫ�ֱ���
//��̬����
//�������ͱ���

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

//ջ֡��ջ������
//ջ֡������ջ�����Ե�һ���ڴ�ռ�
//ջ����һ����������ݽṹ

//***����Լ����_cdecl��
//         ��Լ �����ε�˳���Լ����λ���
//����ѹջ��ʽ�ͺ������ղ�����ջ��ʽ

#endif

#if 0
//*****ָ������õ�����?
//
//Ч��
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
	cout << "��ֵ " << end1 - begin1 << endl;

	size_t begin2 = clock();
	for (size_t i = 0; i < 100000; i++)
	{
		TestFunc3(&a);
	}
	size_t end2 = clock();
	cout << "��ַ " << end2 - begin2 << endl;

	size_t begin3 = clock();
	for (size_t i = 0; i < 100000; i++)
	{
		TestFunc3(&a);
	}
	size_t end3 = clock();
	cout << "������ " << end3 - begin3 << endl;
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

	//��ֵ���� ---C++11
	const char&& rrc = 'c';
	return 0;
}

#endif


#if 0
//const���εĳ��������к곣���滻������
//���滻������Ԥ����׶�
//const���εı����滻�����ڱ���׶�

//�꺯����
//   �ŵ㣺����ߴ�������Ч��--��Ԥ����׶Σ��ú꺯�����滻����λ�ã�û�к������ÿ���
//   ȱ�㣺����Ԥ����׶ν����滻��������в������ͼ��
//         �ڴ���ĸ����Բ��ã��������͡�
//         ���޷�����
//         ���и����ã������ϸ�ʹ�ã�������б����������ţ�ÿһ����ҲҪ�����ţ�
//         �������Ҳ���ܻ��и����þ����������ƣ�++b���֣�һ�������滻���ж���ͻᵼ��b����μ��㣩
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
//��inline��һ������������������
//û��ѭ�����ݹ飬�ſ��ܵ�������������������ͬ����������ͬ��

//�������������ڱ���������׶Σ��ú������滻�������õ�λ��
//              ���˺������ò���ѹջ�Լ�ջ֡������ʱ�俪��
//              ����˴��������Ч��
//ʹ��������������ʹ�����Ͷ���ֿ��������������Ӵ���

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
//������C��auto���εı������Ǿ����Զ��洢���ľֲ�����
//�ֽ񣺸��ݸ�ֵ���������жϱ��������ͣ�����ռλ����
//     ����������Ա����ʼ��

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

	//auto ����ָ�����ͼӲ���*��һ��
	//auto ����������һ��Ҫ&
	//��������������ͱ���һ��
	//������Ϊ������������ȱʡֵҲ���У�
	//������������

	//���ƣ��򻯴���
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
//��Χfor
//����һ��ȷ�����鷶Χ����Ҫ�����Եö��࣬�����׳���
//��Χforע���ǽ�����Ԫ�ؿ�������ʱ����e��


//ʹ�÷�Χfor����������
//                   �ٷ�Χ����ȷ��
//                   �ڵ�������ʵ��++��==����
//ע�����⣺������Ԫ�ؿ�������ʱ����e��
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
//nullptr  �ؼ���
//NULL �곣��
//nullptr_t   ����