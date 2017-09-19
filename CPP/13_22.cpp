#include<iostream>
#include<string>
using namespace std;

class HasPtr {
public:
	HasPtr() :ps(new string()),i(0) {}
	HasPtr(const string &s) :ps(new string(s)),i(0) {}
	~HasPtr() { delete ps; }
	HasPtr(const HasPtr &s)
	{
		ps = new string(*s.ps);
		i = s.i;
	}
	HasPtr& operator=(const HasPtr &rhp)
	{
		string *temp = new string(*rhp.ps);
		delete ps;
		ps = temp;
		i = rhp.i;
		return *this;
	}


private:
	string *ps;
	int i;
};

int main()
{

}