#include"BinaryTree.h"

int main()
{
	char* p = "ABD##E##C#F";
	int size = strlen(p);
	StructNode result = CreatBinaryTree(p, size);

	//前序遍历：
	printf("前序遍历：");
	PreorderTraversal(result.ptr);
	printf("\n");

	//中序遍历：
	printf("中序遍历：");
	InorderTraversal(result.ptr);
	printf("\n");

	//前序遍历：
	printf("前序遍历：");
	PostorderTraversal(result.ptr);
	printf("\n");

	system("pause");
	return 0;
}