#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	char ster[50] = { 0 };
	printf("����������:");
	scanf("%s", ster);
	int i = 0;
	for (i = 0; i < 3; i++)
	{
		if (strcmp("yidingbu!", ster) == 0)
		{
			break;
		}
		else
		{
			printf("�����������!!!\n");
			printf("���ٴ�����:");
		}
	}
	if (i < 3)
	{
		printf("��¼�ɹ�\n");
	}
	else
	{
		printf("������Ӻ��ٴε�¼\n");
	}
	system("pause");
	return 0;
}