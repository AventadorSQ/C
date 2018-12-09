#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>


//双向循环带头结点链表

//定义链表数据类型
#define DataType int

//定义链表结点
typedef struct BCHLinkList
{
	DataType data;
	struct BCHLinkList* prve;
	struct BCHLinkList* next;
}BCHLinkList;

//1.初始化
void InitBCHLinkList(BCHLinkList* BCHptr);

//2.创建新结点
BCHLinkList* CreateBCHLinkList(DataType data);

//3.查找data
BCHLinkList* FindBCHLinkList(BCHLinkList* BCHptr, DataType data);

//4.插入结点
//4.1头插
void HeadAddBCHLinkList(BCHLinkList* BCHptr, DataType data);

//4.2尾插
void WeiAddBCHLinkList(BCHLinkList* BCHptr, DataType data);

//4.3任意结点后插入数据
void RenYiAddBCHLinkList(BCHLinkList* BCHptr, BCHLinkList* pos, DataType data);

//5.删除结点
//5.1头删
void HeadDelBCHLinkList(BCHLinkList* BCHptr);

//5.2尾删
void WeiDelBCHLinkList(BCHLinkList* BCHptr);

//5.3任意结点删除
void RenYiDelBCHLinkList(BCHLinkList* BCHptr, DataType data);

//6.修改结点数据
void RenYiXiuGaiBCHLinkList(BCHLinkList* BCHptr, DataType data1, DataType data);

//7.打印双向循环链表
void PrintBCHLinkList(BCHLinkList* BCHptr);

//8.销毁链表
void DestoryBCHLinkList(BCHLinkList* BCHptr);