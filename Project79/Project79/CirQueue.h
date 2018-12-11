#pragma once

#include<stdio.h>
#include<assert.h>
#include<stdbool.h>
#include<malloc.h>
#include<stdlib.h>

//����ѭ����������
typedef struct
{
	int* ptr;
	int capcity;
	int size;
	int front;
	int rear;
}CirQueue;

//����ѭ������
CirQueue* CreateCirQueue(int k);

//����Ԫ��
void InsertCirQueue(CirQueue* CQPtr, int data);

//ɾ��Ԫ��
void DeleteCirQueue(CirQueue* CQPtr);

//���ض���Ԫ��
int GetHeadCirQueue(CirQueue* CQPtr);

//���ض�βԪ��
int GetWeiCirQueue(CirQueue* CQPtr);

//���ص�ǰʣ������
int GetSurplusCirQueue(CirQueue* CQPtr);

//��ӡѭ������
void PrintCirQueue(CirQueue* CQPtr);