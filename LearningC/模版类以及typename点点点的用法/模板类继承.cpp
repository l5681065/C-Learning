

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

// ����ʾ��
template <typename T = double>
class DerivedClass : public BaseClass<T>
{
public:
	DerivedClass() : BaseClass<T>() {}
	DerivedClass(T val) : BaseClass<T>(val) {}
};

int main()
{
	DerivedClass<> derived1; // ʹ��Ĭ������ double
	DerivedClass<int> derived2(42); // ʹ��ָ������ int

	return 0;
}