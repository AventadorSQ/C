#pragma once

//二叉树
#include<stdio.h>
#include<stdlib.h>

//定义数据类型
typedef int Datatype;

//定义二叉树类型
typedef struct BinaryTreeNode
{
	struct BinaryTreeNode* Left;//左孩子（左子树）
	struct BinaryTreeNode* Right;//右孩子（右子树）
	Datatype data;
}BinaryTreeNode;

//初始化
void InitBinaryTree(BinaryTreeNode* BinaryTree, Datatype arr[], int size);

//前/中/后序遍历
//前序遍历
void Preorder(BinaryTreeNode* BinaryTree);

//中序遍历
void Inorder(BinaryTreeNode* BinaryTree);

//后序遍历
void Postorder(BinaryTreeNode* BinaryTree);
