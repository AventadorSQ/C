//#include<Aventador_SQ.h>
//
//int  Fibonacci(int n)
//{
//	if (1 == n|| 2 == n)
//	{
//		return 1;
//	}
//	else
//	{
//		return Fibonacci(n - 1) + Fibonacci(n - 2);
//	}
//}
//int main()
//{
//	int n = 0;//��ȡ��n����
//	int	a = 0;//�������
//	scanf("%d", &n);
//	a=Fibonacci(n);
//	printf("��%d������%d\n",n,a);
//	system("pause");
//	return 0;
//}
//
////#include<Aventador_SQ.h>
////
////int Fibonacci(unsigned int x)
////{
////	if (x <= 0)
////	{
////		return 0;
////	}
////	if (x == 1)
////	{
////		return 1;
////	}
////	else
////	{
////		return Fibonacci(x - 1) + Fibonacci(x - 2);
////	}
////}
////int main()
////{
////	int n = 0;
////	//	scanf("%d", &n);
////	Fibonacci(n);
////	for (; n = n + 1;)
////		printf("��%d������%d\n", n, Fibonacci(n));
////	system("pause");
////	return 0;
////}
//
//���쳲�������ʱ�临�Ӷ�ΪO(n)=log n

#include<Aventador_SQ.h>

void Fibonacci(int x)
{
	int FFiboZero = 0, FiboZero = 0;
	int FFiboOne = 1, FiboOne = 1;
	int FFiboTwo = 1, FiboTwo = 1;
	int FiboN = 0;

	int i = 0;
	for (i = 2; i <= (x / 2); i++)
	{
		FiboN = FFiboTwo * FiboTwo + FFiboOne * FiboOne;//���þ���������������
		//���н����ﵽ�ƶ��м����
		FFiboZero = FFiboOne;
		FFiboOne = FFiboTwo;
		FFiboTwo = FiboN;
	}
	FiboN = FFiboTwo * FFiboTwo + FFiboOne * FFiboOne;//�õ����յ�����ȡ����
	printf("%d\t%d\n", x, FiboN);
}

void JFibonacci(int x)
{
	int FFiboZero = 0, FiboZero = 0;
	int FFiboOne = 1, FiboOne = 1;
	int FFiboTwo = 1, FiboTwo = 1;
	int FiboN = 0;

	int i = 0;
	for (i = 2; i <= ((x - 1) / 2); i++)
	{
		FiboN = FFiboTwo * FiboTwo + FFiboOne * FiboOne;
		FFiboZero = FFiboOne;
		FFiboOne = FFiboTwo;
		FFiboTwo = FiboN;
	}
	//�������λ��������ʱҪ���������������
	FiboN = FFiboTwo * FFiboTwo + FFiboOne * FFiboOne;
	FFiboTwo = FFiboTwo * FFiboOne + FFiboOne * FFiboZero;
	FiboN = FiboN * FiboTwo + FFiboTwo * FiboOne;
	printf("%d\t%d\n", x, FiboN);
}

int main()
{
	int n = 0;
	printf("nλ��:");
	scanf("%d", &n);
	if (n % 2 == 0)
	{
		JFibonacci(n);//n���Ա�2����
	}
	else
	{
		Fibonacci(n);//n���ܱ�2����
	}
	system("pause");
	return 0;
}

//#include<Aventador_SQ.h>
//
//void Fibonacci(int x)
//{
//	if (x < 1)
//	{
//		printf("�������!!!\n");
//	}
//	else if (x < 3)
//	{
//		printf("��%d������1\n", x );
//	}
//	else
//	{
//		int FiboOne = 1;
//		int FiboTwo = 1;
//		int FiboN = 0;
//		int i=0;
//		for (i = 3; i <= x; i++)
//		{
//			FiboN = FiboOne + FiboTwo;
//			FiboOne = FiboTwo;
//			FiboTwo = FiboN;
//			//printf("%d\t%d\n", i, FiboN);
//		}
//		printf("��%d������%d\n", x, FiboN);
//	}
//}
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	Fibonacci(n);
//	system("pause");
//	return 0;
//}
