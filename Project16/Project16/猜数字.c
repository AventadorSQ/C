////1.������С��Ϸ
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
//	printf("**                           ��������Ϸ                               **\n");
//	printf("************************************************************************\n");
//	printf("**                       ����������0��99֮��                          **\n");
//	printf("************************************************************************\n");
//	printf("**                         1 Play    0 Exit                           **\n");
//	printf("************************************************************************\n");
//	printf("��ѡ��\n");
//}
//
//void Game()
//{
//	int SuiJiShu = 0;
//	SuiJiShu = rand() % 100;
//	int input = 0;
//	printf("�������:");
//	while (1)
//	{
//		scanf("%d", &input);
//		if (input > SuiJiShu)
//		{
//			printf("�´���\n");
//		}
//		else if (input < SuiJiShu)
//		{
//			printf("��С��\n");
//		}
//		else
//		{
//			printf("��ϲ��¶���\n");
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
//			printf("����������:\n");
//		}
//	} while (Switch);
//}
//int main()
//{
//	SuiJiZhongZi();//�����������������
//	menu();//��ӡ�˵�
//	IsPlay();//��ʼ��Ϸ
//	system("pause");
//	return 0;
//}

////2.����������������Ҫ��ѯ������
//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//
//int main()
//{
//	int ArrLen = 0;
//	int input = 0;
//	int left = 0;//�������±�
//	int right = 0;//�������±�
//	int mid = 0;//�м��±�
//	int arr[] = { 1,3,5,7,8,9,15,46,89,999,1024 };
//	ArrLen=sizeof(arr) / sizeof(arr[1]);
//	right = ArrLen - 1;
//	printf("��������Ҫ���ҵ�����:");
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
//			printf("�ҵ��ˣ�%d���±���%d\n", input, mid);
//			break;
//		}
//	}
//	if (left > right)
//	{
//		printf("û�ҵ�\n");
//	}
//	system("pause");
//	return 0;
//}

////3.ģ��������������ĳ���
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
//		printf("����������:");
//		scanf("%s%*c", CharsInput);
//		if (strcmp(CharsInput,"yidingbjmz") == 0)
//		{
//			break;
//		}
//	}
//	if (i == 3)
//	{
//		printf("��������������󣬽�ֹ��¼��\n");
//	}
//	system("pause");
//	return 0;
//}

////4.��ĸ��С��С�������ֻ���
//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//
//int main()
//{
//	int num = 0;
//	char arr[100];
//	printf("�����룺");
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