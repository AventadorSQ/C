#pragma once

#include<stdio.h>
#include<assert.h>
#include<malloc.h>

//����������
#define DataType int

typedef struct LinkListNode
{
	DataType data;
	struct LinkListNode* next;
}LinkListNode;

//����ͷָ��
typedef struct LinkList
{
	LinkListNode* head;
}LinkList;

//1.����������
LinkListNode* CreateLinkListNode(DataType data);

//2.��ʼ������
void InitLinkList(LinkList* first);

//3.��������
void DestoryLinkList(LinkList* first);

//4.����������
LinkListNode* FindLinkList(LinkList* first, DataType data);

//5.���ӽ��
//5.1.ͷ��
void HeadAddLinkList(LinkList* first, DataType data);

//5.2.β��
void WeiChaLinkList(LinkList* first, DataType data);

//5.3.����posλ�ú����
void RenYiChaLinkList(LinkList* first, LinkListNode* pos, DataType data);

//6.ɾ�����
//6.1.ͷɾ
void HeadDelLinkList(LinkList* first);

//6.2.βɾ
void WeiShanLinkList(LinkList* first);

//6.3.����posλ��ɾ�����
//6.3.1.��λ��ɾ��
void RenYiWeiZhiDelLinkList(LinkList* first, LinkListNode* pos);

//6.3.2.������ɾ��
void RenYiDataDelLinkList(LinkList* first, DataType data);

//7.�޸�����������
void UpdateLinkList(LinkList* first, LinkListNode* pos, DataType data);

//8.��ӡ����
void PintLinkList(LinkList* first);


//******************************************************************************************************

//���������������
//1.��ת����
//1.1����һ��ͷָ�룬����ͷ��İ취 *****
void ReversalLinkList_TouCha(LinkList* first);

//1.2��������ָ�룬�ı�ָ��İ취
void ReversalLinkList_ThreePoint(LinkList* first);

//2.�������������еĽ��
//2.1�����ĸ�ָ�뷨
void SwapLinkList(LinkList* first1, DataType data1, LinkList* first2, DataType data2);

//3.ɾ�������ظ��Ľ�� ****
//3.1������ָ�뷨
void DelRepetitionLinkList(LinkList* first);

//4.��һ������x��������ֳ������֣���xС������ߣ�������ұߣ�����ԭ�����λ�ò���
void MidOrdered(LinkList* first, DataType data);

//5.�ҵ������е�����K�����
LinkListNode* FindKLinkList(LinkList* first, int k);

//6.�ҳ���������Ĺ������ *****
LinkListNode* FindTwoComLinkList(LinkList* first1, LinkList* first2);

//7.��������������ϲ���һ���������� *****
void HeBingLinkList(LinkList* first1, LinkList* first2);

//8.ɾ�������нڵ�����ݵ��ڸ���������ֵ�ý��
void DelDataLinkList(LinkList* first, DataType data);

//9.�ж�һ�������Ƿ��ǻ�����������boolֵ��
void IsHuiWenLinkList(LinkList* first);

//10.�ж�һ�������Ƿ��л������з����뻷�ĵ�һ���ڵ㣬���޷��ؿ� ****
LinkListNode* IsYouHuanLinkList(LinkList* first);

//11.���������м�������ż�����صڶ������
LinkListNode* ZhongJianLinkList(LinkList* first);

//12.����/��������K��
void XuanZhuanLinklist(LinkList* first, int k);