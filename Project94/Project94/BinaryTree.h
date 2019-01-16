#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

//���������
typedef struct Node
{
	char data;
	struct Node* left;
	struct Node* right;
}Node;

//1.ǰ�����
void PreorderTraversal(Node* root);

//2.�������
void InorderTraversal(Node* root);

//3.�������
void PostorderTraversal(Node* root);

//4.�������Ľ����
int CountNode(Node* root);

////4.1�������Ľڵ���
//int CountNodeS(Node* root);

//5.�������ĸ߶�
int BinaryHeight(Node* root);

//6.��Ҷ�ӽ�����
int GetLeafSize(Node* root);

//7.���K��ڵ����
int LeaveK(Node* root, int k);

//8.��������data��data���ظ�
Node* FindData(Node* root, char data);

//*****************************************************
//2.1
//2.1.1�ж��������Ƿ���ͬ
bool IsSameTree(Node* p, Node* q);

//2.2.1
//�ж�һ�����Ƿ�Գ�
bool IsDuiChenTree(Node* root);

//2.2.2
//�ж��������Ƿ���Գ�
bool IsMirror(Node* p, Node* q);

//2.3
//�ж��Ƿ��Ǹ߶�ƽ������������������ĸ߶Ȳ����1,��
bool IsBalanced(Node* root);

//*********************************************************

//3.1��֪ǰ�������������������磺A B # # D E #��

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