#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

//定义二叉树
typedef struct Node
{
	char data;
	struct Node* left;
	struct Node* right;
}Node;

//1.前序遍历
void PreorderTraversal(Node* root);

//2.中序遍历
void InorderTraversal(Node* root);

//3.后序遍历
void PostorderTraversal(Node* root);

//4.二叉树的结点数
int CountNode(Node* root);

////4.1二叉树的节点数
//int CountNodeS(Node* root);

//5.二叉树的高度
int BinaryHeight(Node* root);

//6.求叶子结点个数
int GetLeafSize(Node* root);

//7.求第K层节点个数
int LeaveK(Node* root, int k);

//8.在树中找data，data不重复
Node* FindData(Node* root, char data);

//*****************************************************
//2.1
//2.1.1判断两棵树是否相同
bool IsSameTree(Node* p, Node* q);

//2.2.1
//判断一棵树是否对称
bool IsDuiChenTree(Node* root);

//2.2.2
//判断两棵树是否镜像对称
bool IsMirror(Node* p, Node* q);

//2.3
//判断是否是高度平衡二叉树（左右子树的高度差不超过1,）
bool IsBalanced(Node* root);

//*********************************************************

//3.1已知前序遍历构造二叉树（例如：A B # # D E #）

typedef struct
{
	Node* root;
	int UseCount;
}Result;

Result CreateTree(char preorder[], int size);

//Node* Find(Node* root, int val)
//{
//	if (root == NULL)
//	{
//		return NULL;
//	}
//
//	if (root->data == val)
//	{
//		return root;
//	}
//
//	Node* Left = Find(root->left, val);
//	if (Left != NULL)
//	{
//		return Left;
//	}
//
//	Node* Right = Find(root->right, val);
//	if (Right != NULL)
//	{
//		return Right;
//	}
//	return NULL;
//}