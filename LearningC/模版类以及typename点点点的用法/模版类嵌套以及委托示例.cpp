#include <iostream>
#include <functional>
#include <type_traits>

// 定义一个默认的用户策略
struct FDefaultUserPolicy {
	using FDelegateInstanceExtras = int; // 示例类型
};

// 定义一个基础的委托注册类
template <typename DelegateSignature, typename UserPolicy = FDefaultUserPolicy>
class TDelegateRegistration;

template <typename InRetValType, typename... ParamTypes, typename UserPolicy>
class TDelegateRegistration<InRetValType(ParamTypes...), UserPolicy> {
public:
	using FuncType = std::function<InRetValType(ParamTypes...)>;

	void Bind(FuncType InFunc) {
		Func = InFunc;
	}

	InRetValType Execute(ParamTypes... Params) const {
		if (Func) {
			return Func(Params...);
		}
		throw std::runtime_error("Delegate not bound");
	}

private:
	FuncType Func;
};

// 定义一个委托类，继承自 TDelegateRegistration
template <typename DelegateSignature, typename UserPolicy = FDefaultUserPolicy>
class TDelegate;

template <typename InRetValType, typename... ParamTypes, typename UserPolicy>
class TDelegate<InRetValType(ParamTypes...), UserPolicy> : public TDelegateRegistration<InRetValType(ParamTypes...), UserPolicy> {
public:
	using Super = TDelegateRegistration<InRetValType(ParamTypes...), UserPolicy>;

	/*
	然而，using Super::Bind; 的作用是显式地将基类的 Bind 方法引入到派生类的公共接口中。这么做有以下几个好处：
	1.	明确性：显式地引入基类的方法可以让代码更清晰，明确指出哪些基类的方法在派生类中是公开的。
	2.	避免隐藏：如果派生类中定义了与基类同名的方法，基类的方法会被隐藏。使用 using 语句可以避免这种情况。
	*/
	using Super::Bind;
	using Super::Execute;
};

// 示例使用
int main() {
	TDelegate<void(int), FDefaultUserPolicy> MyDelegate;
	MyDelegate.Bind([](int Value) {
		std::cout << "Value: " << Value << std::endl;
		});

	MyDelegate.Execute(42);

	return 0;
}