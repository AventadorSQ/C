#define _CRT_SECURE_NO_WARNINGS
#include"LinkListInterviewQue.h"
#include<stdlib.h>

//用尾插来创建一个链表
void CreateLinkList(LinkList* first)
{
	WeiChaLinkList(first, 10);
	WeiChaLinkList(first, 5);
	WeiChaLinkList(first, 2);
	WeiChaLinkList(first, 3);
	WeiChaLinkList(first, 4);
	WeiChaLinkList(first, 1);
	PintLinkList(first);
}

void CreateLinkListS(LinkList* Two)
{
	HeadAddLinkList(Two, 10);
	HeadAddLinkList(Two, 9);
	HeadAddLinkList(Two, 9);
	HeadAddLinkList(Two, 9);
	HeadAddLinkList(Two, 8);
}
int main()
{
	LinkList* first = (LinkList*)malloc(sizeof(LinkList));
	LinkList* Two = (LinkList*)malloc(sizeof(LinkList));
	InitLinkList(first);
	InitLinkList(Two);
    CreateLinkList(first);//创建链表
	//CreateLinkListS(Two);

	//ReversalLinkList_TouCha(first);//反转链表之头插法
	//PintLinkList(first);

	//ReversalLinkList_ThreePoint(first);//反转链表之三指针法
	//PintLinkList(first);

	//PintLinkList(first);//先打印一下之前两个链表，方便对比
	//PintLinkList(Two);
	//SwapLinkList(first, 10, Two, 6);//交换链表中任意两个结点
	//PintLinkList(first);
	//PintLinkList(Two);

	//PintLinkList(Two);
	//printf("删除连续相同数据的结点:\n");
	//DelRepetitionLinkList(Two);//删除重复的结点
	//PintLinkList(Two);

	//MidOrdered(first, 3);//不完整排序：小 data 大/等（相对位置不变）
	//PintLinkList(first);

	LinkListNode* ptr = FindKLinkList(first, 6);//找到链表中倒数第K个结点
	if (ptr == NULL)
	{
		printf("不存在\n");
	}
	else
	{
		printf("%d\n", ptr->data);
	}

	system("pause");
	return 0;
}