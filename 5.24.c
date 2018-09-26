#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	char ster[50] = { 0 };
	printf("请输入密码:");
	scanf("%s", ster);
	int i = 0;
	for (i = 0; i < 3; i++)
	{
		if (strcmp("yidingbu!", ster) == 0)
		{
			break;
		}
		else
		{
			printf("密码输入错误!!!\n");
			printf("请再次输入:");
		}
	}
	if (i < 3)
	{
		printf("登录成功\n");
	}
	else
	{
		printf("请五分钟后再次登录\n");
	}
	system("pause");
	return 0;
}