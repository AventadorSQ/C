//1.ʵ��һ�����������������ַ����е�k���ַ���
//ABCD����һ���ַ��õ�BCDA
//ABCD���������ַ��õ�CDAB
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
//		for (j = 1; j < num; j++)//ѭ���ƶ��ַ�����λ��
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
//	printf("��������Ҫ�����ĸ�����");
//	scanf("%d", &k);
//	ZuoXuan(arr,num,k);
//	system("pause");
//	return 0;
//}
//2.�ж�һ���ַ����Ƿ�Ϊ����һ���ַ�����ת֮����ַ�����
//���磺����s1 = AABCD��s2 = BCDAA������1������s1 = abcd��s2 = ACBD������0.
////
////AABCD����һ���ַ��õ�ABCDA
////AABCD���������ַ��õ�BCDAA
////
////AABCD����һ���ַ��õ�DAABC
//
#include<Aventador_SQ.h>

int IsXuan(char arr1[], int num1, char arr2[], int num2)
{
	int row = 0;
	int i = 0;
	int j = 0;
	char temp;//���ڼ�¼�����һ���ַ�
	if (num1 != num2)
	{
		return 0;
	}
	else
	{
		//����������˳����ͬ������һ���൱������num1-1����
		//�ж����������
		for (row = 1; row < num1; row++)//��αȽ���ת����
		{
			for (i = 0;i < row;i++)//��ת���ַ����Ĵ���
			{
				temp = arr2[0];
				for (j = 1; j < num1; j++)//ѭ���ƶ��ַ�����λ��
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
	int num1 = 0;//��¼�����һ���ַ����ĳ���
	int num2 = 0;//��¼�ڶ����ַ����ĳ���
	int num = 2;//�������շ���ֵ
	char arr1[100];
	char arr2[100];
	printf("�������ַ���1��");
	scanf("%s", arr1);
	printf("�������ַ���2��");
	scanf("%s", arr2);
	num1 = strlen(arr1);//��ȡ�ַ����ĳ���
	num2 = strlen(arr2);
	num = IsXuan(arr1, num1, arr2, num2);
	if (num == 1)
	{
		printf("����ת�ַ���\n");
	}
	else
	{
		printf("������ת�ַ���\n");
	}
	system("pause");
	return 0;
}
//		////�ж����������
//		//for (row = 1; row < num1; row++)//��αȽ���ת����
//		//{
//		//	for (i = 0; i < row; i++)//��ת���ַ����Ĵ���
//		//	{
//		//		temp = arr2[num1-1];
//		//		for (j = num1 - 1; j >= 0; j--)//ѭ���ƶ��ַ�����λ��
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