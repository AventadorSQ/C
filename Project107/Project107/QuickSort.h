#include<stdio.h>

//交换两个数
void SwapNum(int* num1, int* num2);

//打印数组
void PrintArray(int array[], int size);

//快速排序
//快速排序1基准值在中间
//left 数组第一个元素下标，right数组最后一个元素下标
void QuickSort(int array[], int left, int right);

//快速排序2挖坑法基准值在中间
//left 数组第一个元素下标，right数组最后一个元素下标
void QuickSort2(int array[], int left, int right);

//快速排序3基准值在后边i，j都从头开始
//left 数组第一个元素下标，right数组最后一个元素下标
void QuickSort3(int array[], int left, int right);