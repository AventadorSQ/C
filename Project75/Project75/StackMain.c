#include"Stack.h"

int main()
{
	Stack Sta;
	InitStack(&Sta);

	//»Î’ª
	AddStack(&Sta, 11);
	AddStack(&Sta, 22);
	AddStack(&Sta, 33);
	AddStack(&Sta, 66);
	PrintStack(&Sta);

	//µØ’ª
	DelStack(&Sta);
	PrintStack(&Sta);
	DelStack(&Sta);
	PrintStack(&Sta);
	system("pause");
	return 0;
}