#pragma once//防止头文件被重复引用

typedef DataType int;

#define MAX_SIZE 100
#include<assert.h>
#include<stdio.h>

typedef struct SeqList {
	DataType array[MAX_SIZE];
	int size;      //1.保存顺序表里的有效数据个数
	               //2.当前可用下标
}SeqList;

//相应函数
//初始化/销毁
//增/删/查/改

//初始化（函数设计）
void SeqListInit(SeqList *pSeq)
{
	//1.初始化 size
	//2.可能需要把容器清空

	assert(pSeq != NULL);
	pSeq->size = 0;
	//memset(pSeq->array,' ',MAX_SIZE * sizeof(DataType));
}
//增
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
	pSeq->array[pSeq->size] = data;
	pSeq->size++;
}

//尾删
void SeqListPushPop(SeqList *pSeq)
{
	assert(pSeq);
	//特殊情况，（空了）
	if (pSeq->size <= MAX_SIZE)
	{
		printf("空了\n");
		assert(0);
		return;
	}
	pSeq->size--;
}
//头插
void SeqListPushFront(SeqList *pSeq, DataType data)
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
		pSeq->array[i] = pSeq->array[i - 1];
	}
	//将带插入函数插入顺序表
	pSeq->array[0] = data;
	pSeq->size++;
}

//使用场景
void Test()
{
	SeqList seqList;
	SeqListInit(&seqList);
}