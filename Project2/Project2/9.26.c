//*****************************************************************//
//******2. 计算1/1-1/2+1/3-1/4+1/5 …… + 1/99 - 1/100 的值。******//
//*****************************************************************//
#include<Aventador_SQ.h>

void Price(int num)
{
	int i = 0;
	double temp = 0;
	double price = 0;
	for (i = 1; i <= num; i++)
	{
		if (i % 2 == 0)
		{
			temp = (1 /(double) i)*(-1);//必须进行强制类型转换，否则只能为0（按整形运算）
		}
		else
		{
			temp = (1 / (double)i);
		}
		price = price + temp;
	}
	printf("%f\n", price);
}
int main()
{
	int num = 0;
	printf("输入num的值：\n");
	scanf("%d", &num);
	Price(num);//调用函数求值
	system("pause");
	return 0;
}