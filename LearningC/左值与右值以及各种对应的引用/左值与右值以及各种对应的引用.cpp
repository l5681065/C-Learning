
#include <iostream>

void PrintLValue(int& x) {
	std::cout << "左值引用: " << x << std::endl;
}

void PrintRValue(int&& x) {
	std::cout << "右值引用: " << x << std::endl;
}

int main()
{

	//左值与右值的基本概念
	
	//左值：
	//定义：有明确内存地址、可长期存在的对象（可出现在赋值号左侧）.可以取地址的值，通常是变量或对象的引用.
	//特点:有标识符（变量名）,可获取地址（& 操作）,生命周期超出单个表达式

	int a = 10;   // a 是左值
	int* p = &a;  // 可以取地址
	
	//右值：不能取地址的值，通常是临时对象或字面量
	int b = 20;   // 20 是右值
	int c = a + b; // (a + b) 结果是右值
	//int* p = &(a + b); // 错误，不能对右值取地址

	//左值引用：可以绑定到左值的引用
	int x = 5;
	int& ref = x; // ref 是 x 的左值引用
	ref = 10;     // x 变成 10
	//int& ref2 = 100; // 错误，不能将字面量绑定到左值引用

	//右值引用：可以绑定到右值的引用，通常用于移动语义和完美转发
	int&& rref = 100; // rref 绑定到右值 100
	rref = 200;       // rref 现在是 200

	int&& rref2 = x + 1; // x + 1 是右值
	//int&& rref3 = x; // 错误，不能将左值绑定到右值引用


	a = 10;//重置a的值
	PrintLValue(a);      // 传递左值
	// PrintLValue(20);  // 错误，20是右值，不能绑定到左值引用

	PrintRValue(20);     // 传递右值
	// PrintRValue(a);   // 错误，a是左值，不能绑定到右值引用


	PrintRValue(std::move(a)); // std::move将a转为右值引用
}

