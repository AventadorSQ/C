#include"扫雷头文件.h"


//播放音乐
void MyPlaySound()
{
	PlaySound("李白.wav", NULL, SND_FILENAME | SND_ASYNC);
}

//打印菜单
int Menu(int* Select)
{
	printf("*********************************************\n");
	printf("***                                       ***\n");
	printf("***          1.Play   0.Exit              ***\n");
	printf("***                                       ***\n");
	printf("*********************************************\n");
	printf("请选择：\n");
	scanf("%d", Select);
	return *Select;
}

//判断是否开始游戏
void IsPlay(int* Select)
{
	while (1)
	{
		if (*Select == 1)
		{
			Game();
		}
		else if (*Select == 0)
		{
			printf("游戏结束!!!\n");
			break;
		}
		else
		{
			system("cls");
			Sleep(100);
			printf("输入错误！！！\n请重新输入\n");
			Menu(Select);
		}

	}
}

void InitQiPan(char ArrLeiMap[ROW][COL], int row, int col)//初始化雷盘
{
	memset(ArrLeiMap, ' ', col*row * sizeof(ArrLeiMap[0][0]));
	int count1 = 0;//记录雷的个数
	int num = 0;
	for (int i = 0; i < (COL * ROW); i++)
	{
		row = rand() % 10;
		col = rand() % 10;
		if (ArrLeiMap[row][col] == ' ')
		{
			ArrLeiMap[row][col] = '*';

			count1++;//记录已布雷的个数
			//标记周围的雷数
			num = num + 1;
			//ArrLeiMap[row - 1][col - 1] = num;
			//ArrLeiMap[row - 1][col] = num;
			//ArrLeiMap[row - 1][col + 1] = num;
			//ArrLeiMap[row][col - 1] = num;
			//ArrLeiMap[row][col + 1] = num;
			//ArrLeiMap[row + 1][col - 1] = num;
			//ArrLeiMap[row + 1][col] = num;
			//ArrLeiMap[row + 1][col + 1] = num;
			ArrLeiMap[row - 1][col - 1] = 'num';
			ArrLeiMap[row - 1][col] = 'num';
			ArrLeiMap[row - 1][col + 1] = 'num';
			ArrLeiMap[row][col - 1] = 'num';
			ArrLeiMap[row][col + 1] = 'num';
			ArrLeiMap[row + 1][col - 1] = 'num';
			ArrLeiMap[row + 1][col] = 'num';
			ArrLeiMap[row + 1][col + 1] = 'num';
		}
		if (count1 == (2 * ROW))
		{
			break;
		}
	}
}

void InitShowPan(char ArrShowMap[ROW][COL], int row, int col)//初始化用户界面盘
{
	memset(ArrShowMap, '9', col*row * sizeof(ArrShowMap[0][0]));
}
void PrintShow(char ArrShowMap[ROW][COL], int row, int col)//打印展示的界面棋盘
{
	system("cls");
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		if (i == 0)
		{
			for (j = 0; j < COL; j++)
			{
				printf("----");
			}
			printf("-\n");
		}
		if ((i >= 0) && (i < row))
		{
			for (j = 0; j < COL; j++)
			{
				printf("| %c ", ArrShowMap[i][j]);
			}
			printf("|%2d\n", i + 1);
			for (j = 0; j < COL; j++)
			{
				printf("----");
			}
			printf("-\n");
		}
	}
	for (j = 0; j < row; j++)
	{
		printf(" %2d ", j + 1);
	}
	printf("\n");
}

void Scanf(char ArrShowMap[ROW][COL], char ArrLeiMap[ROW][COL], int row, int col,int* count)
{
	printf("请输入要猜的下标:");
	while (1)
	{
		scanf("%d %d", &row, &col);
		if ((row <= ROW) && (row > 0) && (col <= COL) && (col > 0))
		{
			if (ArrShowMap[row - 1][col - 1] == '9')
			{
				ArrShowMap[row - 1][col - 1] = ArrLeiMap[row - 1][col - 1];
				*count++;
				break;
			}
			if (ArrShowMap[row - 1][col - 1] != '9')
			{
				printf("请重新输入下标：\n");
			}
		}
		else
		{
			printf("请重新输入下标：\n");
		}
	}
}

//判断是否踩雷并判断输赢
void IsWin(char ArrShowMap[ROW][COL],char ArrLeiMap[ROW][COL], int row, int col, int* count)
{
	for (row = 0; row < ROW; row++)
	{
		for (col = 0; col < COL; col++)
		{
			if (ArrShowMap[row][col] == '*')
			{
				printf("您踩雷了\n");
				PrintShow(ArrLeiMap, ROW, COL);
				break;
			}
			else
			{
				if (*count == (ROW*COL - 2 * ROW))
				{
					printf("玩家胜利\n");
				}
			}
		}
	}
}