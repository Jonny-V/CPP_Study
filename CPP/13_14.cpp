#include<iostream>
using namespace std;
class numbered {
public:
	static int num;
	int mysn;
	numbered()
	{
		num++;
		mysn = num;
	}
	numbered(const numbered &s)
	{
		num++;
		mysn = num;
	}
};

void f(const numbered &s)
{
	cout << s.mysn << endl;
}

int numbered::num = 0;

int main()
{
	numbered a, b = a, c = b;
	f(a);
	f(b);
	f(c);
	system("pause");
	return 0;
}