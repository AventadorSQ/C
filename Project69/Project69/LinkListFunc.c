#include "LinkList.h"

//1.����������
LinkListNode* CreateLinkListNode(DataType data)
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

//4.���������㣨�����ظ�����ֻ���������ĵ�һ��Ҫ��ѯ������λ�ã�
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
	return first->head;
}

//5.���ӽ��
//5.1.ͷ��
void HeadAddLinkList(LinkList* first, DataType data)
{
	assert(first);
	//����һ�����
	LinkListNode* NewNode = CreateLinkListNode(data);
	assert(NewNode);
	if (first->head != NULL)
	{
		NewNode->next = first->head->next;
		first->head = NewNode;
	}
	else
	{
		first->head = NewNode;
		first->head = first->head->next;//*****************************************
	}
}

//5.2.β��
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

//5.3.����posλ�ú���루pos�����N����㣩����1��ʼ��
void RenYiChaLinkList(LinkList* first, LinkListNode* pos, DataType data)
{
	assert(pos);
	LinkListNode* NewNode = CreateLinkListNode(data);
	assert(NewNode);
	LinkListNode* ptr = FindLinkList(first, data);
	NewNode->next = ptr->next;
	ptr->next = NewNode;
}

//6.ɾ�����
//6.1.ͷɾ
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

//6.2.βɾ
void WeiShanLinkList(LinkList* first)
{
	assert(first);
	if (first->head == NULL)
	{
		return;
	}
	LinkListNode* ptr = NULL;
	for (; first->head->next != NULL; first->head = first->head->next)
	{
		ptr = first->head;
	}
	free(ptr->next);
	ptr->next = NULL;
}

//6.3.����posλ��ɾ�����
//6.3.1.��λ��ɾ��
void RenYiWeiZhiDelLinkList(LinkList* first, LinkListNode* pos)
{
	assert(first);
	assert(pos);
	LinkListNode* ptr;
	if (first->head == NULL)
	{
		return;
	}
	while (1)
	{
		if (first->head == pos)
		{
			ptr = first->head->next;
			free(first->head);
			first->head = ptr;
			return;
		}
		else
		{
			if (first->head != NULL)
			{
				first->head = first->head->next;
			}
			else
			{
				return;
			}
		}
	}
}

//6.3.2.������ɾ��
void RenYiDataDelLinkList(LinkList* first, DataType data)
{
	assert(first);
	LinkListNode* ptr;
	if (first->head == NULL)
	{
		return;
	}
	while (1)
	{
		if (first->head->data == data)
		{
			ptr = first->head->next;
			free(first->head);
			first->head = first->head->next;
		}
		if (first->head == NULL)
		{
			return;
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
			printf("%d ", first->head->data);
			first->head = first->head->next;
		}
		else
		{
			printf("\n");
			return;
		}
	}
}

////�ҵ�����k���ڵ�
//ListNode* FindKthToTail(ListNode* pListHead, unsigned int k)
//{
//	assert(pListHead);
//	ListNode* ptrk = pListHead;
//	ListNode* ptr = pListNode;
//	int n = 0;
//	while (1)
//	{
//		if ((ptrk != NULL)&&(n<k))
//		{
//			ptrk == ptrk->next; 
//		}
//		else
//		{ 
//			return NULL;
//		}
//	}
//	while (ptrk != NULL)
//	{
//		ptrk = ptrk->next;
//		ptr = ptr->next;
//	}
//	return ptr;
//}
//
////ɾ���ظ��ڵ� 
//
//
////**********************************
////*************whileѭ��************
//{
//	if (ltTail == NULL)
//	{
//		lt = ltTail = cur;
//	}
//	else
//	{
//		ltTail->next = cur;
//		ltTail = ltTail->next;
//	}
//	cur = cur->next;
//}
//
//{
//	if (eqTail == NULL)
//	{
//		eq = eqTail = cur;
//	}
//	else
//	{
//		eqTail->next = cur;
//		eqTail = eqTail->next;
//	}
//	cur = cur->next;
//}
//
//{
//	if (gtTail == NULL)
//	{
//		gt = gtTail = cur;
//	}
//	else
//	{
//		gtTail->next = cur;
//		gtTail = gtTail->next;
//	}
//	cur = cur->next;
//}
//
////*****************************************
//
//if (ltTail == NULL)
//{
//	if (eqTail == NULL)
//	{
//		if (gt == NULL)
//		{
//			return lt;
//		}
//		else
//		{
//			return lt;
//		}
//	}
//	else
//	{
//		if (gt == NULL)
//		{
//			return eq;
//		}
//		else
//		{
//			eqTail->next = gt;
//			return eq;
//		}
//	}
//}
//else
//{
//	if (eqTail == NULL)
//	{
//		if (gt == NULL)
//		{
//			return lt;
//		}
//		else
//		{
//			ltTail->next = gt;
//			return lt;
//		}
//	}
//	else
//	{
//		if (gt == NULL)
//		{
//			ltTail->next = eq;
//			return lt;
//		}
//		else
//		{
//			ltTail->next = eq;
//			eqTail->next = gt;
//			return lt;
//		}
//	}
//}