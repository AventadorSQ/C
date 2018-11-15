#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#define MAX_SIZE 1024

typedef int DataType;

typedef struct SeqList
{
	DataType arr[MAX_SIZE];
	int size;//1.˳����д洢�����ݸ���
	         //2.��¼��ǰ���Դ洢���±�

}SeqList;


//˳����ʼ��
void SeqListInit(SeqList *pSeq)
{
	//1.��ʼ�� size
	//2.������Ҫ���������
	assert(pSeq != NULL);
	pSeq->size = 0;
	//memset(pSeq->arr,' ',MAX_SIZE * sizeof(DataType));
}
//***********************************************************************************
//����ɾ
//***********************************************************************************

//β��
void SeqListPushBack(SeqList *pSeq, DataType data)
{
	assert(pSeq);
	//��������������ˣ�
	if (pSeq->size >= MAX_SIZE)
	{
		printf("����\n");
		assert(0);
		return;
	}
	//��ͨ���
	pSeq->arr[pSeq->size] = data;
	pSeq->size++;
}
//βɾ
void SeqListPushPop(SeqList *pSeq)
{
	assert(pSeq);
	//��������������ˣ�
	if (pSeq->size <= 0)
	{
		printf("����\n");
		assert(0);
		return;
	}
	pSeq->size--;
}

//ͷ��
void SeqListPushFront(SeqList* pSeq, DataType data)
{
	assert(pSeq);
	//��������������ˣ�
	if (pSeq->size >= MAX_SIZE)
	{
		printf("����\n");
		assert(0);
		return;
	}
	//i��ʾλ��
	for (int i = pSeq->size; i > 0; i--)
	{
		pSeq->arr[i] = pSeq->arr[i - 1];
	}
	//�������뺯������˳���
	pSeq->arr[0] = data;
	pSeq->size++;
}

//ͷɾ
void SeqLIstPushDelete(SeqList* pSeq)
{
	assert(pSeq);

	//�ƶ�ÿ��Ԫ��
	for (int i = 1; i < pSeq->size; i++)
	{
		pSeq->arr[i-1] = pSeq->arr[i];
	}
	pSeq->size--;
}

//�м����
void SeqListInsert(SeqList *pSeq, int pos, DataType data)
{
	assert(pSeq);
	assert(pos >= 0 && pos <= pSeq->size);

	if (pSeq->size >= MAX_SIZE)
	{
		printf("˳���������\n");
		assert(0);
		return;
	}

	//����Ҫ�����λ���Լ�����Ԫ�������ƶ�
	for (int i = pSeq->size - 1; i >= pos - 1; i--)
	{
		pSeq->arr[i + 1] = pSeq->arr[i];
	}
	//����Ҫ�����Ԫ��
	pSeq->arr[pos - 1] = data;
	pSeq->size++;
}
//�м�ɾ���ض�λ�õ�Ԫ��
void SeqListZhongJianDelete(SeqList* pSeq,int pos)
{
	assert(pSeq);

	//�п�
	if (pSeq->size <= 0)
	{
		printf("˳����ѿ�\n");
		assert(0);
		return;
	}
	for (int i = pos - 1; i < pSeq->size - 1; i++)
	{
		pSeq->arr[i] = pSeq->arr[i + 1];
	}
	pSeq->size--;
}

//��ӡ˳���
void SeqListPrint(const SeqList* pSeq)
{
	assert(pSeq != NULL);

	for (int i = 0; i < pSeq->size; i++)
	{
		printf("%d ", pSeq->arr[i]);
	}
	printf("\n");
}

//****************************************************************************
//ɾ��������
//****************************************************************************
//ɾ����һ��������Ԫ��
void SeqListDeleteOne(SeqList* pSeq,DataType data)
{
	int num = SeqListFind(pSeq, data);
	if (num == 0)
	{
		return;
	}
	else
	{
		SeqListZhongJianDelete(pSeq, num - 1);
	}
}
//ɾ�����и�Ԫ��
void SeqListDeleteAll(SeqList* pSeq, DataType data)
{
	//3.0*********************************************   1 2 2 3 4 5 6 7 8 9?????????
	//int temp = 0;
	//for (int i = 0; i < pSeq->size; i++)
	//{
	//	if (temp == 0)
	//	{
	//		if (data == pSeq->arr[i])
	//		{
	//			//pSeq->arr[i] = pSeq->arr[i + 1];
	//			//i++;
	//			temp++;
	//		}
	//	}
	//	else
	//	{

	//	}

	//}
	//2.0*********************************************
	//�����¶�̬����
	//DataType* NewArr = (DataType*)malloc(sizeof(DataType)*pSeq->size);
	//int i, j;
	////������Ԫ�ش洢����������
	//for (i = 0, j = 0; i < pSeq->size; i++)
	//{
	//	if (data != pSeq->arr[i])
	//	{
	//		NewArr[j] = pSeq->arr[i];
	//		j++;
	//	}
	//}

	////�ڽ�Ԫ�����´洢��ԭ˳�����
	//for (i = 0; i < j; i++)
	//{
	//	pSeq->arr[i] = NewArr[i];
	//}
	//pSeq->size = j;

	////�ͷ��ڴ�
	//free(NewArr);
	//1.0********************************************
	//int num = 0;
	//while (num = SeqListFind(pSeq, data))
	//{
	//	SeqListZhongJianDelete(pSeq, num - 1);
	//}

}
//****************************************************************************
//����
//****************************************************************************

size_t SeqListFind(SeqList* pSeq, DataType data)
{
	for (int i = 0; i < pSeq->size; i++)
	{
		if (pSeq->arr[i] == data)
		{
			//printf("�ҵ���,�������ڵ�%d��λ�á�\n",i);
			return i + 1;
			break;
		}
	}
	return 0;
}

void Test()
{
	SeqList seqList;
	//��ʼ��
	SeqListInit(&seqList);
	//β��
	SeqListPushBack(&seqList, 6);
	SeqListPushBack(&seqList, 5);
	SeqListPushBack(&seqList, 4);
	SeqListPushBack(&seqList, 3);
	SeqListPushBack(&seqList, 2);
	SeqListPushBack(&seqList, 1);

	printf("β��\n");
	SeqListPrint(&seqList);
	//βɾ
	SeqListPushPop(&seqList);
	printf("βɾ\n");
	SeqListPrint(&seqList);
	//ͷ��
	SeqListPushFront(&seqList, 666);
	printf("ͷ��\n");
	SeqListPrint(&seqList);
	//ͷɾ
	SeqLIstPushDelete(&seqList);
	printf("ͷɾ\n");
	SeqListPrint(&seqList);
	//�м����
	SeqListInsert(&seqList,3,66);
	printf("�м����\n");
	SeqListPrint(&seqList);
	//ɾ���ض�λ��Ԫ��
	SeqListZhongJianDelete(&seqList, 3);
	printf("ɾ���м�Ԫ��\n");
	SeqListPrint(&seqList);

	//����Ԫ��
	size_t num = SeqListFind(&seqList, 3);
	if (num == 0)
	{
		printf("û�ҵ�\n");
	}
	else
	{
		printf("�ҵ����ڵ�%d��λ��\n", num);
	}
}