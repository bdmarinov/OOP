#include "stdafx.h"
#include "Account.h"


Account::Account(int n_iban, int n_ownerid, double n_amount)
{
	iban = n_iban;
	ownerid = n_ownerid;
	amount = n_amount;
}

double Account::getBalance() const
{
	return amount;
}

int Account::getIban() const
{
	return iban;
}

int Account::getCustomerId() const
{
	return ownerid;
}

Account::~Account()
{

}
