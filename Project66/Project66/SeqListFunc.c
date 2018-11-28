#include "SeqList.h"
#include<assert.h>

//�����ڵ�
char* CreateSeqListNode(SeqList* ptr)
{

}

//˳����ʼ��
void InitSeqList(SeqList* ptr)
{

}

//˳�����������
//ͷ��
void TouZengSeqList(SeqList* ptr, int data)
{

}

//β��
void WeiZengSeqList(SeqList* ptr, int data)
{

}

//����λ�ò���
void RenYiZengSeqList(SeqList* ptr, int pos, int data)//pos�±�
{
	assert(ptr);
	//�Ƿ�����
	//...
	assert(pos >=0 && pos <= ptr->size);

	for (int i =ptr->size - 1; i >= pos; i--)
	{
		ptr->data[i + 1] = ptr->data[i];
	}
	ptr->data[pos] = data;
	ptr->size++;
}

void SwapData(char* ptr,char* ptr1)
{
	int temp = *ptr;
	*ptr = *ptr1;
	*ptr1 = temp;
}

//ð��
void SeqListBubbleSort(SeqList* ptr)
{
	assert(ptr);
	for (int i = 0; i < ptr->size; i++)
	{ 
		for (int j = 0; j <= ptr->size - 1 - i; j++)
		{
			if (ptr->data[j] > ptr->data[j + 1])
			{
				SwapData(&ptr->data[j + 1], &ptr->data[j]);
			}
		}
	}
}

//���ֲ���
int SeqListBinarySearch(SeqList* ptr, DataType data)
{
	assert(ptr);
	int left = 0;
	int right = ptr->size - 1;
	while (left <= right)
	{
		int mid = left + (right - left) / 2;
		if (ptr->data[mid] > data)
		{
			right = mid - 1;
		}
		if (ptr->data[mid] < data)
		{
			left = mid + 1;
		}
		if (ptr->data[mid] == data)
		{
			return mid;
		}
	}
	return -1;
}

//ʱ�临�Ӷ�O(n2),�ռ临�Ӷ�O(1)
//��һ����һ��
////ʱ�临�Ӷ�O(n)���ռ临�Ӷ�O(n)
//2 3 5 6 4 4 5 4 6
//���ٿռ�2 3 5 6 5 4 6
//ʱ�临�Ӷ�O(n)���ռ临�Ӷ�O(1)
//2 3 5 6 4 4 5 4 6
//        i   j
//ԭλ��

