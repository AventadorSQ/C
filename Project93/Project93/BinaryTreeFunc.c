#include"BinaryTree.h"

//1.前序遍历
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

//2.中序遍历
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

//3.后序遍历
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

//4.二叉树的结点数
int CountNode(Node* root)
{
	if (root == NULL)
	{
		return 0;
	}
	return CountNode(root->left) + CountNode(root->right) + 1;
}

//5.二叉树的高度
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
//2.1.1判断两棵树是否相同
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
//判断一棵树是否对称
bool IsDuiChenTree(Node* root)
{
	if (root == NULL) 
	{
		return true;
	}
	return IsMirror(root->left, root->right);
}

//2.2.2
//判断两棵树是否镜像对称
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
//判断是否是高度平衡二叉树（每个左右子树的高度差不超过1,）
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

//3.1已知前序遍历构造二叉树（例如：A B # # D E #）

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

	//创建根节点
	Node* root = (Node*)malloc(sizeof(Node));
	root->data = rootdata;

	//创建左子树
	Result left_result = CreateTree(preorder + 1, size - 1);
	//left_result.root;        创建好的左子树的根节点
	//left_result.UseCount;    创建左子树过程中用掉的data的个数

	//创建右子树
	Result right_result = CreateTree(preorder + 1 + left_result.UseCount, size - 1 -  left_result.UseCount);
	root->left = left_result.root;
	root->right = right_result.root;

	Result result = { 
		.root = root,
		.UseCount = 1 + left_result.UseCount + right_result.UseCount
	};
	return result;
}