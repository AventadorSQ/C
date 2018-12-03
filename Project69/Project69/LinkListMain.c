
#define _CRT_SECURE_NO_WARNINGS
#include "LinkList.h"
#include<stdlib.h>

void LinkListTest()
{	
	LinkList* first = (LinkList*)malloc(sizeof(LinkList));
	InitLinkList(first);
	HeadAddLinkList(first, 5);
	HeadAddLinkList(first, 4);
	HeadAddLinkList(first, 3);
	HeadAddLinkList(first, 2);
	HeadAddLinkList(first, 1);
	PintLinkList(first);
}

int main()
{
	LinkListTest();
	system("pause");
	return 0;
}