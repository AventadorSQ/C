#define _CRT_SECURE_NO_WARNINGS
#include"LinkListInterviewQue.h"
#include<stdlib.h>

//��β��������һ������
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
	CreateLinkList(first);//����һ������

	ReversalLinkList_TouCha(first);//��ת����֮ͷ�巨
	PintLinkList(first);

	ReversalLinkList_ThreePoint(first);//��ת����֮��ָ�뷨
	PintLinkList(first);

	system("pause");
	return 0;
}