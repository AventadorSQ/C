#include"BinaryTree.h"

//1.前序遍历
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

//2.中序遍历
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

//3.后序遍历
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

//前序遍历构造二叉树
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

	//创建根结点
	Node* ptr = (Node*)malloc(sizeof(Node));
	ptr->data = data;

	//创建左子树
	StructNode LeftNode = CreatBinaryTree(arr + 1, size-1);
	ptr->Left = LeftNode.ptr;

	//创建右子树
	StructNode RightNode = CreatBinaryTree(arr + 1 + LeftNode.count, size - 1 - LeftNode.count);
	ptr->Right = RightNode.ptr;

	StructNode result =
	{
		.ptr = ptr,
		.count = 1 + LeftNode.count + RightNode.count
	};
	return result;
}