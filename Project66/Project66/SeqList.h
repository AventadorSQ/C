#pragma once

#include<assert.h>

#define DataType int
typedef struct SeqList
{
	DataType* data;
	int capcity;
	int size;
}SeqList;

//�����ڵ�
char* CreateSeqListNode(SeqList* ptr);
//˳����ʼ��
void InitSeqList(SeqList* ptr);
//˳�����������
//ͷ��
void TouZengSeqList(SeqList* ptr,int data);
//β��
void WeiZengSeqList(SeqList* ptr, int data);
//����λ�ò���
void RenYiZengSeqList(SeqList* ptr, int pos, int data);
//˳���ɾ������

//����

//ð��
void SeqListBubbleSort(SeqList* ptr);

//���ֲ���
int SeqListBinarySearch(SeqList* ptr, DataType data);