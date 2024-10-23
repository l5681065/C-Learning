// 二级指针.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
#include <iostream>
using namespace std;

int& funcA()
{
	int * a = new int(100);
	return  *a;
}

int main()
{

	int* a1[2] = {new int(0),new int (10)};
	int** b1 = a1;

	int * c =  b1[1];
	cout << *c << endl;//10

	int * d = &funcA();
	cout << *d << endl;
}
