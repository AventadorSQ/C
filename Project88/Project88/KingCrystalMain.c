#include"KingCrystal.h"

int main()
{
	MyPlaySound();//��������
	int count;//����ֵ
	int Luck_val = 0;
	int integral_1 = 0;//ѡ��ʽ
	int integral = 0;//һ�����Գ鵽��ҫˮ���������(14445)
					 //	int set;//�������յ��鵽��ҫˮ��ʱ����count������ֵΪ0��
	count = 0;
	//MyPlaySound();//��������
	//ZhongDuanSound();//�ж�����

	//int QingkongPage = 0;//���������ϲ����
	//system("cls");
	srand((unsigned int)time(NULL));
	menu(&count);

	printf("�齱��ʽ��Ϊ2�֣�����1��1�Σ�����5��5��,����0�����齱\n");
	printf("���������������������롣\n");
	while (1)
	{
		printf("ʣ�����:%d\n", integral);
		printf("��ѡ��Ҫ�齱�ķ�ʽ:>");
		scanf("%d", &integral_1);
		if (integral_1 == 0)
		{
			printf("���γ齱����\n");
			menu(&count);
			break;
		}
		if (integral_1 == 1)
		{
			if (integral >= 45)
			{
				count++;
				count = probability(&count);//���ó齱����1
				menu(&count);
				integral -= 45;
			}
			else
			{
				static int ChoZhi = 0;
				//���ֲ���Ĵ������ó�ֵ����
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
				//���ֲ���Ĵ������ó�ֵ����
				ChoZhi = VoucherCenter();
				integral = integral + ChoZhi;
			}
		}
		if (count == 361)
		{
			printf("\n");
			printf("********************\n");
			printf("******��ҫˮ��******\n");
			printf("********************\n");
			count = 0;
			menu(&count);
		}
	}
	system("pause");
	return 0;
}