#include <iostream>
using namespace std;

int main()
{
	int N = 100,M = 10;

	//&M ��ֵ���� �����޸�M��ֵ
	auto g = [N, &M](int i) {
		M= 20;
		//N= 11;//���� ���ʽ�����ǿ��޸ĵ���ֵ
		return N*i;
	};
	cout <<g(10)<<endl;
	cout <<M <<endl;


	//���ղ����շ�Χ�����еı���
	auto g1 = [&](int i) {
		M = 30;
		N = 111;
		return N * i;
		};
	cout << g1(10) << endl;
	cout << M << endl;


	//���ղ����շ�Χ�����еı���
	auto g2 = [=](int i) {
		//M = 30;//���� ���ʽ�����ǿ��޸ĵ���ֵ
		//N = 111;//���� ���ʽ�����ǿ��޸ĵ���ֵ
		return N * i;
		};
	cout << g2(10) << endl;
	cout << M << endl;


	//��ϲ���
	auto g3 = [& ,N](int i) {
		M = 40;
		//N = 111;//���� ���ʽ�����ǿ��޸ĵ���ֵ
		return N * i;
		};
	cout << g3(10) << endl;
	cout << M << endl;
}