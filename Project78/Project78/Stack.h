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

//栈的初始化
void StackInit(StackMin* Sptr);

//压栈
void StackPush(StackMin* Sptr, DataType data);

//出栈
void StackPop(StackMin* Sptr);

//获取栈中最小元素
int StackGetMin(StackMin* Sptr);

//获取栈顶元素
void StackGetTop(StackMin* Sptr);

//打印栈
void StackPrint(StackMin* Sptr);

//销毁栈
void StackDestory(StackMin* Sptr);