//1. дһ������̨����, ���������ʱ��, ����ʾ�û�ѡ��༶
//����, 41, ���뵽41
//java6, ���� java6
//
//�����и�һ������, ���е�41���ͬѧ.
//�����Ԫ����һ���ṹ��.������Ҫ����ѧ��������.
//
//ÿ�ΰ��»س�, ��������ѡһ�������, �����ͬѧ�������ͱ�Ŵ�ӡ����.
//����������ʱ����ļ��ж�ȡ��Щ��Ϣ.
//
//2. Ҫ��:
//ÿ���༶��ͬѧ��Ϣ��Ҫ�ӽ�����վ�ϻ�ȡ.
//��ȡ����ѧ����Ϣ���浽һ���ļ���.
//
//C :
//	a) ����һ��url, ���ܻ�ȡ����ҳ������.libcurl
//	b) �õ�html(�ַ���), �����ַ���, ��ȡ�����е�ѧ����Ϣ
//	c) �ѻ�ȡ����ѧ����Ϣ����һ���Ĺ���, ���浽һ���ļ���, ����һ���������.
//	����ʹ�����ı��ķ�ʽ����, ÿ������ռһ��.
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>


//��������İ༶�Ƿ�����
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

	int weizhiclass = 0;//��¼�״γ��ְ༶��λ��
	int weizhinum = 0;//��¼�״γ���ѧ��ѧ�ŵ�λ��
	char ArrClasses[1024] = "40 java6 JAVA6";//��¼���еİ༶
	char ArrClassScanf[200];//��¼����İ༶
	BitStu ArrClass[1024];//��¼�༶��ѧ����Ϣ�����ļ����ݴ�������飩
	int Rand = 0;//��¼�����������
	int TempStrstr1 = 0;//�����з���ֵ
	while (1)
	{
		printf("��ѡ��༶��");
		scanf("%s%*c", ArrClassScanf);
		int TempStrstr = Strstr(ArrClasses, ArrClassScanf, &weizhiclass);//�����ж�����༶�Ƿ�����
		if (TempStrstr != 0)
		{
			if (strcmp(ArrClassScanf, "40") == 0)
			{
				printf("haha\n");
				//��ʼҡ��
				Rand = rand() % 53 + 1;
				char ArrRand[100] = "Rand";

				//����ҳԴ�ĵ������ַ������ҵõ�ѧ����Ϣ���������ĵ�

				//��ȡ�ļ�
				//���ļ����ݴ�������༶����
				//ͨ��ҡ�����������������������Ӧλ��
				TempStrstr1 = Strstr(ArrClass, ArrRand, &weizhinum);//Ѱ�Ҹ�ѧ�Ŷ�Ӧ��λ��
																	//���������
				for (int i = weizhinum; i < weizhinum + 20; i++)//ѭ����ӡ��ѧ�ź����10λ��һ��ѧ����Ϣ20���ֽڣ�
				{
					printf("%c", ArrClass[i - 1]);
				}
				printf("\n");
				//printf("haha\n");
				printf("****************************************************\n");
				printf("***       1,�����齱         0��������Ϸ         ***\n");
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

	int OnOff = 0;//�Ƿ�ʼ��Ϸ
	srand((unsigned int)time(NULL));
	while (1)
	{
		printf("****************************************************\n");
		printf("***       1.�����齱         0.������Ϸ         ***\n");
		printf("****************************************************\n");
		printf("***�����룺");
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