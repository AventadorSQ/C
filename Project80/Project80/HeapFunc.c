#include"Heap.h"

//创建堆
Heap* CreateHeap(int k)
{
	Heap* Hptr = (Heap*)malloc(sizeof(Heap));
	Hptr->ptr = (int*)malloc(sizeof(int)*k);
	Hptr->capcity = k;
	Hptr->size = 0;
	return Hptr;
}

//初始化
void InitHeap(Heap* Hptr, DataType arr[])
{
	int num = sizeof(arr) / sizeof(arr[0]);
	for (int i = 0; i < num; i++)
	{
		Hptr->ptr[i] = arr[i];
	}
}

//插入数据
void InsertHeap(Heap* Hptr, DataType data)
{
	if (Hptr->size > Hptr->capcity)
	{
		printf("堆已满!!!插入失败\n");
		return;
	}
	Hptr->ptr[Hptr->size - 1] = data;
	Hptr->size += 1;
}

//删除堆顶
void DeleteHeap(Heap* Hptr)
{

}

//返回堆顶
DataType GetTopHeap(Heap* Hptr);

//打印堆数据
void PrintHeap(Heap* Hptr);

//销毁堆
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




////中序
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


//先对第一个进行前序一次 并把第二个前序遍历一次 比较
//在进行中序



int maxDepth(struct TreeNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	return 1 + (MaxDepth(root->left)>MaxDepth(root->right) ？ (MaxDepth(root->left) : MaxDepth(root->right)))
}


//互为镜像
bool isMirrorTree(struct TreeNode* p, struct TreeNode* q)
{
	if (p == NULL && q == NULL)
	{
		return true;
	}
	  
}