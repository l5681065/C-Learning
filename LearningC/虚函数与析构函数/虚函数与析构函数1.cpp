#include <iostream>
#include <string.h>
using namespace std;

class Box
{
public:
	const char* name;
	int age;
	float score;
	Box() {
		cout << "调用构造函数Box！" << endl;
	}
	virtual ~Box() {
		cout << "调用析构函数Box！" << endl;
	}
	void say() {
		cout << name << "的年龄是" << age << "，成绩是" << score << endl;
	}
};

class BigBox : public Box
{
public:
	const char* name;
	int age;
	float score;
	BigBox() {
		cout << "调用构造函数BigBox！" << endl;
	}
	~BigBox() {
		cout << "调用析构函数BigBox！" << endl;
	}
	void say() {
		cout << name << "的年龄是" << age << "，成绩是" << score << endl;
	}
};

int main()
{
// new运算符，在堆上新建对象，调用构造函数，并返回该对象的指针
	Box* box = new BigBox;
	box->name = "ss";
	box->age = 18;
	box->score = 100;
	box->say();
	// delete运算符，释放堆上的对象，调用对象的析构函数
	delete box;

	getchar();
	/*
	* 调用构造函数Box！
调用构造函数BigBox！
ss的年龄是18，成绩是100
调用析构函数BigBox！
调用析构函数Box！
	*/
	return 0;
}