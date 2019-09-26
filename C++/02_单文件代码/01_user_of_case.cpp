/*======================================================
*
*程序说明：	4种cast的使用
*运行平台：	Linux/Windows
*创建日期：	20190827
*作	  者：	LiuHuan
*
*======================================================*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class Building{};
class Animal{};
class Cat :public Animal{};

// 1、static_cast
void test01()
{
	int a = 97;
	int b = 98;
	char c = static_cast<char>(a);
	char d = b;
	cout << "C: " << c << ", d: " << d << endl;	// C: a, d: b

	// 基础数据类型指针不能转
	/*int* p = NULL;
	char* sp = static_cast<char*>(p);*/

	// 对象指针 也不能转
	/*Building* building = NULL;
	Animal* animal = static_cast<Animal*>(building);*/

	// 转换具有继承关系的对象指针
	// 父转子	-> OK
	Animal* animal = NULL;
	Cat* cat = static_cast<Cat*>(animal);

	// 子转父 -> OK
	Cat* cat1 = NULL;
	Animal* animal1 = static_cast<Animal*>(cat1);

	// 转换具有继承关系的引用
	// 父转子
	Animal animalobj;
	Animal& aniref = animalobj;
	Cat& catref = static_cast<Cat&>(animalobj);	// OK
	// Cat& catref = static_cast<Cat&>(aniref);  // OK

	// 子转父
	Cat catobj;
	Cat& catref1 = catobj;
	Animal& animalref1 = static_cast<Animal&>(catref1);	// OK
	//Animal& animalref1 = static_cast<Animal&>(catobj);	// OK

	// 结论：static_cast用于内置的数据类型
	// 或者具有继承关系的指针或引用
}

// 2、dynamic_cast转换具有继承关系的指针或引用，在转换前进行对象类型检查
void test02()
{
	// 基础数据类型	-> 不可以
	/*int a = 10;
	char c = dynamic_cast<char>(a);*/

	// 非继承关系的指针	-> 不可以
	/*Animal* ani = NULL;
	Building* building = dynamic_cast<Building*>(ani);*/

	// 具有继承关系指针
	// 父类转子类   小->大 不安全，类型检查不通过
	/*Animal* ani = NULL;
	Cat* cat = dynamic_cast<Cat*>(ani);*/

	// 子类转父类指针（大到小），类型安全
	Cat* cat = NULL;
	Animal* ani = dynamic_cast<Animal*>(cat);

	// 结论：dynamic_cast只能转换具有继承关系的指针或引用
	// 而且只能由子类转为父类
}

// 3、const_cast 指针、引用或对象指针
void test03()
{
	// 1、基础类型
	int a = 10;
	const int& b = a;
	int& c = const_cast<int&>(b);
	c = 20;

	cout << "a: " << a << ", b: " << b << ", c: " << c << endl;	// a: 20, b: 20, c: 20

	// 2、看指针	
	const int* p = NULL;
	int* p2 = const_cast<int*>(p);

	int* p3 = NULL;
	const int* p4 = const_cast<const int*>(p3);
	// 结论：增加或去除变量的const属性
}

// 4、reinterpret_cast 强制转换所有类型
typedef void(*FUNC1)(int, int);
typedef int(*FUNC2)(int, char*);
void test04()
{
	// 1、无关的指针类型都可以进行转换
	Building* building = NULL;
	Animal* ani = reinterpret_cast<Animal*>(building);

	// 2、函数指针转换也可以
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