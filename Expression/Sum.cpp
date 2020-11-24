#include "stdafx.h"
#include "Sum.h"


Sum::Sum(const Expression & n_one, const Expression & n_two)
{
	one = n_one.clone();
	two = n_two.clone();
}

Sum::Sum(const Sum & other)
{
	one = other.one->clone();
	two = other.two->clone();
}

Sum & Sum::operator =(const Sum & other)
{
	if (this != &other) {
		delete one;
		delete two;
		one = other.one->clone();
		two = other.two->clone();
	}
	return *this;
}

double Sum::value() const
{
	return one->value() + two->value();
}
void Sum::print() const
{
	cout << "(";
	one->print();
	cout << "+";
	two->helperPrint();
	cout << ")";
}


Expression * Sum::clone() const
{
	return new Sum(*this);
}

void Sum::helperPrint() const
{
	cout << "(";
	one->print();
	cout << "+";
	two->helperPrint();
	cout << ")";
}

Sum::~Sum()
{
	delete one;
	delete two;
}
