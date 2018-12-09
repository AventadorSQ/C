#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

//栈特点：后进先出

//定义数据类型
#define DataType int

//定义动态顺序表型的栈的初始容量
#define MAX_CAP (2)

//定义动态顺序表型的栈
typedef struct StackSeqList
{
	DataType* ptr;
	int capcity;
	int top;
}Stack;

//初始化
void InitStack(Stack* Sptr);

//销毁
void DestoryStack(Stack* Sptr);

//扩容
void ExpandStack(Stack* Sptr);

//入栈
void AddStack(Stack* Sptr, DataType data);

//弹栈
void DelStack(Stack* Sptr);

//打印栈中数据
void PrintStack(Stack* Sptr);