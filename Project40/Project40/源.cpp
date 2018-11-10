#include<Aventador_SQ.h>
int main()
{
	typedef struct stu {
		char c1='c';
		char c2='z';
		int i=1;
	}s;

	printf("%d\n", sizeof(s));
	system("pause");
	return 0;
}