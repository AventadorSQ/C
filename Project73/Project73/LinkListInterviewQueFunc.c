#include "LinkListInterviewQue.h"

//1.创建链表结点
LinkListNode* CreateLinkListNode(DataType data)
{
	LinkListNode* NewNode = (LinkListNode*)malloc(sizeof(LinkListNode));
	assert(NewNode);
	NewNode->data = data;
	NewNode->next = NULL;
	return NewNode;
}

//2.初始化链表
void InitLinkList(LinkList* first)
{
	assert(first);
	first->head = NULL;
}

//3.销毁链表
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

//4.查找链表结点（不管重复多少只返回遇到的第一个要查询的数据位置）
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

//5.增加结点
//5.1.头插
void HeadAddLinkList(LinkList* first, DataType data)
{
	assert(first);
	//创建一个结点
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

//5.2.尾插
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
	//通过循环找到最后一个结点
	for (; ptr->next != NULL; ptr = ptr->next)
	{
	}
	ptr->next = NewNode;
}

//5.3.任意pos位置插入（pos位置代表第N个结点）（从1开始）（pos是结点地址
void RenYiChaLinkList(LinkList* first, LinkListNode* pos, DataType data)
{
	assert(pos);
	LinkListNode* NewNode = CreateLinkListNode(data);
	assert(NewNode);
	NewNode->next = pos->next;
	pos->next = NewNode;
}

//6.删除结点
//6.1.头删
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

//6.2.尾删
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

//6.3.任意pos位置删除结点
//6.3.1.按位置删除
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
			LinkListNode* ptr1 = ptr->next->next;//标记要删除的结点位置
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

//6.3.2.按数据删除
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

//7.修改链表结点数据
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

//8.打印链表
void PintLinkList(LinkList* first)
{
	assert(first);
	LinkListNode* ptr = first->head;
	if (ptr == NULL)
	{
		printf("空链表\n");
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


//链表面试题锦集：

//1.反转链表
//1.1引入一个头指针，进行头插的办法 *****
void ReversalLinkList_TouCha(LinkList* first)
{
	assert(first);
	LinkListNode* ptr = first->head;
	LinkListNode* ptrs;//标记移动结点的下一个结点
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

//1.2引入三个指针，改变指向的办法
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
		//移动指针
		ptr0 = ptr1;
		ptr1 = ptr2;
		if (ptr1 != NULL)
		{
			ptr2 = ptr2->next;
		}

	}
}

//4.2查找链表结点前一个结点（不管重复多少只返回遇到的第一个要查询的前数据位置）
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

//2.交换两个链表中的结点
//2.1引入四个指针法
void SwapLinkList(LinkList* first1, DataType data1, LinkList* first2, DataType data2)
{
	LinkListNode* ptr1;
	LinkListNode* ptr2;
	LinkListNode* ptr1s;//用来接收该数据结点的下一个结点位置
	LinkListNode* ptr2s;
	LinkListNode* ptr2S;
	if (first1->head->data != data1 && first2->head->data != data2)
	{
		ptr1 = FindLinkList2(first1, data1);//接收数据结点的上一个结点
		ptr2 = FindLinkList2(first2, data2);
		if (ptr1 == NULL || ptr2 == NULL)//如果至少有一条链表不存在则交换无意义
		{
			return;
		}
		else
		{
			ptr1s = ptr1->next;//保存交换的结点位置
			ptr2s = ptr2->next;
			ptr2S = ptr2->next->next;//由于会将第二条链表后面丢失，所以标记
			ptr1->next = ptr2->next;//先把交换的结点及他后面的结点接到另一个上面
			ptr2->next = ptr1s;
			ptr1->next->next = ptr1s->next;//再把交换结点的后面的结点再接回去
			ptr2->next->next = ptr2S;
		}
	}
	else if (first1->head->data == data1 && first2->head->data != data2)
	{
		ptr1 = first1->head;
		LinkListNode* ptr1Next = ptr1->next;
		ptr2 = FindLinkList2(first2, data2);
		ptr1s = ptr1;//保存交换的结点位置
		ptr2s = ptr2->next;
		ptr2S = ptr2->next->next;//由于会将第二条链表后面丢失，所以标记
		ptr1 = ptr2->next;//先把交换的结点及他后面的结点接到另一个上面
		ptr2->next = ptr1s;
		ptr1->next = ptr1Next;//再把交换结点的后面的结点再接回去
		ptr2->next->next = ptr2S;
		first1->head = ptr1;
	}
	else if (first1->head->data != data1 && first2->head->data == data2)
	{
		SwapLinkList(first2, data2, first1, data1);
	}
	else
	{
		ptr1 = first1->head->next;//保存交换的结点的后面结点位置
		ptr2 = first2->head->next;
		ptr1s = first1->head;//标记第一条链表的头指针
		first1->head = first2->head;//第一条链表头指针指向第二条链表
		first1->head->next = ptr1;//把第一条原来的交换的结点后面的结点接回来
		first2->head = ptr1s;//第二条链表头指针指向（原来）第一条链表
		first2->head->next = ptr2;//把第二条原来的交换的结点后面的结点接回来
	}
}

//3.删除所有重复(结点连续重复)的结点 ****
//3.1引入三指针法
void DelRepetitionLinkList(LinkList* first)
{
	assert(first);
	if (first->head == NULL)
	{
		return;
	}
	LinkListNode* ptr0 = NULL;//指向要重复结点的前一个
	LinkListNode* ptr1 = first->head;//指向重复结点的第一个
	LinkListNode* ptr2 = first->head->next;//指向重复结点的下一个不重复结点
	while (ptr1->next != NULL)
	{
		//没有重复的结点时让三个指针依次往前走
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
				//遇到重复的结点数据时，只让ptr2指针往后走，边走边释放
				if (ptr1->next != NULL)
				{
					ptr = ptr2;
					ptr2 = ptr2->next;
					free(ptr);
					ptr1->next = ptr2;
				}
				//处理重复结点的下一个刚好为空的情况
				if (ptr2 == NULL)
				{
					//ptr2为空，指针ptr1走到链表尽头---处理重复链表已完成。（分为两种情况）
					if (ptr0 != NULL)//一、当链表第一个节点不是重复结点时     例子：1 2 2 2 2 2 2 
					{
						free(ptr0->next);
						ptr1 = ptr2;
						ptr0->next = ptr1;
						return;
					}
					else            //二、当链表第一个节点是重复结点时         例子：2 2 2 2 2 2 2 
					{
						free(ptr1);
						ptr1 = ptr2;
						ptr0 = ptr1;
						first->head = ptr0;
						return;
					}
				}
			}
			//处理链表重复结点的下一个不是空（即有结点）时的情况（分为两种）
			if (ptr0 != NULL)//一、ptr0不为空，即第一个节点不是重复结点时     例子：1 2 2 2 2 2 3 4
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
			else           //二、ptr0为空，即第一个节点是重复结点时           例子：2 2 2 2 2 2 3 4
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

//4.给一个数据x，将链表分成两部分，比x小的在左边，大的/相等的在右边，保持原来相对位置不变
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
				LTRailPtr = LTRailPtr->next;//把最后一个指针往后移
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

//5.找到链表中倒数第K个结点
LinkListNode* FindKLinkList(LinkList* first, int k)
{
	assert(first);
	int num = 0;
	if ((k < 1) || (first->head == NULL))
	{
		return NULL;
	}
	LinkListNode* Fastptr = first->head;//快指针先走K-1步
	LinkListNode* Slowptr = first->head;//慢指针指向头指针
	while (Fastptr != NULL)
	{
		if (num + 1 == k)
		{
			while (Fastptr->next != NULL)
			{
				Fastptr = Fastptr->next;//快慢指针一起走
				Slowptr = Slowptr->next;
			}
			return Slowptr;
		}
		num++;
		Fastptr = Fastptr->next;
	}
	return NULL;
}

//6.找出两个链表的公共结点 *****
LinkListNode* FindTwoComLinkList(LinkList* first1, LinkList* first2)
{

}

//7.将两个有序链表合并成一个有序链表 *****
void HeBingLinkList(LinkList* first1, LinkList* first2)
{

}

//8.删除链表中节点的数据等于给定的数据值得结点
void DelDataLinkList(LinkList* first, DataType data)
{

}

//9.判断一个链表是否是回文链表（返回bool值）
void IsHuiWenLinkList(LinkList* first)
{

}

//10.判断一个链表是否有环，若有返回入环的第一个节点，若无返回空 ****
LinkListNode* IsYouHuanLinkList(LinkList* first)
{
	return;
}

//11.返回链表中间结点若是偶数返回第二个结点
LinkListNode* ZhongJianLinkList(LinkList* first)
{
	return;
}

//12.左旋/右旋链表K个
void XuanZhuanLinklist(LinkList* first, int k)
{

}