#include"BubbleSort.h"
#include<stdlib.h>

int main()
{
	int array[] = { 5,6,3,8,9,7,3 };
	//sizeָ�����ʵ�ʳ���
	int size = sizeof(array) / sizeof(array[0]);
	//���ô�ӡ�����Ƚ�δ���������ӡһ��
	PrintArray(array, size);
	//����ð������
	BubbleSortS(array, size);
	//������Ľ����ӡ����
	printf("ð������");
	PrintArray(array, size);
	system("pause");
	return 0;
}