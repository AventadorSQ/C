#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

//�����ַ���
void ZiFuChuan();

#define DataType int
//�����е�ÿһ���ڵ�
typedef struct LinkListNode
{
	DataType data;
	LinkListNode* next;
}LinkListNode;

//����һ��ͷָ��
typedef struct LinkList
{
	LinkListNode* first;
}LinkList;

//����һ���ڵ�

//�����ʼ��


//����

//ͷ��

//ͷɾ

//β��

//βɾ
void WeiShanLinkList(LinkList* ptr)
{
	assert(ptr);
	assert(ptr->first);
	//1��
	if (ptr->first->next == NULL)
	{
		//ͷɾ
	}
	LinkListNode* ptr1;
	for (ptr1 = ptr; ptr1->next->next != NULL; ptr1->next)
	{
	}
	free(ptr1->next);
	ptr1->next = NULL;
}

//���ң�����һ����ַ��

//����posλ�ò���һ�����

//ɾ��posλ��Ľ��
void ShanChuList(LinkListNode* pos)
{
	assert(pos);
	//���ҵ�pos
	LinkListNode* pos1 = pos->next;
	pos->next = pos->next->next;
	free(pos1);
}

//ͨ��dataɾ��
LinkListNode* LinkListRemove(LinkListNode* head, DataType data)
{
	assert(head);
	LinkListNode* ptr = head;
	for (; (ptr->next != NULL); ptr = ptr->next)
	{
		if (ptr->next->data == data)
		{
			 
			ptr->next = ptr->next->next;
		}
	}
}

//��ת����
//1.����������ͷͷ��
//2.ѭ��
//3.����ָ��
LinkListNode* FanZhuanList(LinkListNode* head)
{

}

//    1  2  3  4  5  6
//
//p0 p1 p2 