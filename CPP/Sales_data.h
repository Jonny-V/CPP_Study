//
// Created by Jonny Wu on 2017/9/1.
//

#ifndef SALES_DATA_H
#define SALES_DATA_H

#include<string>
#include <iostream>

class Sales_data {
public:
	friend  std::istream &read(std::istream &is, Sales_data &hs);
	friend  std::ostream &print(std::ostream &os, const Sales_data &hs);
	friend  Sales_data add(const Sales_data &lhs, const Sales_data &rhs);

	Sales_data() = default;
	Sales_data(const std::string &No) :bookNo(No) { };
	Sales_data(const std::string &No, unsigned int price, double num) :
		bookNo(No), units_sold(price), revenue(price*num) { };
	Sales_data(std::istream &is)
	{
		read(is, *this);
	}
	std::string isbn() const;
	double avg_price() const;
	Sales_data &combine(const Sales_data &rhs);

private:
	std::string bookNo; //ISBN
	unsigned int units_sold = 0; //unit price
	double revenue = 0; //all income

};


#endif //SALES_DATA_H