#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

//改变默认对齐方式的值（两种方式）
//1. #pragma pack(num)
//2. 编译器中 项目 -> 属性 -> C/C++ -> 代码生成 -> 结构体成员对齐 ->修改默认值
//   注意是2的n次方倍（1，2, 4, 8, 16, 32） 改为6之类是不可以的

//结构体对齐：
//1. 结构体中每个成员要放在一个对齐的地址上
//2. 结构体整体对齐
//          （找成员类型最大，默认对齐数）


//详解结构体内存对齐规则
//1. 第一个成员在与结构体偏移量为0的地址处。
//2. 其他变量成员要对齐到某个数字（对齐数）的整数倍的地址处。
//     注意：对齐数=编译器默认的一个对齐数与该成员大小的较小值。
//           VS中默认的对齐数为8，gcc中的对齐数为4
//3. 结构体总大小为：最大对齐数（所有变量类型最大者与默认对齐参数取最小）的整数倍。
//4. 如果嵌套了结构体的情况，嵌套的结构体对齐到自己的最大对齐数的整数倍，结构体的整体大小就是所有最大对齐数（含嵌套结构体的对齐数）的整数倍。


 struct Struct
{
	 int a;
	 char b;
	 double c;
	 char d;
 };
int main()
{
	Struct();
	system("pause");
	return 0;
}