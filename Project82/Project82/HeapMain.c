#include"Heap.h"

void SeqHeapTest()
{
	Heap* heap = (Heap*)malloc(sizeof(Heap));
	int array[] = { 2,6,8,4,9,3,1,10 };
	int size = sizeof(array) / sizeof(array[0]);
	int capcaty = 10;
	//����
	HeapCreateHeap(heap, array, size , capcaty);
	PrintHeap(heap);

	//����
	AddHeapNode(heap, 5);
	PrintHeap(heap);

	//ɾ��
	DelHeapFirst(heap);
	PrintHeap(heap);

	//��ȡ�Ѷ�Ԫ��
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