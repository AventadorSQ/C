//*****************************************************************
//1.调整数组使奇数全部都位于偶数前面。
//
//题目：
//
//输入一个整数数组，实现一个函数，
//来调整该数组中数字的顺序使得数组中所有的奇数位于数组的前半部分，
//所有偶数位于数组的后半部分。
//*****************************************************************
//#include<Aventador_SQ.h>
//#define ROW 100
//void JiOuSort(int arr[ROW],int count)
//{
//	//int temp = 0;
//	//for (int i = 0; i < count; i++)
//	//{
//	//	if (arr[i] % 2 == 0)
//	//	{
//	//		for (int j=count; j >= 0; j--)
//	//		{
//	//			if (arr[j - 1] % 2 == 1)
//	//			{
//	//				temp = arr[i];
//	//				arr[i] = arr[j - 1];
//	//				arr[j - 1] = temp;
//	//				break;
//	//			}
//	//		}
//	//	}
//	//}
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
////杨氏矩阵 
//有一个二维数组.
//数组的每行从左到右是递增的，每列从上到下是递增的.
//在这样的数组中查找一个数字是否存在。
//时间复杂度小于O(N);
//
//数组：
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
#define ROW 3
#define COL 3
void Seek(int arr[ROW][COL],int n)
{
	int left = 0;
	int right = ROW;
	int mid = 0;
	while (left <= right)
	{
		mid = (right - left) / 2 + left;
		if (arr[mid][mid] == n)
		{
			printf("找到了\n");
			break;
		}
		if (arr[mid][mid] > n)
		{
			right = mid - 1;
		}
		if (arr[mid][mid] < n)
		{
			left = mid + 1;
		}
	}
	if (left > right)
	{
		printf("没找到\n");
	}

}
int main()
{
	int n = 0;
	int arr[ROW][COL] = { {1,2,3},{2,3,4},{3,4,5} };
	scanf("%d", &n);
	Seek(arr,n);
	system("pause");
	return 0;
}