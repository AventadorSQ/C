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

	////4.1�������Ľڵ���
	//int Count = CountNodeS(result.root);
	//printf("�ڵ������%d\n", Count);

	//6.��Ҷ�ӽ�����
	int num = GetLeafSize(result.root);
	printf("Ҷ�ӽڵ������%d\n", num);

	//7.���K��ڵ����
	int num1 = LeaveK(result.root, 2);
	printf("�ڵ������%d\n", num1);

	//8.��������data��data���ظ�
	Result p;
	p.root = result.root;
	Node* ptr1 = FindData(p.root, 'E');
	printf("ptr1->data = %c\n", ptr1->data);

	system("pause");
	return 0;
}