#pragma once
//ÀàµÄÉùÃ÷
class Person
{
	void SetPersonInfo(char* name, char* gender, int age);
	void PrintPersonInfo();


	char _name[20];
	char _gender[3];
	int _age;
};
