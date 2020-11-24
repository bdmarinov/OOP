#include "stdafx.h"
#include "CurrentAccount.h"


CurrentAccount::CurrentAccount(int n_iban, int n_ownerid, double n_amount) : Account(n_iban, n_ownerid, n_amount)
{

}

void CurrentAccount::deposit(double sum)
{
	amount += sum;
}

bool CurrentAccount::withdraw(double sum)
{
	if (getBalance() - sum >= 0) {
		amount -= sum;
		return true;
	}
	return false;
}

void CurrentAccount::display() const
{
	cout << "Current Account " << iban << " " << ownerid << " " << amount << "\n";
}

CurrentAccount::~CurrentAccount()
{

}
