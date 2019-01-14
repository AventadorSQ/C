#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

//���������
typedef struct Node
{
	int data;
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

//5.�������ĸ߶�
int BinaryHeight(Node* root);

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