#include"BothwayHeadLinkList.h"

//1.初始化
void InitBCHLinkList(BCHLinkList* BCHptr)
{
	BCHptr->data = 0;
	BCHptr->prve = BCHptr;
	BCHptr->next = BCHptr;
}

//2.创建新结点
BCHLinkList* CreateBCHLinkList(DataType data)
{
	BCHLinkList* NewNode = (BCHLinkList*)malloc(sizeof(BCHLinkList));
	NewNode->data = data;
	NewNode->prve = NULL;
	NewNode->next = NULL;
	return NewNode;
}

//3.查找data
BCHLinkList* FindBCHLinkList(BCHLinkList* BCHptr, DataType data)
{
	assert(BCHptr);
	BCHLinkList* ptr = BCHptr->next;
	while (ptr != BCHptr)
	{
		if (ptr->data == data)
		{
			return ptr;
		}
		else
		{
			ptr = ptr->next;
		}
	}
	return NULL;
}

//4.插入结点
//4.1头插
void HeadAddBCHLinkList(BCHLinkList* BCHptr, DataType data)
{
	assert(BCHptr);
	BCHLinkList* NewNode = CreateBCHLinkList(data);
	NewNode->next = BCHptr->next;
	NewNode->prve = BCHptr;
	BCHptr->next->prve = NewNode;
	BCHptr->next = NewNode;
}

//4.2尾插
void WeiAddBCHLinkList(BCHLinkList* BCHptr, DataType data)
{
	assert(BCHptr);
	BCHLinkList* NewNode = CreateBCHLinkList(data);
	NewNode->next = BCHptr;
	NewNode->prve = BCHptr->prve;
	BCHptr->prve->next = NewNode;
	BCHptr->prve = NewNode;
}

//4.3任意结点前插入数据
void RenYiAddBCHLinkList(BCHLinkList* BCHptr, BCHLinkList* pos, DataType data)
{
	assert(BCHptr);
	BCHLinkList* NewNode = CreateBCHLinkList(data);
	NewNode->next = pos;
	NewNode->prve = pos->prve;
	pos->prve->next = NewNode;
	pos->prve = NewNode;
}

//5.删除结点
//5.1头删
void HeadDelBCHLinkList(BCHLinkList* BCHptr)
{
	assert(BCHptr);
	BCHLinkList*ptr = BCHptr->next;
	BCHptr->next = ptr->next;
	ptr->next->prve = BCHptr;
	free(ptr);
	ptr = NULL;
}

//5.2尾删
void WeiDelBCHLinkList(BCHLinkList* BCHptr)
{
	assert(BCHptr);
	BCHLinkList* ptr = BCHptr->prve;
	BCHptr->prve = ptr->prve;
	ptr->prve->next = BCHptr;
	free(ptr);
	ptr = NULL;
}

//5.3任意结点删除
void RenYiDelBCHLinkList(BCHLinkList* BCHptr, DataType data)
{
	assert(BCHptr);
	BCHLinkList* ptr = FindBCHLinkList(BCHptr, data);
	ptr->prve->next = ptr->next;
	ptr->next->prve = ptr->prve;
	free(ptr);
	ptr = NULL;
}

//6.修改结点数据
//data1源数据，data要保存的数据
void RenYiXiuGaiBCHLinkList(BCHLinkList* BCHptr, DataType data1, DataType data)
{
	assert(BCHptr);
	BCHLinkList* ptr = FindBCHLinkList(BCHptr, data1);
	ptr->data = data;
}

//7.打印双向循环链表
void PrintBCHLinkList(BCHLinkList* BCHptr)
{
	assert(BCHptr);
	BCHLinkList* ptr=BCHptr->next;
	if (ptr->next == BCHptr)
	{
		printf("空链表\n");
		return;
	}
	else
	{
		while (ptr != BCHptr)
		{
			printf("-> %d <-", ptr->data);
			ptr = ptr->next;
		}
		printf("\n");
	}
}

//8.销毁链表
void DestoryBCHLinkList(BCHLinkList* BCHptr)
{
	assert(BCHptr);
	while (BCHptr->next != BCHptr)
	{
		HeadDelBCHLinkList(BCHptr);
	}
}