#pragma once

#include<stdio.h>
#include<malloc.h>
#define DataType int

typedef struct LinkNode
{
	DataType data;
	struct LinkNode* Next;
	struct LinkNode* Random;
}LinkNode;

LinkNode* CreateNode(DataType Data);

LinkNode* CopyLinkList(LinkNode* Head);
