//******************************************
//1.һ��������ֻ�����������ǳ���һ�Σ�
//�����������ֶ����������Ρ�
//�ҳ����������֣����ʵ�֡�
//******************************************
//#include<Aventador_SQ.h>
//
//void IsOneNum(int arr[], int num)
//{
//	int i = 0, j = 0;
//	for (i = 0; i < num; i++)
//	{
//		for (j = 0; j < num; j++)		
//		{
//			if (j != i)
//			{
//				if (arr[i] == arr[j])
//				{
//					break;
//				}
//				else if(arr[i] != arr[j])
//				{
//					if (j == num - 1)
//					{
//						printf("%d ", arr[i]);
//					}
//					if ((i == num - 1) && (j == num - 2))//�����ж����һ�����Ƿ�Ψһ
//					{
//						printf("%d\n", arr[i]);
//					}
//				}
//			}
//		}
//	}
//
//}
//int main()
//{
//	int num = 0;
//	int arr[] = { 2,2,5,6,7,8,9,6,7,9,10};
//	num = sizeof(arr) / sizeof(arr[0]);
//	IsOneNum(arr,num);
//	system("pause");
//	return 0;
//}
//
//************************************************
//2.����ˮ��1ƿ��ˮ1Ԫ��2����ƿ���Ի�һƿ��ˮ��
//��20Ԫ�����Զ�����ˮ��
//���ʵ�֡�
//************************************************
//
#include<Aventador_SQ.h>
int SodaWater(int money)
{
	int bottle = money;
	static int yu = 0;
	if ((money % 2 == 0) && (money != 0))
	{
		return bottle + SodaWater(bottle / 2);
	}
	else if ((money % 2 == 1) && (yu == 0))
	{
		yu = 1;
		return bottle + SodaWater(bottle / 2);
	}
	else if ((money % 2 == 1) && (yu == 1))
	{
		yu = 0;
		return bottle + SodaWater(bottle / 2 + 1);
	}
	return bottle;
}
int main()
{
	int Money = 20;
	int num = 0;
	num = SodaWater(Money);
	printf("���Ժ�%dƿ��ˮ\n", num);
	system("pause");
	return 0;
}
//
//************************************************
//3.ģ��ʵ��strcpy 
//************************************************
//
//#include<Aventador_SQ.h>
//
//void Strcopy(char arr1[], const char arr[])
//{
//	int i = 0;
//	int num=strlen(arr);
//	printf("num=%d\n", num);
//	for (i = 0; i <= num; i++)
//	{
//		arr1[i] = arr[i];
//	}
//}
//int main()
//{
//	char arr[1024];
//	char arr1[1024];
//	printf("�����뽫Ҫ�������ַ���(arr)��");
//	scanf("%s", arr);
//	Strcopy(arr1,arr);
//	printf("�ַ���arr1=%s\n", arr1);
//	int num1 = strlen(arr1);
//	printf("num1=%d\n", num1);
//	system("pause");
//	return 0;
//}
//
//*****************************************
//4.ģ��ʵ��strcat 
//*****************************************
//#include<Aventador_SQ.h>
//void Strcat(char arr1[], const char arr[])
//{
//	int Arr1Len = 0;
//	int ArrLen = 0;
//	Arr1Len = strlen(arr1);
//	printf("%d\n", Arr1Len);
//	ArrLen = strlen(arr);
//	printf("%d\n", ArrLen);
//	for (int i = Arr1Len; i <= ( Arr1Len + ArrLen); i++)
//	{
//		arr1[i] = arr[i - Arr1Len];
//	}
//}
//int main()
//{
//	char arr[1024];
//	char arr1[1024];
//	printf("�������ַ���(arr1)��");
//	scanf("%s%*c", arr1);
//	printf("�������ַ���(arr)��");
//	scanf("%s%*c", arr);
//    Strcat(arr1,arr);
//	printf("ƴ�ӵ�arr1�ϵ��ַ���arr1=%s\n", arr1);
//	system("pause");
//	return 0;
//}