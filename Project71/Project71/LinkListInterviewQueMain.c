#define _CRT_SECURE_NO_WARNINGS
#include"LinkListInterviewQue.h"
#include<stdlib.h>

//用尾插来创建一个链表
void CreateLinkList(LinkList* first)
{
	WeiChaLinkList(first, 6);
	WeiChaLinkList(first, 5);
	WeiChaLinkList(first, 4);
	WeiChaLinkList(first, 3);
	WeiChaLinkList(first, 2);
	WeiChaLinkList(first, 1);
	PintLinkList(first);
}

int main()
{
	LinkList* first = (LinkList*)malloc(sizeof(LinkList));
	InitLinkList(first);
	CreateLinkList(first);//创建一条链表

	ReversalLinkList_TouCha(first);//反转链表之头插法
	PintLinkList(first);

	ReversalLinkList_ThreePoint(first);//反转链表之三指针法
	PintLinkList(first);

	system("pause");
	return 0;
}