#include"CirQueue.h"


int main()
{
	CirQueue* CQptr;
	CQptr = CreateCirQueue(6);

	//����Ԫ��
	InsertCirQueue(CQptr, 5);
	//PrintCirQueue(CQptr);
	InsertCirQueue(CQptr, 4);
	InsertCirQueue(CQptr, 3);
	InsertCirQueue(CQptr, 2);
	InsertCirQueue(CQptr, 1);
	PrintCirQueue(CQptr);
	InsertCirQueue(CQptr, 0);
	PrintCirQueue(CQptr);

	//ɾ������Ԫ��
	DeleteCirQueue(CQptr);
	PrintCirQueue(CQptr);
	//DeleteCirQueue(CQptr);
	//PrintCirQueue(CQptr);

	//����Ԫ��
	InsertCirQueue(CQptr, 5);
	PrintCirQueue(CQptr);

	InsertCirQueue(CQptr, 6);
	PrintCirQueue(CQptr);

	//���ض���Ԫ��
	int Head = GetHeadCirQueue(CQptr);
	printf("%d\n", Head);

	//���ض�βԪ��
	int Heads = GetWeiCirQueue(CQptr);
	printf("%d\n", Heads);

	//ʣ������
	int num = GetSurplusCirQueue(CQptr);
	printf("%d\n", num);
	system("pause");
	return 0;
}