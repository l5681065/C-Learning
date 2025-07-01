

template<typename ThreadSafetyMode>
class TDelegateBase:public TDelegateAccessHandlerBase<ThreadSafetyMode>, private FDelegateAllocation
{
	
};

struct FDefaultDelegateUserPolicy
{
	using FDelegateExtras = TDelegateBase<FThreadSafetyMode>;
};


template <typename T, typename DefaultType = int>
class BaseClass
{
public:
	using ValueType = T;

	BaseClass() : value(DefaultType()) {}
	BaseClass(T val) : value(val) {}

	T GetValue() const { return value; }
	void SetValue(T val) { value = val; }

private:
	T value;
};

// 子类示例
template <typename T = double>
class DerivedClass : public BaseClass<T>
{
public:
	DerivedClass() : BaseClass<T>() {}
	DerivedClass(T val) : BaseClass<T>(val) {}
};

int main()
{
	DerivedClass<> derived1; // 使用默认类型 double
	DerivedClass<int> derived2(42); // 使用指定类型 int

	return 0;
}