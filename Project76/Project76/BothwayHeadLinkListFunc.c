#include"BothwayHeadLinkList.h"

//1.��ʼ��
void InitBCHLinkList(BCHLinkList* BCHptr)
{
	BCHptr->data = 0;
	BCHptr->prve = BCHptr;
	BCHptr->next = BCHptr;
}

//2.�����½��
BCHLinkList* CreateBCHLinkList(DataType data)
{
	BCHLinkList* NewNode = (BCHLinkList*)malloc(sizeof(BCHLinkList));
	NewNode->data = data;
	NewNode->prve = NULL;
	NewNode->next = NULL;
	return NewNode;
}

//3.����data
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

//4.������
//4.1ͷ��
void HeadAddBCHLinkList(BCHLinkList* BCHptr, DataType data)
{
	assert(BCHptr);
	BCHLinkList* NewNode = CreateBCHLinkList(data);
	NewNode->next = BCHptr->next;
	NewNode->prve = BCHptr;
	BCHptr->next->prve = NewNode;
	BCHptr->next = NewNode;
}

//4.2β��
void WeiAddBCHLinkList(BCHLinkList* BCHptr, DataType data)
{
	assert(BCHptr);
	BCHLinkList* NewNode = CreateBCHLinkList(data);
	NewNode->next = BCHptr;
	NewNode->prve = BCHptr->prve;
	BCHptr->prve->next = NewNode;
	BCHptr->prve = NewNode;
}

//4.3������ǰ��������
void RenYiAddBCHLinkList(BCHLinkList* BCHptr, BCHLinkList* pos, DataType data)
{
	assert(BCHptr);
	BCHLinkList* NewNode = CreateBCHLinkList(data);
	NewNode->next = pos;
	NewNode->prve = pos->prve;
	pos->prve->next = NewNode;
	pos->prve = NewNode;
}

//5.ɾ�����
//5.1ͷɾ
void HeadDelBCHLinkList(BCHLinkList* BCHptr)
{
	assert(BCHptr);
	BCHLinkList*ptr = BCHptr->next;
	BCHptr->next = ptr->next;
	ptr->next->prve = BCHptr;
	free(ptr);
	ptr = NULL;
}

//5.2βɾ
void WeiDelBCHLinkList(BCHLinkList* BCHptr)
{
	assert(BCHptr);
	BCHLinkList* ptr = BCHptr->prve;
	BCHptr->prve = ptr->prve;
	ptr->prve->next = BCHptr;
	free(ptr);
	ptr = NULL;
}

//5.3������ɾ��
void RenYiDelBCHLinkList(BCHLinkList* BCHptr, DataType data)
{
	assert(BCHptr);
	BCHLinkList* ptr = FindBCHLinkList(BCHptr, data);
	ptr->prve->next = ptr->next;
	ptr->next->prve = ptr->prve;
	free(ptr);
	ptr = NULL;
}

//6.�޸Ľ������
//data1Դ���ݣ�dataҪ���������
void RenYiXiuGaiBCHLinkList(BCHLinkList* BCHptr, DataType data1, DataType data)
{
	assert(BCHptr);
	BCHLinkList* ptr = FindBCHLinkList(BCHptr, data1);
	ptr->data = data;
}

//7.��ӡ˫��ѭ������
void PrintBCHLinkList(BCHLinkList* BCHptr)
{
	assert(BCHptr);
	BCHLinkList* ptr=BCHptr->next;
	if (ptr->next == BCHptr)
	{
		printf("������\n");
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

//8.��������
void DestoryBCHLinkList(BCHLinkList* BCHptr)
{
	assert(BCHptr);
	while (BCHptr->next != BCHptr)
	{
		HeadDelBCHLinkList(BCHptr);
	}
}