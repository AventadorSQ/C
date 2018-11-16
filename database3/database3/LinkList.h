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

//��ʼ��
void ListInit(ListNode** ppFirst)
{
	assert(ppFirst);
	*ppFirst = NULL;
}

//����
void ListDestory(ListNode** ppFirst)
{
	*ppFirst = NULL;
}

//�����ڵ�
static ListNode* ListNodeCreate(DataType data)
{
	ListNode* NewNode = (ListNode*)malloc(sizeof(ListNode));
	assert(NewNode);
	NewNode->data = data;
	NewNode->next = NULL;
	return NewNode;
}
//ͷ�����ӽڵ�
void ListToucha(ListNode** ppFirst, DataType data)
{
	ListNode* NewNode = ListNodeCreate(data);
	NewNode->next = *ppFirst;

	*ppFirst = NewNode;
}

//ĩβ��������
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