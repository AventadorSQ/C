#include "LinkListInterviewQue.h"

//1.����������
LinkListNode* CreateLinkListNode(DataType data)
{
	LinkListNode* NewNode = (LinkListNode*)malloc(sizeof(LinkListNode));
	assert(NewNode);
	NewNode->data = data;
	NewNode->next = NULL;
	return NewNode;
}

//2.��ʼ������
void InitLinkList(LinkList* first)
{
	assert(first);
	first->head = NULL;
}

//3.��������
void DestoryLinkList(LinkList* first)
{
	assert(first);
	LinkListNode* ptr = first->head;
	for (; first->head != NULL; first->head = first->head->next)
	{
		ptr = ptr->next;
		free(first->head);
		first->head = ptr;
	}
}

//4.���������㣨�����ظ�����ֻ���������ĵ�һ��Ҫ��ѯ������λ�ã�
LinkListNode* FindLinkList(LinkList* first, DataType data)
{
	assert(first);
	LinkListNode* ptr = first->head;
	for (; ptr->next != NULL; ptr = ptr->next)
	{
		if (ptr->data == data)
		{
			return ptr;
		}
	}
	return ptr;
}

//5.���ӽ��
//5.1.ͷ��
void HeadAddLinkList(LinkList* first, DataType data)
{
	assert(first);
	//����һ�����
	LinkListNode* NewNode = CreateLinkListNode(data);
	assert(NewNode);
	if (first->head != NULL)
	{
		NewNode->next = first->head;
		first->head = NewNode;
	}
	else
	{
		first->head = NewNode;
	}
}

//5.2.β��
void WeiChaLinkList(LinkList* first, DataType data)
{
	assert(first);
	if (first->head == NULL)
	{
		HeadAddLinkList(first, data);
		return;
	}
	LinkListNode* NewNode = CreateLinkListNode(data);
	assert(NewNode);
	LinkListNode* ptr = first->head;
	//ͨ��ѭ���ҵ����һ�����
	for (; ptr->next != NULL; ptr = ptr->next)
	{
	}
	ptr->next = NewNode;
}

//5.3.����posλ�ò��루posλ�ô����N����㣩����1��ʼ����pos�ǽ���ַ
void RenYiChaLinkList(LinkList* first, LinkListNode* pos, DataType data)
{
	assert(pos);
	LinkListNode* NewNode = CreateLinkListNode(data);
	assert(NewNode);
	NewNode->next = pos->next;
	pos->next = NewNode;
}

//6.ɾ�����
//6.1.ͷɾ
void HeadDelLinkList(LinkList* first)
{
	assert(first);
	if (first->head == NULL)
	{
		return;
	}
	LinkListNode* ptr = first->head->next;
	free(first->head);
	first->head = ptr;
}

//6.2.βɾ
void WeiShanLinkList(LinkList* first)
{
	assert(first);
	if (first->head == NULL)
	{
		return;
	}
	LinkListNode* ptr = first->head;
	LinkListNode* ptr1 = NULL;
	for (; ptr->next != NULL; ptr = ptr->next)
	{
		ptr1 = ptr;
	}
	free(ptr1->next);
	ptr1->next = NULL;
}

//6.3.����posλ��ɾ�����
//6.3.1.��λ��ɾ��
void RenYiWeiZhiDelLinkList(LinkList* first, LinkListNode* pos)
{
	assert(first);
	assert(pos);
	LinkListNode* ptr = first->head;
	if (ptr == NULL)
	{
		return;
	}
	if (ptr == pos)
	{
		HeadDelLinkList(first);
		return;
	}
	while (1)
	{
		if (ptr->next == pos)
		{
			LinkListNode* ptr1 = ptr->next->next;//���Ҫɾ���Ľ��λ��
			free(ptr->next);
			ptr->next = ptr1;
			return;
		}
		else
		{
			if (ptr->next != NULL)
			{
				ptr = ptr->next;
			}
			else
			{
				return;
			}
		}
	}
}

//6.3.2.������ɾ��
void RenYiDataDelLinkList(LinkList* first, DataType data)
{
	assert(first);
	LinkListNode* ptr = first->head;
	if (first->head == NULL)
	{
		return;
	}
	if (ptr->data == data)
	{
		HeadDelLinkList(first);
		return;
	}
	while (1)
	{
		if (ptr->next == NULL)
		{
			return;
		}
		else
		{
			if (ptr->next->data == data)
			{
				LinkListNode* ptr1 = ptr->next->next;
				free(ptr->next);
				ptr->next = ptr1;
			}
			else
			{
				ptr = ptr->next;
			}
		}
	}
}

//7.�޸�����������
void UpdateLinkList(LinkList* first, LinkListNode* pos, DataType data)
{
	assert(pos);
	LinkListNode* ptr = first->head;
	while (1)
	{
		if (ptr != pos)
		{
			if (ptr == NULL)
			{
				return;
			}
			ptr = ptr->next;
		}
		else
		{
			ptr->data = data;
			return;
		}
	}
}

//8.��ӡ����
void PintLinkList(LinkList* first)
{
	assert(first);
	LinkListNode* ptr = first->head;
	if (ptr == NULL)
	{
		printf("������\n");
		return;
	}
	while (1)
	{
		if (ptr != NULL)
		{
			printf("%d ", ptr->data);
			ptr = ptr->next;
		}
		else
		{
			printf("\n");
			return;
		}
	}
}


//**************************************************************************************************


//���������������

//1.��ת����
//1.1����һ��ͷָ�룬����ͷ��İ취 *****
void ReversalLinkList_TouCha(LinkList* first)
{
	assert(first);
	LinkListNode* ptr = first->head;
	LinkListNode* ptrs;//����ƶ�������һ�����
	LinkList* Two = (LinkList*)malloc(sizeof(LinkList));
	InitLinkList(Two);
	while (ptr != NULL)
	{
		ptrs = ptr->next;
		if (Two->head != NULL)
		{
			ptr->next = Two->head;
			Two->head =ptr;
		}
		else
		{
			Two->head = ptr;
			ptr->next = NULL;
		}
		ptr = ptrs;
	}
	first->head = Two->head;
}

//1.2��������ָ�룬�ı�ָ��İ취
void ReversalLinkList_ThreePoint(LinkList* first)
{
	assert(first);
	LinkListNode* ptr0;
	LinkListNode* ptr1;
	LinkListNode* ptr2;
	LinkListNode* ptr = first->head;
	if ((first->head == NULL) || (ptr->next == NULL))
	{
		return;
	}

	ptr0 = ptr;
	ptr1 = ptr->next;
	ptr2 = ptr->next->next;
	int i = 0;
	while (ptr1 != NULL)
	{
		if (i==0)
		{
			i++;
			ptr0->next = NULL;
		}
		ptr1->next = ptr0;
		first->head = ptr1;
		//�ƶ�ָ��
		ptr0 = ptr1;
		ptr1 = ptr2;
		if (ptr1 != NULL)
		{
			ptr2 = ptr2->next;
		}

	}
}

//2.�������������еĽ��
//2.1�����ĸ�ָ�뷨
void SwapLinkList(LinkList* first1, DataType data1, LinkList* first2, DataType data2)
{

}

//3.ɾ�������ظ��Ľ�� ****
//3.1������ָ�뷨
void DelRepetitionLinkList(LinkList* first)
{

}

//4.��һ������x��������ֳ������֣���xС������ߣ�������ұߣ�����ԭ�����λ�ò���
void MidOrdered(LinkList* first, DataType data)
{

}

//5.�ҵ������е�����K�����
LinkListNode* FindKLinkList(LinkList* first, int k)
{
	return;
}

//6.�ҳ���������Ĺ������ *****
LinkListNode* FindTwoComLinkList(LinkList* first1, LinkList* first2)
{
	return;
}

//7.��������������ϲ���һ���������� *****
void HeBingLinkList(LinkList* first1, LinkList* first2)
{

}

//8.ɾ�������нڵ�����ݵ��ڸ���������ֵ�ý��
void DelDataLinkList(LinkList* first, DataType data)
{

}

//9.�ж�һ�������Ƿ��ǻ�����������boolֵ��
void IsHuiWenLinkList(LinkList* first)
{

}

//10.�ж�һ�������Ƿ��л������з����뻷�ĵ�һ���ڵ㣬���޷��ؿ� ****
LinkListNode* IsYouHuanLinkList(LinkList* first)
{
	return;
}

//11.���������м�������ż�����صڶ������
LinkListNode* ZhongJianLinkList(LinkList* first)
{
	return;
}

//12.����/��������K��
void XuanZhuanLinklist(LinkList* first, int k)
{

}