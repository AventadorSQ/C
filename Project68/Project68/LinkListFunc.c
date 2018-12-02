#include "LinkList.h"

//1.创建链表结点
LinkList* CreateLinkListNode(DataType data)
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

//4.增加结点
//4.1.头插
void HeadAddLinkList(LinkList* first, DataType data)
{
	assert(first);
	//创建一个结点
	LinkListNode* NewNode = CreateLinkListNode(data);
	assert(NewNode);
	NewNode->next = first->head->next;
	first->head = NewNode;
}

//4.2.尾插
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

////6.查找链表结点（不管重复多少只返回遇到的第一个要查询的数据位置）
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

//4.3.任意pos位置后插入（pos代表第N个结点）（从1开始）
void RenYiChaLinkList(LinkListNode* pos, DataType data)
{
	assert(pos);
	LinkListNode* NewNode = CreateLinkListNode(data);
	assert(NewNode);
	LinkListNode* ptr = FindLinkList(pos, data);
	NewNode->next = ptr->next;
	ptr->next = NewNode;
}

//5.删除结点
//5.1.头删
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

//5.2.尾删
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

//5.3.任意pos位置删除结点
//5.3.1.按位置删除
void RenYiWeiZhiDelLinkList(LinkList* first, LinkListNode* pos)
{
	
}

//5.3.2.按数据删除
void RenYiDataDelLinkList(LinkList* first, DataType data)
{

}

//6.查找链表结点（不管重复多少只返回遇到的第一个要查询的数据位置）
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