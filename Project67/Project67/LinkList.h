#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

//测试字符串
void ZiFuChuan();

#define DataType int
//链表中的每一个节点
typedef struct LinkListNode
{
	DataType data;
	LinkListNode* next;
}LinkListNode;

//定义一个头指针
typedef struct LinkList
{
	LinkListNode* first;
}LinkList;

//创建一个节点

//链表初始化


//销毁

//头插

//头删

//尾插

//尾删
void WeiShanLinkList(LinkList* ptr)
{
	assert(ptr);
	assert(ptr->first);
	//1个
	if (ptr->first->next == NULL)
	{
		//头删
	}
	LinkListNode* ptr1;
	for (ptr1 = ptr; ptr1->next->next != NULL; ptr1->next)
	{
	}
	free(ptr1->next);
	ptr1->next = NULL;
}

//查找（返回一个地址）

//任意pos位置插入一个结点

//删除pos位后的结点
void ShanChuList(LinkListNode* pos)
{
	assert(pos);
	//查找到pos
	LinkListNode* pos1 = pos->next;
	pos->next = pos->next->next;
	free(pos1);
}

//通过data删除
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

//反转链表
//1.建立新链表头头插
//2.循环
//3.三个指针
LinkListNode* FanZhuanList(LinkListNode* head)
{

}

//    1  2  3  4  5  6
//
//p0 p1 p2 