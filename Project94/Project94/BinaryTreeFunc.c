#include"BinaryTree.h"

//1.前序遍历
void PreorderTraversal(Node* root)
{
	if (root == NULL)
	{
		return;
	}
	printf("%c ", root->data);
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
	printf("%c ", root->data);
	InorderTraversal(root->right);
}

//3.后序遍历
void PostorderTraversal(Node* root)
{
	if (root == NULL)
	{
		return;
	}
	PostorderTraversal(root->left);
	PostorderTraversal(root->right);
	printf("%c ", root->data);
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

////4.1二叉树的节点数
//int CountNodeS(Node* root)
//{
//	if (root == NULL)
//	{
//		return 0;
//	}
//	CountS1++;
//	CountNodeS(root->left);
//	CountNode(root->right);
//	return CountS1;
//}

//5.二叉树的高度
int BinaryHeight(Node* root)
{
	if (root == NULL)
	{
		return 0;
	}

	int leftNode = BinaryHeight(root->left);
	int rightNode = BinaryHeight(root->right);
	return (leftNode >rightNode ? leftNode : rightNode) + 1;
}

//6.求叶子结点个数
int GetLeafSize(Node* root)
{
	if (root == NULL)
	{
		return 0;
	}
	if (root->left == NULL && root->right == NULL)
	{
		return 1;
	}
	return GetLeafSize(root->left) + GetLeafSize(root->right);
}

//7.求第K层节点个数
int LeaveK(Node* root, int k)
{
	if (root == NULL)
	{
		return 0;
	}
	if (k == 1)
	{
		return 1;
	}
	return LeaveK(root->left, k - 1) + LeaveK(root->right, k - 1);
}

//8.在树中找data，data不重复
Node* FindData(Node* root, char data)
{
	if (root == NULL)
	{
		return NULL;
	}
	if (root->data == data)
	{
		return root;
	}
	Node* r = FindData(root->left, data);
	if (r != NULL)
	{
		return r;
	}
    r = FindData(root->right, data);
	if (r != NULL)
	{
		return r;
	}
	return NULL;
}

////9.判断一棵树是另一棵树的子树
//bool IsSameChlidTree(Node* s, Node* t)
//{
//	return preorder(s, t);
//}

//10.前序遍历判断树是否相同
bool preorder(Node* r, Node* t)
{
	if (r == NULL)
	{
		return false;
	}

	//判断S中每一个结点为根的的这棵子树是否和t相等
	if (IsSameTree(r, t))
	{
		return true;
	}

	//r的左子树是否有和t相同的子树
	if (preorder(r->left, t) == true)
	{
		return true;
	}
	if (preorder(r->right, t) == true)
	{
		return true;
	}
	return false;
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
	Result right_result = CreateTree(preorder + 1 + left_result.UseCount, size - 1 - left_result.UseCount);
	root->left = left_result.root;
	root->right = right_result.root;

	Result result = {
		.root = root,
		.UseCount = 1 + left_result.UseCount + right_result.UseCount
	};
	return result;
}

//层序遍历
void CengXv(Node* root)
{
	Node* ptrs = root;

	if (root == NULL)
	{
		return;
	}

	printf("%c ", root->data);
	
}

////判断完全二叉树（层序遍历）
//
//
////非递归前序遍历
//void PreorderTree(Node* root)
//{
//	Node* cur = root;
//	Node* top = NULL;
//
//	while (root != NULL || 栈不为空)
//	{
//		printf("%c ", cur->data);
//		//当前压栈
//		//指向根左孩子
//	}
//
//	//top指向栈顶元素，弹出
//
//	
//}