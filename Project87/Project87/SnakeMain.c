#include"Snake.h"

int main()
{
	//1.��ӡ��ʼ��Ϸ����
	FirstPage();

	//2.��������
	MyPlaySound();

	//3.�ո����ʼ��Ϸ
	SpaceKey();

	//4.ֹͣ��������
	StopMusic();

	//5.��ս���
	CLear();

	//6.��ӡ�߿�
	while (1)
	{
		CLear();
		PrintBackground();
	}

	system("pause");
	return 0;
}