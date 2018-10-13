////1.猜数字小游戏
//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//#include<time.h>
//
//void SuiJiZhongZi()
//{
//	srand((unsigned int)time(NULL));
//}
//void menu()
//{
//	printf("************************************************************************\n");
//	printf("**                           猜数字游戏                               **\n");
//	printf("************************************************************************\n");
//	printf("**                       所猜数字在0～99之间                          **\n");
//	printf("************************************************************************\n");
//	printf("**                         1 Play    0 Exit                           **\n");
//	printf("************************************************************************\n");
//	printf("请选择：\n");
//}
//
//void Game()
//{
//	int SuiJiShu = 0;
//	SuiJiShu = rand() % 100;
//	int input = 0;
//	printf("请猜数字:");
//	while (1)
//	{
//		scanf("%d", &input);
//		if (input > SuiJiShu)
//		{
//			printf("猜大了\n");
//		}
//		else if (input < SuiJiShu)
//		{
//			printf("猜小了\n");
//		}
//		else
//		{
//			printf("恭喜你猜对了\n");
//			break;
//		}
//	}
//}
//
//void IsPlay()
//{
//	int Switch = 0;
//	do
//	{
//		scanf("%d", &Switch);
//		if (Switch == 1)
//		{
//			Game();
//			break;
//		}
//		else if (Switch == 0)
//		{
//			break;
//		}
//		else
//		{
//			printf("请重新输入:\n");
//		}
//	} while (Switch);
//}
//int main()
//{
//	SuiJiZhongZi();//产生随机生成数种子
//	menu();//打印菜单
//	IsPlay();//开始游戏
//	system("pause");
//	return 0;
//}

////2.在有序数组中找想要查询的数字
//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//
//int main()
//{
//	int ArrLen = 0;
//	int input = 0;
//	int left = 0;//数组左下标
//	int right = 0;//数组右下标
//	int mid = 0;//中间下标
//	int arr[] = { 1,3,5,7,8,9,15,46,89,999,1024 };
//	ArrLen=sizeof(arr) / sizeof(arr[1]);
//	right = ArrLen - 1;
//	printf("请输入想要查找的数字:");
//	scanf("%d", &input);
//	while (left <= right)
//	{
//		mid = left + ((right - left) >> 2);
//		if (input > arr[mid])
//		{
//			left = mid + 1;
//		}
//		else if (input < arr[mid])
//		{
//			right = mid - 1;
//		}
//		else if(input == arr[mid])
//		{
//			printf("找到了，%d的下标是%d\n", input, mid);
//			break;
//		}
//	}
//	if (left > right)
//	{
//		printf("没找到\n");
//	}
//	system("pause");
//	return 0;
//}

////3.模拟三次密码输入的场景
//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//
//int main()
//{
//	char CharsInput[10];
//	//char password[] = "yidingbjmz";
//	int i = 0;
//	for (i = 0; i < 3; i++)
//	{
//		printf("请输入密码:");
//		scanf("%s%*c", CharsInput);
//		if (strcmp(CharsInput,"yidingbjmz") == 0)
//		{
//			break;
//		}
//	}
//	if (i == 3)
//	{
//		printf("连续三次输入错误，禁止登录。\n");
//	}
//	system("pause");
//	return 0;
//}

////4.字母大化小，小化大，数字化无
//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//
//int main()
//{
//	int num = 0;
//	char arr[100];
//	printf("请输入：");
//	scanf("%s", arr);
//	num = strlen(arr);
//	for (int i = 0; i < num; i++)
//	{
//		if (arr[i] >= 'a'&&arr[i] <= 'z')
//		{
//			printf("%c", arr[i] - 32);
//		}
//		if (arr[i] >= 'A'&&arr[i] <= 'Z')
//		{
//			printf("%c", arr[i] + 32);
//		}
//	}
//	system("pause");
//	return 0;
//}