
#define _CRT_SECURE_NO_WARNINGS
#include "LinkList.h"
#include<stdlib.h>

void LinkListTest()
{
	LinkList* first = (LinkList*)malloc(sizeof(LinkList));
	InitLinkList(first);
	//头插
	HeadAddLinkList(first, 5);
	HeadAddLinkList(first, 4);
	HeadAddLinkList(first, 3);
	HeadAddLinkList(first, 2);
	HeadAddLinkList(first, 1);
	PintLinkList(first);
	
	//尾插
	WeiChaLinkList(first, 6);
	WeiChaLinkList(first, 7);
	WeiChaLinkList(first, 8);
	WeiChaLinkList(first, 9);
	WeiChaLinkList(first, 10);
	PintLinkList(first);
	
	//任意数据位置后插入
	LinkListNode* ptr = FindLinkList(first, 10);
	RenYiChaLinkList(first, ptr, 12);
	PintLinkList(first);

	//头删
	HeadDelLinkList(first);
	PintLinkList(first);

	//头插
	HeadAddLinkList(first, 1);
	PintLinkList(first);
	//尾删
	WeiShanLinkList(first);
	PintLinkList(first);

	//任意结点位置删除
	LinkListNode* ptr1 = FindLinkList(first, 1);
	RenYiWeiZhiDelLinkList(first, ptr1);
	PintLinkList(first);

	//任意数据删除
	RenYiDataDelLinkList(first, 10);
	PintLinkList(first);

	//修改链表中结点数据
	LinkListNode* ptr2 = FindLinkList(first, 2);
	UpdateLinkList(first, ptr2, 1);
	PintLinkList(first);
}

int main()
{
	LinkListTest();
	system("pause");
	return 0;
}