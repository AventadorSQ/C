#pragma once

#include<assert.h>

#define DataType int
typedef struct SeqList
{
	DataType* data;
	int capcity;
	int size;
}SeqList;

//创建节点
char* CreateSeqListNode(SeqList* ptr);
//顺序表初始化
void InitSeqList(SeqList* ptr);
//顺序表增加数据
//头插
void TouZengSeqList(SeqList* ptr,int data);
//尾插
void WeiZengSeqList(SeqList* ptr, int data);
//任意位置插入
void RenYiZengSeqList(SeqList* ptr, int pos, int data);
//顺序表删除数据

//查找

//冒泡
void SeqListBubbleSort(SeqList* ptr);

//二分查找
int SeqListBinarySearch(SeqList* ptr, DataType data);