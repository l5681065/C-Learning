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
		cout << "���ù��캯��Box��" << endl;
	}
	virtual ~Box() {
		cout << "������������Box��" << endl;
	}
	void say() {
		cout << name << "��������" << age << "���ɼ���" << score << endl;
	}
};

class BigBox : public Box
{
public:
	const char* name;
	int age;
	float score;
	BigBox() {
		cout << "���ù��캯��BigBox��" << endl;
	}
	~BigBox() {
		cout << "������������BigBox��" << endl;
	}
	void say() {
		cout << name << "��������" << age << "���ɼ���" << score << endl;
	}
};

int main()
{
// new��������ڶ����½����󣬵��ù��캯���������ظö����ָ��
	Box* box = new BigBox;
	box->name = "ss";
	box->age = 18;
	box->score = 100;
	box->say();
	// delete��������ͷŶ��ϵĶ��󣬵��ö������������
	delete box;

	getchar();
	/*
	* ���ù��캯��Box��
���ù��캯��BigBox��
ss��������18���ɼ���100
������������BigBox��
������������Box��
	*/
	return 0;
}