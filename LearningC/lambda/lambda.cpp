#include <iostream>
using namespace std;

int main()
{
	int N = 100,M = 10;

	//&M 按值捕获 可以修改M的值
	auto g = [N, &M](int i) {
		M= 20;
		//N= 11;//报错 表达式必须是可修改的左值
		return N*i;
	};
	cout <<g(10)<<endl;
	cout <<M <<endl;


	//按照捕获封闭范围内所有的变量
	auto g1 = [&](int i) {
		M = 30;
		N = 111;
		return N * i;
		};
	cout << g1(10) << endl;
	cout << M << endl;


	//按照捕获封闭范围内所有的变量
	auto g2 = [=](int i) {
		//M = 30;//报错 表达式必须是可修改的左值
		//N = 111;//报错 表达式必须是可修改的左值
		return N * i;
		};
	cout << g2(10) << endl;
	cout << M << endl;


	//混合捕获
	auto g3 = [& ,N](int i) {
		M = 40;
		//N = 111;//报错 表达式必须是可修改的左值
		return N * i;
		};
	cout << g3(10) << endl;
	cout << M << endl;
}