#pragma once

#include<stdio.h>
#include<assert.h>
#include<malloc.h>

//����������
#define DataType int

typedef struct LinkListNode
{
	DataType data;
	struct LinkListNode* next;
}LinkListNode;

//����ͷָ��
typedef struct LinkList
{
	LinkListNode* head;
}LinkList;

//1.����������
LinkListNode* CreateLinkListNode(DataType data);

//2.��ʼ������
void InitLinkList(LinkList* first);

//3.��������
void DestoryLinkList(LinkList* first);

//4.����������
LinkListNode* FindLinkList(LinkList* first, DataType data);

//5.���ӽ��
//5.1.ͷ��
void HeadAddLinkList(LinkList* first, DataType data);

//5.2.β��
void WeiChaLinkList(LinkList* first, DataType data);

//5.3.����posλ�ú����
void RenYiChaLinkList(LinkList* first, LinkListNode* pos, DataType data);

//6.ɾ�����
//6.1.ͷɾ
void HeadDelLinkList(LinkList* first);

//6.2.βɾ
void WeiShanLinkList(LinkList* first);

//6.3.����posλ��ɾ�����
//6.3.1.��λ��ɾ��
void RenYiWeiZhiDelLinkList(LinkList* first,LinkListNode* pos);

//6.3.2.������ɾ��
void RenYiDataDelLinkList(LinkList* first, DataType data);

//7.�޸�����������
void UpdateLinkList(LinkList* first, LinkListNode* pos, DataType data);

//8.��ӡ����
void PintLinkList(LinkList* first);