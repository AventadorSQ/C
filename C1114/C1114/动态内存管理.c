//void* malloc (size_t size)size1.���ֽ�Ϊ��λ2.��
//����ռ�����
//����ռ�Ҫ��NULL
//�μ�ʵϰ������ƽʱռ�ڴ�50%

//free(void* ptr)
//free��malloc����ʹ��

//free�����ͷŶ��Ͽռ䣬����δ������Ϊ
//�����ܽ�

//�ڴ�����
//��
//c��C++�ϵ�����


//calloc����malloc����
//1.��ʼ��
//2.������ͬ

//����malloc
//����ʼ����  new
//

//realloc
//1.����ռ乻��ֱ������
//2.������ռ䲻��������Ҫ���а���

//1billion��10�ڣ� 1G
//1million ��һ����1M
//1ǧ 1K

//ָ��Խ�磬����Խ���Ϊδ������Ϊ
//
//���malloc��������ڴ�����ͷ��ǣ������ַ����malloc�����λ�ã�����δ������Ϊ
//
//int* p=(int*)malloc(100)
//p++;
//free(p);

//�ظ��ͷ�δ������Ϊ

//Ұָ��
//ָ��ָ���Ѿ����ͷŵ��ڴ�

//�ڴ�й©
//û�м�ʱfree
//1.
//2.

#include<Aventador_SQ.h>


void Print()
{
	int arr[] = { 1,2,3 };
	int* p = arr;
	//setbuf("stdout,NULL");
	printf("%d\n%d\n%d\n", *p++, *p++, *p++);
}

void GetMemory(char* p)
{
	p = (char*)malloc(100);
}
void test()
{
	char a[1024];
	char *str = a;
	GetMemory(str);
	strcpy(str, "hello world");
	printf(str);
}
int main()
{
	test();
	//Print();
	system("pause");
	return 0;
}