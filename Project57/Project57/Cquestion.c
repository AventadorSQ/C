#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>

void Test1()
{
	char arr1[] = "abcde";
	char* arr2 = "abcdef";
	char arr3[5] = "abcde";
	char arr5[] = { 'a','b','c','d','e' };
}

void Test2()
{
	unsigned char c1 = 225;
	unsigned char c2 = 230;
	unsigned char c3 = 0;
	c3 = c1 + c2;
	printf("%d\n%d\n", c1 + c2, c3);
}

void Test3()
{
	typedef struct Str
	{
		//unsigned char c1 : 4;//4个bit（100）
		//unsigned char c2 : 2;//2个bit（10）
		//unsigned char c4 : 1;//1个bit（1）
		//unsigned char c5 : 1;//1个bit（1）
		//unsigned char c3;
		int _a : 2;
		int _b : 5;
		int _c : 10;
		int _d : 15;
	}Str;

	Str* ptr = (Str*)malloc(sizeof(Str));
	printf("%d\n", sizeof(ptr));
	printf("%d\n", sizeof(*ptr));
}

void Test4()
{
	char c1;
	unsigned char c2;
	unsigned short num;
	c1 = 128;
	c2 = 128;
	num = c1 + c2;
	//128  
	//0000 0000 0000 0000 0000 0000 1000 0000
	//-128
	//1000 0000 0000 0000 0000 0000 1000 0000
	//1111 1111 1111 1111 1111 1111 0111 1111
	//1111 1111 1111 1111 1111 1111 1000 0000
	printf("0x0 0x%x\n", num);//0x0    
	num = (unsigned char)c1 + c2;
	printf("0x100 0x%x\n", num);//0x100
	num = c1 + (char)c2;
	printf("0xff00 0x%x\n", num);//0xff00
}
int main()
{
	//Test1();
	//Test2();
	//Test3();
	Test4();
	system("pause");
	return 0;
}