#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdlib>
using namespace std;

class Student
{
public:
	void SetStudentInfo(char* name, char* gender, int age)
	{
		strcpy(_name, name);
		strcpy(_gender, gender);
		_age = age;
	}
	void PrintStudentInfo()
	{
		cout << _name << " " << _gender << " " << endl;
	}
	int GetAge()
	{
		return _age;
	}
public:
	char _name[1024];
	char _gender[1024];
	int _age;
};
class Stu
{};
//С�᣺
//��C++�У�������vs��ռһ���ֽ�
//��װʵ�֣���+�����޶���

//public�����������ֱ�ӱ�����
//protected��
//private������������ֱ�ӱ�����
//class��Ĭ�Ϸ���Ȩ��private
//struct��Ĭ�Ϸ���Ȩ��public������C����
//2.���������
//       ������һ���࣬������һ���µ�����
//           1.������Ҫ����Ա�������������ֺ����б�������һ��
//           2.���еĳ�Ա���������о���ȫ�ֵ�����
//3.���ʵ����
// �ࡪ��>ʵ��������>����
//4.������ģ��
//   1.ֱ�ӿ��������˳�Ա����+��Ա����
//   2.���ã�����ͬһ����Ա��������ָ�롪��>�洢���еĳ�Ա����
//                                 ���еĳ�Ա����
//   3.ʵ�ʶ���ģ�ͣ���Ͷ��󣩣��������еġ���Ա����
//   4.�����һ����Ĵ�С��
//    ֻ�����еĳ�Ա������ӣ�ע���ڴ���룩
//    ���ࣺ�����������У������С1��Ϊ���ֲ�ͬ�Ķ���
//   5.thisָ��
//       1.C��ʽ��������β���һ���ṹ�壺��Ҫ�ṹ��ĵ�ַ

int main()
{
	Stu s2;
	Student s1;
	cout << sizeof(s2) << endl;
	cout << sizeof(s1) << endl;
	system("pause");
	return 0;
}