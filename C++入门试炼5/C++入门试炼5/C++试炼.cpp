//*********************************************************************
//******             在C++中class和struct的区别：                ******
//*********************************************************************
//在类和对象中
//struct 默认访问权限为public属性（目的兼容C语言）
//class 默认为访问权限private属性
//*********************************************************************

//*********************************************************************
//******                C语言和C++中struct区别                   ******
//*********************************************************************
//C++中可以放函数
//struct定义的成员变量前可以加访问限定符
//*********************************************************************
//C++三大特性（封装，继承，多态）之：封装
//封装：将数据和操作数据的方法进行有机结合，隐藏对象的属性和实现细节，仅对外公开接口和对象来进行交互
//      就是把数据和其相应的方法进行结合，隐藏其具体过程只对外公开接口和对象
#define _CRT_SECURE_NO_WARNINGS
#include"Student.h"
#include<iostream>

using namespace std;

int main()
{
	Student s1, s2, s3;
	s1.SetStudentInfo("Jack", "男", 18);
	s2.SetStudentInfo("静静", "女", 18);
	s3.SetStudentInfo("强子", "男", 7);
	s1.PrintStudentInfo();
	s2.PrintStudentInfo();
	s3.PrintStudentInfo();
	//s1.SetStudentInfo("Jack", "男", 19);//为何_age定为私有属性依旧能访问修改？
	//s1.PrintStudentInfo();
	s3.Getage();

	Ints a;
	Ints* pa = &a;
	int* pa1 = (int*)((int)&a + 8);
	int* pa2 = (int*)((int)&a + offsetof(Ints, z));
	*pa1 = 10;
	*pa2 = 20;
	//pa1 = (int*)((int)&s3 + offsetof(Student, _age));
	system("pause");
	return 0;
}

//*********************************************************************
//******                   offsetof宏功能                        ******
//*********************************************************************