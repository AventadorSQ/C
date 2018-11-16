#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<cassert>

typedef int DataType;

typedef struct ListNode
{
	DataType data;
	struct ListNode *next;
	//DataType *next;
}ListNode;

//初始化
void ListInit(ListNode** ppFirst)
{
	assert(ppFirst);
	*ppFirst = NULL;
}

//销毁
void ListDestory(ListNode** ppFirst)
{
	*ppFirst = NULL;
}

//创建节点
static ListNode* ListNodeCreate(DataType data)
{
	ListNode* NewNode = (ListNode*)malloc(sizeof(ListNode));
	assert(NewNode);
	NewNode->data = data;
	NewNode->next = NULL;
	return NewNode;
}
//头部增加节点
void ListToucha(ListNode** ppFirst, DataType data)
{
	ListNode* NewNode = ListNodeCreate(data);
	NewNode->next = *ppFirst;

	*ppFirst = NewNode;
}

//末尾插入数据
void ListWeicha(ListNode** ppFirst, DataType data)
{
	ListNode* NewNode = ListNodeCreate(data);
	//******************************************************************
	ListNode* DataZhi = *ppFirst;
	while (DataZhi != NULL)
	{
		DataZhi = DataZhi->next;
	}
	DataZhi = NewNode;
	////******************************************************************
	//if (*ppFirst == NULL)
	//{
	//	*ppFirst = NewNode;
	//	return;
	//}
	//ListNode* DataZhi = *ppFirst;
	//while (DataZhi->next != NULL)
	//{
	//	DataZhi = DataZhi->next;
	//}
	//DataZhi->next = NewNode;
	//*******************************************************************
}
void Test()
{
	ListNode* first;
	ListInit(&first);
	//ListToucha(&first, 5);
	//ListToucha(&first, 4);
	//ListToucha(&first, 3);
	ListWeicha(&first, 6);
}