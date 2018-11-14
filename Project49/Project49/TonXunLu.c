#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<Windows.h>
#include<mmsystem.h>
#include<conio.h>


#pragma comment(lib,"winmm.lib")


//�������


//������Ϣ
typedef struct Person
{
	char name[1024];
	char phone[1024];
}Person;

#define SIZE 1000
//�ṹ��ͨѶ¼
typedef struct AddBooks
{
	Person person[SIZE];
	int size;
}AddBooks;
AddBooks g_AddBooks;

enum
{
	TUICHU = 0,
	ADD,
	DELET,
	XIUGAI,
	FIND,
	PRINT,
	CLEAR
};


//��������
void MyPlaySound()
{
	{
		//���·��
		PlaySound("���.wav", NULL, SND_FILENAME | SND_ASYNC);
	}
}
//�ж�����
void ZhongDuanSound()
{
	char InputKongGe;
	while (1)
	{
		InputKongGe = _getch();
		if (' ' == InputKongGe)
		{
			break;
		}
	}
	PlaySound(NULL, 0, 0);
}
void Init()
{
	g_AddBooks.size = 0;
	//for (int i = 0; i < SIZE; i++)
	//{
	//	strcpy(g_AddBooks.person[i].name,"");
	//	strcpy(g_AddBooks.person[i].phone, "");
	//}
	memset(g_AddBooks.person, 0, sizeof(g_AddBooks.person));
}

int Menu()
{

	printf("*************************************************************\n");
	printf("******     1.���    2.ɾ��      3.�޸�    4.����      ******\n");
	printf("******     5.��ʾ    6.���      0.�˳�                ******\n");
	printf("*************************************************************\n");
	printf("�����룺");
	int choice = 0;
	scanf("%d", &choice);
	return choice;
	//::.--. - .::
	//:(():::::  �����ճ�������
	//(_, \), _)::��������ȴ���� |
	//:: : -'--`--:::::::: ~~|     ,       \ _ /
	//:::::::::::::::::: : , | `-._/| -= = (_) == -
	//::::::::^^::::::::.' |   /||\      /   \
				//::::::^^::::::::.'   | ./ ||`\       |
//::::::::::::::: / `-. |/._ || \
		//::::::::::::::|      ||   ||   \
		//~~= ~_~^~= ~\~~~~~~~'~~~~'~~~~/ ~~`` ~= ~^~
//~^^~~-= ~^~^ `------------- - '~^~=~^~_~^=~^~
}

void AddPerson()
{
	if (g_AddBooks.size >= SIZE)
	{
		printf("��ǰͨѶ¼����������ʧ�ܣ�����\n");
		return;
	}
	printf("���һ���û���Ϣ\n");
	printf("�������û���\n");
	scanf("%s", g_AddBooks.person[g_AddBooks.size].name);
	printf("�������û��ֻ���\n");
	scanf("%s", g_AddBooks.person[g_AddBooks.size].phone);
	g_AddBooks.size++;
	printf("����ɹ�\n");
}
void DeletePerson()
{
	printf("��������Ҫɾ�����û����\n");
	int num = 0;
	scanf("%d", &num);
	if (num <= 0 || num > g_AddBooks.size)
	{
		printf("����ı�ŷǷ���ɾ��ʧ��\n");
		return;
	}
	strcpy(g_AddBooks.person[num - 1].name, g_AddBooks.person[g_AddBooks.size - 1].name);
	strcpy(g_AddBooks.person[num - 1].phone, g_AddBooks.person[g_AddBooks.size - 1].phone);
	g_AddBooks.size--;
	printf("ɾ���ɹ���\n");
}
void XiuGaiPerson()
{
	printf("��������Ҫ�޸ĵ��û����\n");
	int num = 0;
	scanf("%d", &num);
	if (num <= 0 || num > g_AddBooks.size)
	{
		printf("����ı�ŷǷ����޸�ʧ��\n");
		return;
	}
	printf("���������û���\n");
	scanf("%s", g_AddBooks.person[num].name);
	printf("���������û��ֻ���\n");
	scanf("%s", g_AddBooks.person[num].phone);
	printf("�޸ĳɹ���\n");
}
void FindPerson()
{
	//printf("��������Ҫ���ҵ��û����\n");
	//int num = 0;
	//scanf("%d", &num);
	//if (num <= 0 || num > g_AddBooks.size)
	//{
	//	printf("����ı�ŷǷ�������ʧ��\n");
	//	return;
	//}
	//printf("�û�����%s", g_AddBooks.person[num].name);
	//printf("�û��ֻ��ţ�%s", g_AddBooks.person[num].phone);
	printf("��������Ҫ���ҵ��û�:\n");
	char name[1024];
	scanf("%s", &name);
	int count = 0;
	for (int i = 0; i < g_AddBooks.size; i++)
	{
		if (strcmp(name, g_AddBooks.person[i].name) == 0)
		{
			if (count == 0)
			{
				printf("�ҵ���\n");
			}
			printf("%s\n", g_AddBooks.person[i].phone);
			count++;
		}
	}
	if (count == 0)
	{
		printf("û�ҵ����û�\n");
	}
	else
	{
		printf("���ҵ�%d���û���Ϣ\n", count);
	}
	printf("���ҳɹ���\n");
}
void PrintPerson()
{
	printf("��ӡ�����û���Ϣ\n");
	for (int i = 0; i < g_AddBooks.size; i++)
	{
		printf("%d %s:%s\n", i + 1, g_AddBooks.person[i].name, g_AddBooks.person[i].phone);
	}
	printf("����ӡ%d����Ϣ\n", g_AddBooks.size);
}
void ClearPerson()
{
	printf("��ȷ��Ҫȫ�������\n");
	printf("1.��    2.��\n");
	int temp = 0;
	scanf("%d", &temp);
	if (temp == 1)
	{
		g_AddBooks.size = 0;
		printf("������\n");
	}
	else
	{
		printf("���ʧ��\n");
	}
}

int main()
{
	MyPlaySound();
	//ZhongDuanSound();
	Init();//��ʼ��
	while (1)
	{
		int chioce = Menu();
		switch (chioce)
		{
		case ADD:
			system("cls");
			AddPerson();
			break;
		case DELET:
			system("cls");
			DeletePerson();
			break;
		case XIUGAI:
			system("cls");
			XiuGaiPerson();
			break;
		case FIND:
			system("cls");
			FindPerson();
			break;
		case PRINT:
			system("cls");
			PrintPerson();
			break;
		case CLEAR:
			system("cls");
			ClearPerson();
			break;
		case TUICHU:
			printf("Byebye\n");
			system("pause");
			return 0;
		default:
			break;
		}
	}
	return 0;
}