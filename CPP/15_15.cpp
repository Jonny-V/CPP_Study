#include<string>
#include<iostream>
using namespace std;

class Quote{
public:
	Quote() = default;
	Quote(const string &s, double sales_price) :bookNo(s),price(sales_price) { }
	string isbn() const { return bookNo; }
	virtual double net_price(size_t n) const
	{
		return n*price;
	}
private:
	string bookNo = "";
protected:
	double price = 0.0;
};

class Disc_quote :public Quote {
public:
	Disc_quote() = default;
	Disc_quote(const string &s,double sales_price,size_t n,double disc)
		:Quote(s,sales_price),num(n),discount(disc) { }
	double net_price(size_t n) const = 0;

protected:
	size_t num = 0;
	double discount = 0.0;
};

class Bluk_quote :public Disc_quote {
public:
	Bluk_quote() = default;
	Bluk_quote(const string &s, double sales_price, size_t n, double disc)
		:Disc_quote(s, sales_price, n, disc) {}
	double net_price(size_t n) const override
	{
		if(n>=num)
			return n*price*(1 - discount);
		else
			return n*price;
	}
};

class Max_quote :public Disc_quote {
public:
	Max_quote() = default;
	Max_quote(const string &s, double sales_price, size_t n, double disc)
		:Disc_quote(s, sales_price, n, disc) {}
	double net_price(size_t n) const override
	{
		if(n<num)
			return n*price*(1 - discount);
		else
			return n*price;
	}
};

void print_total(const Quote& book, size_t n)
{
	double ret = book.net_price(n);
	cout << "ISBN:" << book.isbn() << "	total due:" << ret << endl;
	//	return ret;
}

int main()
{
	Quote book1("1120", 2.5);
	Bluk_quote book2("1121", 2.5, 10, 0.1);
	Max_quote book3("1122", 2.5, 10, 0.2);
//	Disc_quote book4("1122", 2.5, 10, 0.2);
	print_total(book1, 4);
	print_total(book2, 12);
	print_total(book3, 8);
	system("pause");
	return 0;
}