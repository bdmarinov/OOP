#include "stdafx.h"
#include "Customer.h"


Customer::Customer(int n_id, string n_name, string n_address)
{
	id = n_id;
	name = n_name;
	address = n_address;
}

int Customer::getID() const
{
	return id;
}

string Customer::getName() const
{
	return name;
}

string Customer::getAddress() const
{
	return address;
}

void Customer::display() const
{
	cout << getID() << " " << getName() << " " << getAddress() << "\n";
}

Customer::~Customer()
{

}
