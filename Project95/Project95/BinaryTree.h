#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>

typedef struct Node
{
	char data;
	struct Node* Left;
	struct Node* Right;
}Node;

typedef struct StuctNode
{
	Node* ptr;
	int count;
}StructNode;

//前序遍历构造二叉树
StructNode CreatBinaryTree(char arr[], int size);

//1.前序遍历
void PreorderTraversal(Node* ptr);

//2.中序遍历
void InorderTraversal(Node* ptr);

//3.后序遍历
void PostorderTraversal(Node* ptr);