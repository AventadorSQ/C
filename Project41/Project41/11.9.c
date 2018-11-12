
#include<Aventador_SQ.h>

//优化1.0
void XuanZhuan1(char *arr, int k)
{
	char arr1[1024] = "0";
	int i = 0;
	int temp = k;
	int temp1 = temp;
	while (temp !=0)
	{
		arr1[i] = arr[i];
		i++;
		temp--;
	}
	//printf("%d\n", strlen(arr1));
	arr = &arr[temp1];
	strcat(arr, arr1);
	printf("%s\n", arr);
}

////优化2.0
void XuanZhuan2(char *arr, int k)
{
	char arr1[1024];
	strcpy(arr1, arr);
	arr = &arr[k];
	//printf("%s\n", arr);
	strncat(arr, arr1, k);
	printf("%s\n", arr);
}

int main()
{

	int k = 0;
	char arr[1024] = "0";
	int n = 0;
	printf("请输入要旋转的字符串：");
	scanf("%s%*c", arr);
	printf("请输入要旋转的次数：");
	scanf("%d", &k);
	n = k % strlen(arr);
	//XuanZhuan1(arr, n);
	XuanZhuan2(arr, n);

	system("pause");
	return 0;
}
//int arr[] = { 1,2,3 };
//int *p = arr;
/*printf("%d\n", *p++);
printf("%d\n", *p++);
printf("%d\n", *p++);*/
/*printf("%d%d%d\n", *p++, *p++, *p++);*/
////喝汽水
//void num(int k)
//{
//	int total=k;
//	while (k > 1)
//	{
//		total += k / 2;
//		k = k / 2 + k % 2;
//	}
//	printf("%d\n", total);//2*k-1
//}
//int n = 0;
//scanf("%d", &n);
//num(n);
//#include<assert.h>
//char* Strcpy(char* dest, char * src)
//{
//	char* ret = dest;
//	assert(dest);
//	assert(src);
//	while (*dest++ = *src++);
//	return ret;
//}
//
//char* Strcat(char* dest, char* src)
//{
//	char* set = dest;
//	assert(dest);
//	assert(src);
//	dest = &dest[strlen(dest)];
//	while (*dest++ = *src++);
//	return set;
//}
//int main()
//{
//	char arr[] = "123456";
//	char arr1[] = "abcd";
//	char* p;
//	p = Strcat(arr, arr1);
//	p = Strcpy(arr1, arr);
//	printf("%s\n", p);
//	system("pause");
//	return 0;
//}

