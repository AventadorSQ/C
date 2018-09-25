#include "game.h"
void menu()
{
	printf("************************************************\n");
	printf("******      1.��ʼ            0.����      ******\n");
	printf("************************************************\n");
	printf("******           *��ʾ�������            ******\n");
	printf("******           0��ʾ��������            ******\n");
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
		printf("��ϲ��Ӯ��\n");
	}
	else if (set == '0')
	{
		printf("����Ӯ��\n");
	}
	else if (set == 'p')
	{
		printf("ƽ��\n");
	}
}
void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("��ѡ��>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			break;
		default:
			printf("ѡ��ʧ��!!!\n");
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
