#include<iostream>

using namespace std;


//��ֵ
void Swap(int left, int right)
{
	int temp = left;
	left = right;
	right = temp;
}

//�ŵ㣺�����ĸ����ò���Ӱ��ʵ��
//ȱ�㣺�������β�����ô��Ҳ����ı��ⲿ��ʵ��

//��ַ
void Swap1(int* pLeft, int* pRight)
{
	int temp = *pLeft;
	*pLeft = *pRight;
	*pRight = temp;
}

//�ŵ㣺��ͨ���޸ĺ������β����ı��ⲿ��ʵ��
//ȱ�㣺�����ĸ�����


//������
void Swap2(int& left, int& right)
{
	int temp = left;
	left = right;
	right = temp;
}

//������������͵Ĳ����������ں����в���Ҫ�ı��βΣ���ô���const�Ͳ���
void Test(const int& a)
{

}

//��������õķ�ʽ��Ϊ�����ķ���ֵ���ͣ����ܷ���ջ�ϵĿռ�
//���صı�������������һ��Ҫ�Ⱥ������������ڳ�
int& TestRet()
{
	int ret = 10;//ret��ջ�ϵĿռ䣬���溯���ĵĽ����ͻᱻ����ϵͳ�ջ�
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

	//���õ����ڽ�ʵ���

	//int a = 66;
	//int b = 22;
	//Swap2(a, b);
	//cout << a << endl;
	//cout << b << endl;

	int& temp = TestRet();//temp������һ����Ч�ռ�
	cout << temp << endl;//��ʱ�ں������е���ʱ�ռ仹û�б�����
	cout << temp << endl;//�Ѿ������ǣ����������ֵ
	cout << temp << endl;
	system("pause");
	return 0;
}