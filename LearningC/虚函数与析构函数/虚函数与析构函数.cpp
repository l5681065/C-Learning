//// 虚函数与析构函数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
////
//
//#include <iostream>
//#include <string.h>
//using namespace std;
//
//class People {
//protected:
//    string RaceName;
//public:
//
//    //virtual People(const string& name) :RaceName(name)
//    /*https://zhuanlan.zhihu.com/p/365463954
//1、为什么构造函数不可以是虚函数
// ①从存储空间角度
//
//虚函数对应一个vtable，这大家都知道，可是这个vtable其实是存储在对象的内存空间的。问题出来了，如果构造函数是虚的，就需要通过 vtable来调用，可是对象还没有实例化，也就是内存空间还没有，无法找到vtable，所以构造函数不能是虚函数。
//
//②从使用角度
//
//虚函数的作用在于通过父类的指针或者引用来调用它的时候能够变成调用子类的那个成员函数。而构造函数是在创建对象时自动调用的，不可能通过父类的指针或者引用去调用，因此也就规定构造函数不能是虚函数。
//
//2、为什么析构函数可以是虚函数
//编译器总是根据类型来调用类成员函数。一个派生类的指针可以安全地转化为一个基类的指针。这样删除一个基类的指针的时候，C++不管这个指针指向一个基类对象还是一个派生类的对象，调用的都是基类的析构函数而不是派生类的。如果你依赖于派生类的析构函数的代码来释放资源，而没有重写析构函数，那么会有资源泄漏。
//
//所以建议的方式是将析构函数声明为虚函数。一个函数一旦声明为虚函数，那么不管你是否加上virtual 修饰符，它在所有派生类中都成为虚函数。但是由于理解明确起见，建议的方式还是加上virtual 修饰符。
//
//C++不把虚析构函数直接作为默认值的原因是虚函数表的开销以及和C语言的类型的兼容性。有虚函数的对象总是在开始的位置包含一个隐含的虚函数表指针成员。
//        */
//    People(const string& name) :RaceName(name)
//    {
//
//    }
//
//    virtual ~People()
//    {
//        cout << "People Destructor " << endl;
//    }
//
//    virtual void Run()
//    {
//        cout << "People Run" << endl;
//    }
//
//};
//
///*
//*class BlackMen :public People  这行必须加public,不加public  默认是私有继承
//* 默认继承的话 代码里    People &people1 = blackMen;这句话会报错
//* error C2243: “类型强制转换”: 从“BlackMen *”到“People &”的转换存在，但无法访问
//* https://www.cnblogs.com/fly-smart/p/17554126.html
//*/
//class BlackMen :public People
//
//{
//public:
//    BlackMen() :People("BlackMen")
//    {
//    }
//    void Run() override
//    {
//        cout << "BlackMen Run" << endl;
//    }
//
//    ~BlackMen()
//    {
//        cout << "BlackMen Destructor" << endl;
//    }
//};
//
//
//
//int main_1()
//{
//    BlackMen  blackMen;
//    People& people1 = blackMen;
//    People* people2 = &blackMen;
//    blackMen.Run();
//    people1.Run();
//    people2->Run();
//    return 0;
//}
//
//
//class Box
//{
//public:
//    const char* name;
//    int age;
//    float score;
//    Box() {
//        cout << "调用构造函数Box！" << endl;
//    }
//    ~Box() {
//        cout << "调用析构函数Box！" << endl;
//    }
//    void say() {
//        cout << name << "的年龄是" << age << "，成绩是" << score << endl;
//    }
//};
//
//class BigBox : public Box
//{
//public:
//    const char* name;
//    int age;
//    float score;
//    BigBox() {
//        cout << "调用构造函数BigBox！" << endl;
//    }
//    ~BigBox() {
//        cout << "调用析构函数BigBox！" << endl;
//    }
//    void say() {
//        cout << name << "的年龄是" << age << "，成绩是" << score << endl;
//    }
//};
//
//
//
//
//int main_2()
//{
//    // new运算符，在堆上新建对象，调用构造函数，并返回该对象的指针
//    Box* box = new BigBox;
//    box->name = "ss";
//    box->age = 18;
//    box->score = 100;
//    box->say();
//    // delete运算符，释放堆上的对象，调用对象的析构函数
//    delete box;
//
//    getchar();
//    /*
//调用构造函数Box！
//调用构造函数BigBox！
//ss的年龄是18，成绩是100
//调用析构函数Box！
//
//BigBox继承Box，Box*基类指针指向了派生类对象，但调用delete box时，却是调用的基类的析构函数！这时，由于没有重写析构函数，产生了资源泄漏。
//只需要把基类的析构函数变成虚函数，就可以调用派生类的析构函数了。
//*/
//    return 0;
//}
//
