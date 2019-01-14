#include"BinaryTree.h"

//1.ǰ�����
void PreorderTraversal(Node* root)
{
	if (root == NULL)
	{
		return;
	}
	printf("%d ", root->data);
	PreorderTraversal(root->left);
	PreorderTraversal(root->right);
}

//2.�������
void InorderTraversal(Node* root)
{
	if (root == NULL)
	{
		return;
	}
	InorderTraversal(root->left);
	printf("%d ", root->data);
	InorderTraversal(root->right);
}

//3.�������
void PostorderTraversal(Node* root)
{
	if (root == NULL)
	{
		return;
	}
	InorderTraversal(root->left);
	InorderTraversal(root->right);
	printf("%d ", root->data);
}

//4.�������Ľ����
int CountNode(Node* root)
{
	if (root == NULL)
	{
		return 0;
	}
	return CountNode(root->left) + CountNode(root->right) + 1;
}

//5.�������ĸ߶�
int BinaryHeight(Node* root)
{
	if (root == NULL)
	{
		return 0;
	}

	int leftNode = BinaryHeight(root->left);
	int rightNode = BinaryHeight(root->right);
	return (leftNode >rightNode ? leftNode : rightNode)+1; 
} 


//2.1
//2.1.1�ж��������Ƿ���ͬ
bool IsSameTree(Node* p, struct Node* q)
{
	if (p == NULL && q == NULL)
	{
		return true;
	}
	if (p == NULL || q == NULL)
	{
		return false;
	}

	return (p->data == q->data) && IsSameTree(p->left, q->left) && IsSameTree(p->right, q->right);
}

//2.2.1
//�ж�һ�����Ƿ�Գ�
bool IsDuiChenTree(Node* root)
{
	if (root == NULL) 
	{
		return true;
	}
	return IsMirror(root->left, root->right);
}

//2.2.2
//�ж��������Ƿ���Գ�
bool IsMirror(Node* p, Node* q)
{
	if (p == NULL && q == NULL)
	{
		return true;
	}
	if (p == NULL || q == NULL)
	{
		return false;
	}

	return p->data = q->data && IsMirror(p->left, q->left) && IsMirror(p->right, q->left);
}

//2.3
//�ж��Ƿ��Ǹ߶�ƽ���������ÿ�����������ĸ߶Ȳ����1,��
bool IsBalanced(Node* root)
{
	if (root == NULL)
	{
		return true;
	}
	int left_BinaryHeight = BinaryHeight(root->left);
	int right_BinaryHeight = BinaryHeight(root->right);
	int num = left_BinaryHeight - right_BinaryHeight;
	if (num > 1 || num < -1)
	{
		return false;
	}
	return IsBalanced(root->left) && IsBalanced(root->right);
}

//3.1��֪ǰ�������������������磺A B # # D E #��

typedef struct
{
	Node* root;
	int UseCount;
}Result;

Result CreateTree(char preorder[], int size)
{
	if (size == 0)
	{
		Result result = {
			.root = NULL,
			.UseCount = 0
		};
		return result;
	}
	char rootdata = preorder[0];
	if (rootdata == '#')
	{
		Result result = {
			.root = NULL,
			.UseCount = 1
		};
		return result;
	}

	//�������ڵ�
	Node* root = (Node*)malloc(sizeof(Node));
	root->data = rootdata;

	//����������
	Result left_result = CreateTree(preorder + 1, size - 1);
	//left_result.root;        �����õ��������ĸ��ڵ�
	//left_result.UseCount;    �����������������õ���data�ĸ���

	//����������
	Result right_result = CreateTree(preorder + 1 + left_result.UseCount, size - 1 -  left_result.UseCount);
	root->left = left_result.root;
	root->right = right_result.root;

	Result result = { 
		.root = root,
		.UseCount = 1 + left_result.UseCount + right_result.UseCount
	};
	return result;
}