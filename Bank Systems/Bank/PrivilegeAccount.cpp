#include "stdafx.h"
#include "PrivilegeAccount.h"


PrivilegeAccount::PrivilegeAccount(int n_iban, int n_ownerid, double n_amount, double n_overdraft) : Account(n_iban, n_ownerid, n_amount)
{
	overdraft = n_overdraft;
}

double PrivilegeAccount::getOverdraft() const
{
	return overdraft;
}

void PrivilegeAccount::deposit(double sum)
{
	amount += sum;
}

bool PrivilegeAccount::withdraw(double sum)
{
	if ((getBalance() + overdraft) - sum >= 0) {
		amount -= sum;
		return true;
	}
	return false;
}

void PrivilegeAccount::display() const
{
	cout << "Privilege Account " << iban << " " << ownerid << " " << overdraft << " " << amount << "\n";
}

PrivilegeAccount::~PrivilegeAccount()
{

}
