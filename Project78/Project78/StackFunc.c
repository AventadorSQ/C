#include"Stack.h"


//ջ�ĳ�ʼ��
void StackInit(StackMin* Sptr)
{
	Sptr->capcity = MAX_SIZE;
	Sptr->data = NULL;
	Sptr->top = 0;
}

//����
void IsExpandStack(StackMin* Sptr)
{
	if (Sptr->top >= Sptr->capcity)
	{
		Sptr->capcity *= 2;
		StackMin* NewNode = (StackMin*)malloc(sizeof(StackMin)*Sptr->capcity);
		assert(NewNode);

	}
}
//ѹջ
void StackPush(StackMin* Sptr, DataType data)
{

}

//��ջ
void StackPop(StackMin* Sptr);

//��ȡջ����СԪ��
int StackGetMin(StackMin* Sptr);

//��ȡջ��Ԫ��
void StackGetTop(StackMin* Sptr);

//��ӡջ
void StackPrint(StackMin* Sptr);

//����ջ
void StackDestory(StackMin* Sptr);



Heap->array[Heap->size] = child;
Heap->size++;

int num = (Heap->size - 2) / 2;
while(num)
{
	if ((Heap->size - 2) / 2 != 0)
	{
		if (Heap->array[num] < child)
		{
			//����

		}
		num = (num - 1) / 2;
	}
	else
	{
		//���ʵ�
	}

}




//�� 
//          �߼�����ȫ������
//              ���/С��
//     ���ã�����ֵ

