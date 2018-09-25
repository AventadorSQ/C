#include "game.h"
void menu()
{
	printf("************************************************\n");
	printf("******      1.开始            0.结束      ******\n");
	printf("************************************************\n");
	printf("******           *表示玩家走棋            ******\n");
	printf("******           0表示电脑走棋            ******\n");
	printf("************************************************\n");
}

void game()
{
	char arr[ROW][COL];
	char set ;
	InitBoard(arr, ROW, COL);
//	Display(arr, ROW, COL);
	do
	{
		ComputerMove(arr);
		Display(arr, ROW, COL);
		set = IsWin(arr, ROW, COL);
		if (set != ' ')
		{
			break;
		}
		PlayerMove(arr, ROW, COL);
		Display(arr, ROW, COL);
		set = IsWin(arr, ROW, COL);
		if (set != ' ')
		{
			break;
		}
		printf("********************************************\n");
		printf("********************************************\n");
	} while (set==' ');//set == ' '
	if (set == '*')
	{
		printf("恭喜你赢了\n");
	}
	else if (set == '0')
	{
		printf("电脑赢了\n");
	}
	else if (set == 'p')
	{
		printf("平局\n");
	}
}
void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请选择：>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			break;
		default:
			printf("选择失败!!!\n");
			break;
		}
	} while (input);
}

int main()
{
	test();
	system("pause");
	return 0;
}
