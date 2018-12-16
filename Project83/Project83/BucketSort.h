#pragma once

#include<stdio.h>
#include<stdlib.h>

typedef int DataType;

//定义存储数据类型
typedef struct BucSort
{
	DataType* arr;
	int capacity;
}BucSort;

//初始化
void InitArray(BucSort* SortArr, DataType arr[], int size);

//桶排序
void BucketSort(DataType arr[], int size);

//打印结果
void PrintArr(DataType arr[], int size);