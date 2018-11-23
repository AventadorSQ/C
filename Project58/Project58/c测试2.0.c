#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#include<windows.h>

void Test1()
{
	char* ptr = "abcdefX3000";
	char arr[] = "abcdefX3000";
	printf("%d\n", strlen(ptr));//11
	printf("%d\n", strlen(arr));//11
	printf("%d\n", sizeof(ptr));//4
	printf("%d\n", sizeof(arr));//12
}

void Test2()
{
	unsigned char arr[4];
	typedef struct Str
	{
		unsigned char c1;
		unsigned char c2 : 1;    //00 000 00 0
		unsigned char c3 : 2;    //00 101 00 1
		unsigned char c4 : 3;    //2^5+2^3+1==32+8+1
	}Str;
	Str* ptr;
	memset(arr, 0, 4);
	ptr = (Str*)arr;
	ptr->c1 = 2;
	ptr->c2 = 3;
	ptr->c3 = 4;
	ptr->c4 = 5;
	char* ptr1 = (((char*)(&arr))+1);
	printf("%d\n", *ptr1);

}

void Test3()
{
	char arr[10];// = "0";
	strncpy(arr, "hello", 6);
	printf("%s\n", arr);
}

void GetMemory(char** pptr)
{
	if (pptr == NULL)
	{
		assert(0);
		return;
	}
	*pptr = (char*)malloc(256);
	return;
}
void Test4()
{
	char* ptr = NULL;
	GetMemory(&ptr);
	strcpy(ptr, " hello world\r\n");
	printf("%s\n", ptr);
	free(ptr);
}

char* Get(char** ptr1)
{
	*ptr1 = "hello world";
	return *ptr1;
}

void Test5()
{
	char* ptr = NULL;
	if (NULL != Get(&ptr))
	{
		printf("\r\n ptr = %s\n", ptr);
	}
}

void Test6()
{
	unsigned char arr[255];
	unsigned char i;
	for (i = 0; i <= 255; i++)
	{
		arr[i] = i;
		Sleep(100);
		printf("%d\n",arr[i]);
	}
}

char* GetM()
{
	static char ptr1[] = "hello world";
	return ptr1;
}
void Test7()
{
	char* ptr = NULL;
	ptr = GetM();
	printf(ptr);
}
int main()
{
	//Test1();
	//Test2();
	//Test3();
	//Test4();
	//Test5();
	//Test6();
	Test7();
	system("pause");
	return 0;
}