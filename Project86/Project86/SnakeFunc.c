#include"Snake.h"

//1.��ӡ��ʼ��Ϸ����
void FirstPage()
{
	printf("\n\n\n\n\n");
	printf("\t\t\t ����ӭ����̰������Ϸ��\n\n");
	printf("\t\t\t  �����ո����ʼ��Ϸ��\n\n");
	printf("\t\t\t��w a s d �����ߵķ���\n\n");
}

//2.��������
void MyPlaySound()
{
	PlaySound("ׯ���� - ��������.wav", NULL, SND_FILENAME | SND_ASYNC);
}