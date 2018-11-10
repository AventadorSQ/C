//1. 写一个控制台程序, 启动程序的时候, 先提示用户选择班级
//例如, 41, 进入到41
//java6, 进入 java6
//
//程序中搞一个数组, 所有的41班的同学.
//数组的元素是一个结构体.至少需要包含学生的姓名.
//
//每次按下回车, 从数组中选一个随机数, 把这个同学的姓名和编号打印出来.
//程序启动的时候从文件中读取这些信息.
//
//2. 要求:
//每个班级的同学信息需要从教务网站上获取.
//获取到的学生信息保存到一个文件里.
//
//C :
//	a) 给定一个url, 就能获取到网页的数据.libcurl
//	b) 得到html(字符串), 解析字符串, 获取到其中的学生信息
//	c) 把获取到的学生信息按照一定的规则, 保存到一个文件中, 供第一个程序加载.
//	例如使用行文本的方式保存, 每个姓名占一行.
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>


//查找输入的班级是否有误
int Strstr(char arr[], const char arr1[], int* location)
{
	int i = 0;
	int ArrLen = strlen(arr);
	int Arr1Len = strlen(arr1);
	int temp = ArrLen - Arr1Len;
	for (i = 0; i <= temp; i++)
	{
		for (int j = 0; j < Arr1Len; j++)
		{
			if (arr[i + j] != arr1[j])
			{
				break;
			}
			else
			{
				if (j == Arr1Len - 1)
				{
					*location = i + 1;
					return 1;
				}
			}
		}
	}
	return 0;
}

void Game(int* OnOff)
{
	typedef struct BitStu {
		int num;
		char arr[16];
	}BitStu;

	int weizhiclass = 0;//记录首次出现班级的位置
	int weizhinum = 0;//记录首次出现学生学号的位置
	char ArrClasses[1024] = "40 java6 JAVA6";//记录所有的班级
	char ArrClassScanf[200];//记录输入的班级
	BitStu ArrClass[1024];//记录班级的学生信息（将文件数据存入该数组）
	int Rand = 0;//记录产生的随机数
	int TempStrstr1 = 0;//函数有返回值
	while (1)
	{
		printf("请选择班级：");
		scanf("%s%*c", ArrClassScanf);
		int TempStrstr = Strstr(ArrClasses, ArrClassScanf, &weizhiclass);//用于判断输入班级是否有误
		if (TempStrstr != 0)
		{
			if (strcmp(ArrClassScanf, "40") == 0)
			{
				printf("haha\n");
				//开始摇奖
				Rand = rand() % 53 + 1;
				char ArrRand[100] = "Rand";

				//将网页源文档进行字符串查找得到学生信息，并存入文档

				//读取文件
				//将文件数据存入所查班级数组
				//通过摇奖的数字在数组里面查找相应位置
				TempStrstr1 = Strstr(ArrClass, ArrRand, &weizhinum);//寻找该学号对应的位置
																	//输出到界面
				for (int i = weizhinum; i < weizhinum + 20; i++)//循环打印该学号后面的10位（一条学生信息20个字节）
				{
					printf("%c", ArrClass[i - 1]);
				}
				printf("\n");
				//printf("haha\n");
				printf("****************************************************\n");
				printf("***       1,继续抽奖         0，结束游戏         ***\n");
				printf("****************************************************\n");
				scanf("%d", OnOff);
				if (*OnOff == 0)
				{
					break;
				}
			}
		}
	}
}
int main()
{

	int OnOff = 0;//是否开始游戏
	srand((unsigned int)time(NULL));
	while (1)
	{
		printf("****************************************************\n");
		printf("***       1.继续抽奖         0.结束游戏         ***\n");
		printf("****************************************************\n");
		printf("***请输入：");
		scanf("%d", &OnOff);
		if (OnOff == 1)
		{
			Game(&OnOff);
		}
		if (OnOff == 0)
		{
			break;
		}
	}
	system("pause");
	return 0;
}