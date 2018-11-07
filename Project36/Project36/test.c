////*******************************
////1.实现strstr
////2.实现strchr
////3.实现strcmp
////4.实现memcpy
////5.实现memmove
////*******************************
////***1.实现strstr ***（字符串的查找）
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
//	int location = 0;//记录字符串首次出现的位置
//	char arr[1024];
//	char arr1[1024];
//	printf("请输入源字符串：");
//	scanf("%s", arr);
//	printf("请输入待查字符串：");
//	scanf("%s", arr1);
//	int temp = Strstr(arr, arr1, &location);
//	if (temp == 1)
//	{
//		printf("找到了\n");
//		printf("该字符串首次出现的源字符串的位置是:第%d位\n", location);
//	}
//	else
//	{
//		printf("没找到\n");
//	}
//	system("pause");
//	return 0;
//}
//
//2.实现strchr（查找字符首次出现的位置）
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
//	int location = 0;//记录字符首次出现的位置
//	char arr[1024];
//	char Char;
//	printf("请输入源字符串：");
//	scanf("%s%*c", arr);
//	printf("请输入待查字符：");
//	scanf("%c%*c", &Char);
//	int temp = Strchr(arr, Char, &location);
//	if (temp == 1)
//	{
//		printf("找到了\n");
//		printf("该字符首次出现的源字符串的位置是:第%d位\n", location);
//	}
//	else
//	{
//		printf("没找到\n");
//	}
//	system("pause");
//	return 0;
//}
//
//2.实现strcmp（比较两个字符串）
//#include<Aventador_SQ.h>
//int Strcmp(char arr[], char arr1[])
//{
//	int i = 0;
//	int num = 0;
//	int ArrLen = strlen(arr);//求取字符串的长度
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
//	int temp = 0;//接受判断两个字符串之后的返回值
//	char arr[1024];
//	char arr1[1024];
//	printf("请输入源字符串：");
//	scanf("%s%*c", arr);
//	printf("请输入待比较字符串：");
//	scanf("%s%*c", arr1);
//	temp = Strcmp(arr, arr1);
//	if (temp == 1)
//	{
//		printf("源字符串大于待比较字符串\n");
//	}
//	else if (temp == 0)
//	{
//		printf("源字符串等于待比较字符串\n");
//	}
//	else
//	{
//		printf("源字符串小于待比较字符串\n");
//	}
//	system("pause");
//	return 0;
//}
//
//4.实现memcpy（从源字符串复制n个字节的数据到需要复制的地方）
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
	size_t n = 0;//需要复制的字符个数
	//typedef struct student {
	//	char name[100];
	//	int age;
	//}stu;
	//stu arr[1024] = { {"zhensan", 20},{"lisi", 22},{"jmz", 23} };
	//stu DestArr[1024];
	//printf("请输入需要复制的个数：");
	//scanf("%d", &n);
	char arr[] = "hello world!!!";
	char dest[1024];
	Memcpy(dest,arr,8);
	printf("%s", dest);
	system("pause");
	return 0;
}

////5.实现memmove