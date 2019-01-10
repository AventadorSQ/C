#include"KingCrystal.h"

int main()
{
	MyPlaySound();//播放音乐
	int count;//幸运值
	int Luck_val = 0;
	int integral_1 = 0;//选择方式
	int integral = 0;//一定可以抽到荣耀水晶所需积分(14445)
					 //	int set;//用来接收当抽到荣耀水晶时返回count（幸运值为0）
	count = 0;
	//MyPlaySound();//播放音乐
	//ZhongDuanSound();//中断音乐

	//int QingkongPage = 0;//用来清理上层输出
	//system("cls");
	srand((unsigned int)time(NULL));
	menu(&count);

	printf("抽奖方式分为2种，输入1抽1次，输入5出5次,输入0结束抽奖\n");
	printf("输入其它数字请重新输入。\n");
	while (1)
	{
		printf("剩余积分:%d\n", integral);
		printf("请选择要抽奖的方式:>");
		scanf("%d", &integral_1);
		if (integral_1 == 0)
		{
			printf("本次抽奖结束\n");
			menu(&count);
			break;
		}
		if (integral_1 == 1)
		{
			if (integral >= 45)
			{
				count++;
				count = probability(&count);//调用抽奖函数1
				menu(&count);
				integral -= 45;
			}
			else
			{
				static int ChoZhi = 0;
				//积分不足的处理，调用充值函数
				ChoZhi = VoucherCenter();
				integral = integral + ChoZhi;
			}
		}
		if (integral_1 == 5)
		{
			if (integral >= 200)
			{
				count = count + 5;
				probability_1(&count);
				menu(&count);
				integral -= 200;
			}
			else
			{
				static int ChoZhi = 0;
				//积分不足的处理，调用充值函数
				ChoZhi = VoucherCenter();
				integral = integral + ChoZhi;
			}
		}
		if (count == 361)
		{
			printf("\n");
			printf("********************\n");
			printf("******荣耀水晶******\n");
			printf("********************\n");
			count = 0;
			menu(&count);
		}
	}
	system("pause");
	return 0;
}