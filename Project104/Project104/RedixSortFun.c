//基数排序
//1.按照低位优先开始
//6 8 9 2 4 1 3 7


//交换两个数
void Swap(int* num1, int* num2)
{
	int temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}

//数组中最大的数
int MaxNum(int array[], int size)
{
	int temp = array[0];
	int i;
	for (i = 1; i < size; i++)
	{
		if (array[i] > temp)
		{
			temp = array[i];
		}
	}
	return temp;
}

//最大的数有多少位，记录其位数
int MaxWeiShu(int num)
{
	int counts = 0;
	while (1)
	{
		if (num / 10 != 0)
		{
			num = num / 10;
			counts++;
		}
		else
		{
			break;
		}
	}
	return counts;
}


void RadixSort(int array[], int size)
{
	//数组中最大的数
	int Max = MaxNum(array, size);
	//最大的数有多少位，记录其位数
	int count = MaxWeiShu(Max);
	if (size <= 0)
	{
		return;
	}
	//记录每个桶中存放的个数
	int arrk[10] = { 0 };
	//一个数某位上的数的大小
	int OneNum;
	//创建10个桶
	int arr[10][100000] = { 0 };

	//取出每个数的每个位数按其大小进行排序
	for (int i = 0; i < count; i++)
	{
		//将所有数进行存放进桶中
		for (int j = 0; j < size; j++)
		{
			//判断每一个数不同位上的数
			int temp = (array[j] / pow(10, i)) % 10;
			//判断归类的数在哪个桶中，并放进去
			for (OneNum = 0; OneNum < 10; OneNum++)
			{
				if (temp == OneNum)
				{
					arr[OneNum][arrk[OneNum]] = array[j];
					arrk[OneNum] += 1;
					break;
				}
			}
		}
	}

	int as = 0;
	//将每一次排序后的数重新放回原数组
	for (OneNum = 0; OneNum < 10; OneNum++)
	{
		//将每个桶中的数一次在放回原数组
		for (int x = 0; x < arrk[OneNum]; x++)
		{
			array[as] = arr[OneNum][x];
			as++;
		}
	}
}

//打印排序后的数组
void PrintArray(int array, int size)
{
	for (int y = 0; y < size; y++)
	{
		printf("%d ", array[y]);
	}
	printf("\n");
}


