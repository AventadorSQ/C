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
			Two->head = ptr;
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
		if (i == 0)
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

//4.2����������ǰһ����㣨�����ظ�����ֻ���������ĵ�һ��Ҫ��ѯ��ǰ����λ�ã�
LinkListNode* FindLinkList2(LinkList* first, DataType data)
{
	assert(first);
	LinkListNode* ptr = first->head;
	if (ptr == NULL)
	{
		return NULL;
	}
	//else
	//{
	//	if (first->head->data == data)
	//	{
	//		return first;
	//	}
	//}
	for (; ptr->next != NULL; ptr = ptr->next)
	{
		if (ptr->next->data == data)
		{
			return ptr;
		}
	}
	return NULL;
}

//2.�������������еĽ��
//2.1�����ĸ�ָ�뷨
void SwapLinkList(LinkList* first1, DataType data1, LinkList* first2, DataType data2)
{
	LinkListNode* ptr1;
	LinkListNode* ptr2;
	LinkListNode* ptr1s;//�������ո����ݽ�����һ�����λ��
	LinkListNode* ptr2s;
	LinkListNode* ptr2S;
	if (first1->head->data != data1 && first2->head->data != data2)
	{
		ptr1 = FindLinkList2(first1, data1);//�������ݽ�����һ�����
		ptr2 = FindLinkList2(first2, data2);
		if (ptr1 == NULL || ptr2 == NULL)//���������һ�����������򽻻�������
		{
			return;
		}
		else
		{
			ptr1s = ptr1->next;//���潻���Ľ��λ��
			ptr2s = ptr2->next;
			ptr2S = ptr2->next->next;//���ڻὫ�ڶ���������涪ʧ�����Ա��
			ptr1->next = ptr2->next;//�Ȱѽ����Ľ�㼰������Ľ��ӵ���һ������
			ptr2->next = ptr1s;
			ptr1->next->next = ptr1s->next;//�ٰѽ������ĺ���Ľ���ٽӻ�ȥ
			ptr2->next->next = ptr2S;
		}
	}
	else if (first1->head->data == data1 && first2->head->data != data2)
	{
		ptr1 = first1->head;
		LinkListNode* ptr1Next = ptr1->next;
		ptr2 = FindLinkList2(first2, data2);
		ptr1s = ptr1;//���潻���Ľ��λ��
		ptr2s = ptr2->next;
		ptr2S = ptr2->next->next;//���ڻὫ�ڶ���������涪ʧ�����Ա��
		ptr1 = ptr2->next;//�Ȱѽ����Ľ�㼰������Ľ��ӵ���һ������
		ptr2->next = ptr1s;
		ptr1->next = ptr1Next;//�ٰѽ������ĺ���Ľ���ٽӻ�ȥ
		ptr2->next->next = ptr2S;
		first1->head = ptr1;
	}
	else if (first1->head->data != data1 && first2->head->data == data2)
	{
		SwapLinkList(first2, data2, first1, data1);
	}
	else
	{
		ptr1 = first1->head->next;//���潻���Ľ��ĺ�����λ��
		ptr2 = first2->head->next;
		ptr1s = first1->head;//��ǵ�һ�������ͷָ��
		first1->head = first2->head;//��һ������ͷָ��ָ��ڶ�������
		first1->head->next = ptr1;//�ѵ�һ��ԭ���Ľ����Ľ�����Ľ��ӻ���
		first2->head = ptr1s;//�ڶ�������ͷָ��ָ��ԭ������һ������
		first2->head->next = ptr2;//�ѵڶ���ԭ���Ľ����Ľ�����Ľ��ӻ���
	}
}

//3.ɾ�������ظ�(��������ظ�)�Ľ�� ****
//3.1������ָ�뷨
void DelRepetitionLinkList(LinkList* first)
{
	assert(first);
	if (first->head == NULL)
	{
		return;
	}
	LinkListNode* ptr0 = NULL;//ָ��Ҫ�ظ�����ǰһ��
	LinkListNode* ptr1 = first->head;//ָ���ظ����ĵ�һ��
	LinkListNode* ptr2 = first->head->next;//ָ���ظ�������һ�����ظ����
	while (ptr1->next != NULL)
	{
		//û���ظ��Ľ��ʱ������ָ��������ǰ��
		if (ptr1->data != ptr2->data)
		{
			ptr0 = ptr1;
			ptr1 = ptr2;
			ptr2 = ptr2->next;
		}
		else
		{
			LinkListNode* ptr;
			while (ptr1->data == ptr2->data)
			{
				//�����ظ��Ľ������ʱ��ֻ��ptr2ָ�������ߣ����߱��ͷ�
				if (ptr1->next != NULL)
				{
					ptr = ptr2;
					ptr2 = ptr2->next;
					free(ptr);
					ptr1->next = ptr2;
				}
				//�����ظ�������һ���պ�Ϊ�յ����
				if (ptr2 == NULL)
				{
					//ptr2Ϊ�գ�ָ��ptr1�ߵ�����ͷ---�����ظ���������ɡ�����Ϊ���������
					if (ptr0 != NULL)//һ���������һ���ڵ㲻���ظ����ʱ     ���ӣ�1 2 2 2 2 2 2 
					{
						free(ptr0->next);
						ptr1 = ptr2;
						ptr0->next = ptr1;
						return;
					}
					else            //�����������һ���ڵ����ظ����ʱ         ���ӣ�2 2 2 2 2 2 2 
					{
						free(ptr1);
						ptr1 = ptr2;
						ptr0 = ptr1;
						first->head = ptr0;
						return;
					}
				}
			}
			//���������ظ�������һ�����ǿգ����н�㣩ʱ���������Ϊ���֣�
			if (ptr0 != NULL)//һ��ptr0��Ϊ�գ�����һ���ڵ㲻���ظ����ʱ     ���ӣ�1 2 2 2 2 2 3 4
			{
				free(ptr0->next);
				ptr1 = ptr2;
				ptr0->next = ptr1;
				if (ptr1 == NULL)
				{
					return;
				}
				if (ptr2 != NULL)
				{
					ptr2 = ptr2->next;
				}
			}
			else           //����ptr0Ϊ�գ�����һ���ڵ����ظ����ʱ           ���ӣ�2 2 2 2 2 2 3 4
			{
				free(ptr1);
				ptr1 = ptr2;
				ptr0 = ptr1;
				first->head = ptr0;
				if (ptr2 == NULL)
				{
					return;
				}
			}
		}
	}
}

//4.��һ������x��������ֳ������֣���xС������ߣ����/��ȵ����ұߣ�����ԭ�����λ�ò���
void MidOrdered(LinkList* first, DataType data)
{
	assert(first);
	if (first->head == NULL)
	{
		return;
	}
	LinkList* LTPtr = (LinkList*)malloc(sizeof(LinkList));
	InitLinkList(LTPtr);
	LinkListNode* LTRailPtr = NULL;
	LinkList* ETGTPtr = (LinkList*)malloc(sizeof(LinkList));
	InitLinkList(ETGTPtr);
	LinkListNode* ETGTRailPtr = NULL;
	LinkListNode* ptr = first->head;
	while (ptr != NULL)
	{
		if (ptr->data < data)
		{
			if (LTPtr->head == NULL)
			{
				LTPtr->head  = ptr;
				LTRailPtr = ptr;
				ptr = ptr->next;
				LTRailPtr->next = NULL;
			}
			else
			{
				LTRailPtr->next = ptr;
				ptr = ptr->next;
				LTRailPtr = LTRailPtr->next;//�����һ��ָ��������
				LTRailPtr->next = NULL;
			}
		}
		else
		{
			if (ETGTPtr->head == NULL)
			{
				ETGTPtr->head = ptr;
				ETGTRailPtr = ptr;
				ptr = ptr->next;
				ETGTRailPtr->next = NULL;
			}
			else
			{
				ETGTRailPtr->next = ptr;
				ptr = ptr->next;
				ETGTRailPtr = ETGTRailPtr->next;
				ETGTRailPtr->next = NULL;
			}
		}
	}
	if (LTPtr->head == NULL)
	{
		first->head = ETGTPtr->head;
	}
	else if (LTPtr->head != NULL && ETGTPtr->head == NULL)
	{
		first->head = LTPtr->head;
	}
	else 
	{
		LTRailPtr->next = ETGTPtr->head;
		first->head = LTPtr->head;
	}
}

//5.�ҵ������е�����K�����
LinkListNode* FindKLinkList(LinkList* first, int k)
{
	assert(first);
	int num = 0;
	if ((k < 1) || (first->head == NULL))
	{
		return NULL;
	}
	LinkListNode* Fastptr = first->head;//��ָ������K-1��
	LinkListNode* Slowptr = first->head;//��ָ��ָ��ͷָ��
	while (Fastptr != NULL)
	{
		if (num + 1 == k)
		{
			while (Fastptr->next != NULL)
			{
				Fastptr = Fastptr->next;//����ָ��һ����
				Slowptr = Slowptr->next;
			}
			return Slowptr;
		}
		num++;
		Fastptr = Fastptr->next;
	}
	return NULL;
}

//6.�ҳ���������Ĺ������ *****
LinkListNode* FindTwoComLinkList(LinkList* first1, LinkList* first2)
{

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