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

void InitQiPan(char ArrLeiMap[ROW][COL], int row, int col)//��ʼ������
{
	memset(ArrLeiMap, ' ', col*row * sizeof(ArrLeiMap[0][0]));
	int count1 = 0;//��¼�׵ĸ���
	int num = 0;
	for (int i = 0; i < (COL * ROW); i++)
	{
		row = rand() % 10;
		col = rand() % 10;
		if (ArrLeiMap[row][col] == ' ')
		{
			ArrLeiMap[row][col] = '*';

			count1++;//��¼�Ѳ��׵ĸ���
			//�����Χ������
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

void InitShowPan(char ArrShowMap[ROW][COL], int row, int col)//��ʼ���û�������
{
	memset(ArrShowMap, '9', col*row * sizeof(ArrShowMap[0][0]));
}
void PrintShow(char ArrShowMap[ROW][COL], int row, int col)//��ӡչʾ�Ľ�������
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
				break;
			}
			if (ArrShowMap[row - 1][col - 1] != '9')
			{
				printf("�����������±꣺\n");
			}
		}
		else
		{
			printf("�����������±꣺\n");
		}
	}
}

//�ж��Ƿ���ײ��ж���Ӯ
void IsWin(char ArrShowMap[ROW][COL],char ArrLeiMap[ROW][COL], int row, int col, int* count)
{
	for (row = 0; row < ROW; row++)
	{
		for (col = 0; col < COL; col++)
		{
			if (ArrShowMap[row][col] == '*')
			{
				printf("��������\n");
				PrintShow(ArrLeiMap, ROW, COL);
				break;
			}
			else
			{
				if (*count == (ROW*COL - 2 * ROW))
				{
					printf("���ʤ��\n");
				}
			}
		}
	}
}