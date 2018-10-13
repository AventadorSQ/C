#pragma once

#include<stdlib.h>
#include<assert.h>
typedef int DataType;
#define INIT_CAPCITY 3

typedef struct SeqListD {
	DataType* parray;
	int capacity;//当前容量
	int size;
}SeqListD;

//初始化/销毁/插入
//初始化
void SeqListDInit(SeqListD *pSeq)
{
	pSeq->capacity = INIT_CAPCITY;
	pSeq->parray = (DataType*)malloc(sizeof(DataType)*pSeq->capacity);
	assert(pSeq->parray);

	pSeq->size = 0;
}
