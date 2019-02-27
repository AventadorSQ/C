#include"Sort.h"

//0.ð������
void BubbleSort(int array[], int size)
{
	int i = 0;
	int j = 0;
	for (i = 1; i < size; i++)
	{
		int k = 1;
		for (j = 0; j < size - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				int temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				k = 0;
			}
		}
		if (k == 1)
		{
			break;
		}
	}
	for (i = 0; i < size; i++)
	{
		printf("%d ", array[i]);
	}
}

//1.ֱ�Ӳ������򣨴��Ʋ��ƵĹ��̣�
//5,6,1,2,3,7,4,9,6 
void InsertSort(int array[],int length)
{
	int i = 0;
	int j = 0;
	int temp;
	for (i = 1; i < length; i++)
	{
		temp = array[i];
		for (j = i - 1; j >= 0; j--)
		{
			if (array[j] <= temp)
			{
				/*array[j + 1] = temp;*/
				break;
			}
			else
			{
				array[j + 1] = array[j];
			}
			/*if (j == 0)
			{
				array[j] = temp;
			}*/
		}
		array[j + 1] = temp;
		
	}

	for (i = 0; i < length; i++)
	{
		printf("%d ", array[i]);
	}
}

//1.2���ֲ��ң���������

//2.ϣ������
void InsertSortNum(int array[], int length,int Num)
{
	int i = 0;
	int j = 0;
	int temp;
	for (i = 1; i < length; i += Num)
	{
		temp = array[i];
		for (j = i - Num; j >= 0; j -= Num)
		{
			if (array[j] <= temp)
			{
				/*array[j + 1] = temp;*/
				break;
			}
			else
			{
				array[j + Num] = array[j];
			}
			/*if (j == 0)
			{
			array[j] = temp;
			}*/
		}
		array[j + Num] = temp;

	}
}

void ShellSort(int array[], int length)
{
	int k = length;
	while (k > 1)
	{
		k = (k / 3) + 1;
		InsertSortNum(array, length, k);
	}
	for (int i = 0; i < length; i++)
	{
		printf("%d ", array[i]);
	}
}

//3.ѡ������  ÿ���ҵ���С�Ļ����ķ������յ�λ����
void SelectSort(int array[], int size)
{
	int i, j;
	int MIN = 0;
	for (j = 0; j < size - 1; j++)
	{
		MIN = j;
		for (i = j + 1; i < size; i++)
		{
			if (array[MIN] > array[i])
			{
				MIN = i;
			}
		}
		int temp = array[MIN];
		array[MIN] = array[j];
		array[j] = temp;
	}
	for (i = 0; i < size; i++)
	{
		printf("%d ", array[i]);
	}
}

//5.������
//root��ʾҪ�����Ľ���±�

//���µ���
void ADjustDown(int array[], int size, int root)
{
	int left = 2 * root + 1;
	int right = 2 * root + 2;
	if(left < size)
	{
		int max = left;
		if (right < size && array[left] < array[right])
		{
			max = right;
		}
		if (array[root] >= array[max])
		{
			return;
		}
		int temp = array[max];
		array[max] = array[root];
		array[root] = temp;
		ADjustDown(array, size, max);
	}

}

void CreateHeap(int array[], int size)
{
	//���һ����Ҷ�ӽ��(size-2)/2
	for (int i = (size - 2) / 2; i >= 0; i--)
	{
		ADjustDown(array, size, i);
	}
}

void HeapSort(int array[], int size)
{
	//1.����
	CreateHeap(array, size);

	//2.���������������Ϊ���
	for (int i = size - 1; i > 0; i--)
	{
		int temp = array[0];
		array[0] = array[i];
		array[i] = temp;
		ADjustDown(array, i, 0);
	}

	for (int i = 0; i < size; i++)
	{
		printf("%d ", array[i]);
	}
}