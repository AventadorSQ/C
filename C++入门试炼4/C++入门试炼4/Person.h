//��ֹͷ�ļ����ظ��������ַ�ʽ
//1.#pragma once
//2.��������ĺ�
#ifndef __PERSON__H__
#define __PERSON__H__

//��������

//#pragma once

//...
//ͷ�ļ�

class Person
{
	void SetPersonInfo(char* name, char* gender, int age);
	void PrintPersonInfo();

	char _name[1024];
	char _gender[1024];
	int _age;
};


#endif