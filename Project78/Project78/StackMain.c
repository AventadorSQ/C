#include"Stack.h"

void TestStack()
{
	StackMin* Stack = (StackMin*)malloc(sizeof(StackMin));
	StackInit(Stack);
	StackPush(Stack, 5);
	StackPush(Stack, 6);
	StackPush(Stack, 7);
	StackPush(Stack, 8);
	StackPrint(Stack);
}

int main()
{
	TestStack();
	system("pause");
	return 0;
}