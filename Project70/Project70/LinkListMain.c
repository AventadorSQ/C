
#define _CRT_SECURE_NO_WARNINGS
#include "LinkList.h"
#include<stdlib.h>

void LinkListTest()
{
	LinkList* first = (LinkList*)malloc(sizeof(LinkList));
	InitLinkList(first);
	//ͷ��
	HeadAddLinkList(first, 5);
	HeadAddLinkList(first, 4);
	HeadAddLinkList(first, 3);
	HeadAddLinkList(first, 2);
	HeadAddLinkList(first, 1);
	PintLinkList(first);
	
	//β��
	WeiChaLinkList(first, 6);
	WeiChaLinkList(first, 7);
	WeiChaLinkList(first, 8);
	WeiChaLinkList(first, 9);
	WeiChaLinkList(first, 10);
	PintLinkList(first);
	
	//��������λ�ú����
	LinkListNode* ptr = FindLinkList(first, 10);
	RenYiChaLinkList(first, ptr, 12);
	PintLinkList(first);

	//ͷɾ
	HeadDelLinkList(first);
	PintLinkList(first);

	//ͷ��
	HeadAddLinkList(first, 1);
	PintLinkList(first);
	//βɾ
	WeiShanLinkList(first);
	PintLinkList(first);

	//������λ��ɾ��
	LinkListNode* ptr1 = FindLinkList(first, 1);
	RenYiWeiZhiDelLinkList(first, ptr1);
	PintLinkList(first);

	//��������ɾ��
	RenYiDataDelLinkList(first, 10);
	PintLinkList(first);

	//�޸������н������
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