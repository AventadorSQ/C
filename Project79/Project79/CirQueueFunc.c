#include"CirQueue.h"

//创建循环队列
CirQueue* CreateCirQueue(int k)
{
	CirQueue* CQPtr = (CirQueue*)malloc(sizeof(CirQueue));
	CQPtr->capcity = k;//队列容量
	CQPtr->size = 0;//队列元素个数
	CQPtr->ptr = (int*)malloc(sizeof(int)*k);
	CQPtr->front = -1;//代表队首元素下标
	CQPtr->rear = 0;//代表队尾下一个元素的下标
	return CQPtr;
}

//插入元素
void InsertCirQueue(CirQueue* CQPtr, int data)
{
	if (CQPtr->size >= CQPtr->capcity)
	{
		printf("循环队列已满,插入失败！！！\n");
		return;
	}
	if (CQPtr->front == -1)
	{
		CQPtr->front = 0;
	}
	CQPtr->ptr[CQPtr->rear] = data;
	CQPtr->rear = (CQPtr->rear + 1)% CQPtr->capcity;
	CQPtr->size++;
}

//删除元素
void DeleteCirQueue(CirQueue* CQPtr)
{
	if (CQPtr->size == 0)
	{
		return;
	}
	CQPtr->front = ((CQPtr->front + 1)% CQPtr->capcity);
	CQPtr->size--;
}

//返回队首元素
int GetHeadCirQueue(CirQueue* CQPtr)
{
	if (CQPtr->size == 0)
	{
		return -1;
	}
	return CQPtr->ptr[CQPtr->front];
}

//返回队尾元素************************************
int GetWeiCirQueue(CirQueue* CQPtr)
{
	if (CQPtr->size == 0)
	{
		return -1;
	}
	return CQPtr->ptr[(CQPtr->capcity + (CQPtr->rear - 1)) % CQPtr->capcity];
}

//返回当前剩余容量
int GetSurplusCirQueue(CirQueue* CQPtr)
{
	return CQPtr->capcity - CQPtr->size;
}

//打印循环队列
void PrintCirQueue(CirQueue* CQPtr)
{
	if (CQPtr->size == 0)
	{
		printf("空队列\n");
		return;
	}
	int fronts = CQPtr->front;
	if (fronts == CQPtr->rear)
	{
		printf("<-- %d ", CQPtr->ptr[fronts]);
		fronts = (1+fronts) % CQPtr->capcity;
	}
	while (fronts != CQPtr->rear)
	{
		printf("<-- %d ", CQPtr->ptr[fronts]);
		fronts = (1+fronts) % CQPtr->capcity;
	}
	printf("\n");
}