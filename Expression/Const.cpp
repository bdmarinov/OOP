#include "stdafx.h"
#include "Const.h"


Const::Const( double n_val) : val(n_val)
{

}

double Const::value() const
{
	return val;
}

void Const::print() const
{
	cout << val;
}

Expression * Const::clone() const
{
	return new Const(*this);
}

void Const::helperPrint() const
{
	cout << val;
}

Const::~Const()
{

}
