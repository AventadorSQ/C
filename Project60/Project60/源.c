#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

void Test1()
{
	int num = 9;
	float* pfloat = (float*)&num;
	printf("num=%d\n", num);
	printf("*pfloat=%f\n", *pfloat);

	*pfloat = 9.0;
	printf("num=%d\n", num);
	printf("*pfloat=%f\n", *pfloat);
}

//�ص�������һ��ͨ������ָ����õĺ����������Ѻ�����ָ�루��ַ����Ϊ�������ݸ���һ�������������ָ�뱻������������ָ��ĺ���
//�ص����������ɸú�����ʵ�ַ�ֱ�ӵ��ã��������ض����¼�����������ʱ������һ�����ã����ڶԸ��¼�������������Ӧ
int int_cmp(const void* p1, const void* p2)
{
	return (*(int*)p1 > *(int*)p2);
}
void Test2()
{
	int arr[] = { 1,3,5,7,9,2,4,6,8,0 };
	int i = 0;
	qsort(arr, sizeof(arr) / sizeof(arr[0]), sizeof(int), int_cmp);
	for (i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
int main()
{
	Test1();
	//�ص�����
	Test2();
	system("pause");
	return 0;
}