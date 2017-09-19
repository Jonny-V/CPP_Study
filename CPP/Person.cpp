//
// Created by Jonny Wu on 2017/9/1.
//

#include "Person.h"

std::string Person::getname() const {
	return name;
}

std::string Person::getaddress() const {
	return address;
}

std::istream &read(std::istream &is, Person &someone) {
	is >> someone.name >> someone.address;
	return is;
}

std::ostream &print(std::ostream &os, const Person &someone) {
	os << someone.getname() << " " << someone.getaddress();
	return os;
}
