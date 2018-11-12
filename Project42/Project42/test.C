#include<stdint.h>
#include<Aventador_SQ.h>

//模拟实现memcpy
void* Memcpy(void* dest, void* src, size_t count)
{
	void* ret = dest;
	while (count--)
	{
		*(char*)dest = *(char*)src;
		dest = (char*)dest + 1;
		src = (char*)src + 1;
	}
	return ret;
}

//模拟实现memmove
void* Memmove(void* dest, void* src, size_t count)
{
	void* ret = dest;
	if (dest <= src || (char*)dest >= (char*)src + count)
	{
		while (count--)
		{
			*(char*)dest = *(char*)src;
			dest = (char*)dest + 1;
			src = (char*)src + 1;
		}
	}
	else
	{
		dest = (char*)dest + count - 1;
		src = (char*)src + count - 1;
		while (count--)
		{
			*(char*)dest = *(char*)src;
			dest = (char*)dest + 1;
			src = (char*)src + 1;
		}
	}
	return ret;
}

int main()
{
	char arr[] = "2jin2gmin8gzhen";
	char arr1[1024] = "0";
	int x = strlen(arr);
	char* p=Memcpy(arr1, arr, x);
	printf("%s\n", p);
	printf("%s\n", arr);
	char* p1 = Memmove(arr1, arr, x);
	printf("%s\n", p1);
	printf("%s\n", arr1);
	system("pause");
	return 0;
}
////
//union IP {
//	uint32_t ip;
//	struct {
//		uint8_t a;
//		uint8_t b;
//		uint8_t c;
//		uint8_t d;
//	} ip_;
//};
//union IP ip;
//ip.ip = 0x12345678;
//printf("%d.%d.%d.%d\n", ip.ip_.a, ip.ip_.b, ip.ip_.c, ip.ip_.d);