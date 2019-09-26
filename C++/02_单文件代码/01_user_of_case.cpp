/*======================================================
*
*����˵����	4��cast��ʹ��
*����ƽ̨��	Linux/Windows
*�������ڣ�	20190827
*��	  �ߣ�	LiuHuan
*
*======================================================*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class Building{};
class Animal{};
class Cat :public Animal{};

// 1��static_cast
void test01()
{
	int a = 97;
	int b = 98;
	char c = static_cast<char>(a);
	char d = b;
	cout << "C: " << c << ", d: " << d << endl;	// C: a, d: b

	// ������������ָ�벻��ת
	/*int* p = NULL;
	char* sp = static_cast<char*>(p);*/

	// ����ָ�� Ҳ����ת
	/*Building* building = NULL;
	Animal* animal = static_cast<Animal*>(building);*/

	// ת�����м̳й�ϵ�Ķ���ָ��
	// ��ת��	-> OK
	Animal* animal = NULL;
	Cat* cat = static_cast<Cat*>(animal);

	// ��ת�� -> OK
	Cat* cat1 = NULL;
	Animal* animal1 = static_cast<Animal*>(cat1);

	// ת�����м̳й�ϵ������
	// ��ת��
	Animal animalobj;
	Animal& aniref = animalobj;
	Cat& catref = static_cast<Cat&>(animalobj);	// OK
	// Cat& catref = static_cast<Cat&>(aniref);  // OK

	// ��ת��
	Cat catobj;
	Cat& catref1 = catobj;
	Animal& animalref1 = static_cast<Animal&>(catref1);	// OK
	//Animal& animalref1 = static_cast<Animal&>(catobj);	// OK

	// ���ۣ�static_cast�������õ���������
	// ���߾��м̳й�ϵ��ָ�������
}

// 2��dynamic_castת�����м̳й�ϵ��ָ������ã���ת��ǰ���ж������ͼ��
void test02()
{
	// ������������	-> ������
	/*int a = 10;
	char c = dynamic_cast<char>(a);*/

	// �Ǽ̳й�ϵ��ָ��	-> ������
	/*Animal* ani = NULL;
	Building* building = dynamic_cast<Building*>(ani);*/

	// ���м̳й�ϵָ��
	// ����ת����   С->�� ����ȫ�����ͼ�鲻ͨ��
	/*Animal* ani = NULL;
	Cat* cat = dynamic_cast<Cat*>(ani);*/

	// ����ת����ָ�루��С�������Ͱ�ȫ
	Cat* cat = NULL;
	Animal* ani = dynamic_cast<Animal*>(cat);

	// ���ۣ�dynamic_castֻ��ת�����м̳й�ϵ��ָ�������
	// ����ֻ��������תΪ����
}

// 3��const_cast ָ�롢���û����ָ��
void test03()
{
	// 1����������
	int a = 10;
	const int& b = a;
	int& c = const_cast<int&>(b);
	c = 20;

	cout << "a: " << a << ", b: " << b << ", c: " << c << endl;	// a: 20, b: 20, c: 20

	// 2����ָ��	
	const int* p = NULL;
	int* p2 = const_cast<int*>(p);

	int* p3 = NULL;
	const int* p4 = const_cast<const int*>(p3);
	// ���ۣ����ӻ�ȥ��������const����
}

// 4��reinterpret_cast ǿ��ת����������
typedef void(*FUNC1)(int, int);
typedef int(*FUNC2)(int, char*);
void test04()
{
	// 1���޹ص�ָ�����Ͷ����Խ���ת��
	Building* building = NULL;
	Animal* ani = reinterpret_cast<Animal*>(building);

	// 2������ָ��ת��Ҳ����
	FUNC1 func1 = NULL;
	FUNC2 func2 = reinterpret_cast<FUNC2>(func1);
}

int main()
{
	// test01();
	// test02();
	// test03();
	test04();
	getchar();
	return 0;
}