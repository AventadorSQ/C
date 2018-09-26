#pragma once//��ֹͷ�ļ����ظ�����

typedef DataType int;

#define MAX_SIZE 100
#include<assert.h>
#include<stdio.h>

typedef struct SeqList {
	DataType array[MAX_SIZE];
	int size;      //1.����˳��������Ч���ݸ���
	               //2.��ǰ�����±�
}SeqList;

//��Ӧ����
//��ʼ��/����
//��/ɾ/��/��

//��ʼ����������ƣ�
void SeqListInit(SeqList *pSeq)
{
	//1.��ʼ�� size
	//2.������Ҫ���������

	assert(pSeq != NULL);
	pSeq->size = 0;
	//memset(pSeq->array,' ',MAX_SIZE * sizeof(DataType));
}
//��
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
	pSeq->array[pSeq->size] = data;
	pSeq->size++;
}

//βɾ
void SeqListPushPop(SeqList *pSeq)
{
	assert(pSeq);
	//��������������ˣ�
	if (pSeq->size <= MAX_SIZE)
	{
		printf("����\n");
		assert(0);
		return;
	}
	pSeq->size--;
}
//ͷ��
void SeqListPushFront(SeqList *pSeq, DataType data)
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
		pSeq->array[i] = pSeq->array[i - 1];
	}
	//�������뺯������˳���
	pSeq->array[0] = data;
	pSeq->size++;
}

//ʹ�ó���
void Test()
{
	SeqList seqList;
	SeqListInit(&seqList);
}