#include"Heap.h"

void SeqHeapTest()
{
	Heap* heap = (Heap*)malloc(sizeof(Heap));
	int array[] = { 2,6,8,4,9,3,1,10 };
	int size = sizeof(array) / sizeof(array[0]);
	int capcaty = 10;
	//建堆
	HeapCreateHeap(heap, array, size , capcaty);
	PrintHeap(heap);

	//插入
	AddHeapNode(heap, 5);
	PrintHeap(heap);

	//删除
	DelHeapFirst(heap);
	PrintHeap(heap);

	//获取堆顶元素
	int num = GetHeapFirst(heap);
	printf("%d\n", num);
}
int main()
{
	//Test();
	SeqHeapTest();
	system("pause");
	return 0;
}