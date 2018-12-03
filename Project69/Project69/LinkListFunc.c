#include "LinkList.h"

//1.创建链表结点
LinkListNode* CreateLinkListNode(DataType data)
{
	LinkListNode* NewNode = (LinkListNode*)malloc(sizeof(LinkListNode));
	assert(NewNode);
	NewNode->data = data;
	NewNode->next = NULL;
	return NewNode;
}

//2.初始化链表
void InitLinkList(LinkList* first)
{
	assert(first);
	first->head = NULL;
}

//3.销毁链表
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

//4.查找链表结点（不管重复多少只返回遇到的第一个要查询的数据位置）
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

//5.增加结点
//5.1.头插
void HeadAddLinkList(LinkList* first, DataType data)
{
	assert(first);
	//创建一个结点
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

//5.2.尾插
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
	//通过循环找到最后一个结点
	for (; first->head->next != NULL; first->head = first->head->next)
	{
	}
	first->head->next = NewNode;
}

//5.3.任意pos位置后插入（pos代表第N个结点）（从1开始）
void RenYiChaLinkList(LinkList* first, LinkListNode* pos, DataType data)
{
	assert(pos);
	LinkListNode* NewNode = CreateLinkListNode(data);
	assert(NewNode);
	LinkListNode* ptr = FindLinkList(first, data);
	NewNode->next = ptr->next;
	ptr->next = NewNode;
}

//6.删除结点
//6.1.头删
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

//6.2.尾删
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

//6.3.任意pos位置删除结点
//6.3.1.按位置删除
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

//6.3.2.按数据删除
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

//7.修改链表结点数据
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

//8.打印链表
void PintLinkList(LinkList* first)
{
	assert(first);
	if (first->head == NULL)
	{
		printf("空链表\n");
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

////找倒数第k个节点
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
////删除重复节点 
//
//
////**********************************
////*************while循环************
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