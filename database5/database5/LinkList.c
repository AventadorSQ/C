#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

#define DataType int

typedef struct LinkList
{
	DataType data;
	struct LinkList* Next;
}LinkList;

//�����ʼ��
void ListInit(LinkList** ppFirst)
{
	*ppFirst = NULL;
}

//�����ڵ�
static LinkList* CreateListNode(DataType data)
{
	LinkList* ptr = (LinkList*)malloc(sizeof(LinkList));
	assert(ptr);
	ptr->data = data;
	ptr->Next = NULL;
	return ptr;
}
//ͷ��
void LinkListTouCha(LinkList** First, DataType data)
{
	LinkList* ptrs = CreateListNode(data);
	ptrs->Next = *First;
	*First = ptrs;
}
//�����ӡ����
void PrintReverse(LinkList* First)
{
	LinkList* ptr = NULL;
	if (First == NULL)
	{
		printf("������Ϊ��\n");
		return;
	}
	while (ptr != First)
	{
		LinkList* ptr1 = First;
		while (ptr1->Next != ptr)
		{
			ptr1 = ptr1->Next;
		}
		printf("%d ", ptr1->data);
		ptr = ptr1;
	}
}

//�ݹ�
void DiGuiPrintReverse(LinkList* First)
{
	LinkList* ptr = First;
	if (ptr->Next == NULL)
	{
		printf("%d ", ptr->data);
	}
	else
	{
		DiGuiPrintReverse(ptr->Next);
		printf("%d ", ptr->data);
	}
}

//��ӡ
void PrintList(LinkList* ppFirst)
{
	LinkList* ptr = ppFirst;
	if (ptr == NULL)
	{
		printf("������\n");
	}
	else
	{
		while (1)
		{
			if (ptr != NULL)
			{
				printf("%d ", ptr->data);
				ptr = ptr->Next;
			}
			else
			{
				printf("\n");
				break;
			}
		}
	}
}

int main()
{
	LinkList* ptr;
	ListInit(&ptr);
	LinkListTouCha(&ptr, 5);
	LinkListTouCha(&ptr, 4);
	LinkListTouCha(&ptr, 3);
	LinkListTouCha(&ptr, 2);
	LinkListTouCha(&ptr, 1);
	LinkListTouCha(&ptr, 0);
	PrintList(ptr);
	PrintReverse(ptr);
	printf("\n");
	DiGuiPrintReverse(ptr);
	printf("\n");
	PrintList(ptr);
	system("pause");
	return 0;
}