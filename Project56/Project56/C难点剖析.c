#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

//�⵱ǰ�������ֽ��򣨴��/С�ˣ�
void CheckSystem1()
{
	int num = 1;
	int _num = (*(char*)&num);
	printf("%d\n", _num);
	if (_num == 1)
	{
		printf("С��\n");
	}
	else
	{
		printf("���\n");
	}
}

void CheckSystem2()
{
	union
	{
		int num;
		char a;
	}Sunion;
	Sunion.num = 0x12345678;
	printf("%x\n", Sunion.a);
	printf("%d\n", Sunion.a);//ʮ����120
	if (Sunion.a == 0x78)
	{
		printf("С��\n");
	}
	else
	{
		printf("���\n");
	}
}

//�洢����
void Char()
{
	char a = -1;
	signed char b = -1;
	unsigned char c = -1;
	printf("a = %d,b = %d,c = %d\n", a, b, c);
}

//����������ռ�ֽ�
void ZiJie()
{
	printf("char:%d\n", sizeof(char));
	printf("short:%d\n", sizeof(short));
	printf("int:%d\n", sizeof(int));
	printf("long:%d\n", sizeof(long));
	printf("long long:%d\n", sizeof(long long));
	printf("float:%d\n", sizeof(float));
	printf("double:%d\n", sizeof(double));
}


int main()
{
	//CheckSystem1();
	//CheckSystem2();

	//Char();

	ZiJie();
	system("pause");
	return 0;
}