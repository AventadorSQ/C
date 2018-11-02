//1.实现一个函数，可以左旋字符串中的k个字符。
//ABCD左旋一个字符得到BCDA
//ABCD左旋两个字符得到CDAB
//#include<Aventador_SQ.h>
//void ZuoXuan(char arr[],int num,int k)
//{
//	int i = 0;
//	int j = 0;
//	char temp;
//	while (i < k)
//	{
//		temp = arr[0];
//		
//		for (j = 1; j < num; j++)//循环移动字符串的位置
//		{
//			arr[j-1]= arr[j];
//			if (j == num - 1)
//			{
//				arr[j] = temp;
//			}
//		}
//		//arr[j] = temp;
//		i++;
//	}
//	//for (i = 0; i < num; i++)
//	//{
//	//	printf("%c", arr[i]);
//	//}
//	//printf("\n");
//	printf("%s\n", arr);
//}
//
//int main()
//{
//	int k = 0;
//	int num = 0;
//	char arr[100];
//	scanf("%s", arr);
//	num = strlen(arr);
//	printf("请输入需要左旋的个数：");
//	scanf("%d", &k);
//	ZuoXuan(arr,num,k);
//	system("pause");
//	return 0;
//}
//2.判断一个字符串是否为另外一个字符串旋转之后的字符串。
//例如：给定s1 = AABCD和s2 = BCDAA，返回1，给定s1 = abcd和s2 = ACBD，返回0.
////
////AABCD左旋一个字符得到ABCDA
////AABCD左旋两个字符得到BCDAA
////
////AABCD右旋一个字符得到DAABC
//
#include<Aventador_SQ.h>

int IsXuan(char arr1[], int num1, char arr2[], int num2)
{
	int row = 0;
	int i = 0;
	int j = 0;
	char temp;//用于记录保存第一个字符
	if (num1 != num2)
	{
		return 0;
	}
	else
	{
		//左旋与右旋顺序相同（左旋一个相当于右旋num1-1个）
		//判断左旋的情况
		for (row = 1; row < num1; row++)//逐次比较旋转次数
		{
			for (i = 0;i < row;i++)//旋转的字符数的次数
			{
				temp = arr2[0];
				for (j = 1; j < num1; j++)//循环移动字符串的位置
				{
					arr2[j - 1] = arr2[j];
					if (j == num1 - 1)
					{
						arr2[j] = temp;
					}
				}
				for (j = 0; j < num1; j++)
				{
					if (arr1[j] == arr2[j])
					{
						if (j == num1 - 1)
						{
							return 1;
						}
					}
				}
			}
		}
	}
	return 0;
}
int main()
{
	int num1 = 0;//记录输入第一条字符串的长度
	int num2 = 0;//记录第二条字符串的长度
	int num = 2;//用来接收返回值
	char arr1[100];
	char arr2[100];
	printf("请输入字符串1：");
	scanf("%s", arr1);
	printf("请输入字符串2：");
	scanf("%s", arr2);
	num1 = strlen(arr1);//求取字符串的长度
	num2 = strlen(arr2);
	num = IsXuan(arr1, num1, arr2, num2);
	if (num == 1)
	{
		printf("是旋转字符串\n");
	}
	else
	{
		printf("不是旋转字符串\n");
	}
	system("pause");
	return 0;
}
//		////判断右旋的情况
//		//for (row = 1; row < num1; row++)//逐次比较旋转次数
//		//{
//		//	for (i = 0; i < row; i++)//旋转的字符数的次数
//		//	{
//		//		temp = arr2[num1-1];
//		//		for (j = num1 - 1; j >= 0; j--)//循环移动字符串的位置
//		//		{
//		//			arr2[j] = arr2[j - 1];
//		//			if (j == 0)
//		//			{
//		//				arr2[j] = temp;
//		//			}
//		//		}
//		//		for (j = 0; j < num1; j++)
//		//		{
//		//			if (arr1[j] == arr2[j])
//		//			{
//		//				if (j == num1 - 1)
//		//				{
//		//					return 2;
//		//				}
//		//			}
//		//		}
//		//	}
//		//}