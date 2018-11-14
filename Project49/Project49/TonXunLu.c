#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<Windows.h>
#include<mmsystem.h>
#include<conio.h>


#pragma comment(lib,"winmm.lib")


//添加音乐


//个人信息
typedef struct Person
{
	char name[1024];
	char phone[1024];
}Person;

#define SIZE 1000
//结构体通讯录
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


//播放音乐
void MyPlaySound()
{
	{
		//相对路径
		PlaySound("李白.wav", NULL, SND_FILENAME | SND_ASYNC);
	}
}
//中断音乐
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
	printf("******     1.添加    2.删除      3.修改    4.查找      ******\n");
	printf("******     5.显示    6.清除      0.退出                ******\n");
	printf("*************************************************************\n");
	printf("请输入：");
	int choice = 0;
	scanf("%d", &choice);
	return choice;
	//::.--. - .::
	//:(():::::  东边日出西边雨
	//(_, \), _)::道是无晴却有情 |
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
		printf("当前通讯录已满，插入失败！！！\n");
		return;
	}
	printf("添加一个用户信息\n");
	printf("请输入用户名\n");
	scanf("%s", g_AddBooks.person[g_AddBooks.size].name);
	printf("请输入用户手机号\n");
	scanf("%s", g_AddBooks.person[g_AddBooks.size].phone);
	g_AddBooks.size++;
	printf("插入成功\n");
}
void DeletePerson()
{
	printf("请输入需要删除的用户编号\n");
	int num = 0;
	scanf("%d", &num);
	if (num <= 0 || num > g_AddBooks.size)
	{
		printf("输入的编号非法，删除失败\n");
		return;
	}
	strcpy(g_AddBooks.person[num - 1].name, g_AddBooks.person[g_AddBooks.size - 1].name);
	strcpy(g_AddBooks.person[num - 1].phone, g_AddBooks.person[g_AddBooks.size - 1].phone);
	g_AddBooks.size--;
	printf("删除成功！\n");
}
void XiuGaiPerson()
{
	printf("请输入需要修改的用户编号\n");
	int num = 0;
	scanf("%d", &num);
	if (num <= 0 || num > g_AddBooks.size)
	{
		printf("输入的编号非法，修改失败\n");
		return;
	}
	printf("请输入新用户名\n");
	scanf("%s", g_AddBooks.person[num].name);
	printf("请输入新用户手机号\n");
	scanf("%s", g_AddBooks.person[num].phone);
	printf("修改成功！\n");
}
void FindPerson()
{
	//printf("请输入需要查找的用户编号\n");
	//int num = 0;
	//scanf("%d", &num);
	//if (num <= 0 || num > g_AddBooks.size)
	//{
	//	printf("输入的编号非法，查找失败\n");
	//	return;
	//}
	//printf("用户名：%s", g_AddBooks.person[num].name);
	//printf("用户手机号：%s", g_AddBooks.person[num].phone);
	printf("请输入需要查找的用户:\n");
	char name[1024];
	scanf("%s", &name);
	int count = 0;
	for (int i = 0; i < g_AddBooks.size; i++)
	{
		if (strcmp(name, g_AddBooks.person[i].name) == 0)
		{
			if (count == 0)
			{
				printf("找到了\n");
			}
			printf("%s\n", g_AddBooks.person[i].phone);
			count++;
		}
	}
	if (count == 0)
	{
		printf("没找到该用户\n");
	}
	else
	{
		printf("共找到%d条用户信息\n", count);
	}
	printf("查找成功！\n");
}
void PrintPerson()
{
	printf("打印所有用户信息\n");
	for (int i = 0; i < g_AddBooks.size; i++)
	{
		printf("%d %s:%s\n", i + 1, g_AddBooks.person[i].name, g_AddBooks.person[i].phone);
	}
	printf("共打印%d条信息\n", g_AddBooks.size);
}
void ClearPerson()
{
	printf("您确定要全部清空吗？\n");
	printf("1.是    2.否\n");
	int temp = 0;
	scanf("%d", &temp);
	if (temp == 1)
	{
		g_AddBooks.size = 0;
		printf("清空完成\n");
	}
	else
	{
		printf("清空失败\n");
	}
}

int main()
{
	MyPlaySound();
	//ZhongDuanSound();
	Init();//初始化
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