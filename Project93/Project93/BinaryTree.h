#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

//定义二叉树
typedef struct Node
{
	int data;
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

//5.二叉树的高度
int BinaryHeight(Node* root);

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