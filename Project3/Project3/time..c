//*******************************************************************//
//******3. ��д������һ�� 1�� 100 �����������г��ֶ��ٴ�����9��******//
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