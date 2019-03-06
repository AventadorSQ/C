#include"QuickSort.h"


void Swap(int* num1, int* num2)
{
	int temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}
//��������
//left���±� right���±�
void QuickSort(int array[], int left, int right)
{
	//��һ��������û��
	if (right - left <= 0)
	{
		return;
	}

	int i = left;
	int j = right;
	int mid = (j + i) / 2;

	//��������
	if (right - left == 1)
	{
		if (array[mid] > array[mid + 1])
		{
			Swap(&array[mid + 1], &array[mid]);
			mid = mid + 1;
			return;
		}
		return;
	}

	//ȡ������ֵΪ��׼
	//������������
	//3 6 2
	if (right - left > 1)
	{
		if (array[mid] > array[j])
		{
			Swap(&array[mid], &array[j]);
		}
		if (array[i] > array[j])
		{
			Swap(&array[i], &array[j]);
		}
		if (array[i] > array[mid])
		{
			Swap(&array[i], &array[mid]);
		}
	}

	//�������ĸ���
	if (right - left > 2)
	{
		//����ֵ�͵����ڶ���ֵ���н������Ҽ�¼��ֵ�����±�
		Swap(&array[mid], &array[right - 1]);
		mid = right - 1;

		//���ұ�j��ʼ���±�
		j = right - 2;
		i = left + 1;
		while (i < j)
		{
			if (array[i] > array[mid])
			{
				while (i < j)
				{
					if (array[j] < array[mid])
					{
						Swap(&array[i], &array[j]);
						break;
					}
					j--;
				}
			}
			if (i < j)
			{
				i++;
			}
		}
		//��һ�˽������һ��������ֵ��Ԫ�ؽ��н������Ҽ�¼��ֵ�±�
		if (array[i] > array[mid])
		{
			Swap(&array[i], &array[mid]);
			mid = i;
		}
		QuickSort(array, left, mid - 1);
		QuickSort(array, mid + 1, right);
	}
}


//int Sma = 0;
//int Big = 0;
//while(1)
//{
//	if (array[Big] < array[size - 1])
//	{
//		Big++;
//	}
//	if (array[Sma] > array[size - 1])
//	{
//		Sma++;
//	}
//	Swap(&array[Big], &array[Sma]);
//}

