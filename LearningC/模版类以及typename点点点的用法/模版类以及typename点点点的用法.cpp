//#include <iostream>
//#include <string>
//
//template <typename... Args>
//class MyClass
//{
//public:
//	void PrintAll(Args... args)
//	{
//		(std::cout << ... << args) << std::endl; // 使用折叠表达式打印所有参数
//	}
//};
//
//int main()
//{
//	MyClass<int, double, std::string> myClass;
//	myClass.PrintAll(1, 2.5, "Hello");
//	return 0;
//}