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
	LinkListNode* ptr = first->head;
	for (; first->head != NULL; first->head = first->head->next)
	{
		ptr = ptr->next;
		free(first->head);
		first->head = ptr;
	}
}

//4.查找链表结点（不管重复多少只返回遇到的第一个要查询的数据位置）
LinkListNode* FindLinkList(LinkList* first, DataType data)
{
	assert(first);
	LinkListNode* ptr = first->head;
	for (; ptr->next != NULL; ptr = ptr->next)
	{
		if (ptr->data == data)
		{
			return ptr;
		}
	}
	return ptr;
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
		NewNode->next = first->head;
		first->head = NewNode;
	}
	else
	{
		first->head = NewNode;
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
	LinkListNode* ptr = first->head;
	//通过循环找到最后一个结点
	for (; ptr->next != NULL; ptr = ptr->next)
	{
	}
	ptr->next = NewNode;
}

//5.3.任意pos位置插入（pos位置代表第N个结点）（从1开始）（pos是结点地址
void RenYiChaLinkList(LinkList* first, LinkListNode* pos, DataType data)
{
	assert(pos);
	LinkListNode* NewNode = CreateLinkListNode(data);
	assert(NewNode);
	NewNode->next = pos->next;
	pos->next = NewNode;
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
	LinkListNode* ptr = first->head->next;
	free(first->head);
	first->head = ptr;
}

//6.2.尾删
void WeiShanLinkList(LinkList* first)
{
	assert(first);
	if (first->head == NULL)
	{
		return;
	}
	LinkListNode* ptr = first->head;
	LinkListNode* ptr1 = NULL;
	for (; ptr->next != NULL; ptr = ptr->next)
	{
		ptr1 = ptr;
	}
	free(ptr1->next);
	ptr1->next = NULL;
}

//6.3.任意pos位置删除结点
//6.3.1.按位置删除
void RenYiWeiZhiDelLinkList(LinkList* first, LinkListNode* pos)
{
	assert(first);
	assert(pos);
	LinkListNode* ptr = first->head;
	if (ptr == NULL)
	{
		return;
	}
	if (ptr == pos)
	{
		HeadDelLinkList(first);
		return;
	}
	while (1)
	{
		if (ptr->next == pos)
		{
			LinkListNode* ptr1 = ptr->next->next;//标记要删除的结点位置
			free(ptr->next);
			ptr->next = ptr1;
			return;
		}
		else
		{
			if (ptr->next != NULL)
			{
				ptr = ptr->next;
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
	LinkListNode* ptr = first->head;
	if (first->head == NULL)
	{
		return;
	}
	if (ptr->data == data)
	{
		HeadDelLinkList(first);
		return;
	}
	while (1)
	{
		if (ptr->next == NULL)
		{
			return;
		}
		else
		{
			if (ptr->next->data == data)
			{
				LinkListNode* ptr1 = ptr->next->next;
				free(ptr->next);
				ptr->next = ptr1;
			}
			else
			{
				ptr = ptr->next;
			}
		}
	}
}

//7.修改链表结点数据
void UpdateLinkList(LinkList* first, LinkListNode* pos, DataType data)
{
	assert(pos);
	LinkListNode* ptr = first->head;
	while (1)
	{
		if (ptr != pos)
		{
			if (ptr == NULL)
			{
				return;
			}
			ptr = ptr->next;
		}
		else
		{
			ptr->data = data;
			return;
		}
	}
}

//8.打印链表
void PintLinkList(LinkList* first)
{
	assert(first);
	LinkListNode* ptr = first->head;
	if (ptr == NULL)
	{
		printf("空链表\n");
		return;
	}
	while (1)
	{
		if (ptr != NULL)
		{
			printf("%d ", ptr->data);
			ptr = ptr->next;
		}
		else
		{
			printf("\n");
			return;
		}
	}
}