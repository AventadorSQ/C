#include"BubbleSort.h"

//����������
void SwapNum(int* ptr1, int* ptr2)
{
	int temp = *ptr1;
	*ptr1 = *ptr2;
	*ptr2 = temp;
}

//ð������
void BubbleSort(int array[], int size)
{
	//ð�������߹�������
	for (int i = 0; i < size; i++)
	{
		//ÿ������
		for (int j = 0; j < size - 1; j++)
		{
			//����������ߣ����ս��������������
			if (array[j] > array[j + 1])
			{
				//����������
				SwapNum(&array[j], &array[j + 1]);
			}
		}
	}
}


//��ӡ����
void PrintArray(int array[], int size)
{
	int i = 0;
	while(i < size)
	{
		printf("%d ", array[i]);
		i++;
	}
	printf("\n");
}

//ð������
void BubbleSortS(int array[], int size)
{
	//ð�������߹�������
	for (int i = 0; i < size - 1; i++)
	{
		int k = 1;
		//ÿ������
		for (int j = 0; j < size - 1 - i; j++)
		{
			//����������ߣ����ս��������������
			if (array[j] > array[j + 1])
			{
				//����������
				SwapNum(&array[j], &array[j + 1]);
				k = 0;
			}
		}

		//�ж��Ƿ��Ѿ�����
		if (k == 1)
		{
			break;
		}
	}
}