//��������
//1.���յ�λ���ȿ�ʼ
//6 8 9 2 4 1 3 7


//����������
void Swap(int* num1, int* num2)
{
	int temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}

//������������
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

//�������ж���λ����¼��λ��
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
	//������������
	int Max = MaxNum(array, size);
	//�������ж���λ����¼��λ��
	int count = MaxWeiShu(Max);
	if (size <= 0)
	{
		return;
	}
	//��¼ÿ��Ͱ�д�ŵĸ���
	int arrk[10] = { 0 };
	//һ����ĳλ�ϵ����Ĵ�С
	int OneNum;
	//����10��Ͱ
	int arr[10][100000] = { 0 };

	//ȡ��ÿ������ÿ��λ�������С��������
	for (int i = 0; i < count; i++)
	{
		//�����������д�Ž�Ͱ��
		for (int j = 0; j < size; j++)
		{
			//�ж�ÿһ������ͬλ�ϵ���
			int temp = (array[j] / pow(10, i)) % 10;
			//�жϹ���������ĸ�Ͱ�У����Ž�ȥ
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
	//��ÿһ�������������·Ż�ԭ����
	for (OneNum = 0; OneNum < 10; OneNum++)
	{
		//��ÿ��Ͱ�е���һ���ڷŻ�ԭ����
		for (int x = 0; x < arrk[OneNum]; x++)
		{
			array[as] = arr[OneNum][x];
			as++;
		}
	}
}

//��ӡ����������
void PrintArray(int array, int size)
{
	for (int y = 0; y < size; y++)
	{
		printf("%d ", array[y]);
	}
	printf("\n");
}


