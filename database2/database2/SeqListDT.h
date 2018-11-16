#pragma once

#define _CRT_SECURE_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>


typedef int DataType;

#define INIT_CAPACITY (3)

typedef struct SeqListD
{
	DataType* parr;
	DataType capacity;//当前容量
	int size;
}SeqListD;

//初始化
void SeqListDInit(SeqListD* pSeq)
{
	pSeq->capacity = INIT_CAPACITY;
	pSeq->parr = (DataType*)malloc(sizeof(DataType)*pSeq->capacity);
	assert(pSeq->parr);
	pSeq->size = 0;
}

//销毁
void SeqListDDestroy(SeqListD* pSeq)
{
	free(pSeq->parr);
	pSeq->capacity = 0;
	pSeq->parr = NULL;
	pSeq->size = 0;
}

//扩容
static void ExpandIfRequired(SeqListD* pSeq)
{
	if (pSeq->size >= pSeq->capacity)
	{
		pSeq->capacity += 1000;
		DataType* NewParr = (DataType*)malloc(sizeof(DataType)*pSeq->capacity);//存储不够时申请新空间
		for (int i = 0; i < pSeq->size; i++)
		{
			NewParr[i] = pSeq->parr[i];
		}

		free(pSeq->parr);
		pSeq->parr = NewParr;
	}
}
//头插
void SeqListDTouCha(SeqListD* pSeq, DataType data)
{
	ExpandIfRequired(pSeq);//判断是否扩容
	//全部右移
	for (int i = pSeq->size - 1; i >= 0; i--)
	{
		pSeq->parr[i + 1] = pSeq->parr[i];
	}
	pSeq->parr[0] = data;
	pSeq->size++;
}

//头删
void SeqListDTouShan(SeqListD* pSeq)
{
	for (int i = 1; i < pSeq->size; i++)
	{
		pSeq->parr[i - 1] = pSeq->parr[i];
	}
	pSeq->size--;
}
//尾插
void SeqListDWeiCha(SeqListD* pSeq,DataType data)
{
	ExpandIfRequired(pSeq);
	pSeq->parr[pSeq->size] = data;
	pSeq->size++;
}

//尾删
void SeqListDWeiShan(SeqListD* pSeq)
{
	pSeq->size--;
}

//指定位置插入
void SeqListDRenYiCha(SeqListD* pSeq, int pos, DataType data)
{
	ExpandIfRequired(pSeq);
	for (int i = pSeq->size - 1; i >= pos-1; i--)
	{
		pSeq->parr[i + 1] = pSeq->parr[i];
	}
	pSeq->parr[pos - 1] = data;
	pSeq->size++;
}

//指定位置删除
void SeqListDRenYiShan(SeqListD* pSeq, int pos)
{
	for (int i = pos; i < pSeq->size; i++)
	{
		pSeq->parr[i - 1] = pSeq->parr[i];
	}
	pSeq->size--;
}

//查找
int SeqListDFind(SeqListD* pSeq, DataType data)
{
	for (int i = 0; i < pSeq->size - 1; i++)
	{
		if (data == pSeq->parr[i])
		{
			return i;
			//break;
		}
	}
	return -1;
}

//删除指定的所有相同元素
void SeqListDAllFind(SeqListD* pSeq, DataType data)
{
	//1.0时间复杂度为O(n^2)
	int num = 0;
	while ((num = SeqListDFind(pSeq, data)) != -1)
	{
		SeqListDRenYiShan(pSeq, num + 1);
	}
	//条件编译
#if 0
	//2.0需要开辟新空间
	DataType* NewArr = (DataType*)malloc(sizeof(DataType)*pSeq->size);//另外开辟空间用来做数据搬移
	int j = 0;
	for (int i = 0; i < pSeq->size; i++)
	{
		if (data != pSeq->parr[i])
		{
			NewArr[j] = pSeq->parr[i];
			j++;//j指向下一个元素（就是当前新开辟空间里存储的元素个数）
		}
	}
	free(pSeq->parr);
	pSeq->parr = NewArr;
	pSeq->size = j;
#endif

	////3.0优点：不用开辟新的内存而且搬运算次数少
	//int j = 0, temp = 0;
	//for (int i = 0; i < pSeq->size; i++)
	//{
	//	if (data == pSeq->parr[i])
	//	{
	//		if (temp == 0)
	//		{
	//			temp = i;//记录首次出现的位置
	//		}
	//		j++;//记录重复的个数
	//	}
	//	else
	//	{
	//		pSeq->parr[temp] = pSeq->parr[i];
	//		temp++;
	//	}
	//}
	//pSeq->size -= j;//元素的长度-删除的个数

}

//打印查找结果
void  SeqListDFindPrint(int* num)
{
	if (*num == -1)
	{
		printf("没找到\n");
	}
	else
	{
		printf("找到了,出现第一次的下标是%d。\n",*num);
	}
}

//打印
void SeqListDPrint(const SeqListD* pSeq)
{
	assert(pSeq != NULL);

	for (int i = 0; i < pSeq->size; i++)
	{
		printf("%d ", pSeq->parr[i]);
	}
	printf("\n");
}
void Test()
{
	SeqListD seqlistdt;
	SeqListDInit(&seqlistdt);
	//尾插
	SeqListDWeiCha(&seqlistdt, 10);
	SeqListDWeiCha(&seqlistdt, 6);
	SeqListDWeiCha(&seqlistdt, 6);
	SeqListDWeiCha(&seqlistdt, 6);
	SeqListDWeiCha(&seqlistdt, 5);
	SeqListDWeiCha(&seqlistdt, 4);
	SeqListDWeiCha(&seqlistdt, 3);
	SeqListDWeiCha(&seqlistdt, 2);
	SeqListDPrint(&seqlistdt);
	//尾删
	SeqListDWeiShan(&seqlistdt);
	SeqListDPrint(&seqlistdt);
	//头插
	SeqListDTouCha(&seqlistdt, 8);
	SeqListDTouCha(&seqlistdt, 7);
	SeqListDPrint(&seqlistdt);
	//头删
	SeqListDTouShan(&seqlistdt);
	SeqListDPrint(&seqlistdt);
	//指定位置插入
	SeqListDRenYiCha(&seqlistdt, 4, 9);
	SeqListDPrint(&seqlistdt);
	//指定位置删除
	SeqListDRenYiShan(&seqlistdt, 4);
	SeqListDPrint(&seqlistdt);
	//查找(顺序表中没有该元素的情况)
	int temp = SeqListDFind(&seqlistdt, 0);
	//打印查找结果
	SeqListDFindPrint(&temp);
	//查找(顺序表中有该元素的情况)
	int temp1 = SeqListDFind(&seqlistdt, 5);
	//打印查找结果
	SeqListDFindPrint(&temp1);
	//删除指定的所有元素
	SeqListDAllFind(&seqlistdt, 6);
	SeqListDPrint(&seqlistdt);
}