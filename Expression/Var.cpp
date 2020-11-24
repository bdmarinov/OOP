#include "stdafx.h"
#include "Var.h"


Var::Var(const char * n_name, double n_val) : val(n_val)
{
	name = new char[strlen(n_name) + 1];
	strcpy(name, n_name);
}

Var::Var(const Var & other) : val(other.value())
{
	name = nullptr;
	setName(other.name);
}

Var & Var::operator =(const Var & other)
{
	if (this != &other) {
		val = other.value();
		setName(other.name);
	}
	return *this;
}

void Var::setValue(double n_val)
{
	val = n_val;
}

double Var::value() const
{
	return val;
}

void Var::print() const
{
	cout << name;
}

void Var::setName(const char * n_name)
{
	if (name != nullptr) {
		delete[] name;
		name = nullptr;
	}
	name = new char[strlen(n_name) + 1];
	strcpy(name, n_name);
}

Expression * Var::clone() const
{
	return new Var(*this);
}

void Var::helperPrint() const
{
	cout << val;
}

Var::~Var()
{
	delete[] name;
}
