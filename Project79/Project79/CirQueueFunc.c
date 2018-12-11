#include"CirQueue.h"

//����ѭ������
CirQueue* CreateCirQueue(int k)
{
	CirQueue* CQPtr = (CirQueue*)malloc(sizeof(CirQueue));
	CQPtr->capcity = k;//��������
	CQPtr->size = 0;//����Ԫ�ظ���
	CQPtr->ptr = (int*)malloc(sizeof(int)*k);
	CQPtr->front = -1;//�������Ԫ���±�
	CQPtr->rear = 0;//�����β��һ��Ԫ�ص��±�
	return CQPtr;
}

//����Ԫ��
void InsertCirQueue(CirQueue* CQPtr, int data)
{
	if (CQPtr->size >= CQPtr->capcity)
	{
		printf("ѭ����������,����ʧ�ܣ�����\n");
		return;
	}
	if (CQPtr->front == -1)
	{
		CQPtr->front = 0;
	}
	CQPtr->ptr[CQPtr->rear] = data;
	CQPtr->rear = (CQPtr->rear + 1)% CQPtr->capcity;
	CQPtr->size++;
}

//ɾ��Ԫ��
void DeleteCirQueue(CirQueue* CQPtr)
{
	if (CQPtr->size == 0)
	{
		return;
	}
	CQPtr->front = ((CQPtr->front + 1)% CQPtr->capcity);
	CQPtr->size--;
}

//���ض���Ԫ��
int GetHeadCirQueue(CirQueue* CQPtr)
{
	if (CQPtr->size == 0)
	{
		return -1;
	}
	return CQPtr->ptr[CQPtr->front];
}

//���ض�βԪ��************************************
int GetWeiCirQueue(CirQueue* CQPtr)
{
	if (CQPtr->size == 0)
	{
		return -1;
	}
	return CQPtr->ptr[(CQPtr->capcity + (CQPtr->rear - 1)) % CQPtr->capcity];
}

//���ص�ǰʣ������
int GetSurplusCirQueue(CirQueue* CQPtr)
{
	return CQPtr->capcity - CQPtr->size;
}

//��ӡѭ������
void PrintCirQueue(CirQueue* CQPtr)
{
	if (CQPtr->size == 0)
	{
		printf("�ն���\n");
		return;
	}
	int fronts = CQPtr->front;
	if (fronts == CQPtr->rear)
	{
		printf("<-- %d ", CQPtr->ptr[fronts]);
		fronts = (1+fronts) % CQPtr->capcity;
	}
	while (fronts != CQPtr->rear)
	{
		printf("<-- %d ", CQPtr->ptr[fronts]);
		fronts = (1+fronts) % CQPtr->capcity;
	}
	printf("\n");
}