#include<iostream>
using namespace std;

class Base {
public:
	virtual void f()	{		cout << "Base::f()" << endl;	}
	virtual void g()	{		cout << "Base::g()" << endl;	}
	virtual void h()	{		cout << "Base::h()" << endl;	}
};

class Base1 {
public:
	virtual void f()	{		cout << "Base1::f()" << endl;	}
	virtual void g()	{		cout << "Base1::g()" << endl;	}
	virtual void h()	{		cout << "Base1::h()" << endl;	}
};

class Base2 {
public:
	virtual void f()	{		cout << "Base2::f()" << endl;	}
	virtual void g()	{		cout << "Base2::g()" << endl;	}
	virtual void h()	{		cout << "Base2::h()" << endl;	}
};

class Derive :public Base {
public:
	virtual void f1()	{		cout << "Derive::f1()" << endl;	}
	virtual void g1()	{		cout << "Derive::g1()" << endl;	}
	virtual void h1()	{		cout << "Derive::h1()" << endl;	}
private:
	virtual void m()	{		cout << "Derive::m()" << endl;	}
protected:
	virtual void n()	{		cout << "Derive::n()" << endl;	}
};

class Derive1 :public Base {
public:
	void f() override	{		cout << "Derive1::f()" << endl;	}
	void g() override	{		cout << "Derive1::g()" << endl;	}
	virtual void h1()	{		cout << "Derive1::h1()" << endl;}
};

class Multi_Derivel :public Base, public Base1, public Base2 {
	virtual void f1()	{		cout << "Multi_Derive::f1()" << endl;	}
	virtual void g1()	{		cout << "Multi_Derive::g1()" << endl;	}
	virtual void h1()	{		cout << "Multi_Derive::h1()" << endl;	}
};

class Multi_Derivel1 :public Base, public Base1, public Base2 {
	void f() override	{		cout << "Multi_Derive1::f()" << endl;	}
	virtual void g1()	{		cout << "Multi_Derive1::g1()" << endl;	}
	virtual void h1()	{		cout << "Multi_Derive1::h1()" << endl;	}
};

int main()
{
	typedef void(*Fun)(void);
	Fun pFun = nullptr;

	/*�麯����ʵ�ֻ���*/
	Base b;
	cout << "�麯�����ַΪ��" << &b << endl;
	cout << "�麯�����һ���麯����ַΪ��" << (int*)*(int*)(&b) << endl;
	for (int i = 0; i < 3; i++)
	{
		pFun = (Fun)*((int*)*(int*)(&b) + i);
		pFun();
	}
	cout << endl;

	/*����̳и����麯������ƣ��޸��ǣ� �����麯����ǰ �����麯���ں�*/
	pFun = nullptr;
	Derive d;
	for (int i = 0; i < 6; i++)
	{
		pFun = (Fun)*((int*)*(int*)(&d) + i);
		pFun();
	}
	cout << endl;
	
	/*����̳и����麯������ƣ��и��ǣ� ���า�Ǻ�����ǰ �����麯������ �����麯���ں�*/
	pFun = nullptr;
	Derive1 d1;
	for (int i = 0; i < 4; i++)
	{
		pFun = (Fun)*((int*)*(int*)(&d1) + i);
		pFun();
	}
	cout << endl;

	/*���ؼ̳� �����޸��� ÿ�����඼��һ���麯���� ������麯�����ڵ�һ��������麯������*/
	pFun = nullptr;
	Multi_Derivel md;
	for (int i = 0; i < 6; i++)
	{
		pFun = (Fun)*((int*)*(int*)(&md) + i);
		pFun();
	}
	pFun = nullptr;
	for (int i = 0; i < 3; i++)
	{
		pFun = (Fun)*((int*)*((int*)(&md) + 1) + i);
		pFun();
	}
	pFun = nullptr;
	for (int i = 0; i < 3; i++)
	{
		pFun = (Fun)*((int*)*((int*)(&md) + 2) + i);
		pFun();
	}
	cout << endl;
	
	/*���ؼ̳� �����и��� ÿ�����඼��һ���麯���� ���ǵĺ��������麯������λ��Ȼ���Ǹ�����麯����������麯�����ڵ�һ��������麯������*/
	pFun = nullptr;
	Multi_Derivel1 md1;
	for (int i = 0; i < 5; i++)
	{
		pFun = (Fun)*((int*)*(int*)(&md1) + i);
		pFun();
	}
	pFun = nullptr;
	for (int i = 0; i < 3; i++)
	{
		pFun = (Fun)*((int*)*((int*)(&md1) + 1) + i);
		pFun();
	}
	pFun = nullptr;
	for (int i = 0; i < 3; i++)
	{
		pFun = (Fun)*((int*)*((int*)(&md1) + 2) + i);
		pFun();
	}
	cout << endl;

	/*���ú���ָ�� �ø���ָ��������������麯�� ��¶��C++�İ�ȫ��Ƿȱ ���⻹���Է���private��protected���麯����*/
	Derive dt;
	Base *bt = &dt;
	pFun = nullptr;
	for (int i = 0; i < 8; i++)
	{
		pFun = (Fun)*((int*)*(int*)(&(*bt)) + i);
		pFun();
	}
	cout << endl;


	system("pause");
	return 0;
}