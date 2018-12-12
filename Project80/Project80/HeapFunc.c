#include"Heap.h"

//������
Heap* CreateHeap(int k)
{
	Heap* Hptr = (Heap*)malloc(sizeof(Heap));
	Hptr->ptr = (int*)malloc(sizeof(int)*k);
	Hptr->capcity = k;
	Hptr->size = 0;
	return Hptr;
}

//��ʼ��
void InitHeap(Heap* Hptr, DataType arr[])
{
	int num = sizeof(arr) / sizeof(arr[0]);
	for (int i = 0; i < num; i++)
	{
		Hptr->ptr[i] = arr[i];
	}
}

//��������
void InsertHeap(Heap* Hptr, DataType data)
{
	if (Hptr->size > Hptr->capcity)
	{
		printf("������!!!����ʧ��\n");
		return;
	}
	Hptr->ptr[Hptr->size - 1] = data;
	Hptr->size += 1;
}

//ɾ���Ѷ�
void DeleteHeap(Heap* Hptr)
{

}

//���ضѶ�
DataType GetTopHeap(Heap* Hptr);

//��ӡ������
void PrintHeap(Heap* Hptr);

//���ٶ�
void DestorHeap(Heap* Hptr);


void AdjustDown(int array[], int size, int root)
{
	if ( root > size - 1)
	{
		if (2 * root + 1 >= size)
		{
			return;
		}
		else
		{
			int min = 2 * root + 1;
			if (array[root] > array[2 * root + 2])
			{
				Swap(&array[root], &array[2 * root + 1]);
			}
			else
			{
				if(array[root/2 - 1])
			}
		}
	}
}




////����
//void ZhongXv(Node* root)
//{
//	if (root == NULL)
//	{
//		return;
//	}
//	Preorder(root->left);
//	printf("%d", root->val);
//	Preorder(root->right);
//}


//�ȶԵ�һ������ǰ��һ�� ���ѵڶ���ǰ�����һ�� �Ƚ�
//�ڽ�������



int maxDepth(struct TreeNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	return 1 + (MaxDepth(root->left)>MaxDepth(root->right) �� (MaxDepth(root->left) : MaxDepth(root->right)))
}


//��Ϊ����
bool isMirrorTree(struct TreeNode* p, struct TreeNode* q)
{
	if (p == NULL && q == NULL)
	{
		return true;
	}
	  
}