#pragma once

#include<stdio.h>
#include<assert.h>
#include<malloc.h>

//定义链表类
#define DataType int

typedef struct LinkListNode
{
	DataType data;
	struct LinkListNode* next;
}LinkListNode;

//定义头指针
typedef struct LinkList
{
	LinkListNode* head;
}LinkList;

//1.创建链表结点
LinkListNode* CreateLinkListNode(DataType data);

//2.初始化链表
void InitLinkList(LinkList* first);

//3.销毁链表
void DestoryLinkList(LinkList* first);

//4.查找链表结点
LinkListNode* FindLinkList(LinkList* first, DataType data);

//5.增加结点
//5.1.头插
void HeadAddLinkList(LinkList* first, DataType data);

//5.2.尾插
void WeiChaLinkList(LinkList* first, DataType data);

//5.3.任意pos位置后插入
void RenYiChaLinkList(LinkList* first, LinkListNode* pos, DataType data);

//6.删除结点
//6.1.头删
void HeadDelLinkList(LinkList* first);

//6.2.尾删
void WeiShanLinkList(LinkList* first);

//6.3.任意pos位置删除结点
//6.3.1.按位置删除
void RenYiWeiZhiDelLinkList(LinkList* first, LinkListNode* pos);

//6.3.2.按数据删除
void RenYiDataDelLinkList(LinkList* first, DataType data);

//7.修改链表结点数据
void UpdateLinkList(LinkList* first, LinkListNode* pos, DataType data);

//8.打印链表
void PintLinkList(LinkList* first);


//******************************************************************************************************

//链表面试题锦集：
//1.反转链表
//1.1引入一个头指针，进行头插的办法 *****
void ReversalLinkList_TouCha(LinkList* first);

//1.2引入三个指针，改变指向的办法
void ReversalLinkList_ThreePoint(LinkList* first);

//2.交换两个链表中的结点
//2.1引入四个指针法
void SwapLinkList(LinkList* first1, DataType data1, LinkList* first2, DataType data2);

//3.删除所有重复的结点 ****
//3.1引入三指针法
void DelRepetitionLinkList(LinkList* first);

//4.给一个数据x，将链表分成两部分，比x小的在左边，大的在右边，保持原来相对位置不变
void MidOrdered(LinkList* first, DataType data);

//5.找到链表中倒数第K个结点
LinkListNode* FindKLinkList(LinkList* first, int k);

//6.找出两个链表的公共结点 *****
LinkListNode* FindTwoComLinkList(LinkList* first1, LinkList* first2);

//7.将两个有序链表合并成一个有序链表 *****
void HeBingLinkList(LinkList* first1, LinkList* first2);

//8.删除链表中节点的数据等于给定的数据值得结点
void DelDataLinkList(LinkList* first, DataType data);

//9.判断一个链表是否是回文链表（返回bool值）
void IsHuiWenLinkList(LinkList* first);

//10.判断一个链表是否有环，若有返回入环的第一个节点，若无返回空 ****
LinkListNode* IsYouHuanLinkList(LinkList* first);

//11.返回链表中间结点若是偶数返回第二个结点
LinkListNode* ZhongJianLinkList(LinkList* first);

//12.左旋/右旋链表K个
void XuanZhuanLinklist(LinkList* first, int k);