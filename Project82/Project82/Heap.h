
//����ѣ�
//      ������һ����ȫ������
//      ˳��洢
//      ���ã�����ֵ����Ч��
//      ��Ϊ��С�Ѻʹ��
//****************************************************
//  ���Ѷ���
//    ���µ�����
//     1. �ж��Ƿ��к��ӣ��ǲ���Ҷ�ӽڵ㣩
//         ֱ�ӽ���
//     2.�к���
//        �����к��Ӷ���
//              ����С�ĺ���
//     3.����ֵ����С���ӵ�ֵ
//         ����ֵС��
//             ֱ�ӽ���
//         ������������ֵ
//ѭ��

//�ܽ᣺��Ѵ�ֵ�����ߣ�С��Сֵ������
//      ���Сֵ�����ߣ�С�Ѵ�ֵ������

//��������ȫ������
//     ����ֻ�ж������ڲ���
//����˳��洢����ʽ
//     �ж�Խ��
//�ж����ӽ����±��Ƿ�Խ��
//*****************************************************
//��n ����2*n+1   ����2*n+2
//*****************************************************



//���ѵĹ���***
//��ѭ���׵��ƵĹ���
//  ѭ���Ƿ�Ҷ�ӽ���ѭ����������Ҫ�����Ľ�����ڷ�֧��Ϊ���նѵĹ���
//�����ʼ��ʱ���ǻ��ҵģ�����Ҫ�Ӳ���Ҷ�ӽڵ�����һ����㿪ʼ���±��ǣ�(size-2)/2�Ľ�㿪ʼ
void CreateHeap(int array[], int size);

//array[size]���������С
//root����Ҫ�����Ľ����±�
//ǰ��:[root]���ڵĽ�����������Ѿ�������˵�������

#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

//˳�����
typedef int HPDataType;

typedef struct Heap
{
	HPDataType* arr;
	int size;
	int capacity;
}Heap;


//���µ���
void ADjustDown(int array[], int size, int root);

//���ϵ���
void ADjustUp(int array[], int size, int root);

//����
void HeapCreateHeap(Heap* heap, int array[], int size, int capacity);
//����
void AddHeapNode(Heap* heap, int data);
//ɾ��
void DelHeapFirst(Heap* heap);

//���ضѶ�Ԫ��
HPDataType GetHeapFirst(Heap* heap);

//��ӡ��
void PrintHeap(Heap* heap);