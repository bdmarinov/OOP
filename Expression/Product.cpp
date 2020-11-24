#include "stdafx.h"
#include "Product.h"


Product::Product(const Expression & n_one, const Expression & n_two)
{
	one = n_one.clone();
	two = n_two.clone();
}

Product::Product(const Product & other)
{
	one = other.one->clone();
	two = other.two->clone();
}

Product & Product::operator =(const Product & other)
{
	if (this != &other) {
		delete one;
		delete two;
		one = other.one->clone();
		two = other.two->clone();
	}
	return *this;
}

double Product::value() const
{
	return one->value() * two->value();
}
void Product::print() const
{
	cout << "(";
	one->print();
	cout << "*";
	two->helperPrint();
	cout << ")";
}

Expression * Product::clone() const
{
	return new Product(*this);
}

void Product::helperPrint() const
{
	cout << "(";
	one->print();
	cout << "*";
	two->helperPrint();
	cout << ")";
}

Product::~Product()
{
	delete one;
	delete two;
}
