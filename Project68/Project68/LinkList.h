#pragma once

#include<stdio.h>
#include<assert.h>


//����������
#define DataType int

typedef struct LinkListNode
{
	DataType data;
	LinkListNode* next;
}LinkListNode;

//����ͷָ��
typedef struct LinkList
{
	LinkListNode* head;
}LinkList;

//1.����������
LinkList* CreateLinkListNode( DataType data);

//2.��ʼ������
void InitLinkList(LinkList* first);

//3.��������
void DestoryLinkList(LinkList* first);

//4.���ӽ��
//4.1.ͷ��
void HeadAddLinkList(LinkList* first, DataType data);

//4.2.β��
void WeiChaLinkList(LinkList* first, DataType data);

//4.3.����posλ�ú����
void RenYiChaLinkList(LinkListNode* pos, DataType data);

//5.ɾ�����
//5.1.ͷɾ
void HeadDelLinkList(LinkList* first);

//5.2.βɾ
void WeiShanLinkList(LinkList* first);

//5.3.����posλ��ɾ�����
//5.3.1.��λ��ɾ��
void RenYiWeiZhiDelLinkList(LinkListNode* pos);

//5.3.2.������ɾ��
void RenYiDataDelLinkList(LinkList* first, DataType data);

//6.����������
void FindLinkList(LinkList* first, DataType data);

//7.�޸�����������
void UpdateLinkList(LinkListNode* pos, DataType data);

//8.��ӡ����
void PintLinkList(LinkList* first);