#include <iostream>
#include <thread>
#include <string.h>

using namespace std;
//void myprint(const int& i, char* pmybuf)
//{
//	cout << i <<endl;//i并不是mvar的引用,实际是复制出来的值的引用(i跟mvary的地址不一样),即便主线程detach了子线程,那么子线程中用i值应该是安全的; 
//
//	cout << pmybuf << endl;//指针在detach子线程时,绝对会有问题.
//	return ;
//}

//改成下面这样可不可以? 
void myprint(const int& i, const string & pmybuf)
{
	cout << i << endl;
	cout << pmybuf.c_str() << endl;
	return;
}

int main()
{
	//一:传递临时对象作为线程参数
	int  mvar = 1;
	int &mvary = mvar;
	char mybuf[] = "test!";
	
	////mvary复制一份值给 myprint的const int& i
	//thread mytobj(myprint,mvary,mybuf	);//但是mybuf到底是什么时候转成string?
	////实事上存在mybuf都被回收了(main函数执行完了),系统才用mybuf去转string
	//所以需要改成这样
	thread mytobj(myprint, mvary, string(mybuf));//直接讲mybuf转换成string对象,这样可以保证在线程中用肯定有效的对象

	//mytobj.join();
	mytobj.detach();
	cout << "main last line" << endl;

	return 0;
}

