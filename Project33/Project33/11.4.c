//—°‘Ò≈≈–Ú∑®
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int array[10];
	int i, j;
	int point = 0;
	int sign = 0;

	for (i = 0; i < 10; i++)
	{
		printf("array[%d]=", i);
		scanf("%d", &array);
	}

	for (i = 0; i < 9; i++)
	{
		point = array[i];
		sign = i;
		for (j = sign + 1; j < 10; j++)
		{
			if (point > array[j])
			{
				point = array[j];
				sign = j;
			}
		}
		array[sign] = array[i];
		array[i] = point;
	}

	for (i = 0; i < 10; i++)
	{
		printf("%d\t", array[i]);
	}
	system("pause");
	return 0;
}