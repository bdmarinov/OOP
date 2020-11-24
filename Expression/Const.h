#pragma once
#include "Expression.h"
class Const :
	public Expression
{
public:
	Const(double = 0);

	double value() const override;
	void print() const override;

	void helperPrint() const override;
	Expression * clone() const override;

	~Const();

private:
	double val;
};

