//存在问题:
//王者荣耀积分夺宝 
//#include<Aventador_SQ.h>
//#include<mmsystem.h>
//#include<conio.h>
//
//#pragma comment(lib,"winmm.lib")

#include"KingCrystal.h"

//打印菜单
void menu(int count)
{
	printf("=======================================================================================\n");
	printf("***************************************************************************************\n");
	printf("***** ┏┳┳┳┳┳┳┳┳┳┳┳┳┳┓                              ┏┳┳┳┳┳┳┳┳┳┳┳┳┳┳┳┳┳┓┏┳┳┳┳┳┳┳┳┳┓ *****\n");
	printf("***** ┣   积分夺宝  ┫                              ┣ 本周累计个数重置┫┣   规则  ┫ *****\n");
	printf("***** ┗┻┻┻┻┻┻┻┻┻┻┻┻┻┛                              ┗┻┻┻┻┻┻┻┻┻┻┻┻┻┻┻┻┻┛┗┻┻┻┻┻┻┻┻┻┛ *****\n");
	printf("***** ┏┳┳┳┳┳┳┳┳┳┳┳┳┳┓┏┳┳┳┳┳┳┳┳┳┳┳┳┳┓┏┳┳┳┳┳┳┳┳┳┳┳┳┳┓┏┳┳┳┳┳┳┳┳┳┳┳┳┳┓┏┳┳┳┳┳┳┳┳┳┳┳┳┳┓ *****\n");
	printf("***** ┣   荣耀水晶  ┫┣     李白    ┫┣ 铭文碎片(80)┫┣ 4级铭文:荆棘┫┣   钻石(50)  ┫ *****\n");
	printf("***** ┗┻┻┻┻┻┻┻┻┻┻┻┻┻┛┗┻┻┻┻┻┻┻┻┻┻┻┻┻┛┗┻┻┻┻┻┻┻┻┻┻┻┻┻┛┗┻┻┻┻┻┻┻┻┻┻┻┻┻┛┗┻┻┻┻┻┻┻┻┻┻┻┻┻┛ *****\n");
	printf("***** ┏┳┳┳┳┳┳┳┳┳┳┳┳┳┓   ┏┳┳┳┳┳┳┳┳┳┳┳┳┓                            ┏┳┳┳┳┳┳┳┳┳┳┳┳┳┓ *****\n");
	printf("***** ┣   死神来了  ┫   ┣  幸运值:%3d┫                            ┣  英雄碎片(5)┫ *****\n", count);
	printf("***** ┗┻┻┻┻┻┻┻┻┻┻┻┻┻┛   ┗┻┻┻┻┻┻┻┻┻┻┻┻┛                            ┗┻┻┻┻┻┻┻┻┻┻┻┻┻┛ *****\n");
	printf("***** ┏┳┳┳┳┳┳┳┳┳┳┳┳┳┓  ┏┳┳┳┳┳┳┳┳┳┳┳┳┳┳┳┳┳┳┳┳┓┏┳┳┳┳┳┳┳┳┳┳┳┳┳┳┳┳┳┓  ┏┳┳┳┳┳┳┳┳┳┳┳┳┳┓ *****\n");
	printf("***** ┣     杨戬    ┫  ┣   积45买1次        ┫┣     积200买5次  ┫  ┣ 3级铭文:致命┫ *****\n");
	printf("***** ┗┻┻┻┻┻┻┻┻┻┻┻┻┻┛  ┗┻┻┻┻┻┻┻┻┻┻┻┻┻┻┻┻┻┻┻┻┛┗┻┻┻┻┻┻┻┻┻┻┻┻┻┻┻┻┻┛  ┗┻┻┻┻┻┻┻┻┻┻┻┻┻┛ *****\n");
	printf("***** ┏┳┳┳┳┳┳┳┳┳┳┳┳┳┓┏┳┳┳┳┳┳┳┳┳┳┳┳┳┓┏┳┳┳┳┳┳┳┳┳┳┳┳┳┓┏┳┳┳┳┳┳┳┳┳┳┳┳┳┓┏┳┳┳┳┳┳┳┳┳┳┳┳┳┓ *****\n");
	printf("***** ┣ 5级铭文:传承┫┣ 铭文碎片(50)┫┣   偶像歌手  ┫┣   金币(288) ┫┣  皮肤碎片(5)┫ *****\n");
	printf("***** ┗┻┻┻┻┻┻┻┻┻┻┻┻┻┛┗┻┻┻┻┻┻┻┻┻┻┻┻┻┛┗┻┻┻┻┻┻┻┻┻┻┻┻┻┛┗┻┻┻┻┻┻┻┻┻┻┻┻┻┛┗┻┻┻┻┻┻┻┻┻┻┻┻┻┛ *****\n");
	printf("***************************************************************************************\n");
	printf("=======================================================================================\n");
}

//清空上层输出
void Clean()
{
	system("cls");
	printf("***************************************************************************************\n");
	printf("**                                                                                   **\n");
}
//方式1抽奖
int probability(int count)
{
	Clean();
	int num;
	int static i = 0;
	int static j = 0;
	int static k = 0;
MZ:
	num = rand() % 361;
	if (count != 360)
	{
		if (num == 228)
		{
			printf("\n");
			printf("********************\n");
			printf("******荣耀水晶******\n");
			printf("********************\n");
			return 0;
		}
		else if (num > 0 && num < 90)
		{
			printf("钻石(50)\n");
		}
		else if (num >= 90 && num < 228)
		{
			printf("铭文碎片(50)\n");
		}
		else if (num >= 229 && num < 280)
		{
			printf("铭文碎片(80)\n");
		}
		else if (num == 280 || num == 281)
		{
			if (i == 0)
			{
				printf("偶像歌手\n");
				i++;
			}
			else
				goto MZ;
		}
		else if (num > 281 && num < 287)
		{
			if (j == 0)
			{
				printf("死神来了\n");
				j++;
			}
			else
				goto MZ;
		}
		else if (num >= 287 && num < 318)
		{
			if (k == 0)
			{
				printf("杨戬\n");
				k++;
			}
			else
				goto MZ;
		}
		else if (num >= 318 && num < 321)
		{
			printf("5级铭文:传承");
		}
		else if (num >= 321 && num < 335)
		{
			printf("皮肤碎片(5)\n");
		}
		else if (num >= 335 && num < 340)
		{
			printf("金币(288)\n");
		}
		else if (num >= 340 && num < 350)
		{
			printf("英雄碎片(5)\n");
		}
		else if (num >= 350 && num < 355)
		{
			printf("4级铭文:荆棘\n");
		}
		else
		{
			printf("3级铭文:致命\n");
		}
	}
	return count;
}
//方式2抽奖
int probability_1(int count)
{
	Clean();
	int i;
	int static yangjian = 0;
	int static ouxiang = 0;
	int static sishen = 0;
	int num;
	for (i = 0; i < 5; i++)
	{
	Repet:
		num = rand() % 361;
		if (num == 228)
		{
			printf("\n");
			printf("********************\n");
			printf("******荣耀水晶******\n");
			printf("********************\n");
			return 0;
		}
		else if (num > 0 && num < 80)
		{
			printf("钻石(50)\t");
		}
		else if (num >= 80 && num < 200)
		{
			printf("铭文碎片(50)\t");
		}
		else if (num >= 200 && num < 280)
		{
			printf("铭文碎片(80)\t");
		}
		else if (num == 280 || num == 281)
		{
			if (ouxiang == 0)
			{
				printf("偶像歌手\t");
				ouxiang++;
			}
			else
			{
				goto Repet;
			}
		}
		else if (num > 281 && num < 287)
		{
			if (sishen == 0)
			{
				printf("死神来了\t");
				sishen++;
			}
			else
			{
				goto Repet;
			}
		}
		else if (num >= 287 && num < 318)
		{
			if (yangjian == 0)
			{
				printf("杨戬\t");
				yangjian++;
			}
			else
			{
				goto Repet;
			}
		}
		else if (num >= 318 && num < 321)
		{
			printf("5级铭文:传承\t");
		}
		else if (num >= 321 && num < 335)
		{
			printf("皮肤碎片(5)\t");
		}
		else if (num >= 335 && num < 340)
		{
			printf("金币(288)\t");
		}
		else if (num >= 340 && num < 350)
		{
			printf("英雄碎片(5)\t");
		}
		else if (num >= 350 && num < 355)
		{
			printf("4级铭文:荆棘\t");
		}
		else
		{
			printf("3级铭文:致命\t");
		}
	}
	printf("\n");
	return count;
}
//充值函数
int VoucherCenter()
{
	int nums = 0;
	int jine = 0;
	printf("积分不足请选择：\n");
	printf("(家里有矿)请充值请选择1，退出充值选择2。\n");
	scanf("%d", &nums);
	if (nums == 1)
	{
		printf("************************* ************************ ************************** ***************************\n");
		printf("***1.|---  10点券   ---|* * 2.|---  60点券   ---|* *  3.|---  180点券   ---|* * 4.|---  300点券   ---|***\n");
		printf("***  |**购买 ￥ 1RMB **|* *   |**购买 ￥ 6RMB **|* *    |**购买 ￥ 18RMB **|* *   |**购买 ￥ 30RMB **|***\n");
		printf("************************* ************************ ************************** ***************************\n");
		printf("\n");
		printf("************************* ************************* ************************* ***************************\n");
		printf("***5.|---   680点券 ---|* * 6.|---  1180点券  ---|* * 7.|---  1980点券  ---|* * 8.|---  3480点券  ---|***\n");
		printf("***  |**购买 ￥ 68RMB**|* *   |**购买 ￥ 118RMB**|* *   |**购买 ￥ 198RMB**|* *   |**购买 ￥ 348RMB**|***\n");
		printf("************************* ************************* ************************* ***************************\n");
	recharge:
		printf("请选择充值的金额(直接输入数字即可单位RMB)：");//(直接输入数字即可单位RMB)
		scanf("%d", &jine);
		//printf("元\n");
		switch (jine)
		{
		case 1:
		case 6:
		case 18:
		case 30:
		case 68:
		case 118:
		case 198:
		case 348:
			printf("%d RMB充值中请稍后...\n", jine);
			//调用充值函数(单位ms)请等待...
			Sleep(3000);
			printf("\n");
			printf("*****************\n");
			printf("*** 充值成功! ***\n");
			printf("*****************\n");
			printf("\n");
			break;
		default:
			printf("输入错误请重新选择:\n");
			goto recharge;
		}

	}
	return jine * 10;//转换为点券
}

////播放音乐
void MyPlaySound()
{
	{
		//相对路径
		PlaySound("李白.wav", NULL, SND_FILENAME | SND_ASYNC);
		//SND_ASYNC|SND_RESOURCE|SND_NODEFAULT|SND_LOOP
		//SND_ASYNC|SND_RESOURCE|SND_NODEFAULT
		//SND_FILENAME | SND_ASYNC
		//printf("hehe\n");
		//PlaySound("邓紫棋 - 喜欢你.wav", NULL, SND_FILENAME | SND_ASYNC);
		//PlaySound("我很快乐.wav", NULL, SND_FILENAME | SND_ASYNC);
		////PlaySound("庄心妍 - 断了乱了.wav", NULL, SND_FILENAME | SND_ASYNC);
		//绝对路径
		//PlaySound("D:\\酷狗\\邓紫棋 - 喜欢你.wav", NULL, SND_FILENAME | SND_ASYNC);
		//PlaySound("D:\\酷狗\\邓紫棋 - 喜欢你.wav", NULL, SND_FILENAME | SND_ASYNC);
		//PlaySound("D:\\酷狗\\邓紫棋 - 喜欢你.wav", NULL, SND_FILENAME | SND_ASYNC);
		//PlaySound("D:\\酷狗\\邓紫棋 - 喜欢你.wav", NULL, SND_FILENAME | SND_ASYNC);
		//PlaySound("D:\\酷狗\\邓紫棋 - 喜欢你.wav", NULL, SND_FILENAME | SND_ASYNC);
		//PlaySound("D:\\酷狗\\邓紫棋 - 喜欢你.wav", NULL, SND_FILENAME | SND_ASYNC);
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

//int main()
//{
//	MyPlaySound();//播放音乐
//	int count;//幸运值
//	int Luck_val = 0;
//	int integral_1 = 0;//选择方式
//	int integral = 0;//一定可以抽到荣耀水晶所需积分(14445)
//					 //	int set;//用来接收当抽到荣耀水晶时返回count（幸运值为0）
//	count = 0;
//	//MyPlaySound();//播放音乐
//	//ZhongDuanSound();//中断音乐
//
//	//int QingkongPage = 0;//用来清理上层输出
//	//system("cls");
//	srand((unsigned int)time(NULL));
//	menu(count);
//
//	printf("抽奖方式分为2种，输入1抽1次，输入5出5次,输入0结束抽奖\n");
//	printf("输入其它数字请重新输入。\n");
//	while (1)
//	{
//		printf("剩余积分:%d\n", integral);
//		printf("请选择要抽奖的方式:>");
//		scanf("%d", &integral_1);
//		if (integral_1 == 0)
//		{
//			printf("本次抽奖结束\n");
//			menu(count);
//			break;
//		}
//		if (integral_1 == 1)
//		{
//			if (integral >= 45)
//			{
//				count++;
//				count = probability(count);//调用抽奖函数1
//				menu(count);
//				integral -= 45;
//			}
//			else
//			{
//				static int ChoZhi = 0;
//				//积分不足的处理，调用充值函数
//				ChoZhi = VoucherCenter();
//				integral = integral + ChoZhi;
//			}
//		}
//		if (integral_1 == 5)
//		{
//			if (integral >= 200)
//			{
//				count = count + 5;
//				probability_1(count);
//				menu(count);
//				integral -= 200;
//			}
//			else
//			{
//				static int ChoZhi = 0;
//				//积分不足的处理，调用充值函数
//				ChoZhi = VoucherCenter();
//				integral = integral + ChoZhi;
//			}
//		}
//		if (count == 361)
//		{
//			printf("\n");
//			printf("********************\n");
//			printf("******荣耀水晶******\n");
//			printf("********************\n");
//			count = 0;
//			menu(count);
//		}
//	}
//	system("pause");
//	return 0;
//}

//int main()
//{
//	int *p = NULL;
//	int a[100] = { 0 };
//	printf("sizeof(p)=%d\n", sizeof(p));
//	printf("sizeof(*p)=%d\n", sizeof(*p));
//	printf("sizeof(a)=%d\n", sizeof(a));
//	printf("sizeof(a[100])=%d\n", sizeof(a[100]));
//	printf("sizeof(&a[0])=%d\n", sizeof(&a[0]));
//	return 0;
//}