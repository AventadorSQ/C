#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

#define DataType int
#define MAX_SIZE (2)

typedef struct StackMin
{
	DataType data;
	int capcity;
	int top;
}StackMin;

//ջ�ĳ�ʼ��
void StackInit(StackMin* Sptr);

//ѹջ
void StackPush(StackMin* Sptr, DataType data);

//��ջ
void StackPop(StackMin* Sptr);

//��ȡջ����СԪ��
int StackGetMin(StackMin* Sptr);

//��ȡջ��Ԫ��
void StackGetTop(StackMin* Sptr);

//��ӡջ
void StackPrint(StackMin* Sptr);

//����ջ
void StackDestory(StackMin* Sptr);