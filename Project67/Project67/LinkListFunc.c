#include "LinkList.h"
#include<string.h>

void ZiFuChuan()
{
	char arr[4] = "abcd";
	printf("%s\n", arr);
	printf("%d\n", sizeof(arr));
	printf("%d\n", sizeof(&arr));
	printf("%d\n", sizeof(*arr));
	printf("%d\n", strlen(arr));
}