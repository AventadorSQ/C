#include"ɨ��ͷ�ļ�.h"


//��������
void MyPlaySound()
{
	PlaySound("���.wav", NULL, SND_FILENAME | SND_ASYNC);
}

//��ӡ�˵�
int Menu(int* Select)
{
	printf("*********************************************\n");
	printf("***                                       ***\n");
	printf("***          1.Play   0.Exit              ***\n");
	printf("***                                       ***\n");
	printf("*********************************************\n");
	printf("��ѡ��\n");
	scanf("%d", Select);
	return *Select;
}

//�ж��Ƿ�ʼ��Ϸ
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
			printf("��Ϸ����!!!\n");
			break;
		}
		else
		{
			system("cls");
			Sleep(100);
			printf("������󣡣���\n����������\n");
			Menu(Select);
		}

	}
}

void InitQiPan(char ArrLeiMap[ROW][COL])//��ʼ������
{
	int col = 0;
	int row = 0;
	memset(ArrLeiMap, ' ', ROW*COL * sizeof(ArrLeiMap[0][0]));
	int LeiCount = 0;//��¼�׵ĸ���
	int i = 0;
	int LeiNum = 0;//�����Χ�׵ĸ���
	for ( i = 0; i < (COL * ROW); i++)
	{
		row = rand() % 10;
		col = rand() % 10;
		if (ArrLeiMap[row][col] == ' ')
		{
			ArrLeiMap[row][col] = '*';

			LeiCount++;//��¼�Ѳ��׵ĸ���
		}
		if (LeiCount == (2 * ROW))
		{
			break;
		}
	}
	////ͳ����Χ�׵ĸ���
	//for (row = 0;row < ROW; row++)
	//{
	//	for (col = 0; col < COL; col++)
	//	{
	//		if (ArrLeiMap[row][col] != '*')
	//		{
	//			LeiNum = ((ArrLeiMap[row - 1][col - 1] - ' ') +
	//				(ArrLeiMap[row - 1][col] - ' ') +
	//				(ArrLeiMap[row - 1][col + 1] - ' ') +
	//				(ArrLeiMap[row][col - 1] - ' ') +
	//				(ArrLeiMap[row][col + 1] - ' ') +
	//				(ArrLeiMap[row + 1][col - 1] - ' ') +
	//				(ArrLeiMap[row + 1][col] - ' ') +
	//				(ArrLeiMap[row + 1][col + 1] - ' ')) / 10 + 16;
	//			ArrLeiMap[row][col] = ' ' + LeiNum;
	//		}
	//	}
	//}
}

void InitShowPan(char ArrShowMap[ROW][COL], int row, int col)//��ʼ���û�������
{
	memset(ArrShowMap, '9', col*row * sizeof(ArrShowMap[0][0]));
}
void PrintShow(char ArrShowMap[ROW][COL], char ArrLeiMap[ROW][COL], int row, int col)//��ӡչʾ�Ľ�������
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
				printf("| %c ", ArrLeiMap[i][j]);
			//	printf("| %c ", ArrShowMap[i][j]);
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


void Scanf(char ArrShowMap[ROW][COL], char ArrLeiMap[ROW][COL], int* ScanfRow, int* ScanfCol,int* count)
{
	int row = 0, col = 0;
	printf("������Ҫ�µ��±�:");
	while (1)
	{
		scanf("%d %d", &row, &col);
		if ((row <= ROW) && (row > 0) && (col <= COL) && (col > 0))
		{
			if (ArrShowMap[row - 1][col - 1] == '9')
			{
				ArrShowMap[row - 1][col - 1] = ArrLeiMap[row - 1][col - 1];
				*count++;
				*ScanfRow = row;
				*ScanfCol = col;
				break;
			}
			if (ArrShowMap[row - 1][col - 1] != '9')
			{
				printf("�����������±꣺\n");
			}
		}
		else
		{
			printf("���ٴ������±꣺\n");
		}
	}
}

//�ж��Ƿ���ײ��ж���Ӯ(���԰�)
void IsWin(char ArrShowMap[ROW][COL], char ArrLeiMap[ROW][COL], int* ScanfRow, int* ScanfCol, int* count)
{

			if (ArrLeiMap[*ScanfRow][*ScanfCol] == '*')
			{
				printf("��������\n");
				PrintShow(ArrShowMap, ArrLeiMap, ROW, COL);
			}
			else
			{
				if (*count == (ROW*COL - 2 * ROW))
				{
					printf("���ʤ��\n");
				}
			}
}

////�ж��Ƿ���ײ��ж���Ӯ
//void IsWin(char ArrShowMap[ROW][COL],char ArrLeiMap[ROW][COL], int row, int col, int* count)
//{
//	for (row = 0; row < ROW; row++)
//	{
//		for (col = 0; col < COL; col++)
//		{
//			if (ArrShowMap[row][col] == '*')
//			{
//				printf("��������\n");
//				PrintShow(ArrShowMap,ArrLeiMap, ROW, COL);
//				break;
//			}
//			else
//			{
//				if (*count == (ROW*COL - 2 * ROW))
//				{
//					printf("���ʤ��\n");
//				}
//			}
//		}
//	}
//}