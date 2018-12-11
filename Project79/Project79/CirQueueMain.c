#include"CirQueue.h"


int main()
{
	CirQueue* CQptr;
	CQptr = CreateCirQueue(6);

	//插入元素
	InsertCirQueue(CQptr, 5);
	//PrintCirQueue(CQptr);
	InsertCirQueue(CQptr, 4);
	InsertCirQueue(CQptr, 3);
	InsertCirQueue(CQptr, 2);
	InsertCirQueue(CQptr, 1);
	PrintCirQueue(CQptr);
	InsertCirQueue(CQptr, 0);
	PrintCirQueue(CQptr);

	//删除队首元素
	DeleteCirQueue(CQptr);
	PrintCirQueue(CQptr);
	//DeleteCirQueue(CQptr);
	//PrintCirQueue(CQptr);

	//插入元素
	InsertCirQueue(CQptr, 5);
	PrintCirQueue(CQptr);

	InsertCirQueue(CQptr, 6);
	PrintCirQueue(CQptr);

	//返回队首元素
	int Head = GetHeadCirQueue(CQptr);
	printf("%d\n", Head);

	//返回队尾元素
	int Heads = GetWeiCirQueue(CQptr);
	printf("%d\n", Heads);

	//剩余容量
	int num = GetSurplusCirQueue(CQptr);
	printf("%d\n", num);
	system("pause");
	return 0;
}