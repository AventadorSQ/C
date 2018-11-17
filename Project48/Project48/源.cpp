


#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void zhizhen()
{
	char b;
	char* p = &b;

}

int main()
{
	FILE* fp = fopen("../文件试炼1.txt", "w+");//打开操作
	//                                  fp:"句柄"(遥控器)
	//                                                      stream：流
	//返回值=fread(缓冲区，一次的字节数，个数，fp);//读文件
	char buf[] = "hello world file";
	fwrite(buf, 1, strlen(buf), fp);
	//打开文件个数有限
	fclose(fp);
	//频繁进行打开文件，如果没有关闭叫做：“文件描述符泄露”
	FILE* fp1 = fopen("../文件试炼2.doc", "w+");
	if (fp1 == NULL)
	{
		printf("文件打开失败\n");
		return 0;
	}
	int a;
	while ((a = fgetc(stdin)) != EOF)
	{
		fputc(a, stdout);
		fputc(a, fp1);
	}
	fflush(fp1);
	fclose(fp1);
	//zhizhen();
	system("pause");
	return 0;
}



















