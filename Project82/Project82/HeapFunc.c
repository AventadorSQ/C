//#include"Heap.h"
//
////��С��
//void CreateHeap(int array[], int size)
//{
//	int FNLNode = (size - 2) / 2;
//	for (; FNLNode >= 0; FNLNode--)
//	{
//		ADjustDown(array, size, FNLNode);
//	}
//}
//
////�����
//
////�����С��(���µ���) С����
//void ADjustDown(int array[], int size, int root)
//{
//	int left = 2 * root + 1;
//	int right = 2 * root + 2;
//	int num;
//	if (left >= size)
//	{
//		return;
//	}
//
//	if (right < size && array[right] < array[left])
//	{
//		num = right;
//	}
//	else
//	{
//		num = left;
//	}
//
//	if (array[root] <= array[num])
//	{
//		return;
//	}
//
//	int temp = array[root];
//	array[root] = array[num];
//	array[num] = temp;
//
//	ADjustDown(array, size, num);
//}
//
////С��
////���ϵ���
//void ADjustUp(int array[], int size, int root)
//{
//	while (root != 0)
//	{
//		if (array[(root - 1) / 2] <= 0)
//		{
//			return;
//		}
//		if (array[(root - 1) / 2] < array[root])
//		{
//			return;
//		}
//		int temp = array[(root - 1) / 2];
//		array[(root - 1) / 2] = array[root];
//		array[root] = temp;
//		root = (root - 1) / 2;
//	}
//	//ADjustUp(array, size, root);
//}

//***********************************************************

#include"Heap.h"

//��С��
void CreateHeap(int array[], int size)
{
	int FNLNode = (size - 2) / 2;
	for (; FNLNode >= 0; FNLNode--)
	{
		ADjustDown(array, size, FNLNode);
	}
}


//�����С��(���µ���) С����
void ADjustDown(int array[], int size, int root)
{
	int left = 2 * root + 1;
	int right = 2 * root + 2;
	int num;
	if (left >= size)
	{
		return;
	}
	if (right < size && array[right] < array[left])
	{
		num = right;
	}
	else
	{
		num = left;
	}

	if (array[root] <= array[num])
	{
		return;
	}

	int temp = array[root];
	array[root] = array[num];
	array[num] = temp;

	ADjustDown(array, size, num);
}

//С��
//���ϵ���
void ADjustUp(int array[], int size, int root)
{
	while (root != 0)
	{
		if (array[(root - 1) / 2] <= 0)
		{
			return;
		}
		if (array[(root - 1) / 2] < array[root])
		{
			return;
		}
		int temp = array[(root - 1) / 2];
		array[(root - 1) / 2] = array[root];
		array[root] = temp;
		root = (root - 1) / 2;
	}
	//ADjustUp(array, size, root);
}

//����
void HeapCreateHeap(Heap* heap, int array[], int size , int capacity)
{
	heap->capacity = capacity;
	heap->size = size;
	heap->arr = (int*)malloc(sizeof(int)*heap->capacity);
	for (int i = 0; i < size; i++)
	{
		heap->arr[i] = array[i];
	}

	CreateHeap(heap->arr, heap->size);
}

//����
void AddHeapNode(Heap* heap, int data)
{
	if (heap->size == heap->capacity)
	{
		return;
	}
	heap->arr[heap->size] = data;
	heap->size++;
	ADjustUp(heap->arr, heap->size, heap->size - 1);
}

//ɾ��
void DelHeapFirst(Heap* heap)//O(logn)
{
	assert(heap->size > 0);
	heap->arr[0] = heap->arr[heap->size - 1];
	heap->size--;
	ADjustDown(heap->arr, heap->size, 0);
}

//���ضѶ�Ԫ��
HPDataType GetHeapFirst(Heap* heap)
{
	assert(heap->size > 0);
	return heap->arr[0];
}

//��ӡ��
void PrintHeap(Heap* heap)
{
	assert(heap->size > 0);
	for (int i = 0; i < heap->size; i++)
	{
		printf("%d ", heap->arr[i]);
	}
	printf("\n");
}