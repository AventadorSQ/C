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
	printf("如需说明请输入数字0\n");
	while (1)
	{
		printf("请输入：\n");
		scanf("%d", &num);
		count++;
		if (0 == num)
		{
			printf("输入1现实当前系统日期，输入2显示当前系统时间，输入其它任意字符，则退出查询\n");
		}
		else if (1 == num)
		{
			printf("当前系统日期:\n");
			printf("%d-%d-%d\n", systime->tm_year + 1900, systime->tm_mon + 1, systime->tm_mday);
		}
		else if (2 == num)
		{
			printf("当前系统时间:\n");
			printf("%d:%d:%d\n", systime->tm_hour, systime->tm_min, systime->tm_sec);
		}
		else
		{
			if (count < 2)
			{
				goto data;
			}
			printf("退出查询\n");
			break;
		}
	}
	system("pause");
	return 0;
}