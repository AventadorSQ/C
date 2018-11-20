#include<stdio.h>
#include<stdlib.h>

int fun()
{
	static int count = 1;
	return ++count;
}

void ZhiZhen()
{
#define N_VALUES 5
	float values[N_VALUES];
	float* vp;
	for (vp = &values[0]; vp < &values[N_VALUES];)
	{
		*vp++ = 0;
	}
}

//判断大小端
int CheckSys1()
{
	int i = 1;
	return (*(char*)&i);
}

void PrintSys()
{
	int ret = CheckSys1();
	if (ret == 1)
	{
		printf("小端\n");
	}
	else
	{
		printf("大端\n");
	}
}

void CheckSys2()
{
	union
	{
		int i;
		char c;
	}un = { 0x12345678 };
	printf("%x\n", un.c);
	if (un.c == 0x78)
	{
		printf("小端\n");
	}
	else
	{
		printf("大端\n");
	}
}
int main()
{
	PrintSys();
	CheckSys2();

	//ZhiZhen();
	//int temp;
	//temp = fun() - fun() * fun();
	//printf("%d\n", temp);
	//int i = 0;
	//int k = 0;
	//for (i = 0, k = 0; k = 0; i++, k++)
	//{
	//	k++;
	//	printf("hehe\n");
	//}
	system("pause");
	return 0;
}