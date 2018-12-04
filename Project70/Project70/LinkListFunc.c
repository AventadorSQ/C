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
	LinkListNode* ptr = first->head;
	for (; first->head != NULL; first->head = first->head->next)
	{
		ptr = ptr->next;
		free(first->head);
		first->head = ptr;
	}
}

//4.���������㣨�����ظ�����ֻ���������ĵ�һ��Ҫ��ѯ������λ�ã�
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
		NewNode->next = first->head;
		first->head = NewNode;
	}
	else
	{
		first->head = NewNode;
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
	LinkListNode* ptr = first->head;
	//ͨ��ѭ���ҵ����һ�����
	for (; ptr->next != NULL; ptr = ptr->next)
	{
	}
	ptr->next = NewNode;
}

//5.3.����posλ�ò��루posλ�ô����N����㣩����1��ʼ����pos�ǽ���ַ
void RenYiChaLinkList(LinkList* first, LinkListNode* pos, DataType data)
{
	assert(pos);
	LinkListNode* NewNode = CreateLinkListNode(data);
	assert(NewNode);
	NewNode->next = pos->next;
	pos->next = NewNode;
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
	LinkListNode* ptr = first->head->next;
	free(first->head);
	first->head = ptr;
}

//6.2.βɾ
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

//6.3.����posλ��ɾ�����
//6.3.1.��λ��ɾ��
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
			LinkListNode* ptr1 = ptr->next->next;//���Ҫɾ���Ľ��λ��
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

//6.3.2.������ɾ��
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

//7.�޸�����������
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

//8.��ӡ����
void PintLinkList(LinkList* first)
{
	assert(first);
	LinkListNode* ptr = first->head;
	if (ptr == NULL)
	{
		printf("������\n");
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