#include <iostream>
#include <functional>
#include <type_traits>

// ����һ��Ĭ�ϵ��û�����
struct FDefaultUserPolicy {
	using FDelegateInstanceExtras = int; // ʾ������
};

// ����һ��������ί��ע����
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

// ����һ��ί���࣬�̳��� TDelegateRegistration
template <typename DelegateSignature, typename UserPolicy = FDefaultUserPolicy>
class TDelegate;

template <typename InRetValType, typename... ParamTypes, typename UserPolicy>
class TDelegate<InRetValType(ParamTypes...), UserPolicy> : public TDelegateRegistration<InRetValType(ParamTypes...), UserPolicy> {
public:
	using Super = TDelegateRegistration<InRetValType(ParamTypes...), UserPolicy>;

	/*
	Ȼ����using Super::Bind; ����������ʽ�ؽ������ Bind �������뵽������Ĺ����ӿ��С���ô�������¼����ô���
	1.	��ȷ�ԣ���ʽ���������ķ��������ô������������ȷָ����Щ����ķ��������������ǹ����ġ�
	2.	�������أ�����������ж����������ͬ���ķ���������ķ����ᱻ���ء�ʹ�� using �����Ա������������
	*/
	using Super::Bind;
	using Super::Execute;
};

// ʾ��ʹ��
int main() {
	TDelegate<void(int), FDefaultUserPolicy> MyDelegate;
	MyDelegate.Bind([](int Value) {
		std::cout << "Value: " << Value << std::endl;
		});

	MyDelegate.Execute(42);

	return 0;
}