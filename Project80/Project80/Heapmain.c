#include"Heap.h"

#define MAX_SIZE (7)

int main()
{

	Heap* Hptr = CreateHeap(MAX_SIZE);
	DataType arr[MAX_SIZE] = { 9,6,8,7,5,4,3 };
	InitHeap(Hptr,arr);
	system("pause");
	return 0;
}