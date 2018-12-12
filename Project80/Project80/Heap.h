
//�������������
//typedef struct Heap
//{
//	DataType* data;//�洢�ĵ�ǰ����
//	//struct Heap* Left;//ָ����������
//	//struct Heap* Right;//ָ�������Һ���
//}Heap;

#pragma once

//���
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>


//������������
#define DataType int

//˳��洢�ѣ����������
typedef struct Heap
{
	DataType* ptr;
	int capcity;
	int size;
}Heap;

//������
Heap* CreateHeap(int k);

//��ʼ��
void InitHeap(Heap* Hptr, DataType arr[]);

//��������
void InsertHeap(Heap* Hptr, DataType data);

//ɾ���Ѷ�
void DeleteHeap(Heap* Hptr);

//���ضѶ�
DataType GetTopHeap(Heap* Hptr);

//��ӡ������
void PrintHeap(Heap* Hptr);

//���ٶ�
void DestorHeap(Heap* Hptr);