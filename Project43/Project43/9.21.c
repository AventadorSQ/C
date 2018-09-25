#include "game.h"
void InitBoard(char arr[ROW][COL], int row, int col)
{
	memset(arr, ' ', col*row * sizeof(arr[0][0]));
	//int i = 0;
	//int j = 0;
	//for (i = 0; i < row; i++) {
	//	for (j = 0; j < col; j++)
	//	{
	//		arr[i][j]=' ';
	//	}
	//}
}

void Display(char arr[ROW][COL], int row, int col)
{
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
		if ((i >= 0) && (i < row ))
		{
			for (j = 0; j < COL; j++)
			{
				printf("| %c ",arr[i][j]);
			}
			printf("|%2d\n",i+1);
			for (j = 0; j < COL; j++)
			{
				printf("----");
			}
			printf("-\n");
		}
		//for (j = 0; j < row; j++)
		//{
		//	printf("  %d ", j + 1);
		//}
	}
	for (j = 0; j < row; j++)
	{
		printf(" %2d ", j + 1);
	}
	printf("\n");
}

void ComputerMove(char arr[ROW][COL])
{
	int x = 0;
	int y = 0;
	while (1)
	{
		x = rand() % ROW;
		y = rand() % COL;
		if (arr[x][y] == ' ')
		{
			arr[x][y] = '0';
			break;
		}
	}
}

void PlayerMove(char arr[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	while (1)
	{
		printf("请输入坐标：");
		scanf("%d%d", &x, &y);
		x--;
		y--;
		if ((x >= 0) && (x <= ROW-1) && (y >= 0) && (y <= COL-1))
		{
			if (arr[x][y] == ' ')
			{
				arr[x][y] = '*';
				break;
			}
			else
			{
				printf("坐标有误!!!\n");
			}
		}
		else
		{
			printf("坐标有误!!!\n");
		}
	}
}

int IsFull(char arr[ROW][COL], int row, int col)
{
	int i = 0, j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (arr[i][j] == ' ')
				return 0;
			break;
		}
	}
	return 1;
}
char IsWin(char arr[ROW][COL], int row, int col)
{
	int i = 0, j = 0;
	//棋子横排能赢得可能
	for (i = 0; i < row; i++)
	{
		for (j = 0; j <= col - 5; j++)//5是五子棋
		{
			if ((arr[i][j] == arr[i][j + 1]) && (arr[i][j + 1] == arr[i][j + 2]) && (arr[i][j + 1] == arr[i][j + 3]) && (arr[i][j + 1] == arr[i][j + 4]) && (arr[i][j] != ' '))
			{
				return arr[i][j];
			}
		}
	}
//	printf("横排\n");
	//棋子竖排能赢得可能
	for (i = 0; i < col; i++)
	{
		for (j = 0; j <= row - 5; j++)//5可以替换
		{
			if ((arr[j][i] == arr[j + 1][i]) && (arr[j + 1][i] == arr[j + 2][i]) && (arr[j + 1][i] == arr[j + 3][i]) && (arr[j + 1][i] == arr[j + 4][i]) && (arr[j][i] != ' '))
			{
				return arr[j][i];
			}
		}
	}
//	printf("竖排\n");
	////主对角线系列赢的可能(测试版)
	//for (i = 0; i <= row - 5; i++)
	//{
	//	for (j = 0; j <= col - 5; j++)
	//	{
	//		printf("%cA", arr[i][j]);
	//		if ((arr[i][j] == arr[i + 1][j + 1]) && (arr[i + 1][j + 1] == arr[i + 2][j + 2]) && (arr[i + 2][j + 2] == arr[i + 3][j + 3]) && (arr[i + 3][j + 3] == arr[i + 4][j + 4]) && (arr[i][j] != ' '))
	//		{
	//			return arr[i][j];
	//		}
	//	}
	//	printf("\n");
	//}
	//printf("对角排\n");
	//主对角线系列赢的可能
	for (i = 0; i <= row - 5; i++)
	{
		for (j = 0; j <= col - 5; j++)
		{
			if ((arr[i][j] == arr[i + 1][j + 1]) && (arr[i + 1][j + 1] == arr[i + 2][j + 2]) && (arr[i + 2][j + 2] == arr[i + 3][j + 3]) && (arr[i + 3][j + 3] == arr[i + 4][j + 4]) && (arr[i][j] != ' '))
			{
				return arr[i][j];
			}
		}
	}
//	printf("对角排\n");
////	副对角线系列赢的可能(测试版)
//	for (i = row-5; i >=0; i--)
//	{
//		for (j = 0; j <=col-5; j++)
//		{
//			//printf("%cA", arr[i][j]);
//			if ((arr[i + 4][j] == arr[i + 3][j + 1])
//				&& (arr[i + 3][j + 1] == arr[i + 2][j + 2])
//				&& (arr[i + 2][j + 2] == arr[i + 1][j + 3])
//				&& (arr[i + 1][j + 3] == arr[i][j + 4])
//				&& (arr[i + 4][j] != ' '))
//			{
//				return arr[i + 4][j];
//			}
//		}
//		//printf("\n");
//	}
	//副对角线赢得可能
	for (i = 0; i <= row - 5; i++)
	{
		for (j = col - 5; j >= 0; j--)
		{
			if     ((arr[i][j + 4] == arr[i + 1][j + 3])
				&& (arr[i + 1][j + 3] == arr[i + 2][j + 2]) 
				&& (arr[i + 2][j + 2] == arr[i + 3][j + 1]) 
				&& (arr[i + 3][j + 1] == arr[i + 4][j]) 
				&& (arr[i][j + 4] != ' '))
			{
				return arr[i][j + 4];
			}
		}

	}
//	printf("反对角排\n");
	if (IsFull(arr, row, col))
	{
		return'q';
	}
	return' ';
}
