//**************************************************************
//1.
//5λ�˶�Ա�μ���10��̨��ˮ����������������Ԥ��������
//Aѡ��˵��B�ڶ����ҵ�����
//Bѡ��˵���ҵڶ���E���ģ�
//Cѡ��˵���ҵ�һ��D�ڶ���
//Dѡ��˵��C����ҵ�����
//Eѡ��˵���ҵ��ģ�A��һ��
//����������ÿλѡ�ֶ�˵����һ�룬����ȷ�����������Ρ�
//**************************************************************
//#include<Aventador_SQ.h>
//
//void MingCi()
//{
//	int arr[5] = { 0 };
//	//if (((arr[0] == 3) + (arr[1] == 2) == 1) + ((arr[1] == 2) + (arr[4] == 4) == 1) + ((arr[2] == 1) + (arr[3] == 2) == 1) + ((arr[2] == 3) + (arr[3] == 3) == 1) +
//	//	((arr[4] == 4) + (arr[0] == 1) == 1) == 5)
//	//{
//	//	printf("A=%d,B=%d,C=%d,D=%d,E=%d\n",arr[0],arr[1],arr[2],arr[3],arr[4]);
//	//}
//	for(arr[0] = 1; arr[0] <= 5; arr[0]++)
//		for (arr[1] = 1; arr[1] <= 5; arr[1]++)
//			for (arr[2] = 1; arr[2] <= 5; arr[2]++)
//				for (arr[3] = 1; arr[3] <= 5; arr[3]++)
//					for (arr[4] = 1; arr[4] <= 5; arr[4]++)
//					{
//						if (((arr[0] == 3) + (arr[1] == 2) == 1) + ((arr[1] == 2) + (arr[4] == 4) == 1) + ((arr[2] == 1) + (arr[3] == 2) == 1) + ((arr[2] == 3) + (arr[3] == 3) == 1) +
//							((arr[4] == 4) + (arr[0] == 1) == 1) == 5)
//						{
//							if (arr[0] * arr[1] * arr[2] * arr[3] * arr[4] == 120)
//							{
//								printf("A=%d,B=%d,C=%d,D=%d,E=%d\n", arr[0], arr[1], arr[2], arr[3], arr[4]);
//							}
//						}
//					}
//}
//int main()
//{
//	MingCi();
//	system("pause");
//	return 0;
//}
//**************************************************************
//2.
//�ձ�ĳ�ط�����һ��ıɱ��������ͨ���Ų�ȷ��ɱ�����ֱ�Ϊ4��
//���ɷ���һ��������Ϊ4�����ɷ��Ĺ��ʡ�
//A˵�������ҡ�
//B˵����C��
//C˵����D��
//D˵��C�ں�˵
//��֪3����˵���滰��1����˵���Ǽٻ���
//�����������Щ��Ϣ��дһ��������ȷ������˭�����֡�
//**************************************************************
//**************************************************************
//3.����Ļ�ϴ�ӡ������ǡ�
//1
//1 1
//1 2 1
//1 3 3 1
///*************************************************************

//#include<Aventador_SQ.h>
//
//int main()
//{
//	char a = -1;
//	signed char b = -1;
//	unsigned char c = -1;
//	printf("%d %d %d\n", a, b, c);
//	system("pause");
//	return 0;
//}

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<time.h>
//ɨ����Ϸ
#define ROW 9
#define COL 9
#define MINE_COUNT  10 
char mine_map[ROW + 2][COL + 2];
// ow_map, ʹ��'*', ��ʾδ�򿪵ķ��飬�Դ򿪷��飬�����þ���
char show_map[ROW + 2][COL + 2];
int Menu()
{
	int choice = 0;
	printf("1.��ʼ��Ϸ\n");
	printf("2.�˳���Ϸ\n");
	printf("����������ѡ��\n");
	scanf("%d", &choice);
	return choice;
}
//ʹ�ö�ά��������ʾɨ�׵ĵ�ͼ
//��һ����ά��������ʾɨ��ɨ�׵ĵ�ͼ������
//�ڶ�����ά��������ʾ�û������ĵ�ͼ
//ɨ�׵ĵ�ͼ��С��9*9���������ǰ������ά���鶨���11*11
//��ʱ�����ǵĵ�ͼ����Ч��Χ[1,ROW]��[1,COL]
//����mine_map,ʹ��'0'��ʾ���ǵ��ף�ʹ��'1'��ʾ�ǵ���
//char mine_map[ROW + 2][COL + 2];
//// ow_map, ʹ��'*', ��ʾδ�򿪵ķ��飬�Դ򿪷��飬�����þ���
//char show_map[ROW + 2][COL + 2];

void Init(char mine_map[ROW + 2][COL + 2], char show_map[ROW + 2][COL + 2]) {
	//1.��ʼ����ͼ(mine_map,show_map),��������
	//����mine_map,�Ȱ��е�Ԫ�ض����ó�'0'
	memset(mine_map, '0', (ROW + 2)*(COL + 2));
	//����show_mine���Ȱ����е�Ԫ�����ó�'*'
	memset(show_map, '0', (ROW + 2)*(COL + 2));

//2.�����������
srand((unsigned int)time(NULL));//�������
int mine_count = MINE_COUNT;
while (mine_count > 0) {
	//�����ѭ����������õ��ף�ÿ���������һ������--mine_count
	int row = rand() % 9 + 1;
	int col = rand() % 9 + 1;
	if (mine_map[row][col] == '0') {
		mine_map[row][col] = '1';
		--mine_count;
	}
  }
}
void DisplayMap(char map[ROW + 2][COL + 2]) {
	//��ӡ��һ�е����ݣ��ĸ��ո�+ÿһ�е�����
	printf("    ");
	for (int col = 1; col <= COL; ++col) {
		printf("%d ", col);
	}
	printf("\n");
	for (int col = 1; col <= COL; ++col) {
		printf("������");
	}
	printf("\n");
	//��ӡ����ĵ�ͼ
	//��ӡ�ڶ��У���ͼ���ϱ߿�
	//���д�ӡ��ͼ�еľ�������
	for (int row = 1; row <= ROW; ++row) {
		//�ȴ�ӡ���к�
		//1=>01    10=>10
		printf("%02d| ", row);
		for (int col = 1; col <= COL; ++col) {
			printf("%c ", map[row][col]);
		}
	}
	//for (int col = 1; col <= COL; ++col) {
	//	printf("%c ", map[row][col]);
	//}
	printf("\n");
}
//��Ҫͳ��row,colλ�õ�Ԫ����Χ�м����ף����Ұѽ�����µ�show_map��

void Game()
{
	//1.��ʼ����ͼ(mine_map,show_map),��������
	//2.�ȴ�ӡ show_map
	//DisplayMap( map[ROW + 2][COL + 2]) {
	DisplayMap( show_map);
	{
		while (1)
		{
			//3.��ʾ�û�������������[1,ROW][1,COL]
			int row = 0;
			int col = 0;
			printf("������Ҫ�����ķ������꣨row,col):");
			scanf("%d %d", &row, &col);
			//4.���û�����ĺϷ��Խ����жϣ������������ʾ�û���������
			if (row <= 0 || row > ROW || col<0 || col>COL)
			{
				printf("�������ɺϷ������������룡\n");//����ô��ô���أ�2018.10.29 Aventador_SQ
				continue;
			}

		}
	}


	//5.�ж���ҵ�ǰ�Ƿ���ף�������ף���Ϸ���������Ҵ�ӡ����
	if (mine_map) {
		//6.���û�в��ף��ж�һ������Ƿ�ʤ������Ҫע��ʤ��������
		int not_mine_count = 0;
		++not_mine_count;
		if (not_mine_count == ROW * COL - MINE_COUNT) {
			printf("ɨ�׳ɹ���\n");
			DisplayMap(mine_map);
			/*break;*/
		}
	}
}
//7.�����Ϸû��ʤ��������Ҫͳ�Ƶ�ǰ��λ����Χ�м����ף����ѽ�����µ�show_map��
void UpdateShowMap(char map[ROW + 2][COL + 2],
	char mine_map[ROW + 2][COL + 2], int row, int col) {
	int mine_count = 0;
	if (mine_map[row - 1][col - 1] == '1') {
		++mine_count;
	}

}

void start()
{
	while (1)
	{
		int choice = Menu();
		if (choice == 0) {
			printf("�˳���Ϸ!\n");
			break;
		}
      		Game();
	}
}
