#include<string>
using namespace std;

class HasPtr {
public:
	HasPtr(const string &s=string()):ps(new string(s)),i(0),use(new size_t(1)){}
	HasPtr(const HasPtr &s)
	{
		++*s.use;
		ps = s.ps;
		i = s.i;
		use = s.use;
	}
	~HasPtr()
	{
		if (--*use == 0)
		{
			delete ps;
			delete use;
		}
	}
	HasPtr& operator=(const HasPtr &rhp)
	{
		++*rhp.use;
		if (--*use == 0)
		{
			delete ps;
			delete use;
		}
		ps = rhp.ps;
		i = rhp.i;
		use = rhp.use;
		return *this;
	}

private:
	string *ps;
	int i;
	size_t *use;
};