#include"BinaryTree.h"

void BinaryTreeTest()
{
	BinaryTreeNode* Tree  = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));
	int arr[] = { 1,2,3,4,5,6,7,8,9,0 };
	int size = sizeof(arr) / sizeof(arr[0]);
	InitBinaryTree(Tree, arr, size);
	Preorder(Tree);
	printf("\n");
	Inorder(Tree);
	printf("\n");
	Postorder(Tree);
}

int main()
{
	BinaryTreeTest();
	system("pause");
	return 0;
}