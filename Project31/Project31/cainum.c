#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<time.h>



void game()
{
	int number3 = 0;
	int number2 = rand() % 101;
	int count = 1;
	printf("���1��100֮���ĳһ����\n");
	//printf("number2=%d\n", number2);
	while (1)
	{
		printf("�������:");
		scanf("%d", &number3);
		if (number3 == number2)
		{
			printf("��ϲ��,�¶���\n");
			break;
		}
		else if (number3 > number2)
		{
			printf("�´���\n");
		}
		else
		{
			printf("��С��\n");
		}
		count++;
	}
	printf("����һ������%d��\n", count);
	printf("��1��������0������Ϸ\n");
	printf("�����ˬ��սһ�����ף�\n");
}

int main()
{
	int number1 = 0;
	printf("*******************************************************\n");
	printf("******************* ����������Ϸ��*********************\n");
	printf("*******************  1 ��ʼ��Ϸ   *********************\n");
	printf("*******************  0 ������Ϸ   *********************\n");
	printf("*******************************************************\n");


	do
	{
		printf("��ѡ��:");
		scanf("%d", &number1);
		srand((unsigned int)time(NULL));

		switch (number1)
		{
		case 1:
			game();
			break;
		case 0:
			break;
		default:
			printf("�������\n");
			break;
		}
	} while (number1);

	system("pause");
	return 0;
}