#pragma once

#include<stdio.h>
#include<assert.h>


//定义链表类
#define DataType int

typedef struct LinkListNode
{
	DataType data;
	LinkListNode* next;
}LinkListNode;

//定义头指针
typedef struct LinkList
{
	LinkListNode* head;
}LinkList;

//1.创建链表结点
LinkList* CreateLinkListNode( DataType data);

//2.初始化链表
void InitLinkList(LinkList* first);

//3.销毁链表
void DestoryLinkList(LinkList* first);

//4.增加结点
//4.1.头插
void HeadAddLinkList(LinkList* first, DataType data);

//4.2.尾插
void WeiChaLinkList(LinkList* first, DataType data);

//4.3.任意pos位置后插入
void RenYiChaLinkList(LinkListNode* pos, DataType data);

//5.删除结点
//5.1.头删
void HeadDelLinkList(LinkList* first);

//5.2.尾删
void WeiShanLinkList(LinkList* first);

//5.3.任意pos位置删除结点
//5.3.1.按位置删除
void RenYiWeiZhiDelLinkList(LinkListNode* pos);

//5.3.2.按数据删除
void RenYiDataDelLinkList(LinkList* first, DataType data);

//6.查找链表结点
void FindLinkList(LinkList* first, DataType data);

//7.修改链表结点数据
void UpdateLinkList(LinkListNode* pos, DataType data);

//8.打印链表
void PintLinkList(LinkList* first);