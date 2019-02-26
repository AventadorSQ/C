#include"LinkList.h"

LinkNode* CreateNode(DataType Data)
{
	LinkNode* NewNode = (LinkNode*)malloc(sizeof(LinkNode));
	NewNode->data = Data;
	NewNode->Next = NULL;
	NewNode->Random = NULL;

	return NewNode;
}

void CopyNewNode(LinkNode* Head)
{
	LinkNode* ptr = Head;
	while (ptr != NULL)
	{
		LinkNode* New = CreateNode(ptr->data);
		New->data = ptr->data;
		New->Next = ptr->Next;
		ptr->Next = New;

		ptr = New->Next;
	}

}

void CopyRandom(LinkNode* Head)
{
	LinkNode* Ptr = Head;
	while (Ptr != NULL)
	{
		LinkNode* newNode = Ptr->Next;

		if (Ptr->Random != NULL)
		{
			newNode->Random = Ptr->Random->Next;
		}

		Ptr = Ptr->Next->Next;
	}
}

LinkNode* SpLit(LinkNode* Head)
{
	LinkNode* NewHead = Head->Next;
	LinkNode* PtrHead = Head;
	LinkNode* PtrNew = NewHead;
	while (1)
	{
		if (PtrNew != NULL)
		{
			PtrHead->Next = PtrNew->Next;
			PtrHead = PtrHead->Next;
		}

		if (PtrHead != NULL)
		{
			PtrNew->Next = PtrHead->Next;
			PtrNew = PtrNew->Next;
		}
		else
		{
			break;
		}
	}
	return NewHead;
}

//复杂链表的复制
LinkNode* CopyLinkList(LinkNode* Head)
{
	if (Head == NULL)
	{
		return NULL;
	}

	//第一步先复制链表并跟在源链表结点后面
	CopyNewNode(Head);

	//第二布复制源链表的Random
	CopyRandom(Head);

	//第三步拆分源新链表
	LinkNode* NewLinkList = SpLit(Head);

	return NewLinkList;
}

