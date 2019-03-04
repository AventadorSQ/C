#include<stdio.h>
typedef struct Node
{
	int data;
	struct Node* next;
}Node;

//      1   2   3
//  5-> 6-> 7-> 8-> 9->NULL
//N<-5<-6 <-7 
Node* Reverse(Node* head)
{
	assert(head);
	Node* ptr1;
	Node* ptr2;
	Node* ptr3;
	ptr1 = NULL;
	ptr2 = head;
	ptr3 = ptr2->next;
	while (ptr3)
	{
		ptr2->next = ptr1;
		ptr1 = ptr2;
		ptr2 = ptr3;
		ptr3 = ptr3->next;
	}
	ptr2->next = ptr1;
	return ptr2;
};

//A B D E F G C
//D B F G E A C
//D G F E B C A

typedef struct TreeNode
{
	int data;
	struct TreeNode*left;
	struct TreeNode*right;
}TreeNode;
void PreorderTraversal(TreeNode* root)
{
	if (root == NULL)
	{
		return;
	}
	printf("%d ", root->data);
	PreorderTraversal( root->left);
	PreorderTraversal(root->right);
}

int GetHeight(TreeNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	return (1 + GetHeight(root->left)) > (1 + GetHeight(root->right)) ? (1 + GetHeight(root->left)) : (1 + GetHeight(root->right));
}

TreeNode* FindData(TreeNode* root, int value)
{
	if (root == NULL)
	{
		return NULL;
	}
	if (root->data == value)
	{
		return root;
	}
	TreeNode* ptr = FindData(root->left, value);
	if (ptr != NULL)
	{
		return ptr;
	}
	ptr = FindData(root->right, value);
	if (ptr != NULL)
	{
		return ptr;
	}
	else 
	{
		return NULL;
	}
}

bool IsCompleteBinaryTree(TreeNode* root)
{
	if (root == NULL)
	{
		return true;
	}
	std::queue<TreeNode *> q;
	q.push(root);

	while (1)
	{
		TreeNode* front = q.front();
		q.pop
	}
}

//前中序遍历
//1.从前序找根
//2.从中序找到根下标 并且

void ADjustDown(int array[], int size, int root)
{
	int left = root * 2 + 1;
	int right = root * 2 + 2;
	int Max = root;
	if (left<size && array[left]>array[Max])
	{
		Max = left;
	}
	if (right<size && array[right]>array[Max])
	{
		Max = right;
	}
	if (Max != root)
	{
		Swap(array[Max], array[root]);
		ADjustDown(array, size, Max);
	}
}