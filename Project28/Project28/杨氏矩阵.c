//*****************************************************************
//1.��������ʹ����ȫ����λ��ż��ǰ�档
//
//��Ŀ��
//
//����һ���������飬ʵ��һ��������
//�����������������ֵ�˳��ʹ�����������е�����λ�������ǰ�벿�֣�
//����ż��λ������ĺ�벿�֡�
//*****************************************************************
//#include<Aventador_SQ.h>
//#define ROW 100
//void JiOuSort(int arr[ROW],int count)
//{
//	int count1 = 0;
//	int i = 0,j=0;
//	int temp = 0;
//	for (i = 0; i < count; i++)
//	{
//		if (arr[i] % 2 == 1)
//		{
//			count1++;
//		}
//	}
//	for (i = 0; i < count1; i++)
//	{
//		if (arr[i] % 2 == 0)
//		{
//			for (j = count1; j < count; j++)
//			{
//				if (arr[j] % 2 == 1)
//				{
//					temp = arr[i];
//					arr[i] = arr[j];
//					arr[j] = temp;
//					break;
//				}
//			}
//		}
//	}
//	for (int i = 0; i < count; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//}
//
//int main()
//{
//	int i = 0;
//	int arr[] = { 2,4,6,8,10,1,3,5,7,9 };
//	int count = sizeof(arr) / sizeof(arr[0]);
//	JiOuSort(arr,count);
//	system("pause");
//	return 0;
//}
//*****************************************************************
//2.
////���Ͼ��� 
//��һ����ά����.
//�����ÿ�д������ǵ����ģ�ÿ�д��ϵ����ǵ�����.
//�������������в���һ�������Ƿ���ڡ�
//ʱ�临�Ӷ�С��O(N);
//
//���飺
//1 2 3
//2 3 4
//3 4 5
//
//
//1 3 4
//2 4 5
//4 5 6
//
//1 2 3
//4 5 6
//7 8 9
//*****************************************************************
#include<Aventador_SQ.h>
#define ROW 5
#define COL 5
void Seek(int arr[ROW][COL], int n)
{
	int left = 0;
	int right = ROW - 1;
	while ((left < ROW) && (right >= 0))
	{
		if (arr[left][right] < n)
		{
			left++;
		}
		else if (arr[left][right] > n)
		{
			right--;
		}
		else if (arr[left][right] == n)
		{
			printf("�ҵ���\n");
			break;
		}
	}
	if ((left >= ROW) || (right < 0))
	{
		printf("û�ҵ�\n");
	}
}

int main()
{
	int n = 0;
	int arr[ROW][COL] = { { 1,2,3,5,6 },
	{ 4,5,6,7,8 },
	{ 7,8,9,10,12 },
	{ 9,10,12,13,14 },
	{ 12,23,45,56,78 } };
	scanf("%d", &n);
	Seek(arr, n);
	system("pause");
	return 0;
}
//int left = 0;
//int right = ROW;
//int mid = 0;
//mid = (right - left) / 2 + left;
//while (left <= right)
//{
//	//mid = (right - left) / 2 + left;
//	if (arr[mid][mid] == n)
//	{
//		printf("�ҵ���\n");
//		break;
//	}
//	if (arr[mid][mid] > n)
//	{
//		right = mid - 1;
//		mid = (right - left) / 2 + left;
//		if (arr[mid][mid] < n)
//		{
//			if ((arr[mid + 1][mid] == n) || (arr[mid][mid + 1] == 1))
//			{
//				printf("�ҵ���\n");
//				break;
//			}
//			else
//			{
//				printf("û�ҵ�\n");
//				break;
//			}
//		}
//	}

//	if (arr[mid][mid] < n)
//	{
//		left = mid + 1;
//		mid = (right - left) / 2 + left;
//		if (arr[mid][mid] > n)
//		{
//			if ((arr[mid][mid - 1] == n) || (arr[mid - 1][mid] == 1))
//			{
//				printf("�ҵ���\n");
//				break;
//			}
//			else
//			{
//				printf("û�ҵ�\n");
//				break;
//			}
//		}
//	}
//}
//if (left > right)
//{
//	printf("û�ҵ�\n");
//}