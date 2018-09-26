//*******************************************************************//
//******3. 编写程序数一下 1到 100 的所有整数中出现多少次数字9。******//
//*******************************************************************//

#define NUM 100
#include<Aventador_SQ.h>

int NineTime()
{
	int count = 0;
	int i = 0;
	int j = 0;
	for (i = 1; i <= NUM; i++)
	{
		for (j = i; j > 0; (j = j / 10))
		{
			if ((j % 10) == 9)
			{
				count++;
			}
		}
	}
	return count;
}

int main()
{
	printf("%d\n", NineTime());
	system("pause");
	return 0;
}