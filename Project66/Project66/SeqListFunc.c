#include "SeqList.h"
#include<assert.h>

//创建节点
char* CreateSeqListNode(SeqList* ptr)
{

}

//顺序表初始化
void InitSeqList(SeqList* ptr)
{

}

//顺序表增加数据
//头插
void TouZengSeqList(SeqList* ptr, int data)
{

}

//尾插
void WeiZengSeqList(SeqList* ptr, int data)
{

}

//任意位置插入
void RenYiZengSeqList(SeqList* ptr, int pos, int data)//pos下标
{
	assert(ptr);
	//是否满了
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

//冒泡
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

//二分查找
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

//时间复杂度O(n2),空间复杂度O(1)
//找一个搬一次
////时间复杂度O(n)，空间复杂度O(n)
//2 3 5 6 4 4 5 4 6
//开辟空间2 3 5 6 5 4 6
//时间复杂度O(n)，空间复杂度O(1)
//2 3 5 6 4 4 5 4 6
//        i   j
//原位置

