#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

//ջ�ص㣺����ȳ�

//������������
#define DataType int

//���嶯̬˳����͵�ջ�ĳ�ʼ����
#define MAX_CAP (2)

//���嶯̬˳����͵�ջ
typedef struct StackSeqList
{
	DataType* ptr;
	int capcity;
	int top;
}Stack;

//��ʼ��
void InitStack(Stack* Sptr);

//����
void DestoryStack(Stack* Sptr);

//����
void ExpandStack(Stack* Sptr);

//��ջ
void AddStack(Stack* Sptr, DataType data);

//��ջ
void DelStack(Stack* Sptr);

//��ӡջ������
void PrintStack(Stack* Sptr);