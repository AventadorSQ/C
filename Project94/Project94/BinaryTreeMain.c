#include"BinaryTree.h"
#include<string.h>

int main()
{
	char* ptr = "ABD##E##C#F";
	int size = strlen(ptr);
	Result result =  CreateTree(ptr, size);
    PreorderTraversal(result.root);
	printf("\n");
	InorderTraversal(result.root);
	printf("\n");
	PostorderTraversal(result.root);
	printf("\n");

	////4.1二叉树的节点数
	//int Count = CountNodeS(result.root);
	//printf("节点个数：%d\n", Count);

	//6.求叶子结点个数
	int num = GetLeafSize(result.root);
	printf("叶子节点个数：%d\n", num);

	//7.求第K层节点个数
	int num1 = LeaveK(result.root, 2);
	printf("节点个数：%d\n", num1);

	//8.在树中找data，data不重复
	Result p;
	p.root = result.root;
	Node* ptr1 = FindData(p.root, 'E');
	printf("ptr1->data = %c\n", ptr1->data);

	system("pause");
	return 0;
}