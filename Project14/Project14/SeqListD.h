#pragma once

#include<stdlib.h>
#include<assert.h>
typedef int DataType;
#define INIT_CAPCITY 3

typedef struct SeqListD {
	DataType* parray;
	int capacity;//��ǰ����
	int size;
}SeqListD;

//��ʼ��/����/����
//��ʼ��
void SeqListDInit(SeqListD *pSeq)
{
	pSeq->capacity = INIT_CAPCITY;
	pSeq->parray = (DataType*)malloc(sizeof(DataType)*pSeq->capacity);
	assert(pSeq->parray);

	pSeq->size = 0;
}
