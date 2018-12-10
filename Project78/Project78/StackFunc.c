#include"Stack.h"


//栈的初始化
void StackInit(StackMin* Sptr)
{
	Sptr->capcity = MAX_SIZE;
	Sptr->data = NULL;
	Sptr->top = 0;
}

//扩容
void IsExpandStack(StackMin* Sptr)
{
	if (Sptr->top >= Sptr->capcity)
	{
		Sptr->capcity *= 2;
		StackMin* NewNode = (StackMin*)malloc(sizeof(StackMin)*Sptr->capcity);
		assert(NewNode);

	}
}
//压栈
void StackPush(StackMin* Sptr, DataType data)
{

}

//出栈
void StackPop(StackMin* Sptr);

//获取栈中最小元素
int StackGetMin(StackMin* Sptr);

//获取栈顶元素
void StackGetTop(StackMin* Sptr);

//打印栈
void StackPrint(StackMin* Sptr);

//销毁栈
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
			//交换

		}
		num = (num - 1) / 2;
	}
	else
	{
		//当皇帝
	}

}




//堆 
//          逻辑上完全二叉树
//              大堆/小堆
//     作用：找最值

