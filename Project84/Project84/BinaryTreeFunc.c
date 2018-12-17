#include"BinaryTree.h"


//初始化
void InitBinaryTree(BinaryTreeNode* BinaryTree, Datatype arr[], int size)
{
	if (size == 0)
	{
		return;
	}
	static int i = 0;
	BinaryTree->data = arr[i];
	i++;
	arr += 1;
	size--;
	BinaryTree->Left= (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));
	InitBinaryTree(BinaryTree->Left, arr, size);
	BinaryTree->Left = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));
	InitBinaryTree(BinaryTree->Right, arr, size);
}

//前/中/后序遍历
//前序遍历
void Preorder(BinaryTreeNode* BinaryTree)
{
	if (BinaryTree == NULL)
	{
		return;
	}
	printf("%d ", BinaryTree->data);
	Preorder(BinaryTree->Left);
	Preorder(BinaryTree->Right);
}

//中序遍历
void Inorder(BinaryTreeNode* BinaryTree)
{
	if (BinaryTree == NULL)
	{
		return;
	}
	Preorder(BinaryTree->Left);
	printf("%d ", BinaryTree->data);
	Postorder(BinaryTree->Right);
}

//后序遍历
void Postorder(BinaryTreeNode* BinaryTree)
{
	if (BinaryTree == NULL)
	{
		return;
	}
	Preorder(BinaryTree->Left);
	Postorder(BinaryTree->Right);
	printf("%d ", BinaryTree->data);
}

//判断两棵树是相同的树

//求二叉树的最大深度

//判断一棵二叉树是否为二叉平衡树

//对称二叉树