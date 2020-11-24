#pragma once
#include "Expression.h"
class Product :
	public Expression
{
public:
	Product(const Expression &, const Expression &);

	Product(const Product &);
	Product & operator =(const Product &);

	double value() const override;
	void print() const override;

	void helperPrint() const override;
	Expression * clone() const override;

	~Product();

private:
	Expression * one;
	Expression * two;
};

