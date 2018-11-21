#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<cassert>

#define DataType int 

typedef struct LinkList
{
	DataType data;
	struct LinkList* next;
}LinkList;

//初始化
void ListInit(LinkList** ppFirst)
{
	assert(ppFirst);
	*ppFirst = NULL;
}

//创建节点
static LinkList* ListNodeCreate(DataType data)
{
	LinkList* NewNode = (LinkList*)malloc(sizeof(LinkList));
	assert(NewNode);
	NewNode->data = data;
	NewNode->next = NULL;
	return NewNode;
}

//首插
void ListFirstAdd(LinkList** ppFirst, DataType data)
{
	LinkList* NewNode = ListNodeCreate(data);
	NewNode->next = *ppFirst;

	*ppFirst = NewNode;
}

//查找
LinkList* ListFind(LinkList* pFirst, DataType data)
{
	for (LinkList* ptr = pFirst; ptr != NULL; ptr = ptr->next)
	{
		if (data == ptr->data)
		{
			return ptr;
		}
	}
	return 0;
}

//打印查找结果
void IsPrintFind(LinkList* ptr)
{
	LinkList* result = ptr;
	if (result != 0)
	{
		printf("找到了\n");
	}
	else
	{
		printf("没找到\n");
	}
}

//在结点前做插入
void ListInsert(LinkList** ppFirst, LinkList* pos, DataType data)
{
	if (*ppFirst == pos)
	{
		ListFirstAdd(ppFirst, data);
	}
	else
	{
		LinkList* ptr = *ppFirst;
		while (ptr->next != pos)
		{
			ptr = ptr->next;
		}
		LinkList* NewNode = ListNodeCreate(data);
		NewNode->next = ptr->next;
		ptr->next = NewNode;
	}
}

//删除结点
void ListNodeDeleteS(LinkList** ppFirst, DataType data)
{
	LinkList* ptr = *ppFirst;
	while (1)
	{
		if (ptr->data == data)
		{
			*ppFirst = ptr->next;
			return;
		}
		else
		{
			while (ptr->next->data != data)
			{
				ptr = ptr->next;
			}
			LinkList* ptr1 = ptr->next->next;//0123
			free(ptr->next);
			ptr->next = ptr1;
			return;
		}
	}
}

//删除节点
void ListNodeDelete(LinkList** ppFirst, LinkList* pos)
{
	//头删
	if (*ppFirst == pos)
	{
		*ppFirst = pos->next;
		free(pos);
		return;
	}

	LinkList* ptr = *ppFirst;
	while (ptr->next != pos)
	{
		ptr = ptr->next;
	}
	ptr->next = pos->next;
	free(pos);
}
//打印
void PrintList(LinkList* ppFirst)
{
	LinkList* ptr = ppFirst;
	if (ptr == NULL)
	{
		printf("无数据\n");
	}
	else
	{
		while (1)
		{
			if (ptr != NULL)
			{
				printf("%d ", ptr->data);
				ptr = ptr->next;
			}
			else
			{
				printf("\n");
				break;
			}
		}
	}
}
void Test()
{
	LinkList* first;
	ListInit(&first);
	ListFirstAdd(&first, 3);//头插
	ListFirstAdd(&first, 2);
	ListFirstAdd(&first, 1);
	PrintList(first);//打印
	LinkList* ptr = ListFind(first, 1);//查找
	IsPrintFind(ptr);//打印查找结果
	ListInsert(&first, ptr, 0);
	PrintList(first);

	//ListNodeDelete(&first, ptr);
	//PrintList(first);
	//0123
	ListNodeDeleteS(&first, 3);
	PrintList(first);
}