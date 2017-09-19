#include<iostream>
#include<vector>
using namespace std;
class X {
public:
	X() {
		cout << "X()" << endl;
	}

	X(const X&) {
		cout << "X(const X&)" << endl;
	}

	X& operator=(const X& x) 
	{	cout << "X& operator=(const X& x)" << endl; 
		return *this; }

	~X() { 
		cout << "~X()" << endl;
	}
};

void func(const X& a, const X b) 
{
	vector<X>vec;
	cout << "1111111111" << endl;
	vec.push_back(a);//X(const X&)
	cout << "1111" << endl;
	vec.push_back(b);//X(const X&)
	cout << "111" << endl;
	//~X()
	//~X()
}

int main()
{
	X* a = new X;//X()
	X* c = a; //X()
	*c = *a;//X& operator=(const X& x)
	X d(*a);//X(const X&)
	func(*a, d);
	system("pause");
	return 0;
	//~X()
	//~X()
	//~X()

	
}

/*
Right Display
X() // ��a���г�ʼ��
X& operator=(const X& x) //
X(const X&)	//
X(const X&)	//������ʼ��
1111111111
X(const X&)  //*aΪ�������ͣ�����Ҫ���и�ֵ����
1111
X(const X&) //bΪֵ���� �˴�Ϊb��ֵ����
X(const X&)	//b��������
~X()	//����b
111
~X()	//����*a
~X()	//����*b
~X()	//����*c

*/