//
// Created by Jonny Wu on 2017/9/1.
//

#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <iostream>

class Person {
public:
	friend std::istream &read(std::istream &is, Person &someone);

	friend std::ostream &print(std::ostream &os, const Person &someone);

	Person() = default;

	Person(const std::string &na, const std::string &addr) :
		name(na), address(addr) {
	};

	Person(std::istream &is) {
		read(is, *this);
	}



private:
	std::string name;
	std::string address;

	std::string getname() const;

	std::string getaddress() const;
};


#endif //PERSON_H
