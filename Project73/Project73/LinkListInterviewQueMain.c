#define _CRT_SECURE_NO_WARNINGS
#include"LinkListInterviewQue.h"
#include<stdlib.h>

//��β��������һ������
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
    CreateLinkList(first);//��������
	//CreateLinkListS(Two);

	//ReversalLinkList_TouCha(first);//��ת����֮ͷ�巨
	//PintLinkList(first);

	//ReversalLinkList_ThreePoint(first);//��ת����֮��ָ�뷨
	//PintLinkList(first);

	//PintLinkList(first);//�ȴ�ӡһ��֮ǰ������������Ա�
	//PintLinkList(Two);
	//SwapLinkList(first, 10, Two, 6);//���������������������
	//PintLinkList(first);
	//PintLinkList(Two);

	//PintLinkList(Two);
	//printf("ɾ��������ͬ���ݵĽ��:\n");
	//DelRepetitionLinkList(Two);//ɾ���ظ��Ľ��
	//PintLinkList(Two);

	//MidOrdered(first, 3);//����������С data ��/�ȣ����λ�ò��䣩
	//PintLinkList(first);

	LinkListNode* ptr = FindKLinkList(first, 6);//�ҵ������е�����K�����
	if (ptr == NULL)
	{
		printf("������\n");
	}
	else
	{
		printf("%d\n", ptr->data);
	}

	system("pause");
	return 0;
}