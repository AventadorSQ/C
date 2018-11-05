//******************************************
//1.一个数组中只有两个数字是出现一次，
//其他所有数字都出现了两次。
//找出这两个数字，编程实现。
//******************************************
#include<Aventador_SQ.h>

void IsOneNum(int arr[], int num)
{
	int i = 0, j = 0;

	for (i = 0; i < num; i++)
	{
		for (j = 0; j < num; j++)		
		{
			if (j != i)
			{
				if (arr[i] == arr[j])
				{
					break;
				}
				else if(arr[i] != arr[j])
				{
					if (j == num)
					{
						printf("%d ", arr[i]);
					}
				}
			}
		}
	}
}
int main()
{
	int num = 0;
	int arr[] = { 2,2,5,6 };//,7,8,9,6,7,9
	num = sizeof(arr) / sizeof(arr[0]);
	IsOneNum(arr,num);
	system("pause");
	return 0;
}