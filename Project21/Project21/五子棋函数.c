#include "五子棋头文件.h"

//初始化棋盘
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

//打印棋盘
void Display(char arr[ROW][COL], int row, int col)
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
				printf("| %c ", arr[i][j]);
			}
			printf("|%2d\n", i + 1);
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

//***********************************************************************************************************************************************
//根据规定规则来判断得分
//1.得分标准规则：没有棋子直接下棋，有1棋子得1分，（一）冲1得1分（至少一条线被堵着），（二）活1得2分（一个子且没有一条线没被堵着），（三）冲2得3分（两个子但一边被堵着）
//                                                （四）活2得4分(两个子)，（五）双活2得5分（四个字），（六）冲3得4分（三个子但一边被堵着）（七）活三得5（三个子）
//                                                 (八) 冲四得5分         （九）活4得6分（4个子）//    （十）五个棋得7分（break）(用于判断)


//  只判断(电脑)最高得分，分数不会累加。
int IsRuleComScore(char arr[ROW][COL], int row, int col, int MaxComScore)
{
	//int row = 0;
	//int col = 0;

	//（十）五个棋得7分（break）(用于判断)
	//10.1横排
	for (row = 0; row < ROW; row++)
	{
		for (col = 0; col < COL; col++)
		{
			if ((arr[row][col] == arr[row][col + 1]) && (arr[row][col] == arr[row][col + 2]) && (arr[row][col] == arr[row][col + 3]) && (arr[row][col] == arr[row][col + 4])
				&& (arr[row][col] == '0'))
			{
				MaxComScore = 10;
				return MaxComScore;
			}
		}
	}
	//10.2竖排
	for (row = 0; row < ROW; row++)
	{
		for (col = 0; col <= COL - 5; col++)//5可以替换
		{
			if ((arr[col][row] == arr[col + 1][row]) && (arr[col + 1][row] == arr[col + 2][row]) && (arr[col + 1][row] == arr[col + 3][row]) && (arr[col + 1][row] == arr[col + 4][row])
				&& (arr[col][row] == '0'))
			{
				MaxComScore = 10;
				return MaxComScore;
			}
		}
	}
	//10.3主对角线
	for (row = 0; row <= ROW - 5; row++)
	{
		for (col = 0; col <= COL - 5; col++)
		{
			if ((arr[row][col] == arr[row + 1][col + 1]) && (arr[row + 1][col + 1] == arr[row + 2][col + 2]) && (arr[row + 2][col + 2] == arr[row + 3][col + 3]) && (arr[row + 3][col + 3] == arr[row + 4][col + 4])
				&& (arr[row][col] == '0'))
			{
				MaxComScore = 10;
				return MaxComScore;
			}
		}
	}
	//10.4副对角线
	for (row = 0; row <= ROW - 5; row++)
	{
		for (col = COL - 5; col >= 0; col--)
		{
			if ((arr[row][col + 4] == arr[row + 1][col + 3])
				&& (arr[row + 1][col + 3] == arr[row + 2][col + 2])
				&& (arr[row + 2][col + 2] == arr[row + 3][col + 1])
				&& (arr[row + 3][col + 1] == arr[row + 4][col])
				&& (arr[row][col + 4] == '0'))
			{
				MaxComScore = 10;
				return MaxComScore;
			}
		}
	}


	//(九)活4得6分(已连接连续的4个棋子且两边都没有对方棋子)
	//9.1.先判断横排
	for (row = 0; row < ROW; row++)
		for (col = 1; col < COL - 4; col++)
		{
			if ((arr[row][col] == arr[row][col + 1]) && (arr[row][col] == arr[row][col + 2]) && (arr[row][col] == arr[row][col + 3])
				&& (arr[row][col] == '0') && ((arr[row][col - 1] == ' ') && (arr[row][col + 4] == ' ')))
			{
				MaxComScore = 9;
				return MaxComScore;
			}
		}
	//9.2.判断竖排
	for (col = 0; col < COL; col++)//for (col = 0; col < COL; col++)
		for (row = 1; row < ROW - 4; row++)
		{
			if ((arr[row][col] == arr[row + 1][col]) && (arr[row][col] == arr[row + 2][col]) && (arr[row][col] == arr[row + 3][col])
				&& (arr[row][col] == '0') && (arr[row - 1][col] == ' ') && (arr[row + 4][col] == ' '))
			{
				MaxComScore = 9;
				return MaxComScore;
			}
		}
	//9.3.判断主对角线
	for (row = 1; row < ROW - 6; row++)
		for (col = 1; col < COL - 4; col++)
		{
			if ((arr[row][col] == arr[row + 1][col + 1]) && (arr[row][col] == arr[row + 2][col + 2]) && (arr[row][col] == arr[row + 3][col + 3])
				&& (arr[row][col] == '0') && (arr[row - 1][col - 1] == ' ') && (arr[row + 4][col + 4] == ' '))
			{
				MaxComScore = 9;
				return MaxComScore;
			}
		}
	//9.4.判断副对角线
	for (row = 1; row <ROW - 4; row++)
	{
		for (col = COL - 5; col >= 1; col--)
		{
			if ((arr[row][col + 3] == arr[row + 1][col + 2]) && (arr[row][col + 3] == arr[row + 2][col + 1]) && (arr[row][col + 3] == arr[row + 3][col])
				&& (arr[row][col + 3] == '0') && (arr[row - 1][col + 4] == ' ') && (arr[row + 4][col - 1] == ' '))
			{
				MaxComScore = 9;
				return MaxComScore;
			}
		}
	}
	//(八) 冲四得5分
    //8.1.先判断横排
	for (row = 0; row < ROW; row++)
		for (col = 1; col < COL - 4; col++)
		{
			if ((arr[row][col] == arr[row][col + 1]) && (arr[row][col] == arr[row][col + 2]) && (arr[row][col] == arr[row][col + 3])
				&& (arr[row][col] == '0') && ((arr[row][col - 1] == '*') && (arr[row][col + 4] == ' ')) || ((arr[row][col - 1] == ' ') && (arr[row][col + 4] == '*')))
			{
				MaxComScore = 8;
				return MaxComScore;
			}
		}
	//8.2.判断竖排
	for (col = 0; col < COL; col++)//for (col = 0; col < COL; col++)
		for (row = 1; row < ROW - 4; row++)
		{
			if ((arr[row][col] == arr[row + 1][col]) && (arr[row][col] == arr[row + 2][col]) && (arr[row][col] == arr[row + 3][col])
				&& (arr[row][col] == '0') && ((arr[row - 1][col] == '*') && (arr[row + 4][col] == ' ')) || ((arr[row - 1][col] == ' ') && (arr[row + 4][col] == '*')))
			{
				MaxComScore = 8;
				return MaxComScore;
			}
		}
	//8.3.判断主对角线
	for (row = 1; row < ROW - 6; row++)
		for (col = 1; col < COL - 4; col++)
		{
			if ((arr[row][col] == arr[row + 1][col + 1]) && (arr[row][col] == arr[row + 2][col + 2]) && (arr[row][col] == arr[row + 3][col + 3])
				&& (arr[row][col] == '0') && ((arr[row - 1][col - 1] == '*') && (arr[row + 4][col + 4] == ' ')) || ((arr[row - 1][col - 1] == ' ') && (arr[row + 4][col + 4] == '*')))
			{
				MaxComScore = 8;
				return MaxComScore;
			}
		}
	//8.4.判断副对角线
	for (row = 1; row <ROW - 4; row++)
	{
		for (col = COL - 5; col >= 1; col--)
		{
			if ((arr[row][col + 3] == arr[row + 1][col + 2]) && (arr[row][col + 3] == arr[row + 2][col + 1]) && (arr[row][col + 3] == arr[row + 3][col])
				&& (arr[row][col + 3] == '0') && ((arr[row - 1][col + 4] == '*') && (arr[row + 4][col - 1] == ' ')) || ((arr[row - 1][col + 4] == ' ') && (arr[row + 4][col - 1] == '*')))
			{
				MaxComScore = 8;
				return MaxComScore;
			}
		}
	}


	//（七）活三（三个子）
	//7.1横排
	for (row = 0; row < ROW - 4; row++)
	{
		for (col = 1; col < COL; col++)
		{
			if (((arr[row][col] == arr[row][col + 1]) && (arr[row][col] == arr[row][col + 2]) && (arr[row][col] == '0')) &&
				(((arr[row][col - 1] == arr[row][col + 3]) && (arr[row][col - 1] == arr[row][col + 4]) && (arr[row][col - 1] == ' ')) ||
				((arr[row][col - 1] == arr[row][col + 3]) && (arr[row][col - 1] == arr[row][col - 2]) && (arr[row][col - 1] == ' '))))
			{
				MaxComScore = 7;
				return MaxComScore;
			}
		}
	}
	//7.2竖排
	for (col = 0; col < COL - 4; col++)
		for (row = 1; row < ROW; row++)
		{
			if (((arr[row][col] == arr[row + 1][col]) && (arr[row][col] == arr[row + 2][col]) && (arr[row][col] == '0')) &&
				(((arr[row - 1][col] == arr[row + 3][col]) && (arr[row - 1][col] == arr[row + 4][col]) && (arr[row - 1][col] == ' ')) ||
				((arr[row - 1][col] == arr[row + 3][col]) && (arr[row - 1][col] == arr[row - 2][col]) && (arr[row - 1][col] == ' '))))
			{
				MaxComScore = 7;
				return MaxComScore;
			}
		}
	//7.3主对角线
	for (row = 1; row < ROW - 4; row++)
	{
		for (col = 1; col < COL - 4; col++)
		{
			if (((arr[row][col] == arr[row + 1][col + 1]) && (arr[row][col] == arr[row + 2][col + 2]) && (arr[row][col] == '0')) &&
				(((arr[row - 1][col - 1] == arr[row + 3][col + 3]) && (arr[row - 1][col - 1] == arr[row + 4][col + 4]) && (arr[row - 1][col - 1] == ' ')) ||
				((arr[row - 1][col - 1] == arr[row + 3][col + 3]) && (arr[row - 1][col - 1] == arr[row - 2][col - 2]) && (arr[row - 1][col - 1] == ' '))))
			{
				MaxComScore = 7;
				return MaxComScore;
			}
		}
	}
	//7.4副对角线
	for (row = 1; row < ROW - 4; row++)
	{
		for (col = COL - 1; col > 4; col--)
		{
			if ((arr[row][col] == arr[row + 1][col - 1]) && (arr[row][col] == arr[row + 2][col - 2]) && (arr[row][col] == '0') &&
				(((arr[row - 1][col + 1] == arr[row + 3][col - 3]) && (arr[row - 1][col + 1] == arr[row + 4][col - 4]) && (arr[row - 1][col + 1] == ' ')) ||
				((arr[row - 1][col + 1] == arr[row + 3][col - 3]) && (arr[row - 2][col + 2] == arr[row + 3][col - 3]) && (arr[row - 1][col + 1] == ' '))))
			{
				MaxComScore = 7;
				return MaxComScore;
			}
		}
	}

	//（六）冲三（3颗子）
	//6.1横排
	for (row = 0; row < ROW - 4; row++)
	{
		for (col = 1; col < COL; col++)
		{
			if (((arr[row][col] == arr[row][col + 1]) && (arr[row][col] == arr[row][col + 2]) && (arr[row][col] == '0')) &&
				(((arr[row][col - 1] == '*') && (arr[row][col + 3] == arr[row][col + 4]) && (arr[row][col + 3] == ' ')) ||
				(('*' == arr[row][col + 3]) && (arr[row][col - 1] == arr[row][col - 2]) && (arr[row][col - 1] == ' '))))
			{
				MaxComScore = 6;
				return MaxComScore;
			}
		}
	}
	//6.2竖排
	for (col = 0; col < COL - 4; col++)
		for (row = 1; row < ROW; row++)
		{
			if (((arr[row][col] == arr[row + 1][col]) && (arr[row][col] == arr[row + 2][col]) && (arr[row][col] == '0')) &&
				(((arr[row - 1][col] == '*') && (arr[row + 3][col] == arr[row + 4][col]) && (arr[row + 3][col] == ' ')) ||
				(('*' == arr[row + 3][col]) && (arr[row - 1][col] == arr[row - 2][col]) && (arr[row - 1][col] == ' '))))
			{
				MaxComScore = 6;
				return MaxComScore;
			}
		}
	//6.3主对角线
	for (row = 1; row < ROW - 4; row++)
	{
		for (col = 1; col < COL - 4; col++)
		{
			if (((arr[row][col] == arr[row + 1][col + 1]) && (arr[row][col] == arr[row + 2][col + 2]) && (arr[row][col] == '0')) &&
				(((arr[row - 1][col - 1] =='*') && (arr[row + 3][col + 3] == arr[row + 4][col + 4]) && (arr[row + 3][col + 3] == ' ')) ||
				(('*' == arr[row + 3][col + 3]) && (arr[row - 1][col - 1] == arr[row - 2][col - 2]) && (arr[row - 1][col - 1] == ' '))))
			{
				MaxComScore = 6;
				return MaxComScore;
			}
		}
	}
	//6.4副对角线
	for (row = 1; row < ROW - 4; row++)
	{
		for (col = COL - 1; col > 4; col--)
		{
			if ((arr[row][col] == arr[row + 1][col - 1]) && (arr[row][col] == arr[row + 2][col - 2]) && (arr[row][col] == '0') &&
				(((arr[row - 1][col + 1] == '*') && (arr[row + 3][col - 3] == arr[row + 4][col - 4]) && (arr[row + 3][col - 3] == ' ')) ||
				(('*' == arr[row + 3][col - 3]) && (arr[row - 2][col + 2] == arr[row - 1][col + 1]) && (arr[row - 1][col + 1] == ' '))))
			{
				MaxComScore = 6;
				return MaxComScore;
			}
		}
	}

	//（五）双活2得5分（已有连续的2个棋子两组且两组有共同交点）
	//5.1.判断反八字型
	for (row = 1; row < ROW - 4; row++)
		for (col = 1; col < COL - 6; col++)
		{
			if ((arr[row][col] == arr[row + 1][col + 1]) && (arr[row + 1][col + 1] == arr[row + 1][col + 3]) && (arr[row + 1][col + 3] == arr[row][col + 4]) &&
				(arr[row][col] == '0') &&
				(arr[row - 1][col - 1] == arr[row + 2][col + 2]) && (arr[row + 2][col + 2] == arr[row - 1][col + 5]) && (arr[row + 2][col + 2] == arr[row + 3][col + 1])
				&& (arr[row + 3][col + 1] == arr[row + 4][col]) && (arr[row + 2][col + 2] == arr[row + 3][col + 3]) && (arr[row + 2][col + 2] == arr[row + 4][col + 4])
				&& (arr[row + 2][col + 2] == ' '))
			{
				MaxComScore = 5;
				return MaxComScore;
			}
		}
	//5.2.判断正八字型
	for (row = ROW - 2; row > 3; row--)
		for (col = COL - 2; col > 3; col--)
		{
			if ((arr[row][col] == arr[row - 1][col - 1]) && (arr[row - 1][col - 1] == arr[row - 1][col - 3]) && (arr[row - 1][col - 3] == arr[row][col - 4]) &&
				(arr[row][col] == '0') &&
				(arr[row + 1][col + 1] == arr[row - 2][col - 2]) && (arr[row - 2][col - 2] == arr[row + 1][col - 5]) && (arr[row - 2][col - 2] == arr[row - 3][col - 1])
				&& (arr[row - 3][col - 1] == arr[row - 4][col]) && (arr[row - 2][col - 2] == arr[row - 3][col - 3]) && (arr[row - 2][col - 2] == arr[row - 4][col - 4])
				&& (arr[row - 2][col - 2] == ' '))
			{
				MaxComScore = 5;
				return MaxComScore;
			}
		}
	//5.3.判断左立八字型
	for (row = 1; row < ROW - 6; row++)
	{
		for (col = 1; col < COL - 4; col++)
		{
			if ((arr[row][col] == arr[row + 1][col + 1]) && (arr[row + 1][col + 1] == arr[row + 3][col + 1]) && (arr[row + 3][col + 1] == arr[row + 4][col]) &&
				(arr[row][col] == '0') &&
				(arr[row - 1][col - 1] == arr[row + 2][col + 2]) && (arr[row + 2][col + 2] == arr[row + 1][col + 3]) && (arr[row + 2][col + 2] == arr[row + 3][col + 3])
				&& (arr[row + 3][col + 3] == arr[row + 5][col - 1]) && (arr[row + 2][col + 2] == arr[row][col + 4]) && (arr[row + 2][col + 2] == arr[row + 4][col + 4])
				&& (arr[row + 2][col + 2] == ' '))
			{
				MaxComScore = 5;
				return MaxComScore;
			}
		}
	}
	//5.4.判断右立八字形
	for (row = 1; row < ROW - 4; row++)//for (col = 1; col < COL - 4; col++)
	{
		for (col = COL - 7; col > 0; col--)
		{
			if ((arr[row][col] == arr[row + 1][col - 1]) && (arr[row + 1][col - 1] == arr[row + 3][col - 1]) && (arr[row + 3][col - 1] == arr[row + 4][col]) &&
				(arr[row][col] == '0') &&
				(arr[row - 1][col + 1] == arr[row + 2][col - 2]) && (arr[row + 2][col - 2] == arr[row + 1][col - 3]) && (arr[row + 2][col - 2] == arr[row + 3][col - 3])
				&& (arr[row + 3][col - 3] == arr[row + 5][col + 1]) && (arr[row + 2][col - 2] == arr[row][col - 4]) && (arr[row + 2][col - 2] == arr[row + 4][col - 4])
				&& (arr[row + 2][col - 2] == ' '))
			{
				MaxComScore = 5;
				return MaxComScore;
			}
		}
	}
	//（四）活2得4分(已有两颗棋子且两边都没有对方棋子)
	//4.1.横排
	for (row = 0; row < ROW; row++)
	{
		for (col = 1; col < COL - 4; col++)
		{
			if ((arr[row][col] == arr[row][col + 1]) && (arr[row][col] == '0') &&
				(((arr[row][col - 1] == arr[row][col + 2]) && (arr[row][col - 1] == arr[row][col + 3]) && (arr[row][col - 1] == arr[row][col + 4]) && (arr[row][col - 1] == ' '))
			    ||((arr[row][col - 1] == arr[row][col + 2]) && (arr[row][col - 1] == arr[row][col - 2]) && (arr[row][col - 1] == arr[row][col - 3]) && (arr[row][col - 1] == ' '))))
			{
				MaxComScore = 4;
				return MaxComScore;
			}
		}
	}
	//4.2.竖排
	for (col = 0; col < COL; col++)//for (col = 0; col < COL; col++)
	{
		for (row = 1; row < ROW - 4; row++)
		{
			if ((arr[row][col] == arr[row + 1][col]) && (arr[row][col] == '0') &&
				(((arr[row - 1][col] == arr[row + 2][col]) && (arr[row - 1][col] == arr[row + 3][col]) && (arr[row - 1][col] == arr[row + 4][col]) && (arr[row - 1][col] == ' '))
				||((arr[row - 1][col] == arr[row + 2][col]) && (arr[row - 1][col] == arr[row - 2][col]) && (arr[row - 1][col] == arr[row - 3][col]) && (arr[row - 1][col] == ' '))))
			{
				MaxComScore = 4;
				return MaxComScore;
			}
		}
	}
	//4.3.主对角线
	for (row = 1; row < ROW - 4; row++)
	{
		for (col = 1; col < COL - 4; col++)
		{
			if ((arr[row][col] == arr[row + 1][col + 1]) && (arr[row][col] == '0') &&
				(((arr[row - 1][col - 1] == arr[row + 2][col + 2]) && (arr[row - 1][col - 1] == arr[row + 3][col + 3]) && (arr[row - 1][col - 1] == arr[row + 4][col + 4])) ||
				((arr[row - 1][col - 1] == arr[row + 2][col + 2]) && (arr[row - 1][col - 1] == arr[row - 2][col - 2]) && (arr[row - 1][col - 1] == arr[row - 3][col - 3]))) &&
					(arr[row - 1][col - 1] == ' '))
			{
				MaxComScore = 4;
				return MaxComScore;
			}
		}
	}
	//4.4.副对角线
	for (row = 1; row < ROW - 4; row++)
	{
		for (col = COL - 5; col > 0; col--)
		{
			if ((arr[row][col] == arr[row + 1][col - 1]) && (arr[row][col] == '0') &&
				(((arr[row - 1][col + 1] == arr[row + 2][col - 2]) && (arr[row - 1][col + 1] == arr[row + 3][col - 3]) && (arr[row - 1][col + 1] == arr[row + 4][col - 4])) ||
				((arr[row - 1][col + 1] == arr[row + 2][col - 2]) && (arr[row - 1][col + 1] == arr[row - 2][col + 2]) && (arr[row - 1][col + 1] == arr[row - 3][col + 3]))) &&
					(arr[row - 1][col + 1] == ' '))
			{
				MaxComScore = 4;
				return MaxComScore;
			}
		}
	}
	//（三）冲2得3分（两个子但一边被堵着）
	//存在问题：没有判断边界
	//3.1横排
	for (row = 0; row < ROW; row++)
	{
		for (col = 1; col < COL - 4; col++)
		{
			if ((arr[row][col] == arr[row][col + 1]) && (arr[row][col] == '0') &&
				(((arr[row][col - 1] == '*') && (arr[row][col + 2] == arr[row][col + 3]) && (arr[row][col + 2] == arr[row][col + 4]) && (arr[row][col + 2] == ' ')) ||
				(('*' == arr[row][col + 2]) && (arr[row][col - 1] == arr[row][col - 2]) && (arr[row][col - 1] == arr[row][col - 3]) && (arr[row][col - 1] == ' '))))
			{
				MaxComScore = 3;
				return MaxComScore;
			}
		}
	}
	//3.2.竖排
	for (col = 0; col < COL; col++)//for (col = 0; col < COL; col++)
	{
		for (row = 1; row < ROW - 4; row++)
		{
			if ((arr[row][col] == arr[row + 1][col]) && (arr[row][col] == '0') &&
				(((arr[row - 1][col] == '*') && (arr[row + 2][col] == arr[row + 3][col]) && (arr[row + 2][col] == arr[row + 4][col]) && (arr[row + 2][col] == ' ')) ||
				(('*' == arr[row + 2][col]) && (arr[row - 1][col] == arr[row - 2][col]) && (arr[row - 1][col] == arr[row - 3][col]) && (arr[row - 1][col] == ' '))))
			{
				MaxComScore = 3;
				return MaxComScore;
			}
		}
	}
	//3.3.主对角线
	for (row = 1; row < ROW - 4; row++)
	{
		for (col = 1; col < COL - 4; col++)
		{
			if ((arr[row][col] == arr[row + 1][col + 1]) && (arr[row][col] == '0') &&
				(((arr[row - 1][col - 1] == '*') && (arr[row + 2][col + 2] == arr[row + 3][col + 3]) && (arr[row + 2][col + 2] == arr[row + 4][col + 4]) && (arr[row + 2][col + 2] == ' ')) ||
				(('*' == arr[row + 2][col + 2]) && (arr[row - 1][col - 1] == arr[row - 2][col - 2]) && (arr[row - 1][col - 1] == arr[row - 3][col - 3]) && (arr[row - 1][col - 1] == ' '))))
			{
				MaxComScore = 3;
				return MaxComScore;
			}
		}
	}
	//3.4.副对角线
	for (row = 1; row < ROW - 4; row++)
	{
		for (col = COL - 5; col > 0; col--)
		{
			if ((arr[row][col] == arr[row + 1][col - 1]) && (arr[row][col] == '0') &&
				(((arr[row - 1][col + 1] == '*') && (arr[row + 2][col - 2] == arr[row + 3][col - 3]) && (arr[row + 2][col - 2] == arr[row + 4][col - 4]) && (arr[row + 2][col - 2] == ' ')) ||
				(('*' == arr[row + 2][col - 2]) && (arr[row - 1][col + 1] == arr[row - 2][col + 2]) && (arr[row - 1][col + 1] == arr[row - 3][col + 3]) && (arr[row - 1][col + 1] == ' '))))
			{
				MaxComScore = 3;
				return MaxComScore;
			}
		}
	}
	//（二）活1得2分（一个子且没有一条线没被堵着）
	for (row = 1; row < ROW - 1; row++)
	{
		for (col = 1; col < COL - 1; col++)
		{
			if ((arr[row][col] == '0') && (arr[row - 1][col - 1] == arr[row - 1][col]) && (arr[row - 1][col - 1] == arr[row - 1][col + 1]) && (arr[row][col + 1] == arr[row - 1][col + 1]) &&
				(arr[row][col + 1] == arr[row + 1][col + 1]) && (arr[row + 1][col] == arr[row + 1][col + 1]) && (arr[row + 1][col] == arr[row + 1][col - 1]) &&
				(arr[row][col - 1] == arr[row + 1][col - 1]) && (arr[row + 1][col - 1] == ' '))
			{
				MaxComScore = 2;
				return MaxComScore;
			}
			//（一）冲2得1分（至少一条线被堵着）
			else
			{
				MaxComScore = 1;
				return MaxComScore;
			}
		}
	}
	return 0;
}
//**************************************************************************************************************************************************

//**************************************************************************************************************************************************
//  只判断(玩家)最高得分，分数不会累加。
int IsRulePlaScore(char arr[ROW][COL], int row, int col, int MaxPlaScore)
{
	//int row = 0;
	//int col = 0;

	//（十）五个棋得7分（break）(用于判断)
	//10.1横排
	for (row = 0; row < ROW; row++)
	{
		for (col = 0; col < COL; col++)
		{
			if ((arr[row][col] == arr[row][col + 1]) && (arr[row][col] == arr[row][col + 2]) && (arr[row][col] == arr[row][col + 3]) && (arr[row][col] == arr[row][col + 4])
				&& (arr[row][col] == '*'))
			{
				MaxPlaScore = 10;
				return MaxPlaScore;
			}
		}
	}
	//10.2竖排
	for (row = 0; row < ROW; row++)
	{
		for (col = 0; col <= COL - 5; col++)//5可以替换
		{
			if ((arr[col][row] == arr[col + 1][row]) && (arr[col + 1][row] == arr[col + 2][row]) && (arr[col + 1][row] == arr[col + 3][row]) && (arr[col + 1][row] == arr[col + 4][row])
				&& (arr[col][row] == '*'))
			{
				MaxPlaScore = 10;
				return MaxPlaScore;
			}
		}
	}
	//10.3主对角线
	for (row = 0; row <= ROW - 5; row++)
	{
		for (col = 0; col <= COL - 5; col++)
		{
			if ((arr[row][col] == arr[row + 1][col + 1]) && (arr[row + 1][col + 1] == arr[row + 2][col + 2]) && (arr[row + 2][col + 2] == arr[row + 3][col + 3]) && (arr[row + 3][col + 3] == arr[row + 4][col + 4])
				&& (arr[row][col] == '*'))
			{
				MaxPlaScore = 10;
				return MaxPlaScore;
			}
		}
	}
	//10.4副对角线
	for (row = 0; row <= ROW - 5; row++)
	{
		for (col = COL - 5; col >= 0; col--)
		{
			if ((arr[row][col + 4] == arr[row + 1][col + 3])
				&& (arr[row + 1][col + 3] == arr[row + 2][col + 2])
				&& (arr[row + 2][col + 2] == arr[row + 3][col + 1])
				&& (arr[row + 3][col + 1] == arr[row + 4][col])
				&& (arr[row][col + 4] == '*'))
			{
				MaxPlaScore = 10;
				return MaxPlaScore;
			}
		}
	}


	//(九)活4得6分(已连接连续的4个棋子且两边都没有对方棋子)
	//9.1.先判断横排
	for (row = 0; row < ROW; row++)
		for (col = 1; col < COL - 4; col++)
		{
			if ((arr[row][col] == arr[row][col + 1]) && (arr[row][col] == arr[row][col + 2]) && (arr[row][col] == arr[row][col + 3])
				&& (arr[row][col] == '*') && ((arr[row][col - 1] == ' ') && (arr[row][col + 4] == ' ')))
			{
				MaxPlaScore = 9;
				return MaxPlaScore;
			}
		}
	//9.2.判断竖排
	for (col = 0; col < COL; col++)//for (col = 0; col < COL; col++)
		for (row = 1; row < ROW - 4; row++)
		{
			if ((arr[row][col] == arr[row + 1][col]) && (arr[row][col] == arr[row + 2][col]) && (arr[row][col] == arr[row + 3][col])
				&& (arr[row][col] == '*') && (arr[row - 1][col] == ' ') && (arr[row + 4][col] == ' '))
			{
				MaxPlaScore = 9;
				return MaxPlaScore;
			}
		}
	//9.3.判断主对角线
	for (row = 1; row < ROW - 6; row++)
		for (col = 1; col < COL - 4; col++)
		{
			if ((arr[row][col] == arr[row + 1][col + 1]) && (arr[row][col] == arr[row + 2][col + 2]) && (arr[row][col] == arr[row + 3][col + 3])
				&& (arr[row][col] == '*') && (arr[row - 1][col - 1] == ' ') && (arr[row + 4][col + 4] == ' '))
			{
				MaxPlaScore = 9;
				return MaxPlaScore;
			}
		}
	//9.4.判断副对角线
	for (row = 1; row <ROW - 4; row++)
	{
		for (col = COL - 5; col >= 1; col--)
		{
			if ((arr[row][col + 3] == arr[row + 1][col + 2]) && (arr[row][col + 3] == arr[row + 2][col + 1]) && (arr[row][col + 3] == arr[row + 3][col])
				&& (arr[row][col + 3] == '*') && (arr[row - 1][col + 4] == ' ') && (arr[row + 4][col - 1] == ' '))
			{
				MaxPlaScore = 9;
				return MaxPlaScore;
			}
		}
	}
	//(八) 冲四得5分
	//8.1.先判断横排
	for (row = 0; row < ROW; row++)
		for (col = 1; col < COL - 4; col++)
		{
			if ((arr[row][col] == arr[row][col + 1]) && (arr[row][col] == arr[row][col + 2]) && (arr[row][col] == arr[row][col + 3])
				&& (arr[row][col] == '*') && ((arr[row][col - 1] == '0') && (arr[row][col + 4] == ' ')) || ((arr[row][col - 1] == ' ') && (arr[row][col + 4] == '0')))
			{
				MaxPlaScore = 8;
				return MaxPlaScore;
			}
		}
	//8.2.判断竖排
	for (col = 0; col < COL; col++)//for (col = 0; col < COL; col++)
		for (row = 1; row < ROW - 4; row++)
		{
			if ((arr[row][col] == arr[row + 1][col]) && (arr[row][col] == arr[row + 2][col]) && (arr[row][col] == arr[row + 3][col])
				&& (arr[row][col] == '*') && ((arr[row - 1][col] == '0') && (arr[row + 4][col] == ' ')) || ((arr[row - 1][col] == ' ') && (arr[row + 4][col] == '0')))
			{
				MaxPlaScore = 8;
				return MaxPlaScore;
			}
		}
	//8.3.判断主对角线
	for (row = 1; row < ROW - 6; row++)
		for (col = 1; col < COL - 4; col++)
		{
			if ((arr[row][col] == arr[row + 1][col + 1]) && (arr[row][col] == arr[row + 2][col + 2]) && (arr[row][col] == arr[row + 3][col + 3])
				&& (arr[row][col] == '*') && ((arr[row - 1][col - 1] == '0') && (arr[row + 4][col + 4] == ' ')) || ((arr[row - 1][col - 1] == ' ') && (arr[row + 4][col + 4] == '0')))
			{
				MaxPlaScore = 8;
				return MaxPlaScore;
			}
		}
	//8.4.判断副对角线
	for (row = 1; row <ROW - 4; row++)
	{
		for (col = COL - 5; col >= 1; col--)
		{
			if ((arr[row][col + 3] == arr[row + 1][col + 2]) && (arr[row][col + 3] == arr[row + 2][col + 1]) && (arr[row][col + 3] == arr[row + 3][col])
				&& (arr[row][col + 3] == '*') && ((arr[row - 1][col + 4] == '0') && (arr[row + 4][col - 1] == ' ')) || ((arr[row - 1][col + 4] == ' ') && (arr[row + 4][col - 1] == '0')))
			{
				MaxPlaScore = 8;
				return MaxPlaScore;
			}
		}
	}


	//（七）活三（三个子）
	//7.1横排
	for (row = 0; row < ROW - 4; row++)
	{
		for (col = 1; col < COL; col++)
		{
			if (((arr[row][col] == arr[row][col + 1]) && (arr[row][col] == arr[row][col + 2]) && (arr[row][col] == '*')) &&
				(((arr[row][col - 1] == arr[row][col + 3]) && (arr[row][col - 1] == arr[row][col + 4]) && (arr[row][col - 1] == ' ')) ||
				((arr[row][col - 1] == arr[row][col + 3]) && (arr[row][col - 1] == arr[row][col - 2]) && (arr[row][col - 1] == ' '))))
			{
				MaxPlaScore = 7;
				return MaxPlaScore;
			}
		}
	}
	//7.2竖排
	for (col = 0; col < COL - 4; col++)
		for (row = 1; row < ROW; row++)
		{
			if (((arr[row][col] == arr[row + 1][col]) && (arr[row][col] == arr[row + 2][col]) && (arr[row][col] == '*')) &&
				(((arr[row - 1][col] == arr[row + 3][col]) && (arr[row - 1][col] == arr[row + 4][col]) && (arr[row - 1][col] == ' ')) ||
				((arr[row - 1][col] == arr[row + 3][col]) && (arr[row - 1][col] == arr[row - 2][col]) && (arr[row - 1][col] == ' '))))
			{
				MaxPlaScore = 7;
				return MaxPlaScore;
			}
		}
	//7.3主对角线
	for (row = 1; row < ROW - 4; row++)
	{
		for (col = 1; col < COL - 4; col++)
		{
			if (((arr[row][col] == arr[row + 1][col + 1]) && (arr[row][col] == arr[row + 2][col + 2]) && (arr[row][col] == '*')) &&
				(((arr[row - 1][col - 1] == arr[row + 3][col + 3]) && (arr[row - 1][col - 1] == arr[row + 4][col + 4]) && (arr[row - 1][col - 1] == ' ')) ||
				((arr[row - 1][col - 1] == arr[row + 3][col + 3]) && (arr[row - 1][col - 1] == arr[row - 2][col - 2]) && (arr[row - 1][col - 1] == ' '))))
			{
				MaxPlaScore = 7;
				return MaxPlaScore;
			}
		}
	}
	//7.4副对角线
	for (row = 1; row < ROW - 4; row++)
	{
		for (col = COL - 1; col > 4; col--)
		{
			if ((arr[row][col] == arr[row + 1][col - 1]) && (arr[row][col] == arr[row + 2][col - 2]) && (arr[row][col] == '*') &&
				(((arr[row - 1][col + 1] == arr[row + 3][col - 3]) && (arr[row - 1][col + 1] == arr[row + 4][col - 4]) && (arr[row - 1][col + 1] == ' ')) ||
				((arr[row - 1][col + 1] == arr[row + 3][col - 3]) && (arr[row - 2][col + 2] == arr[row + 3][col - 3]) && (arr[row - 1][col + 1] == ' '))))
			{
				MaxPlaScore = 7;
				return MaxPlaScore;
			}
		}
	}

	//（六）冲三（3颗子）
	//6.1横排
	for (row = 0; row < ROW - 4; row++)
	{
		for (col = 1; col < COL; col++)
		{
			if (((arr[row][col] == arr[row][col + 1]) && (arr[row][col] == arr[row][col + 2]) && (arr[row][col] == '*')) &&
				(((arr[row][col - 1] == '0') && (arr[row][col + 3] == arr[row][col + 4]) && (arr[row][col + 3] == ' ')) ||
				(('0' == arr[row][col + 3]) && (arr[row][col - 1] == arr[row][col - 2]) && (arr[row][col - 1] == ' '))))
			{
				MaxPlaScore = 6;
				return MaxPlaScore;
			}
		}
	}
	//6.2竖排
	for (col = 0; col < COL - 4; col++)
		for (row = 1; row < ROW; row++)
		{
			if (((arr[row][col] == arr[row + 1][col]) && (arr[row][col] == arr[row + 2][col]) && (arr[row][col] == '*')) &&
				(((arr[row - 1][col] == '0') && (arr[row + 3][col] == arr[row + 4][col]) && (arr[row + 3][col] == ' ')) ||
				(('0' == arr[row + 3][col]) && (arr[row - 1][col] == arr[row - 2][col]) && (arr[row - 1][col] == ' '))))
			{
				MaxPlaScore = 6;
				return MaxPlaScore;
			}
		}
	//6.3主对角线
	for (row = 1; row < ROW - 4; row++)
	{
		for (col = 1; col < COL - 4; col++)
		{
			if (((arr[row][col] == arr[row + 1][col + 1]) && (arr[row][col] == arr[row + 2][col + 2]) && (arr[row][col] == '*')) &&
				(((arr[row - 1][col - 1] == '0') && (arr[row + 3][col + 3] == arr[row + 4][col + 4]) && (arr[row + 3][col + 3] == ' ')) ||
				(('0' == arr[row + 3][col + 3]) && (arr[row - 1][col - 1] == arr[row - 2][col - 2]) && (arr[row - 1][col - 1] == ' '))))
			{
				MaxPlaScore = 6;
				return MaxPlaScore;
			}
		}
	}
	//6.4副对角线
	for (row = 1; row < ROW - 4; row++)
	{
		for (col = COL - 1; col > 4; col--)
		{
			if ((arr[row][col] == arr[row + 1][col - 1]) && (arr[row][col] == arr[row + 2][col - 2]) && (arr[row][col] == '*') &&
				(((arr[row - 1][col + 1] == '0') && (arr[row + 3][col - 3] == arr[row + 4][col - 4]) && (arr[row + 3][col - 3] == ' ')) ||
				(('0' == arr[row + 3][col - 3]) && (arr[row - 2][col + 2] == arr[row - 1][col + 1]) && (arr[row - 1][col + 1] == ' '))))
			{
				MaxPlaScore = 6;
				return MaxPlaScore;
			}
		}
	}

	//（五）双活2得5分（已有连续的2个棋子两组且两组有共同交点）
	//5.1.判断反八字型
	for (row = 1; row < ROW - 4; row++)
		for (col = 1; col < COL - 6; col++)
		{
			if ((arr[row][col] == arr[row + 1][col + 1]) && (arr[row + 1][col + 1] == arr[row + 1][col + 3]) && (arr[row + 1][col + 3] == arr[row][col + 4]) &&
				(arr[row][col] == '*') &&
				(arr[row - 1][col - 1] == arr[row + 2][col + 2]) && (arr[row + 2][col + 2] == arr[row - 1][col + 5]) && (arr[row + 2][col + 2] == arr[row + 3][col + 1])
				&& (arr[row + 3][col + 1] == arr[row + 4][col]) && (arr[row + 2][col + 2] == arr[row + 3][col + 3]) && (arr[row + 2][col + 2] == arr[row + 4][col + 4])
				&& (arr[row + 2][col + 2] == ' '))
			{
				MaxPlaScore = 5;
				return MaxPlaScore;
			}
		}
	//5.2.判断正八字型
	for (row = ROW - 2; row > 3; row--)
		for (col = COL - 2; col > 3; col--)
		{
			if ((arr[row][col] == arr[row - 1][col - 1]) && (arr[row - 1][col - 1] == arr[row - 1][col - 3]) && (arr[row - 1][col - 3] == arr[row][col - 4]) &&
				(arr[row][col] == '*') &&
				(arr[row + 1][col + 1] == arr[row - 2][col - 2]) && (arr[row - 2][col - 2] == arr[row + 1][col - 5]) && (arr[row - 2][col - 2] == arr[row - 3][col - 1])
				&& (arr[row - 3][col - 1] == arr[row - 4][col]) && (arr[row - 2][col - 2] == arr[row - 3][col - 3]) && (arr[row - 2][col - 2] == arr[row - 4][col - 4])
				&& (arr[row - 2][col - 2] == ' '))
			{
				MaxPlaScore = 5;
				return MaxPlaScore;
			}
		}
	//5.3.判断左立八字型
	for (row = 1; row < ROW - 6; row++)
	{
		for (col = 1; col < COL - 4; col++)
		{
			if ((arr[row][col] == arr[row + 1][col + 1]) && (arr[row + 1][col + 1] == arr[row + 3][col + 1]) && (arr[row + 3][col + 1] == arr[row + 4][col]) &&
				(arr[row][col] == '*') &&
				(arr[row - 1][col - 1] == arr[row + 2][col + 2]) && (arr[row + 2][col + 2] == arr[row + 1][col + 3]) && (arr[row + 2][col + 2] == arr[row + 3][col + 3])
				&& (arr[row + 3][col + 3] == arr[row + 5][col - 1]) && (arr[row + 2][col + 2] == arr[row][col + 4]) && (arr[row + 2][col + 2] == arr[row + 4][col + 4])
				&& (arr[row + 2][col + 2] == ' '))
			{
				MaxPlaScore = 5;
				return MaxPlaScore;
			}
		}
	}
	//5.4.判断右立八字形
	for (row = 1; row < ROW - 4; row++)//for (col = 1; col < COL - 4; col++)
	{
		for (col = COL - 7; col > 0; col--)
		{
			if ((arr[row][col] == arr[row + 1][col - 1]) && (arr[row + 1][col - 1] == arr[row + 3][col - 1]) && (arr[row + 3][col - 1] == arr[row + 4][col]) &&
				(arr[row][col] == '*') &&
				(arr[row - 1][col + 1] == arr[row + 2][col - 2]) && (arr[row + 2][col - 2] == arr[row + 1][col - 3]) && (arr[row + 2][col - 2] == arr[row + 3][col - 3])
				&& (arr[row + 3][col - 3] == arr[row + 5][col + 1]) && (arr[row + 2][col - 2] == arr[row][col - 4]) && (arr[row + 2][col - 2] == arr[row + 4][col - 4])
				&& (arr[row + 2][col - 2] == ' '))
			{
				MaxPlaScore = 5;
				return MaxPlaScore;
			}
		}
	}
	//（四）活2得4分(已有两颗棋子且两边都没有对方棋子)
	//4.1.横排
	for (row = 0; row < ROW; row++)
	{
		for (col = 1; col < COL - 4; col++)
		{
			if ((arr[row][col] == arr[row][col + 1]) && (arr[row][col] == '*') &&
				(((arr[row][col - 1] == arr[row][col + 2]) && (arr[row][col - 1] == arr[row][col + 3]) && (arr[row][col - 1] == arr[row][col + 4]) && (arr[row][col - 1] == ' '))
					|| ((arr[row][col - 1] == arr[row][col + 2]) && (arr[row][col - 1] == arr[row][col - 2]) && (arr[row][col - 1] == arr[row][col - 3]) && (arr[row][col - 1] == ' '))))
			{
				MaxPlaScore = 4;
				return MaxPlaScore;
			}
		}
	}
	//4.2.竖排
	for (col = 0; col < COL; col++)//for (col = 0; col < COL; col++)
	{
		for (row = 1; row < ROW - 4; row++)
		{
			if ((arr[row][col] == arr[row + 1][col]) && (arr[row][col] == '*') &&
				(((arr[row - 1][col] == arr[row + 2][col]) && (arr[row - 1][col] == arr[row + 3][col]) && (arr[row - 1][col] == arr[row + 4][col]) && (arr[row - 1][col] == ' '))
					|| ((arr[row - 1][col] == arr[row + 2][col]) && (arr[row - 1][col] == arr[row - 2][col]) && (arr[row - 1][col] == arr[row - 3][col]) && (arr[row - 1][col] == ' '))))
			{
				MaxPlaScore = 4;
				return MaxPlaScore;
			}
		}
	}
	//4.3.主对角线
	for (row = 1; row < ROW - 4; row++)
	{
		for (col = 1; col < COL - 4; col++)
		{
			if ((arr[row][col] == arr[row + 1][col + 1]) && (arr[row][col] == '*') &&
				(((arr[row - 1][col - 1] == arr[row + 2][col + 2]) && (arr[row - 1][col - 1] == arr[row + 3][col + 3]) && (arr[row - 1][col - 1] == arr[row + 4][col + 4])) ||
				((arr[row - 1][col - 1] == arr[row + 2][col + 2]) && (arr[row - 1][col - 1] == arr[row - 2][col - 2]) && (arr[row - 1][col - 1] == arr[row - 3][col - 3]))) &&
					(arr[row - 1][col - 1] == ' '))
			{
				MaxPlaScore = 4;
				return MaxPlaScore;
			}
		}
	}
	//4.4.副对角线
	for (row = 1; row < ROW - 4; row++)
	{
		for (col = COL - 5; col > 0; col--)
		{
			if ((arr[row][col] == arr[row + 1][col - 1]) && (arr[row][col] == '*') &&
				(((arr[row - 1][col + 1] == arr[row + 2][col - 2]) && (arr[row - 1][col + 1] == arr[row + 3][col - 3]) && (arr[row - 1][col + 1] == arr[row + 4][col - 4])) ||
				((arr[row - 1][col + 1] == arr[row + 2][col - 2]) && (arr[row - 1][col + 1] == arr[row - 2][col + 2]) && (arr[row - 1][col + 1] == arr[row - 3][col + 3]))) &&
					(arr[row - 1][col + 1] == ' '))
			{
				MaxPlaScore = 4;
				return MaxPlaScore;
			}
		}
	}
	//（三）冲2得3分（两个子但一边被堵着）
	//存在问题：没有判断边界
	//3.1横排
	for (row = 0; row < ROW; row++)
	{
		for (col = 1; col < COL - 4; col++)
		{
			if ((arr[row][col] == arr[row][col + 1]) && (arr[row][col] == '*') &&
				(((arr[row][col - 1] == '0') && (arr[row][col + 2] == arr[row][col + 3]) && (arr[row][col + 2] == arr[row][col + 4]) && (arr[row][col + 2] == ' ')) ||
				(('0' == arr[row][col + 2]) && (arr[row][col - 1] == arr[row][col - 2]) && (arr[row][col - 1] == arr[row][col - 3]) && (arr[row][col - 1] == ' '))))
			{
				MaxPlaScore = 3;
				return MaxPlaScore;
			}
		}
	}
	//3.2.竖排
	for (col = 0; col < COL; col++)//for (col = 0; col < COL; col++)
	{
		for (row = 1; row < ROW - 4; row++)
		{
			if ((arr[row][col] == arr[row + 1][col]) && (arr[row][col] == '*') &&
				(((arr[row - 1][col] == '0') && (arr[row + 2][col] == arr[row + 3][col]) && (arr[row + 2][col] == arr[row + 4][col]) && (arr[row + 2][col] == ' ')) ||
				(('0' == arr[row + 2][col]) && (arr[row - 1][col] == arr[row - 2][col]) && (arr[row - 1][col] == arr[row - 3][col]) && (arr[row - 1][col] == ' '))))
			{
				MaxPlaScore = 3;
				return MaxPlaScore;
			}
		}
	}
	//3.3.主对角线
	for (row = 1; row < ROW - 4; row++)
	{
		for (col = 1; col < COL - 4; col++)
		{
			if ((arr[row][col] == arr[row + 1][col + 1]) && (arr[row][col] == '*') &&
				(((arr[row - 1][col - 1] == '0') && (arr[row + 2][col + 2] == arr[row + 3][col + 3]) && (arr[row + 2][col + 2] == arr[row + 4][col + 4]) && (arr[row + 2][col + 2] == ' ')) ||
				(('0' == arr[row + 2][col + 2]) && (arr[row - 1][col - 1] == arr[row - 2][col - 2]) && (arr[row - 1][col - 1] == arr[row - 3][col - 3]) && (arr[row - 1][col - 1] == ' '))))
			{
				MaxPlaScore = 3;
				return MaxPlaScore;
			}
		}
	}
	//3.4.副对角线
	for (row = 1; row < ROW - 4; row++)
	{
		for (col = COL - 5; col > 0; col--)
		{
			if ((arr[row][col] == arr[row + 1][col - 1]) && (arr[row][col] == '*') &&
				(((arr[row - 1][col + 1] == '0') && (arr[row + 2][col - 2] == arr[row + 3][col - 3]) && (arr[row + 2][col - 2] == arr[row + 4][col - 4]) && (arr[row + 2][col - 2] == ' ')) ||
				(('0' == arr[row + 2][col - 2]) && (arr[row - 1][col + 1] == arr[row - 2][col + 2]) && (arr[row - 1][col + 1] == arr[row - 3][col + 3]) && (arr[row - 1][col + 1] == ' '))))
			{
				MaxPlaScore = 3;
				return MaxPlaScore;
			}
		}
	}
	//（二）活1得2分（一个子且没有一条线没被堵着）
	for (row = 1; row < ROW - 1; row++)
	{
		for (col = 1; col < COL - 1; col++)
		{
			if ((arr[row][col] == '*') && (arr[row - 1][col - 1] == arr[row - 1][col]) && (arr[row - 1][col - 1] == arr[row - 1][col + 1]) && (arr[row][col + 1] == arr[row - 1][col + 1]) &&
				(arr[row][col + 1] == arr[row + 1][col + 1]) && (arr[row + 1][col] == arr[row + 1][col + 1]) && (arr[row + 1][col] == arr[row + 1][col - 1]) &&
				(arr[row][col - 1] == arr[row + 1][col - 1]) && (arr[row + 1][col - 1] == ' '))
			{
				MaxPlaScore = 2;
				return MaxPlaScore;
			}
			//（一）冲2得1分（至少一条线被堵着）
			else
			{
				MaxPlaScore = 1;
				return MaxPlaScore;
			}
		}
	}
	return 0;
}
//**************************************************************************************************************************************************

//电脑下子
void ComputerMove(char arr[ROW][COL], int row, int col)
{
	//1.得分标准规则：没有棋子直接下棋，有1棋子得1分，（1）冲2得1分，（2）活2得2分，（3）双活2得4分，（4）冲3得3分
	//                                                （5）活3得4分，（6）双活3得5分，（7）活4得5分。
	//  只判断最高得分，分数不会累加。

	//2.循环依次遍历棋盘，先判断己方棋子。调用规则判断己方棋子得分。
	//3.再循环遍历对方棋子，并调用规则判断得分

	int num1 = 0;//记录棋子个数
	int MaxComScoreRow = 0;//记录电脑的最高分时的坐标
	int MaxComScoreCol = 9;
	int MaxPlaScoreRow = 9;//记录玩家的最高分时的坐标
	int MaxPlaScoreCol = 0;
	int ComScore = 0;//记录电脑得分
	int PlaScore = 0;//记录玩家得分
	while (1)
	{

		//判断有没有'0'
		for (row = 0; row < ROW; row++)
		{
			for (col = 0; col < COL; col++)
			{
				//
				//判断有没有'0'
				if (arr[row][col] == '0')
				{
					num1 = 1;//记录电脑棋子数目                                  ???优化
					break;
				}
			}
		}
		//当无子时下法
		if (num1 == 0)
		{
			arr[((ROW - 1) / 2)][((COL - 1) / 2)] = '0';
			break;
		}
		else
		{
			//根据判断得分来下子
			//判断7种得子返回最高得分
			//for (row = 0; row < ROW; row++)
			//{
			//	for (col = 0; col < COL; col++)
			//	{
			//		//调用规则来判断得分
			//		ComScore= IsRuleComScore( arr[ROW][COL], ROW, COL, ComScore);
			//	}
			//}
			ComScore = IsRuleComScore(arr, ROW, COL, ComScore);
			PlaScore = IsRulePlaScore(arr, ROW, COL, ComScore);
			//for (row = 0; row < ROW; row++)
			//{
			//	for (col = 0; col < COL; col++)
			//	{
			//		//调用规则判断玩家得分
			//		PlaScore = IsRuleComScore( arr, ROW, COL, ComScore);
			//	}
			//}
			//4.（判断双方得分高低）
			//如果对方棋子得分>电脑棋子得分则进行防守。
			//如果对方棋子得分<电脑棋子得分则进行进攻。
			//如果电脑棋子得分==对方棋子得分则进行进攻。
			//int MaxComScoreRow = 0;//记录电脑的最高分时的坐标
			//int MaxComScoreCol = 0;
			if (ComScore >= PlaScore)
			{
				int ComScore1 = 0;
				ComScore1 = ComScore;
				//先假设依次给每个空上下电脑的棋子判断电脑的得分高低
				//选择得分最高的位置进行下子
				for (row = 0; row < ROW; row++)
				{
					for (col = 0; col < COL; col++)
					{
						if (arr[row][col] == ' ')
						{
							arr[row][col] = '0';
							ComScore = IsRuleComScore(arr, ROW, COL, ComScore);
							if (ComScore > ComScore1)
							{
								MaxComScoreRow = row;
								MaxComScoreCol = col;
								ComScore1 = ComScore;
								arr[row][col] = ' ';
							}
							arr[row][col] = ' ';

						}
					}
				}
				arr[MaxComScoreRow][MaxComScoreCol] = '0';
				break;
			}
			else if (ComScore < PlaScore)
			{
				//先假设依次给每个空上下玩家的棋子判断玩家的得分高低
				//选择得分最高的位置进行下子
				int PlaScore1 = 0;
				PlaScore1 = PlaScore;
				for (row = 0; row < ROW; row++)
				{
					for (col = 0; col < COL; col++)
					{
						if (arr[row][col] == ' ')
						{
							arr[row][col] = '*';
							PlaScore = IsRulePlaScore(arr, ROW, COL, PlaScore);
							if (PlaScore > PlaScore1)
							{
								MaxPlaScoreRow = row;
								MaxPlaScoreCol = col;
								PlaScore1 = PlaScore;
								arr[row][col] = ' ';
							}
							arr[row][col] = ' ';
						}
					}
				}
				arr[MaxPlaScoreRow][MaxPlaScoreCol] = '0';
				break;
			}
		}
	}
	//int x = 0;
	//int y = 0;
	//while (1)
	//{
	//	x = rand() % ROW;
	//	y = rand() % COL;
	//	if (arr[x][y] == ' ')
	//	{
	//		arr[x][y] = '0';
	//		break;
	//	}
	//}
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
		if ((x >= 0) && (x <= ROW - 1) && (y >= 0) && (y <= COL - 1))
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
			if ((arr[i][j + 4] == arr[i + 1][j + 3])
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
