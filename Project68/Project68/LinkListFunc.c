#include "LinkList.h"

//1.����������
LinkList* CreateLinkListNode(DataType data)
{
	LinkListNode* NewNode = (LinkListNode*)malloc(sizeof(LinkListNode));
	assert(NewNode);
	NewNode->data = data;
	NewNode->next = NULL;
	return NewNode;
}

//2.��ʼ������
void InitLinkList(LinkList* first)
{
	assert(first);
	first->head = NULL;
}

//3.��������
void DestoryLinkList(LinkList* first)
{
	assert(first);
	LinkListNode* ptr;
	for (; first->head != NULL; first->head = first->head->next)
	{
		ptr = first->head->next;
		free(first->head);
		first->head = ptr;
	}
}

//4.���ӽ��
//4.1.ͷ��
void HeadAddLinkList(LinkList* first, DataType data)
{
	assert(first);
	//����һ�����
	LinkListNode* NewNode = CreateLinkListNode(data);
	assert(NewNode);
	NewNode->next = first->head->next;
	first->head = NewNode;
}

//4.2.β��
void WeiChaLinkList(LinkList* first, DataType data)
{
	assert(first);
	if (first->head == NULL)
	{
		HeadAddLinkList(first, data);
		return;
	}
	LinkListNode* NewNode = CreateLinkListNode(data);
	assert(NewNode);
	//ͨ��ѭ���ҵ����һ�����
	for (; first->head->next != NULL; first->head = first->head->next)
	{
	}
	first->head->next = NewNode;
}

////6.���������㣨�����ظ�����ֻ���������ĵ�һ��Ҫ��ѯ������λ�ã�
//LinkListNode* FindLinkList(LinkList* first, DataType data)
//{
//	assert(first);
//	for (; first->head != NULL; first->head = first->head->next)
//	{
//		if (first->head->data == data)
//		{
//			return first->head;
//		}
//	}
//}

//4.3.����posλ�ú���루pos�����N����㣩����1��ʼ��
void RenYiChaLinkList(LinkListNode* pos, DataType data)
{
	assert(pos);
	LinkListNode* NewNode = CreateLinkListNode(data);
	assert(NewNode);
	LinkListNode* ptr = FindLinkList(pos, data);
	NewNode->next = ptr->next;
	ptr->next = NewNode;
}

//5.ɾ�����
//5.1.ͷɾ
void HeadDelLinkList(LinkList* first)
{
	assert(first);
	if (first->head == NULL)
	{
		return;
	}
	LinkList* ptr = first;
	free(first->head);
	first->head = ptr->head->next;
}

//5.2.βɾ
void WeiShanLinkList(LinkList* first) 
{
	assert(first);
	if (first->head == NULL)
	{
		return;
	}
	LinkListNode* ptr;
	for (; first->head->next != NULL; first->head = first->head->next)
	{
	    ptr = first->head;
	}
	free(ptr->next);
	ptr->next = NULL;
}

//5.3.����posλ��ɾ�����
//5.3.1.��λ��ɾ��
void RenYiWeiZhiDelLinkList(LinkList* first, LinkListNode* pos)
{
	
}

//5.3.2.������ɾ��
void RenYiDataDelLinkList(LinkList* first, DataType data)
{

}

//6.���������㣨�����ظ�����ֻ���������ĵ�һ��Ҫ��ѯ������λ�ã�
LinkListNode* FindLinkList(LinkList* first, DataType data)
{
	assert(first);
	for (; first->head != NULL; first->head = first->head->next)
	{
		if (first->head->data == data)
		{
			return first->head;
		}
	}
}

//7.�޸�����������
void UpdateLinkList(LinkList* first, LinkListNode* pos, DataType data)
{
	assert(pos);
	while (1)
	{
		if (first->head != pos)
		{
			if (first->head == NULL)
			{
				return;
			}
			first->head = first->head->next;
		}
		else
		{
			first->head->data = data;
			return;
		}
	}
}

//8.��ӡ����
void PintLinkList(LinkList* first)
{
	assert(first);
	if (first->head == NULL)
	{
		printf("������\n");
		return;
	}
	while (1)
	{
		if (first->head != NULL)
		{
			printf("%d ", first->head);
			first->head = first->head->next;
		}
		else
		{
			printf("\n");
			return;
		}
	}
}