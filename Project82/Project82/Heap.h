
//二叉堆：
//      本身是一颗完全二叉树
//      顺序存储
//      作用：找最值（高效）
//      分为：小堆和大堆
//****************************************************
//  调堆顶：
//    向下调整：
//     1. 判断是否有孩子（是不是叶子节点）
//         直接结束
//     2.有孩子
//        左右有孩子都有
//              找最小的孩子
//     3.根的值和最小孩子的值
//         根的值小了
//             直接结束
//         交换两个结点的值
//循坏

//总结：大堆大值往上走，小堆小值往上走
//      大堆小值往下走，小堆大值往下走

//由于是完全二叉树
//     所以只判断左孩子在不在
//由于顺序存储的形式
//     判断越界
//判断左孩子结点的下标是否越界
//*****************************************************
//亲n 左子2*n+1   右子2*n+2
//*****************************************************



//建堆的过程***
//：循环套递推的过程
//  循环是飞叶子结点的循环，递推是要调整的结点所在分支调为最终堆的过程
//由于最开始的时候是混乱的，所以要从不是叶子节点的最后一个结点开始即下标是：(size-2)/2的结点开始
void CreateHeap(int array[], int size);

//array[size]代表数组大小
//root代表要调整的结点的下标
//前提:[root]所在的结点左右子树已经满足堆了的性质了

#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

//顺序表建堆
typedef int HPDataType;

typedef struct Heap
{
	HPDataType* arr;
	int size;
	int capacity;
}Heap;


//向下调整
void ADjustDown(int array[], int size, int root);

//向上调整
void ADjustUp(int array[], int size, int root);

//建堆
void HeapCreateHeap(Heap* heap, int array[], int size, int capacity);
//增加
void AddHeapNode(Heap* heap, int data);
//删除
void DelHeapFirst(Heap* heap);

//返回堆顶元素
HPDataType GetHeapFirst(Heap* heap);

//打印堆
void PrintHeap(Heap* heap);