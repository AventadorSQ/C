#include "������ͷ�ļ�.h"

//��ʼ������
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

//��ӡ����
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
//���ݹ涨�������жϵ÷�
//1.�÷ֱ�׼����û������ֱ�����壬��1���ӵ�1�֣���һ����1��1�֣�����һ���߱����ţ�����������1��2�֣�һ������û��һ����û�����ţ�����������2��3�֣������ӵ�һ�߱����ţ�
//                                                ���ģ���2��4��(������)�����壩˫��2��5�֣��ĸ��֣�����������3��4�֣������ӵ�һ�߱����ţ����ߣ�������5�������ӣ�
//                                                 (��) ���ĵ�5��         ���ţ���4��6�֣�4���ӣ�//    ��ʮ��������7�֣�break��(�����ж�)


//  ֻ�ж�(����)��ߵ÷֣����������ۼӡ�
int IsRuleComScore(char arr[ROW][COL], int row, int col, int MaxComScore)
{
	//int row = 0;
	//int col = 0;

	//��ʮ��������7�֣�break��(�����ж�)
	//10.1����
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
	//10.2����
	for (row = 0; row < ROW; row++)
	{
		for (col = 0; col <= COL - 5; col++)//5�����滻
		{
			if ((arr[col][row] == arr[col + 1][row]) && (arr[col + 1][row] == arr[col + 2][row]) && (arr[col + 1][row] == arr[col + 3][row]) && (arr[col + 1][row] == arr[col + 4][row])
				&& (arr[col][row] == '0'))
			{
				MaxComScore = 10;
				return MaxComScore;
			}
		}
	}
	//10.3���Խ���
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
	//10.4���Խ���
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


	//(��)��4��6��(������������4�����������߶�û�жԷ�����)
	//9.1.���жϺ���
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
	//9.2.�ж�����
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
	//9.3.�ж����Խ���
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
	//9.4.�жϸ��Խ���
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
	//(��) ���ĵ�5��
    //8.1.���жϺ���
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
	//8.2.�ж�����
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
	//8.3.�ж����Խ���
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
	//8.4.�жϸ��Խ���
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


	//���ߣ������������ӣ�
	//7.1����
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
	//7.2����
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
	//7.3���Խ���
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
	//7.4���Խ���
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

	//������������3���ӣ�
	//6.1����
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
	//6.2����
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
	//6.3���Խ���
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
	//6.4���Խ���
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

	//���壩˫��2��5�֣�����������2�����������������й�ͬ���㣩
	//5.1.�жϷ�������
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
	//5.2.�ж���������
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
	//5.3.�ж�����������
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
	//5.4.�ж�����������
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
	//���ģ���2��4��(�����������������߶�û�жԷ�����)
	//4.1.����
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
	//4.2.����
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
	//4.3.���Խ���
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
	//4.4.���Խ���
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
	//��������2��3�֣������ӵ�һ�߱����ţ�
	//�������⣺û���жϱ߽�
	//3.1����
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
	//3.2.����
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
	//3.3.���Խ���
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
	//3.4.���Խ���
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
	//��������1��2�֣�һ������û��һ����û�����ţ�
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
			//��һ����2��1�֣�����һ���߱����ţ�
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
//  ֻ�ж�(���)��ߵ÷֣����������ۼӡ�
int IsRulePlaScore(char arr[ROW][COL], int row, int col, int MaxPlaScore)
{
	//int row = 0;
	//int col = 0;

	//��ʮ��������7�֣�break��(�����ж�)
	//10.1����
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
	//10.2����
	for (row = 0; row < ROW; row++)
	{
		for (col = 0; col <= COL - 5; col++)//5�����滻
		{
			if ((arr[col][row] == arr[col + 1][row]) && (arr[col + 1][row] == arr[col + 2][row]) && (arr[col + 1][row] == arr[col + 3][row]) && (arr[col + 1][row] == arr[col + 4][row])
				&& (arr[col][row] == '*'))
			{
				MaxPlaScore = 10;
				return MaxPlaScore;
			}
		}
	}
	//10.3���Խ���
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
	//10.4���Խ���
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


	//(��)��4��6��(������������4�����������߶�û�жԷ�����)
	//9.1.���жϺ���
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
	//9.2.�ж�����
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
	//9.3.�ж����Խ���
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
	//9.4.�жϸ��Խ���
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
	//(��) ���ĵ�5��
	//8.1.���жϺ���
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
	//8.2.�ж�����
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
	//8.3.�ж����Խ���
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
	//8.4.�жϸ��Խ���
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


	//���ߣ������������ӣ�
	//7.1����
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
	//7.2����
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
	//7.3���Խ���
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
	//7.4���Խ���
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

	//������������3���ӣ�
	//6.1����
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
	//6.2����
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
	//6.3���Խ���
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
	//6.4���Խ���
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

	//���壩˫��2��5�֣�����������2�����������������й�ͬ���㣩
	//5.1.�жϷ�������
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
	//5.2.�ж���������
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
	//5.3.�ж�����������
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
	//5.4.�ж�����������
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
	//���ģ���2��4��(�����������������߶�û�жԷ�����)
	//4.1.����
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
	//4.2.����
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
	//4.3.���Խ���
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
	//4.4.���Խ���
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
	//��������2��3�֣������ӵ�һ�߱����ţ�
	//�������⣺û���жϱ߽�
	//3.1����
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
	//3.2.����
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
	//3.3.���Խ���
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
	//3.4.���Խ���
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
	//��������1��2�֣�һ������û��һ����û�����ţ�
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
			//��һ����2��1�֣�����һ���߱����ţ�
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

//��������
void ComputerMove(char arr[ROW][COL], int row, int col)
{
	//1.�÷ֱ�׼����û������ֱ�����壬��1���ӵ�1�֣���1����2��1�֣���2����2��2�֣���3��˫��2��4�֣���4����3��3��
	//                                                ��5����3��4�֣���6��˫��3��5�֣���7����4��5�֡�
	//  ֻ�ж���ߵ÷֣����������ۼӡ�

	//2.ѭ�����α������̣����жϼ������ӡ����ù����жϼ������ӵ÷֡�
	//3.��ѭ�������Է����ӣ������ù����жϵ÷�

	int num1 = 0;//��¼���Ӹ���
	int MaxComScoreRow = 0;//��¼���Ե���߷�ʱ������
	int MaxComScoreCol = 9;
	int MaxPlaScoreRow = 9;//��¼��ҵ���߷�ʱ������
	int MaxPlaScoreCol = 0;
	int ComScore = 0;//��¼���Ե÷�
	int PlaScore = 0;//��¼��ҵ÷�
	while (1)
	{

		//�ж���û��'0'
		for (row = 0; row < ROW; row++)
		{
			for (col = 0; col < COL; col++)
			{
				//
				//�ж���û��'0'
				if (arr[row][col] == '0')
				{
					num1 = 1;//��¼����������Ŀ                                  ???�Ż�
					break;
				}
			}
		}
		//������ʱ�·�
		if (num1 == 0)
		{
			arr[((ROW - 1) / 2)][((COL - 1) / 2)] = '0';
			break;
		}
		else
		{
			//�����жϵ÷�������
			//�ж�7�ֵ��ӷ�����ߵ÷�
			//for (row = 0; row < ROW; row++)
			//{
			//	for (col = 0; col < COL; col++)
			//	{
			//		//���ù������жϵ÷�
			//		ComScore= IsRuleComScore( arr[ROW][COL], ROW, COL, ComScore);
			//	}
			//}
			ComScore = IsRuleComScore(arr, ROW, COL, ComScore);
			PlaScore = IsRulePlaScore(arr, ROW, COL, ComScore);
			//for (row = 0; row < ROW; row++)
			//{
			//	for (col = 0; col < COL; col++)
			//	{
			//		//���ù����ж���ҵ÷�
			//		PlaScore = IsRuleComScore( arr, ROW, COL, ComScore);
			//	}
			//}
			//4.���ж�˫���÷ָߵͣ�
			//����Է����ӵ÷�>�������ӵ÷�����з��ء�
			//����Է����ӵ÷�<�������ӵ÷�����н�����
			//����������ӵ÷�==�Է����ӵ÷�����н�����
			//int MaxComScoreRow = 0;//��¼���Ե���߷�ʱ������
			//int MaxComScoreCol = 0;
			if (ComScore >= PlaScore)
			{
				int ComScore1 = 0;
				ComScore1 = ComScore;
				//�ȼ������θ�ÿ�������µ��Ե������жϵ��Եĵ÷ָߵ�
				//ѡ��÷���ߵ�λ�ý�������
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
				//�ȼ������θ�ÿ����������ҵ������ж���ҵĵ÷ָߵ�
				//ѡ��÷���ߵ�λ�ý�������
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
		printf("���������꣺");
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
				printf("��������!!!\n");
			}
		}
		else
		{
			printf("��������!!!\n");
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
	//���Ӻ�����Ӯ�ÿ���
	for (i = 0; i < row; i++)
	{
		for (j = 0; j <= col - 5; j++)//5��������
		{
			if ((arr[i][j] == arr[i][j + 1]) && (arr[i][j + 1] == arr[i][j + 2]) && (arr[i][j + 1] == arr[i][j + 3]) && (arr[i][j + 1] == arr[i][j + 4]) && (arr[i][j] != ' '))
			{
				return arr[i][j];
			}
		}
	}
	//	printf("����\n");
	//����������Ӯ�ÿ���
	for (i = 0; i < col; i++)
	{
		for (j = 0; j <= row - 5; j++)//5�����滻
		{
			if ((arr[j][i] == arr[j + 1][i]) && (arr[j + 1][i] == arr[j + 2][i]) && (arr[j + 1][i] == arr[j + 3][i]) && (arr[j + 1][i] == arr[j + 4][i]) && (arr[j][i] != ' '))
			{
				return arr[j][i];
			}
		}
	}
	//	printf("����\n");
	////���Խ���ϵ��Ӯ�Ŀ���(���԰�)
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
	//printf("�Խ���\n");
	//���Խ���ϵ��Ӯ�Ŀ���
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
	//	printf("�Խ���\n");
	////	���Խ���ϵ��Ӯ�Ŀ���(���԰�)
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
	//���Խ���Ӯ�ÿ���
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
	//	printf("���Խ���\n");
	if (IsFull(arr, row, col))
	{
		return'q';
	}
	return' ';
}
