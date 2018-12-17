#pragma once

//������
#include<stdio.h>
#include<stdlib.h>

//������������
typedef int Datatype;

//�������������
typedef struct BinaryTreeNode
{
	struct BinaryTreeNode* Left;//���ӣ���������
	struct BinaryTreeNode* Right;//�Һ��ӣ���������
	Datatype data;
}BinaryTreeNode;

//��ʼ��
void InitBinaryTree(BinaryTreeNode* BinaryTree, Datatype arr[], int size);

//ǰ/��/�������
//ǰ�����
void Preorder(BinaryTreeNode* BinaryTree);

//�������
void Inorder(BinaryTreeNode* BinaryTree);

//�������
void Postorder(BinaryTreeNode* BinaryTree);
