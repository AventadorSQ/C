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

//ǰ��������������
StructNode CreatBinaryTree(char arr[], int size);

//1.ǰ�����
void PreorderTraversal(Node* ptr);

//2.�������
void InorderTraversal(Node* ptr);

//3.�������
void PostorderTraversal(Node* ptr);