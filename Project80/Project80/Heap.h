
//定义二叉树类型
//typedef struct Heap
//{
//	DataType* data;//存储的当前数据
//	//struct Heap* Left;//指向它的左孩子
//	//struct Heap* Right;//指向它的右孩子
//}Heap;

#pragma once

//大堆
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>


//定义数据类型
#define DataType int

//顺序存储堆，定义堆类型
typedef struct Heap
{
	DataType* ptr;
	int capcity;
	int size;
}Heap;

//创建堆
Heap* CreateHeap(int k);

//初始化
void InitHeap(Heap* Hptr, DataType arr[]);

//插入数据
void InsertHeap(Heap* Hptr, DataType data);

//删除堆顶
void DeleteHeap(Heap* Hptr);

//返回堆顶
DataType GetTopHeap(Heap* Hptr);

//打印堆数据
void PrintHeap(Heap* Hptr);

//销毁堆
void DestorHeap(Heap* Hptr);