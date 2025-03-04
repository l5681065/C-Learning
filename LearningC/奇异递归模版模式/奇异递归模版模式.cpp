
//奇异递归模板模式（Curiously Recurring Template Pattern，CRTP）是C++中一种利用模板和继承实现静态多态的技术。其核心思想是派生类将自己作为模板参数传递给基类，使得基类能够在编译时访问派生类的成员，从而避免运行时虚函数开销。

#include <iostream>

//CRTP的基本结构 Begin
template <typename Derived>
class Base {
public:
	void interface() {
		static_cast<Derived*>(this)->implementation(); // 静态多态调用
	}
};

class Derived : public Base<Derived> { // 派生类将自己作为模板参数
public:
	void implementation() {
		// 具体实现
	}
};
//CRTP的基本结构 End

//CRTP的实际应用场景及示例
//1. 静态多态（替代虚函数）
//虚函数会引入运行时开销，而CRTP可以在编译时绑定方法。

template <typename Derived>
class Shape {
public:
	void draw() const {
		static_cast<const Derived*>(this)->draw_impl();
	}
};

class Circle : public Shape<Circle> {
public:
	void draw_impl() const {
		std::cout << "Drawing a circle." << std::endl;
	}
};

class Square : public Shape<Square> {
public:
	void draw_impl() const {
		std::cout << "Drawing a square." << std::endl;
	}
};

// 使用模板函数实现静态派发
template <typename T>
void render(const Shape<T>& shape) {
	shape.draw();
}


int main1()
{
	Circle c;
	Square s;
	render(c); // 输出: Drawing a circle.
	render(s); // 输出: Drawing a square.
	return 0;
}

//2. 方法调用计数
//基类统计派生类方法的调用次数。
template <typename Derived>
class CallCounter {
public:
	void execute() {
		++count_;
		static_cast<Derived*>(this)->actual_execute();
	}
	static int get_count() { return count_; }
private:
	static int count_;
};

template <typename Derived>
int CallCounter<Derived>::count_ = 0;

class MyOperation : public CallCounter<MyOperation> {
public:
	void actual_execute() {
		std::cout << "Performing operation." << std::endl;
	}
};

int main2() {
	MyOperation op;
	op.execute(); // 输出: Performing operation.
	op.execute();
	std::cout << "Count: " << MyOperation::get_count() << std::endl; // 输出: Count: 2
	return 0;
}

//3. 运算符重载
//基类提供通用运算符实现，派生类仅需实现必要接口。
template <typename Derived>
class VectorBase {
public:
	Derived operator+(const Derived& other) const {
		Derived result = static_cast<const Derived&>(*this);
		for (size_t i = 0; i < result.size(); ++i) {
			result[i] += other[i];
		}
		return result;
	}
};

class Vec3 : public VectorBase<Vec3> {
public:
	Vec3(float x, float y, float z) : data_{ x, y, z } {}
	float operator[](size_t i) const { return data_[i]; }
	float& operator[](size_t i) { return data_[i]; }
	size_t size() const { return 3; }
private:
	float data_[3];
};

int main3() {
	Vec3 a(1, 2, 3), b(4, 5, 6);
	Vec3 c = a + b; // 调用基类的operator+
	std::cout << c[0] << ", " << c[1] << ", " << c[2] << std::endl; // 输出: 5, 7, 9
	return 0;
}

//4. 单例模式
//基类模板管理单例实例，派生类自动获得单例特性。
template <typename T>
class Singleton {
public:
	static T& get_instance() {
		static T instance;
		return instance;
	}
protected:
	Singleton() = default;
	Singleton(const Singleton&) = delete;
	Singleton& operator=(const Singleton&) = delete;
};

class Logger : public Singleton<Logger> {
	friend class Singleton<Logger>; // 允许基类访问私有构造函数
private:
	Logger() = default;
public:
	void log(const std::string& msg) {
		std::cout << "Log: " << msg << std::endl;
	}
};

int main() {
	Logger::get_instance().log("Hello CRTP!"); // 输出: Log: Hello CRTP!
}

