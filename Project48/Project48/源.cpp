


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
	FILE* fp = fopen("../�ļ�����1.txt", "w+");//�򿪲���
	//                                  fp:"���"(ң����)
	//                                                      stream����
	//����ֵ=fread(��������һ�ε��ֽ�����������fp);//���ļ�
	char buf[] = "hello world file";
	fwrite(buf, 1, strlen(buf), fp);
	//���ļ���������
	fclose(fp);
	//Ƶ�����д��ļ������û�йرս��������ļ�������й¶��
	FILE* fp1 = fopen("../�ļ�����2.doc", "w+");
	if (fp1 == NULL)
	{
		printf("�ļ���ʧ��\n");
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



















