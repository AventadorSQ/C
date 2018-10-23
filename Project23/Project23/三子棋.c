
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
			printf("-------------\n");
		}
		printf("| %c | %c | %c |\n", arr[i][0], arr[i][1], arr[i][2]);
		if (i != row - 1)
		{
			printf("|---|---|---|\n");
		}
		if (i == row - 1)
		{
			printf("-------------\n");
		}
	}
}
int x = 0;
int y = 0;
void ComputerMove(char arr[ROW][COL])
{
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
		if ((x >= 0) && (x <= 2) && (y >= 0) && (y <= 2))
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
	for (i = 0; i < row; i++)
	{
		for (j = 0; j <= col - 3; j++)//3是三子棋,3可以替换
		{
			if ((arr[i][j] == arr[i][j + 1]) && (arr[i][j + 1] == arr[i][j + 2]) && (arr[i][j] != ' '))
			{
				return arr[i][j];
			}
		}
	}
	for (i = 0; i < col; i++)
	{
		for (j = 0; j <= row - 3; j++)//3是三子棋,3可以替换
		{
			if ((arr[i][j] == arr[i][j + 1]) && (arr[i][j + 1] == arr[i][j + 2]) && (arr[i][j] != ' '))
			{
				return arr[i][j];
			}
		}
	}
	for (i = 0; i <= row - 3; i++)
	{
		for (j = 0; j <= col - 3; j++)
		{
			if ((arr[i][j] == arr[i + 1][j + 1]) && (arr[i][i] == arr[i + 1][j + 1]) && (arr[i + 1][j + 1] == arr[i + 2][j + 2]) && (arr[i][j] != ' '))
			{
				return arr[i][j];
			}
		}
	}
	for (i = 0; i = row - 3; i++)
	{
		for (j = col - 3; j >= 0; j--)
		{
			if ((arr[i][j + 2] == arr[i + 1][j + 1]) && (arr[i][i] == arr[i + 1][j + 1]) && (arr[i + 1][j + 1] == arr[i + 2][j]) && (arr[i][j] != ' '))
			{
				return arr[i][j];
			}
		}
	}

	if (IsFull(arr, row, col))
	{
		return'q';
	}
	return' ';
}