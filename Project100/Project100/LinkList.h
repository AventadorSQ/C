#pragma once

#include<stdio.h>
#include<malloc.h>
#define DataType int

//定义链表类型
typedef struct LinkNode
{
	DataType data;
	struct LinkNode* Next;
	struct LinkNode* Random;
}LinkNode;

//创建新结点
LinkNode* CreateNode(DataType Data);

//复制复杂链表
LinkNode* CopyLinkList(LinkNode* Head);
