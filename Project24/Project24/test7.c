
////******************************************
//1.дһ���������ز����������� 1 �ĸ���
//���磺 15 0000 1111 4 �� 1
//����ԭ�ͣ�
//int count_one_bits(unsigned int value)
//{
//	// ���� 1��λ�� 
//}
//********************************************

//λ������
//    &   ȫ1Ϊ1
//    |   ��1Ϊ1
//    ^   10/01Ϊ0��ȫ1��ȫ0Ϊ0��
#include<Aventador_SQ.h>
//int count_one_bits(unsigned int value)
//{
//	int count = 0;
//	for (count = 0; value != 0; value /= 2)
//	{
//		if (value % 2 == 1)
//		{
//			count++;
//		}
//	}
//	return count;
//}

//int count_one_bits(unsigned int value)
//{
//	int count = 0;
//	for (count = 0; value != 0; value /= 2)
//	{
//		if (value % 2 == 1)
//		{
//			count++;
//		}
//	}
//	return count;
//}
//
//int main()
//{
//	unsigned int n = 0;
//	int count = 0;
//	scanf("%d", &n);
//	count = count_one_bits(n);
//	printf("%d\n", count);
//	system("pause");
//	return 0;
//}

////**********************************************
////2.��ȡһ�������������������е�ż��λ������λ�� 
////�ֱ�������������С�
////**********************************************
//
//#include<Aventador_SQ.h>
//
//void TwoJiOu(int n)
//{
//	int count = 0;
//	int num = 0;
//	int num2 = n;
//	int num3 = n;
//	for (; n != 0; n /= 2)
//	{
//		count++;
//		//printf("%d", n);
//	}
//	printf("%d\n", count);
//	printf("����λ�����ǣ�");
//	for (num = 1; num <= count; num++)
//	{
//		if (num % 2 == 1)
//		{
//			printf("%d ", (num2 % 2));
//			num2 /= 4;
//		}
//	}
//	printf("\nż��λ�����ǣ�");
//	for (num = 1; num <= count; num++)
//	{
//		if (num % 2 == 0)
//		{
//			printf("%d ", (num3 % 2));
//			num3 /= 4;
//		}
//	}
//	printf("\n");
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	TwoJiOu(n);
//	system("pause");
//	return 0;
//}

////********************************
////3. ���һ��������ÿһλ��
////********************************
//
//#include<Aventador_SQ.h>
//
//void Print(int num)
//{
//	int count = 0;
//	int num1 = num;
//	int i = 0;
//	while (1)
//	{
//		if (num != 0)
//		{
//			num /= 10;
//			count++;
//		}
//		else
//		{
//			break;
//		}
//	}
//	printf("������%dλ��\n", count);
//	if (num1 > 0)
//	{
//		for (i = 1; i <= count; i++)
//		{
//			printf("%d ", num1 % 10);
//			num1 /= 10;
//		//	printf("%d ", (num1 / (10*(count-i))));
//		//	num1 = num1 % (10 * (count - i));
//		}
//	}
//	else
//	{
//		printf("�������!!!\n");
//	}
//}
//int main()
//{
//	int num = 0;
//	scanf("%d", &num);
//	Print(num);
//	system("pause");
//	return 0;
//}

//****************************************************************
//4.���ʵ�֣� 
//����int��32λ������m��n�Ķ����Ʊ���У��ж��ٸ�λ(bit)��ͬ��
//�������� :
//1999 2299
//������� : 7
////**************************************************************

#include<Aventador_SQ.h>
void IsNoSameBit(int num1, int num2)
{
	int i = 0;
	int sum1 = 0;
	int sum2 = 0;
	int count = 0;//��¼���������и���λ��ͬ�ĸ���
	if ((num1 >= 0) && (num2 >= 0))
	{
		for (i = 1; i <= 32; i++)
		{
			sum1 = num1 % 2;
			sum2 = num2 % 2;
			if (sum1 != sum2)
			{
				count++;
			}
			num1 /= 2;
			num2 /= 2;
		}
		printf("%d\n", count);
	}
	else
	{
		printf("�������!!!\n");
	}
}
int main()
{
	int num1 = 0;
	int num2 = 0;
	scanf("%d %d", &num1, &num2);
	IsNoSameBit(num1, num2);
	system("pause");
	return 0;
}