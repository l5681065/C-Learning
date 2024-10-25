#include<iostream>
using namespace std;

#define formatPrint(x,format) printf(#x "=%" #format "\n",x)

#define DEBUG_ON 0

#if DEBUG_ON
#define log(fmt,...)\
	printf("file: %s  func:%s line:%d   "fmt,\
	 __FILE__,__FUNCTION__,__LINE__,__VA_ARGS__)
#else
#define log(fmt,...)
#endif // DEBUG_ON

#define args a,b
#define  F(f)  f(args)

//避免重复包含或者重定义的办法除了 #pragma once之外 还可以用如下办法
#ifndef ClassName
#define ClassName
void GlobalFunction() {
}
class ClassName {
};
#endif // !ClassName


int sum(int a, int b)
{
	return a + b;
}
const int Num_Zero = 0;
const int Num_First = 1;
const int Num_Second = 2;
const int Num_Thrid = 3;

void PrintSwitchCase(int caseIndex)
{
	switch (caseIndex)
	{
	case Num_First:cout << "First" << endl; break;
	case Num_Second:cout << "Second" << endl; break;
	case Num_Thrid:cout << "Thrid" << endl; break;
	default:
		break;
	}
}


void PrintSwitchCase_Marco(int caseIndex)
{
	switch (caseIndex)
	{
#define STR(x) #x 
#define printValueName(Value) \
	case Num_##Value:cout<<STR(Value)<<endl;break;
		printValueName(First)
			printValueName(Second)
			printValueName(Thrid)
	}
}

#define DLLEXPORT __declspec(dllexport)
#define COREUOBJECT_API DLLEXPORT

COREUOBJECT_API int Add(int a,int b)
{
	return a + b;
}

int main()
{
	const char* name = "YOYO";
	formatPrint(name, s);
	printf("name=%s\n", name);
	formatPrint(name, x);
	printf("name=%x\n", name);

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			log("i=%d j=%d\n", i, j);
			printf("file: %s  func:%s line:%d i1=%d j1=%d\n", __FILE__, __FUNCTION__, __LINE__, i, j);
		}
	}
	int a = 10, b = 20;
	int s = F(sum);
	cout << "sum = " << s << endl;

	//简化switch 
	PrintSwitchCase(1);
	PrintSwitchCase_Marco(1);
	return 0;
}