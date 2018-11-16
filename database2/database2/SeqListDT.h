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
	DataType capacity;//��ǰ����
	int size;
}SeqListD;

//��ʼ��
void SeqListDInit(SeqListD* pSeq)
{
	pSeq->capacity = INIT_CAPACITY;
	pSeq->parr = (DataType*)malloc(sizeof(DataType)*pSeq->capacity);
	assert(pSeq->parr);
	pSeq->size = 0;
}

//����
void SeqListDDestroy(SeqListD* pSeq)
{
	free(pSeq->parr);
	pSeq->capacity = 0;
	pSeq->parr = NULL;
	pSeq->size = 0;
}

//����
static void ExpandIfRequired(SeqListD* pSeq)
{
	if (pSeq->size >= pSeq->capacity)
	{
		pSeq->capacity += 1000;
		DataType* NewParr = (DataType*)malloc(sizeof(DataType)*pSeq->capacity);//�洢����ʱ�����¿ռ�
		for (int i = 0; i < pSeq->size; i++)
		{
			NewParr[i] = pSeq->parr[i];
		}

		free(pSeq->parr);
		pSeq->parr = NewParr;
	}
}
//ͷ��
void SeqListDTouCha(SeqListD* pSeq, DataType data)
{
	ExpandIfRequired(pSeq);//�ж��Ƿ�����
	//ȫ������
	for (int i = pSeq->size - 1; i >= 0; i--)
	{
		pSeq->parr[i + 1] = pSeq->parr[i];
	}
	pSeq->parr[0] = data;
	pSeq->size++;
}

//ͷɾ
void SeqListDTouShan(SeqListD* pSeq)
{
	for (int i = 1; i < pSeq->size; i++)
	{
		pSeq->parr[i - 1] = pSeq->parr[i];
	}
	pSeq->size--;
}
//β��
void SeqListDWeiCha(SeqListD* pSeq,DataType data)
{
	ExpandIfRequired(pSeq);
	pSeq->parr[pSeq->size] = data;
	pSeq->size++;
}

//βɾ
void SeqListDWeiShan(SeqListD* pSeq)
{
	pSeq->size--;
}

//ָ��λ�ò���
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

//ָ��λ��ɾ��
void SeqListDRenYiShan(SeqListD* pSeq, int pos)
{
	for (int i = pos; i < pSeq->size; i++)
	{
		pSeq->parr[i - 1] = pSeq->parr[i];
	}
	pSeq->size--;
}

//����
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

//ɾ��ָ����������ͬԪ��
void SeqListDAllFind(SeqListD* pSeq, DataType data)
{
	//1.0ʱ�临�Ӷ�ΪO(n^2)
	int num = 0;
	while ((num = SeqListDFind(pSeq, data)) != -1)
	{
		SeqListDRenYiShan(pSeq, num + 1);
	}
	//��������
#if 0
	//2.0��Ҫ�����¿ռ�
	DataType* NewArr = (DataType*)malloc(sizeof(DataType)*pSeq->size);//���⿪�ٿռ����������ݰ���
	int j = 0;
	for (int i = 0; i < pSeq->size; i++)
	{
		if (data != pSeq->parr[i])
		{
			NewArr[j] = pSeq->parr[i];
			j++;//jָ����һ��Ԫ�أ����ǵ�ǰ�¿��ٿռ���洢��Ԫ�ظ�����
		}
	}
	free(pSeq->parr);
	pSeq->parr = NewArr;
	pSeq->size = j;
#endif

	////3.0�ŵ㣺���ÿ����µ��ڴ���Ұ����������
	//int j = 0, temp = 0;
	//for (int i = 0; i < pSeq->size; i++)
	//{
	//	if (data == pSeq->parr[i])
	//	{
	//		if (temp == 0)
	//		{
	//			temp = i;//��¼�״γ��ֵ�λ��
	//		}
	//		j++;//��¼�ظ��ĸ���
	//	}
	//	else
	//	{
	//		pSeq->parr[temp] = pSeq->parr[i];
	//		temp++;
	//	}
	//}
	//pSeq->size -= j;//Ԫ�صĳ���-ɾ���ĸ���

}

//��ӡ���ҽ��
void  SeqListDFindPrint(int* num)
{
	if (*num == -1)
	{
		printf("û�ҵ�\n");
	}
	else
	{
		printf("�ҵ���,���ֵ�һ�ε��±���%d��\n",*num);
	}
}

//��ӡ
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
	//β��
	SeqListDWeiCha(&seqlistdt, 10);
	SeqListDWeiCha(&seqlistdt, 6);
	SeqListDWeiCha(&seqlistdt, 6);
	SeqListDWeiCha(&seqlistdt, 6);
	SeqListDWeiCha(&seqlistdt, 5);
	SeqListDWeiCha(&seqlistdt, 4);
	SeqListDWeiCha(&seqlistdt, 3);
	SeqListDWeiCha(&seqlistdt, 2);
	SeqListDPrint(&seqlistdt);
	//βɾ
	SeqListDWeiShan(&seqlistdt);
	SeqListDPrint(&seqlistdt);
	//ͷ��
	SeqListDTouCha(&seqlistdt, 8);
	SeqListDTouCha(&seqlistdt, 7);
	SeqListDPrint(&seqlistdt);
	//ͷɾ
	SeqListDTouShan(&seqlistdt);
	SeqListDPrint(&seqlistdt);
	//ָ��λ�ò���
	SeqListDRenYiCha(&seqlistdt, 4, 9);
	SeqListDPrint(&seqlistdt);
	//ָ��λ��ɾ��
	SeqListDRenYiShan(&seqlistdt, 4);
	SeqListDPrint(&seqlistdt);
	//����(˳�����û�и�Ԫ�ص����)
	int temp = SeqListDFind(&seqlistdt, 0);
	//��ӡ���ҽ��
	SeqListDFindPrint(&temp);
	//����(˳������и�Ԫ�ص����)
	int temp1 = SeqListDFind(&seqlistdt, 5);
	//��ӡ���ҽ��
	SeqListDFindPrint(&temp1);
	//ɾ��ָ��������Ԫ��
	SeqListDAllFind(&seqlistdt, 6);
	SeqListDPrint(&seqlistdt);
}