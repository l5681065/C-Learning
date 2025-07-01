#include <functional>
#include <iostream>

// 定义一个返回bool类型且不接受任何参数的函数类型
typedef std::function<bool()> CanExecuteAction;

bool MyFunction()
{
	// 检查命令是否可以执行的代码
	return true;
}

int main1()
{
	// 使用std::bind将函数绑定到委托
	CanExecuteAction canExecuteDelegate = std::bind(&MyFunction);

	// 执行委托并获取返回值
	bool canExecute = canExecuteDelegate();
	std::cout << "Can execute: " << canExecute << std::endl;

	return 0;
}