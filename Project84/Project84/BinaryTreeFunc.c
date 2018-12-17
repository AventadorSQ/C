#include"BinaryTree.h"


//��ʼ��
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

//ǰ/��/�������
//ǰ�����
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

//�������
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

//�������
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

//�ж�����������ͬ����

//���������������

//�ж�һ�ö������Ƿ�Ϊ����ƽ����

//�Գƶ�����