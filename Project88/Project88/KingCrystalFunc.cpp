//��������:
//������ҫ���ֶᱦ 
//#include<Aventador_SQ.h>
//#include<mmsystem.h>
//#include<conio.h>
//
//#pragma comment(lib,"winmm.lib")

#include"KingCrystal.h"

//��ӡ�˵�
void menu(int count)
{
	printf("=======================================================================================\n");
	printf("***************************************************************************************\n");
	printf("***** ���ששששששששששששש�                              ���ששששששששששששששששש����ששששששששש� *****\n");
	printf("***** ��   ���ֶᱦ  ��                              �� �����ۼƸ������éϩ�   ����  �� *****\n");
	printf("***** ���ߩߩߩߩߩߩߩߩߩߩߩߩߩ�                              ���ߩߩߩߩߩߩߩߩߩߩߩߩߩߩߩߩߩ����ߩߩߩߩߩߩߩߩߩ� *****\n");
	printf("***** ���ששששששששששששש����ששששששששששששש����ששששששששששששש����ששששששששששששש����ששששששששששששש� *****\n");
	printf("***** ��   ��ҫˮ��  �ϩ�     ���    �ϩ� ������Ƭ(80)�ϩ� 4������:�����ϩ�   ��ʯ(50)  �� *****\n");
	printf("***** ���ߩߩߩߩߩߩߩߩߩߩߩߩߩ����ߩߩߩߩߩߩߩߩߩߩߩߩߩ����ߩߩߩߩߩߩߩߩߩߩߩߩߩ����ߩߩߩߩߩߩߩߩߩߩߩߩߩ����ߩߩߩߩߩߩߩߩߩߩߩߩߩ� *****\n");
	printf("***** ���ששששששששששששש�   ���שששששששששששש�                            ���ששששששששששששש� *****\n");
	printf("***** ��   ��������  ��   ��  ����ֵ:%3d��                            ��  Ӣ����Ƭ(5)�� *****\n", count);
	printf("***** ���ߩߩߩߩߩߩߩߩߩߩߩߩߩ�   ���ߩߩߩߩߩߩߩߩߩߩߩߩ�                            ���ߩߩߩߩߩߩߩߩߩߩߩߩߩ� *****\n");
	printf("***** ���ששששששששששששש�  ���שששששששששששששששששששש����ששששששששששששששששש�  ���ששששששששששששש� *****\n");
	printf("***** ��     ���    ��  ��   ��45��1��        �ϩ�     ��200��5��  ��  �� 3������:������ *****\n");
	printf("***** ���ߩߩߩߩߩߩߩߩߩߩߩߩߩ�  ���ߩߩߩߩߩߩߩߩߩߩߩߩߩߩߩߩߩߩߩߩ����ߩߩߩߩߩߩߩߩߩߩߩߩߩߩߩߩߩ�  ���ߩߩߩߩߩߩߩߩߩߩߩߩߩ� *****\n");
	printf("***** ���ששששששששששששש����ששששששששששששש����ששששששששששששש����ששששששששששששש����ששששששששששששש� *****\n");
	printf("***** �� 5������:���Щϩ� ������Ƭ(50)�ϩ�   ż�����  �ϩ�   ���(288) �ϩ�  Ƥ����Ƭ(5)�� *****\n");
	printf("***** ���ߩߩߩߩߩߩߩߩߩߩߩߩߩ����ߩߩߩߩߩߩߩߩߩߩߩߩߩ����ߩߩߩߩߩߩߩߩߩߩߩߩߩ����ߩߩߩߩߩߩߩߩߩߩߩߩߩ����ߩߩߩߩߩߩߩߩߩߩߩߩߩ� *****\n");
	printf("***************************************************************************************\n");
	printf("=======================================================================================\n");
}

//����ϲ����
void Clean()
{
	system("cls");
	printf("***************************************************************************************\n");
	printf("**                                                                                   **\n");
}
//��ʽ1�齱
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
			printf("******��ҫˮ��******\n");
			printf("********************\n");
			return 0;
		}
		else if (num > 0 && num < 90)
		{
			printf("��ʯ(50)\n");
		}
		else if (num >= 90 && num < 228)
		{
			printf("������Ƭ(50)\n");
		}
		else if (num >= 229 && num < 280)
		{
			printf("������Ƭ(80)\n");
		}
		else if (num == 280 || num == 281)
		{
			if (i == 0)
			{
				printf("ż�����\n");
				i++;
			}
			else
				goto MZ;
		}
		else if (num > 281 && num < 287)
		{
			if (j == 0)
			{
				printf("��������\n");
				j++;
			}
			else
				goto MZ;
		}
		else if (num >= 287 && num < 318)
		{
			if (k == 0)
			{
				printf("���\n");
				k++;
			}
			else
				goto MZ;
		}
		else if (num >= 318 && num < 321)
		{
			printf("5������:����");
		}
		else if (num >= 321 && num < 335)
		{
			printf("Ƥ����Ƭ(5)\n");
		}
		else if (num >= 335 && num < 340)
		{
			printf("���(288)\n");
		}
		else if (num >= 340 && num < 350)
		{
			printf("Ӣ����Ƭ(5)\n");
		}
		else if (num >= 350 && num < 355)
		{
			printf("4������:����\n");
		}
		else
		{
			printf("3������:����\n");
		}
	}
	return count;
}
//��ʽ2�齱
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
			printf("******��ҫˮ��******\n");
			printf("********************\n");
			return 0;
		}
		else if (num > 0 && num < 80)
		{
			printf("��ʯ(50)\t");
		}
		else if (num >= 80 && num < 200)
		{
			printf("������Ƭ(50)\t");
		}
		else if (num >= 200 && num < 280)
		{
			printf("������Ƭ(80)\t");
		}
		else if (num == 280 || num == 281)
		{
			if (ouxiang == 0)
			{
				printf("ż�����\t");
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
				printf("��������\t");
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
				printf("���\t");
				yangjian++;
			}
			else
			{
				goto Repet;
			}
		}
		else if (num >= 318 && num < 321)
		{
			printf("5������:����\t");
		}
		else if (num >= 321 && num < 335)
		{
			printf("Ƥ����Ƭ(5)\t");
		}
		else if (num >= 335 && num < 340)
		{
			printf("���(288)\t");
		}
		else if (num >= 340 && num < 350)
		{
			printf("Ӣ����Ƭ(5)\t");
		}
		else if (num >= 350 && num < 355)
		{
			printf("4������:����\t");
		}
		else
		{
			printf("3������:����\t");
		}
	}
	printf("\n");
	return count;
}
//��ֵ����
int VoucherCenter()
{
	int nums = 0;
	int jine = 0;
	printf("���ֲ�����ѡ��\n");
	printf("(�����п�)���ֵ��ѡ��1���˳���ֵѡ��2��\n");
	scanf("%d", &nums);
	if (nums == 1)
	{
		printf("************************* ************************ ************************** ***************************\n");
		printf("***1.|---  10��ȯ   ---|* * 2.|---  60��ȯ   ---|* *  3.|---  180��ȯ   ---|* * 4.|---  300��ȯ   ---|***\n");
		printf("***  |**���� �� 1RMB **|* *   |**���� �� 6RMB **|* *    |**���� �� 18RMB **|* *   |**���� �� 30RMB **|***\n");
		printf("************************* ************************ ************************** ***************************\n");
		printf("\n");
		printf("************************* ************************* ************************* ***************************\n");
		printf("***5.|---   680��ȯ ---|* * 6.|---  1180��ȯ  ---|* * 7.|---  1980��ȯ  ---|* * 8.|---  3480��ȯ  ---|***\n");
		printf("***  |**���� �� 68RMB**|* *   |**���� �� 118RMB**|* *   |**���� �� 198RMB**|* *   |**���� �� 348RMB**|***\n");
		printf("************************* ************************* ************************* ***************************\n");
	recharge:
		printf("��ѡ���ֵ�Ľ��(ֱ���������ּ��ɵ�λRMB)��");//(ֱ���������ּ��ɵ�λRMB)
		scanf("%d", &jine);
		//printf("Ԫ\n");
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
			printf("%d RMB��ֵ�����Ժ�...\n", jine);
			//���ó�ֵ����(��λms)��ȴ�...
			Sleep(3000);
			printf("\n");
			printf("*****************\n");
			printf("*** ��ֵ�ɹ�! ***\n");
			printf("*****************\n");
			printf("\n");
			break;
		default:
			printf("�������������ѡ��:\n");
			goto recharge;
		}

	}
	return jine * 10;//ת��Ϊ��ȯ
}

////��������
void MyPlaySound()
{
	{
		//���·��
		PlaySound("���.wav", NULL, SND_FILENAME | SND_ASYNC);
		//SND_ASYNC|SND_RESOURCE|SND_NODEFAULT|SND_LOOP
		//SND_ASYNC|SND_RESOURCE|SND_NODEFAULT
		//SND_FILENAME | SND_ASYNC
		//printf("hehe\n");
		//PlaySound("������ - ϲ����.wav", NULL, SND_FILENAME | SND_ASYNC);
		//PlaySound("�Һܿ���.wav", NULL, SND_FILENAME | SND_ASYNC);
		////PlaySound("ׯ���� - ��������.wav", NULL, SND_FILENAME | SND_ASYNC);
		//����·��
		//PlaySound("D:\\�ṷ\\������ - ϲ����.wav", NULL, SND_FILENAME | SND_ASYNC);
		//PlaySound("D:\\�ṷ\\������ - ϲ����.wav", NULL, SND_FILENAME | SND_ASYNC);
		//PlaySound("D:\\�ṷ\\������ - ϲ����.wav", NULL, SND_FILENAME | SND_ASYNC);
		//PlaySound("D:\\�ṷ\\������ - ϲ����.wav", NULL, SND_FILENAME | SND_ASYNC);
		//PlaySound("D:\\�ṷ\\������ - ϲ����.wav", NULL, SND_FILENAME | SND_ASYNC);
		//PlaySound("D:\\�ṷ\\������ - ϲ����.wav", NULL, SND_FILENAME | SND_ASYNC);
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

//int main()
//{
//	MyPlaySound();//��������
//	int count;//����ֵ
//	int Luck_val = 0;
//	int integral_1 = 0;//ѡ��ʽ
//	int integral = 0;//һ�����Գ鵽��ҫˮ���������(14445)
//					 //	int set;//�������յ��鵽��ҫˮ��ʱ����count������ֵΪ0��
//	count = 0;
//	//MyPlaySound();//��������
//	//ZhongDuanSound();//�ж�����
//
//	//int QingkongPage = 0;//���������ϲ����
//	//system("cls");
//	srand((unsigned int)time(NULL));
//	menu(count);
//
//	printf("�齱��ʽ��Ϊ2�֣�����1��1�Σ�����5��5��,����0�����齱\n");
//	printf("���������������������롣\n");
//	while (1)
//	{
//		printf("ʣ�����:%d\n", integral);
//		printf("��ѡ��Ҫ�齱�ķ�ʽ:>");
//		scanf("%d", &integral_1);
//		if (integral_1 == 0)
//		{
//			printf("���γ齱����\n");
//			menu(count);
//			break;
//		}
//		if (integral_1 == 1)
//		{
//			if (integral >= 45)
//			{
//				count++;
//				count = probability(count);//���ó齱����1
//				menu(count);
//				integral -= 45;
//			}
//			else
//			{
//				static int ChoZhi = 0;
//				//���ֲ���Ĵ������ó�ֵ����
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
//				//���ֲ���Ĵ������ó�ֵ����
//				ChoZhi = VoucherCenter();
//				integral = integral + ChoZhi;
//			}
//		}
//		if (count == 361)
//		{
//			printf("\n");
//			printf("********************\n");
//			printf("******��ҫˮ��******\n");
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