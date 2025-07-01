#include <iostream>

void modify1(int* p) {
	*p = 100;
}

int main1() {
	const int a = 10;
	const int * pa1 = &a;
	//modify(&pa1); // 错误：不能直接传递 const int* 给 int*

	// 正确：使用 const_cast 去除 const
	modify1(const_cast<int*>(pa1));
	
	std::cout << a << std::endl; // 未定义行为，a 是 const
	//注意：如果原始对象本身是 const（如上例），通过 const_cast 修改它会导致未定义行为。
	//只有当原始对象本身不是 const，只是通过 const 指针 / 引用访问时，才可以安全地去除 const 并修改。
	//因此这个例子只是说明这么做可以通过编译,

	return 0;
}


void modify(int* p) {
	*p = 100;
}

int main() {
	int b = 10;                // 原始对象不是 const
	const int* pb = &b;        // 通过 const 指针访问 . 注意 int* 可以隐式转换成 const int *   但是const int* → int*：不能隐式转换，需 const_cast，且有风险。

	modify(const_cast<int*>(pb)); // 安全：b 本身不是 const

	std::cout << b << std::endl; // 输出 100，修改成功且无未定义行为

	return 0;
}