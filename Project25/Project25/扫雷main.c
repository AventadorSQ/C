#include"ɨ��ͷ�ļ�.h"
int ScanfRow = 0;//��������±�
int ScanfCol = 0;//��������±�
int count = 0;
void Game()
{
	//��ʼ����Ϸ
	char ArrLeiMap[ROW][COL];
	char ArrShowMap[ROW][COL];
	srand((unsigned int)time(NULL));
	InitQiPan(ArrLeiMap);//��ʼ������
	InitShowPan(ArrShowMap, ROW, COL);//��ʼ���û�������
	PrintShow(ArrShowMap, ArrLeiMap, ROW, COL);//��ӡչʾ�Ľ�������
	while (1)
	{
		Scanf(ArrShowMap, ArrLeiMap, &ScanfRow, &ScanfCol, &count);//��Ҳ���Ϸ
		IsWin(ArrShowMap, ArrLeiMap, &ScanfRow, &ScanfCol, &count);//�ж���Ӯ
		PrintShow(ArrShowMap, ArrLeiMap, ROW, COL);//��ӡ���µĽ�������
	}
}
int main()
{
	int Select = 0;//ѡ�񿪹�
	//������Ϸ����
	MyPlaySound();

	//ɨ�׳�ʼ����
	Select=Menu(&Select);

	//ѡ���Ƿ�ʼ��Ϸ
	IsPlay(&Select);
	//��ʼ��Ϸ
	//Game();
	//�ж���Ӯ
	//������Ϸ
	system("pause");
	return 0;
}