#pragma once

#include<stdio.h>
#include<assert.h>
#include<stdbool.h>
#include<malloc.h>
#include<stdlib.h>

//定义循环队列类型
typedef struct
{
	int* ptr;
	int capcity;
	int size;
	int front;
	int rear;
}CirQueue;

//创建循环队列
CirQueue* CreateCirQueue(int k);

//插入元素
void InsertCirQueue(CirQueue* CQPtr, int data);

//删除元素
void DeleteCirQueue(CirQueue* CQPtr);

//返回队首元素
int GetHeadCirQueue(CirQueue* CQPtr);

//返回队尾元素
int GetWeiCirQueue(CirQueue* CQPtr);

//返回当前剩余容量
int GetSurplusCirQueue(CirQueue* CQPtr);

//打印循环队列
void PrintCirQueue(CirQueue* CQPtr);