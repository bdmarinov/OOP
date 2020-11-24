#pragma once
#include "Expression.h"
class Sum :
	public Expression
{
public:
	Sum(const Expression &, const Expression &);

	Sum(const Sum &);
	Sum & operator =(const Sum &);

	double value() const override;
	void print() const override;

	void helperPrint() const override;
	Expression * clone() const override;

	~Sum();

private:
	Expression * one;
	Expression * two;
};

