#include"BinaryTree.h"

int main()
{
	char* p = "ABD##E##C#F";
	int size = strlen(p);
	StructNode result = CreatBinaryTree(p, size);

	//ǰ�������
	printf("ǰ�������");
	PreorderTraversal(result.ptr);
	printf("\n");

	//���������
	printf("���������");
	InorderTraversal(result.ptr);
	printf("\n");

	//ǰ�������
	printf("ǰ�������");
	PostorderTraversal(result.ptr);
	printf("\n");

	system("pause");
	return 0;
}