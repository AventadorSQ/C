#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#define MAX_SIZE 1024

typedef int DataType;

typedef struct SeqList
{
	DataType arr[MAX_SIZE];
	int size;//1.顺序表中存储的数据个数
	         //2.记录当前可以存储的下标

}SeqList;


//顺序表初始化
void SeqListInit(SeqList *pSeq)
{
	//1.初始化 size
	//2.可能需要把容器清空
	assert(pSeq != NULL);
	pSeq->size = 0;
	//memset(pSeq->arr,' ',MAX_SIZE * sizeof(DataType));
}
//***********************************************************************************
//增，删
//***********************************************************************************

//尾插
void SeqListPushBack(SeqList *pSeq, DataType data)
{
	assert(pSeq);
	//特殊情况，（满了）
	if (pSeq->size >= MAX_SIZE)
	{
		printf("满了\n");
		assert(0);
		return;
	}
	//普通情况
	pSeq->arr[pSeq->size] = data;
	pSeq->size++;
}
//尾删
void SeqListPushPop(SeqList *pSeq)
{
	assert(pSeq);
	//特殊情况，（空了）
	if (pSeq->size <= 0)
	{
		printf("空了\n");
		assert(0);
		return;
	}
	pSeq->size--;
}

//头插
void SeqListPushFront(SeqList* pSeq, DataType data)
{
	assert(pSeq);
	//特殊情况，（满了）
	if (pSeq->size >= MAX_SIZE)
	{
		printf("满了\n");
		assert(0);
		return;
	}
	//i表示位置
	for (int i = pSeq->size; i > 0; i--)
	{
		pSeq->arr[i] = pSeq->arr[i - 1];
	}
	//将带插入函数插入顺序表
	pSeq->arr[0] = data;
	pSeq->size++;
}

//头删
void SeqLIstPushDelete(SeqList* pSeq)
{
	assert(pSeq);

	//移动每个元素
	for (int i = 1; i < pSeq->size; i++)
	{
		pSeq->arr[i-1] = pSeq->arr[i];
	}
	pSeq->size--;
}

//中间插入
void SeqListInsert(SeqList *pSeq, int pos, DataType data)
{
	assert(pSeq);
	assert(pos >= 0 && pos <= pSeq->size);

	if (pSeq->size >= MAX_SIZE)
	{
		printf("顺序表已满。\n");
		assert(0);
		return;
	}

	//把需要插入的位置以及后面元素往后移动
	for (int i = pSeq->size - 1; i >= pos - 1; i--)
	{
		pSeq->arr[i + 1] = pSeq->arr[i];
	}
	//插入要插入的元素
	pSeq->arr[pos - 1] = data;
	pSeq->size++;
}
//中间删除特定位置的元素
void SeqListZhongJianDelete(SeqList* pSeq,int pos)
{
	assert(pSeq);

	//判空
	if (pSeq->size <= 0)
	{
		printf("顺序表已空\n");
		assert(0);
		return;
	}
	for (int i = pos - 1; i < pSeq->size - 1; i++)
	{
		pSeq->arr[i] = pSeq->arr[i + 1];
	}
	pSeq->size--;
}

//打印顺序表
void SeqListPrint(const SeqList* pSeq)
{
	assert(pSeq != NULL);

	for (int i = 0; i < pSeq->size; i++)
	{
		printf("%d ", pSeq->arr[i]);
	}
	printf("\n");
}

//****************************************************************************
//删除（二）
//****************************************************************************
//删除第一个遇到的元素
void SeqListDeleteOne(SeqList* pSeq,DataType data)
{
	int num = SeqListFind(pSeq, data);
	if (num == 0)
	{
		return;
	}
	else
	{
		SeqListZhongJianDelete(pSeq, num - 1);
	}
}
//删除所有该元素
void SeqListDeleteAll(SeqList* pSeq, DataType data)
{
	//3.0*********************************************   1 2 2 3 4 5 6 7 8 9?????????
	//int temp = 0;
	//for (int i = 0; i < pSeq->size; i++)
	//{
	//	if (temp == 0)
	//	{
	//		if (data == pSeq->arr[i])
	//		{
	//			//pSeq->arr[i] = pSeq->arr[i + 1];
	//			//i++;
	//			temp++;
	//		}
	//	}
	//	else
	//	{

	//	}

	//}
	//2.0*********************************************
	//创建新动态数组
	//DataType* NewArr = (DataType*)malloc(sizeof(DataType)*pSeq->size);
	//int i, j;
	////将其他元素存储在新数组中
	//for (i = 0, j = 0; i < pSeq->size; i++)
	//{
	//	if (data != pSeq->arr[i])
	//	{
	//		NewArr[j] = pSeq->arr[i];
	//		j++;
	//	}
	//}

	////在将元素重新存储进原顺序表中
	//for (i = 0; i < j; i++)
	//{
	//	pSeq->arr[i] = NewArr[i];
	//}
	//pSeq->size = j;

	////释放内存
	//free(NewArr);
	//1.0********************************************
	//int num = 0;
	//while (num = SeqListFind(pSeq, data))
	//{
	//	SeqListZhongJianDelete(pSeq, num - 1);
	//}

}
//****************************************************************************
//查找
//****************************************************************************

size_t SeqListFind(SeqList* pSeq, DataType data)
{
	for (int i = 0; i < pSeq->size; i++)
	{
		if (pSeq->arr[i] == data)
		{
			//printf("找到了,该数据在第%d个位置。\n",i);
			return i + 1;
			break;
		}
	}
	return 0;
}

void Test()
{
	SeqList seqList;
	//初始化
	SeqListInit(&seqList);
	//尾插
	SeqListPushBack(&seqList, 6);
	SeqListPushBack(&seqList, 5);
	SeqListPushBack(&seqList, 4);
	SeqListPushBack(&seqList, 3);
	SeqListPushBack(&seqList, 2);
	SeqListPushBack(&seqList, 1);

	printf("尾插\n");
	SeqListPrint(&seqList);
	//尾删
	SeqListPushPop(&seqList);
	printf("尾删\n");
	SeqListPrint(&seqList);
	//头插
	SeqListPushFront(&seqList, 666);
	printf("头插\n");
	SeqListPrint(&seqList);
	//头删
	SeqLIstPushDelete(&seqList);
	printf("头删\n");
	SeqListPrint(&seqList);
	//中间插入
	SeqListInsert(&seqList,3,66);
	printf("中间插入\n");
	SeqListPrint(&seqList);
	//删除特定位置元素
	SeqListZhongJianDelete(&seqList, 3);
	printf("删除中间元素\n");
	SeqListPrint(&seqList);

	//查找元素
	size_t num = SeqListFind(&seqList, 3);
	if (num == 0)
	{
		printf("没找到\n");
	}
	else
	{
		printf("找到了在第%d个位置\n", num);
	}
}