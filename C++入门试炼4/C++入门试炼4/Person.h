//防止头文件被重复包含两种方式
//1.#pragma once
//2.条件编译的宏
#ifndef __PERSON__H__
#define __PERSON__H__

//二者区别：

//#pragma once

//...
//头文件

class Person
{
	void SetPersonInfo(char* name, char* gender, int age);
	void PrintPersonInfo();

	char _name[1024];
	char _gender[1024];
	int _age;
};


#endif