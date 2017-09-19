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

	/*虚函数表实现机制*/
	Base b;
	cout << "虚函数表地址为：" << &b << endl;
	cout << "虚函数表第一个虚函数地址为：" << (int*)*(int*)(&b) << endl;
	for (int i = 0; i < 3; i++)
	{
		pFun = (Fun)*((int*)*(int*)(&b) + i);
		pFun();
	}
	cout << endl;

	/*子类继承父类虚函数表机制（无覆盖） 父类虚函数在前 子类虚函数在后*/
	pFun = nullptr;
	Derive d;
	for (int i = 0; i < 6; i++)
	{
		pFun = (Fun)*((int*)*(int*)(&d) + i);
		pFun();
	}
	cout << endl;
	
	/*子类继承父类虚函数表机制（有覆盖） 子类覆盖函数在前 父类虚函数在中 子类虚函数在后*/
	pFun = nullptr;
	Derive1 d1;
	for (int i = 0; i < 4; i++)
	{
		pFun = (Fun)*((int*)*(int*)(&d1) + i);
		pFun();
	}
	cout << endl;

	/*多重继承 函数无覆盖 每个父类都有一个虚函数表 子类的虚函数放在第一个父类的虚函数表中*/
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
	
	/*多重继承 函数有覆盖 每个父类都有一个虚函数表 覆盖的函数放在虚函数表首位，然后是父类的虚函数表，子类的虚函数放在第一个父类的虚函数表中*/
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

	/*利用函数指针 用父类指针来访问子类的虚函数 暴露出C++的安全性欠缺 另外还可以访问private和protected的虚函数表*/
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