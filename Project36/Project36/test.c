////*******************************
////1.ʵ��strstr
////2.ʵ��strchr
////3.ʵ��strcmp
////4.ʵ��memcpy
////5.ʵ��memmove
////*******************************
////***1.ʵ��strstr ***���ַ����Ĳ��ң�
//#include<Aventador_SQ.h>
//
//int Strstr(char arr[], const char arr1[],int* location)
//{
//	int i = 0;
//	int ArrLen = strlen(arr);
//	int Arr1Len = strlen(arr1);
//	int temp = ArrLen - Arr1Len;
//	for (i = 0; i <= temp; i++)
//	{
//		for (int j = 0; j < Arr1Len; j++)
//		{
//			if (arr[i + j] != arr1[j])
//			{
//				break;
//			}
//			else
//			{
//				if (j == Arr1Len -1)
//				{
//					*location = i + 1;
//					return 1;
//				}
//			}
//		}
//	}
//	return 0;
//}
//int main()
//{
//	int location = 0;//��¼�ַ����״γ��ֵ�λ��
//	char arr[1024];
//	char arr1[1024];
//	printf("������Դ�ַ�����");
//	scanf("%s", arr);
//	printf("����������ַ�����");
//	scanf("%s", arr1);
//	int temp = Strstr(arr, arr1, &location);
//	if (temp == 1)
//	{
//		printf("�ҵ���\n");
//		printf("���ַ����״γ��ֵ�Դ�ַ�����λ����:��%dλ\n", location);
//	}
//	else
//	{
//		printf("û�ҵ�\n");
//	}
//	system("pause");
//	return 0;
//}
//
//2.ʵ��strchr�������ַ��״γ��ֵ�λ�ã�
//#include<Aventador_SQ.h>
//
//int Strchr(char arr[], char Char,int* location)
//{
//	int i = 0;
//	int ArrLen = strlen(arr);
//	int temp = ArrLen;
//	for (i = 0; i <= temp; i++)
//	{
//		if (arr[i] == Char)
//		{
//			*location = i + 1;
//			return 1;
//		}
//	}
//	return 0;
//}
//int main()
//{
//	int location = 0;//��¼�ַ��״γ��ֵ�λ��
//	char arr[1024];
//	char Char;
//	printf("������Դ�ַ�����");
//	scanf("%s%*c", arr);
//	printf("����������ַ���");
//	scanf("%c%*c", &Char);
//	int temp = Strchr(arr, Char, &location);
//	if (temp == 1)
//	{
//		printf("�ҵ���\n");
//		printf("���ַ��״γ��ֵ�Դ�ַ�����λ����:��%dλ\n", location);
//	}
//	else
//	{
//		printf("û�ҵ�\n");
//	}
//	system("pause");
//	return 0;
//}
//
//2.ʵ��strcmp���Ƚ������ַ�����
//#include<Aventador_SQ.h>
//int Strcmp(char arr[], char arr1[])
//{
//	int i = 0;
//	int num = 0;
//	int ArrLen = strlen(arr);//��ȡ�ַ����ĳ���
//	int Arr1Len = strlen(arr1);
//	if (ArrLen >= Arr1Len)
//	{
//		num = ArrLen;
//	}
//	else
//	{
//		num = Arr1Len;
//	}
//	for (i = 0; i < num; i++)
//	{
//		if (arr[i] > arr1[i])
//		{
//			return 1;
//		}
//		if (arr[i] < arr1[i])
//		{
//			return -1;
//		}
//		if (arr[i] == arr1[i])
//		{
//			if (i == num - 1)
//			{
//				return 0;
//			}
//		}
//	}
//}
//int main()
//{
//	int temp = 0;//�����ж������ַ���֮��ķ���ֵ
//	char arr[1024];
//	char arr1[1024];
//	printf("������Դ�ַ�����");
//	scanf("%s%*c", arr);
//	printf("��������Ƚ��ַ�����");
//	scanf("%s%*c", arr1);
//	temp = Strcmp(arr, arr1);
//	if (temp == 1)
//	{
//		printf("Դ�ַ������ڴ��Ƚ��ַ���\n");
//	}
//	else if (temp == 0)
//	{
//		printf("Դ�ַ������ڴ��Ƚ��ַ���\n");
//	}
//	else
//	{
//		printf("Դ�ַ���С�ڴ��Ƚ��ַ���\n");
//	}
//	system("pause");
//	return 0;
//}
//
//4.ʵ��memcpy����Դ�ַ�������n���ֽڵ����ݵ���Ҫ���Ƶĵط���
#include<Aventador_SQ.h>
#define size_t unsigned long
void Memcpy(void* DestArr, const void* arr, size_t n)
{
	unsigned int i = 0;
	char* des = (char*)DestArr;
	char* ar = (char*)arr;
	for (i = 0; i < n; i++)
	{
		*des++ = *ar++;
	}
	return DestArr;
}
int main()
{
	size_t n = 0;//��Ҫ���Ƶ��ַ�����
	//typedef struct student {
	//	char name[100];
	//	int age;
	//}stu;
	//stu arr[1024] = { {"zhensan", 20},{"lisi", 22},{"jmz", 23} };
	//stu DestArr[1024];
	//printf("��������Ҫ���Ƶĸ�����");
	//scanf("%d", &n);
	char arr[] = "hello world!!!";
	char dest[1024];
	Memcpy(dest,arr,8);
	printf("%s", dest);
	system("pause");
	return 0;
}

////5.ʵ��memmove