//void* malloc (size_t size)size1.以字节为单位2.？
//申请空间连续
//申请空间要判NULL
//参加实习：程序平时占内存50%

//free(void* ptr)
//free和malloc搭配使用

//free必须释放堆上空间，否则未定义行为
//博客总结

//内存区域
//堆
//c和C++上的区别


//calloc它与malloc区别
//1.初始化
//2.参数不同

//常用malloc
//若初始化用  new
//

//realloc
//1.后面空间够就直接扩容
//2.若后面空间不够，就需要进行搬运

//1billion（10亿） 1G
//1million （一百万）1M
//1千 1K

//指针越界，数组越界均为未定义行为
//
//针对malloc申请出的内存进行释放是，如果地址不是malloc申请的位置，就是未定义行为
//
//int* p=(int*)malloc(100)
//p++;
//free(p);

//重复释放未定义行为

//野指针
//指针指向已经被释放的内存

//内存泄漏
//没有及时free
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