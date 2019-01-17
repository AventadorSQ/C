#include"BinaryTree.h"

//1.ǰ�����
void PreorderTraversal(Node* ptr)
{
	if (ptr == NULL)
	{
		return;
	}
	printf("%c ", ptr->data);
	PreorderTraversal(ptr->Left);
	PreorderTraversal(ptr->Right);
}

//2.�������
void InorderTraversal(Node* ptr)
{
	if (ptr == NULL)
	{
		return;
	}
	InorderTraversal(ptr->Left);
	printf("%c ", ptr->data);
	InorderTraversal(ptr->Right);
}

//3.�������
void PostorderTraversal(Node* ptr)
{
	if (ptr == NULL)
	{
		return;
	}
	PostorderTraversal(ptr->Left);
	PostorderTraversal(ptr->Right);
	printf("%c ", ptr->data);
}

//ǰ��������������
//A B C # # E F # G
StructNode CreatBinaryTree(char arr[], int size)
{
	if (size == 0)
	{
		StructNode result =
		{
			.ptr = NULL,
			.count = 0
		};
		return result;
	}
	char data = arr[0];
	if (arr[0] == '#')
	{
		StructNode result =
		{
			.ptr = NULL,
			.count = 1
		};
		return result;
	}

	//���������
	Node* ptr = (Node*)malloc(sizeof(Node));
	ptr->data = data;

	//����������
	StructNode LeftNode = CreatBinaryTree(arr + 1, size-1);
	ptr->Left = LeftNode.ptr;

	//����������
	StructNode RightNode = CreatBinaryTree(arr + 1 + LeftNode.count, size - 1 - LeftNode.count);
	ptr->Right = RightNode.ptr;

	StructNode result =
	{
		.ptr = ptr,
		.count = 1 + LeftNode.count + RightNode.count
	};
	return result;
}