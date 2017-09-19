#include<iostream>
#include<vector>
using namespace std;

int add(const int &, const int &);
int min(const int &, const int &);
int mul(const int &, const int &);
int div(const int &, const int &);

int main(int argv, char **args)
{
	vector<int(*)(const int &, const int &)> funP{ add,min,mul,div };
	for(auto p = funP.begin(); p != funP.end(); ++p)
		cout << (*p)(4, 2) << endl;
	system("pause");
	return 0;
}

int add(const int &a, const int &b)
{
	return a + b;
}

int min(const int &a, const int &b)
{
	return a - b;
}

int mul(const int &a, const int &b)
{
	return a * b;
}

int div(const int &a, const int &b)
{
	return a / b;
}