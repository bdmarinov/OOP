#pragma once
#include "Expression.h"
class Var :
	public Expression
{
public:
	Var(const char * = "", double = 0);
	Var(const Var &);
	Var & operator =(const Var &);

	void setValue(double);

	double value() const override;
	void print() const override;

	void helperPrint() const override;
	Expression * clone() const override;

	~Var();

private:
	char * name;
	double val;

	void setName(const char *);
};

