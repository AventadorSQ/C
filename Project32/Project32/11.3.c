#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
	int array[] = { 0,1,2};
	int num,count=0;
	struct tm *systime;
	time_t nowtime;
	time(&nowtime);
	systime = localtime(&nowtime);
	data:
	printf("����˵������������0\n");
	while (1)
	{
		printf("�����룺\n");
		scanf("%d", &num);
		count++;
		if (0 == num)
		{
			printf("����1��ʵ��ǰϵͳ���ڣ�����2��ʾ��ǰϵͳʱ�䣬�������������ַ������˳���ѯ\n");
		}
		else if (1 == num)
		{
			printf("��ǰϵͳ����:\n");
			printf("%d-%d-%d\n", systime->tm_year + 1900, systime->tm_mon + 1, systime->tm_mday);
		}
		else if (2 == num)
		{
			printf("��ǰϵͳʱ��:\n");
			printf("%d:%d:%d\n", systime->tm_hour, systime->tm_min, systime->tm_sec);
		}
		else
		{
			if (count < 2)
			{
				goto data;
			}
			printf("�˳���ѯ\n");
			break;
		}
	}
	system("pause");
	return 0;
}