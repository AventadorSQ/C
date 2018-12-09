#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>


//˫��ѭ����ͷ�������

//����������������
#define DataType int

//����������
typedef struct BCHLinkList
{
	DataType data;
	struct BCHLinkList* prve;
	struct BCHLinkList* next;
}BCHLinkList;

//1.��ʼ��
void InitBCHLinkList(BCHLinkList* BCHptr);

//2.�����½��
BCHLinkList* CreateBCHLinkList(DataType data);

//3.����data
BCHLinkList* FindBCHLinkList(BCHLinkList* BCHptr, DataType data);

//4.������
//4.1ͷ��
void HeadAddBCHLinkList(BCHLinkList* BCHptr, DataType data);

//4.2β��
void WeiAddBCHLinkList(BCHLinkList* BCHptr, DataType data);

//4.3��������������
void RenYiAddBCHLinkList(BCHLinkList* BCHptr, BCHLinkList* pos, DataType data);

//5.ɾ�����
//5.1ͷɾ
void HeadDelBCHLinkList(BCHLinkList* BCHptr);

//5.2βɾ
void WeiDelBCHLinkList(BCHLinkList* BCHptr);

//5.3������ɾ��
void RenYiDelBCHLinkList(BCHLinkList* BCHptr, DataType data);

//6.�޸Ľ������
void RenYiXiuGaiBCHLinkList(BCHLinkList* BCHptr, DataType data1, DataType data);

//7.��ӡ˫��ѭ������
void PrintBCHLinkList(BCHLinkList* BCHptr);

//8.��������
void DestoryBCHLinkList(BCHLinkList* BCHptr);