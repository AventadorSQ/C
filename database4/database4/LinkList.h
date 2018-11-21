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

//��ʼ��
void ListInit(LinkList** ppFirst)
{
	assert(ppFirst);
	*ppFirst = NULL;
}

//�����ڵ�
static LinkList* ListNodeCreate(DataType data)
{
	LinkList* NewNode = (LinkList*)malloc(sizeof(LinkList));
	assert(NewNode);
	NewNode->data = data;
	NewNode->next = NULL;
	return NewNode;
}

//�ײ�
void ListFirstAdd(LinkList** ppFirst, DataType data)
{
	LinkList* NewNode = ListNodeCreate(data);
	NewNode->next = *ppFirst;

	*ppFirst = NewNode;
}

//����
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

//��ӡ���ҽ��
void IsPrintFind(LinkList* ptr)
{
	LinkList* result = ptr;
	if (result != 0)
	{
		printf("�ҵ���\n");
	}
	else
	{
		printf("û�ҵ�\n");
	}
}

//�ڽ��ǰ������
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

//ɾ�����
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

//ɾ���ڵ�
void ListNodeDelete(LinkList** ppFirst, LinkList* pos)
{
	//ͷɾ
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
//��ӡ
void PrintList(LinkList* ppFirst)
{
	LinkList* ptr = ppFirst;
	if (ptr == NULL)
	{
		printf("������\n");
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
	ListFirstAdd(&first, 3);//ͷ��
	ListFirstAdd(&first, 2);
	ListFirstAdd(&first, 1);
	PrintList(first);//��ӡ
	LinkList* ptr = ListFind(first, 1);//����
	IsPrintFind(ptr);//��ӡ���ҽ��
	ListInsert(&first, ptr, 0);
	PrintList(first);

	//ListNodeDelete(&first, ptr);
	//PrintList(first);
	//0123
	ListNodeDeleteS(&first, 3);
	PrintList(first);
}