//
// Created by Jonny Wu on 2017/9/1.
//

#include "Sales_data.h"

std::string Sales_data::isbn() const
{
	return bookNo;
}

double Sales_data::avg_price() const
{
	return revenue / units_sold;
}

Sales_data &Sales_data::combine(const Sales_data &rhs)
{
	units_sold += rhs.units_sold;
	revenue += rhs.units_sold;
	return *this;
}

std::istream &read(std::istream &is, Sales_data &hs)
{
	double price = 0;
	is >> hs.bookNo >> hs.units_sold >> price;
	hs.revenue = hs.units_sold * price;
	return  is;
}

std::ostream &print(std::ostream &os, const Sales_data &hs)
{
	os << hs.isbn() << " " << hs.units_sold << " " << hs.avg_price() << " " << hs.revenue;
	return os;
}

Sales_data add(const Sales_data &lhs, const Sales_data &rhs)
{
	Sales_data temp(lhs);
	temp.combine(rhs);
	return temp;
}

