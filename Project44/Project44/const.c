#include<Aventador_SQ.h>

//*****************************************************************************************************
//******              ��C������const���ε��Ǳ���(ֻ��)�����궨����ǳ�����                       ******
//*****************************************************************************************************
//******              ��C++������const���ε��ǳ����������滻�ꡣ�궨����ǳ���                   ******
//*****************************************************************************************************
void Hong()
{
#define num1 10
	int arr1[num1] = { 0 };
}
//void Const()
//{
//	const int num = 10;
//	int arr[num] = { 0 };
//}

//auto ����ı��������ʼ��
void Auto()
{
	auto num = 12;
	auto num2 = 5;
	auto num3 = 'a';
	auto* num4 = "abcdef";
	printf("%d %d %c %s\n", num, num2, num3, num4);

}

//void Auto1()
//{
//	auto num = 12;
//	auto num2 = 5;
//	auto* num4 = "abcdef";
//	auto num3 = 'a';
//	printf("%d %d %c %s\n", num, num2, num3, num4);
//}
int main()
{
	Auto();
	//Auto1();
	Hong();
	//Const();
	system("pause");
	return 0;
}