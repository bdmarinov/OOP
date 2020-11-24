#include "stdafx.h"
#include "SavingsAccount.h"


SavingsAccount::SavingsAccount(int n_iban, int n_ownerid, double n_amount, double n_interestRate) : Account(n_iban, n_ownerid, n_amount)
{
	interestRate = n_interestRate;
}

double SavingsAccount::getInterestRate() const
{
	return interestRate;
}

void SavingsAccount::deposit(double sum)
{
	amount += sum;
}

bool SavingsAccount::withdraw(double sum)
{
	if (getBalance() - sum >= 0) {
		amount -= sum;
		return true;
	}
	return false;
}

void SavingsAccount::display() const
{
	cout << "Savings Account " << iban << " " << ownerid << " " << interestRate << "% " << amount << "\n";
}

SavingsAccount::~SavingsAccount()
{

}
