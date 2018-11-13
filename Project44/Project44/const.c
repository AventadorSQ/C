#include<Aventador_SQ.h>

//*****************************************************************************************************
//******              在C语言中const修饰的是变量(只读)，而宏定义的是常量。                       ******
//*****************************************************************************************************
//******              在C++语言中const修饰的是常量，可以替换宏。宏定义的是常量                   ******
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

//auto 定义的变量必须初始化
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