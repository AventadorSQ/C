#include"Stack.h"

//初始化
void InitStack(Stack* Sptr)
{
	Sptr->capcity = MAX_CAP;
	Sptr->ptr = (DataType*)malloc(sizeof(DataType) * Sptr->capcity);
	assert(Sptr->ptr);
	Sptr->top = 0;
}

//销毁
void DestoryStack(Stack* Sptr)
{
	free(Sptr->ptr);
	Sptr->ptr = NULL;
	Sptr->capcity = 0;
	Sptr->top = 0;
}

//扩容
void ExpandStack(Stack* Sptr)
{
	if (Sptr->top >= Sptr->capcity)
	{
		Sptr->capcity = Sptr->capcity * 2;
		DataType* Newptr = (DataType*)malloc(sizeof(DataType) * Sptr->capcity);
		for (int i = 0; i < Sptr->top; i++)
		{
			Newptr[i] = Sptr->ptr[i];
		}
		free(Sptr->ptr);
		Sptr->ptr = Newptr;
	}
}

//入栈
void AddStack(Stack* Sptr, DataType data)
{
	ExpandStack(Sptr);
	Sptr->ptr[Sptr->top] = data;
	Sptr->top++;
}

//弹栈
void DelStack(Stack* Sptr)
{
	Sptr->top--;
}

//打印栈中数据
void PrintStack(Stack* Sptr)
{
	for (int i = 0; i < Sptr->top; i++)
	{
		printf("%d --> ", Sptr->ptr[i]);
	}
	printf("\n");
}