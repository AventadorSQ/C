#include"LinkList.h"
#include<stdlib.h>

int main()
{
	LinkNode* Node1 = CreateNode(1);
	LinkNode* Node2 = CreateNode(2);
	LinkNode* Node3 = CreateNode(3);
	LinkNode* Node4 = CreateNode(4);
	LinkNode* Node5 = CreateNode(5);

	//1 2 3 4 5
	Node1->Next = Node2;
	Node2->Next = Node3;
	Node3->Next = Node4;
	Node4->Next = Node5;

	//5 1 NULL 4 2
	Node1->Random = Node5;
	Node2->Random = Node1;
	Node3->Random = NULL;
	Node4->Random = Node4;
	Node5->Random = Node2;

	LinkNode* ptr = CopyLinkList(Node1);
	LinkNode* NewList = ptr;
	while (NewList != NULL)
	{
		printf(" %d ->", NewList->data);
		NewList = NewList->Next;
	}
	printf("\n");
	NewList = ptr;
	while (NewList != NULL)
	{
		if (NewList->Random != NULL)
		{
			printf("(%d)->", NewList->Random->data);
		}
		else
		{
			printf("NULL-> ");
		}
		NewList = NewList->Next;
	}
	printf("\n");
	system("pause");
	return 0;
}