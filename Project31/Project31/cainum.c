#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<time.h>



void game()
{
	int number3 = 0;
	int number2 = rand() % 101;
	int count = 1;
	printf("请猜1～100之间的某一数字\n");
	//printf("number2=%d\n", number2);
	while (1)
	{
		printf("请猜数字:");
		scanf("%d", &number3);
		if (number3 == number2)
		{
			printf("恭喜你,猜对了\n");
			break;
		}
		else if (number3 > number2)
		{
			printf("猜大了\n");
		}
		else
		{
			printf("猜小了\n");
		}
		count++;
	}
	printf("本次一共猜了%d次\n", count);
	printf("按1继续，按0结束游戏\n");
	printf("如果不爽再战一把吗亲？\n");
}

int main()
{
	int number1 = 0;
	printf("*******************************************************\n");
	printf("******************* “猜数字游戏”*********************\n");
	printf("*******************  1 开始游戏   *********************\n");
	printf("*******************  0 结束游戏   *********************\n");
	printf("*******************************************************\n");


	do
	{
		printf("请选择:");
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
			printf("输入错误！\n");
			break;
		}
	} while (number1);

	system("pause");
	return 0;
}