#pragma once

#include<stdio.h>
#include<malloc.h>
#define DataType int

//������������
typedef struct LinkNode
{
	DataType data;
	struct LinkNode* Next;
	struct LinkNode* Random;
}LinkNode;

//�����½��
LinkNode* CreateNode(DataType Data);

//���Ƹ�������
LinkNode* CopyLinkList(LinkNode* Head);
