#include<string>
#include<iostream>
using namespace std;

class Quote {
public:
	Quote() = default;
	Quote(const string &s, double sales_price):bookNo(s),price(sales_price) { }
	string isbn() const { return bookNo; }
	virtual double net_price(size_t n) const
	{
		return n*price;
	}
	virtual void debug() const
	{
		cout << "bookNo:" << bookNo << "	price:" << price;
	}
private:
	string bookNo = "";
protected:
	double price = 0.0;
};

class Bulk_quote :public Quote {
public:
	Bulk_quote() = default;
	Bulk_quote(const string &book,double sales_price,size_t n,double disc)
		:Quote(book,sales_price),min(n),discount(disc){ }
	double net_price(size_t n) const override
	{
		if (n >= min)
			return n*price*(1 - discount);
		else
			return n*price;
	}
	void debug() const override
	{
		Quote::debug();
		cout << "	min:" << min << "	discount:" << discount << endl;
	}
private:
	size_t min = 0;
	double discount = 0.0;
};

class Max_quote :public Quote {
public:
	Max_quote() = default;
	Max_quote(const string &book, double sales_price, size_t n, double disc)
		:Quote(book, sales_price), max(n), discount(disc) { }
	double net_price(size_t n) const override
	{
		if (n < max)
			return n*price*(1 - discount);
		else
			return n*price;
	}
	void debug() const override
	{
		Quote::debug();
		cout << "	max:" << max << "	discount:" << discount << endl;
	}
private:
	size_t max = 0;
	double discount = 0.0;
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
	Bulk_quote book2("1121", 2.5, 10, 0.1);
	Max_quote book3("1122", 2.5, 10, 0.2);
	print_total(book1, 4);
	print_total(book2, 12);
	print_total(book3, 8);
	book1.debug();
	cout << endl;
	book2.debug();
	book3.debug();
	system("pause");
	return 0;
}