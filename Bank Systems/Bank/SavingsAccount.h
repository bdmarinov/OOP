#pragma once
#include "Account.h"
class SavingsAccount :
	public Account
{
public:
	SavingsAccount(int, int, double, double = 2);

	double getInterestRate() const;

	void deposit(double) override;
	bool withdraw(double) override;

	void display() const override;

	~SavingsAccount();

private:
	double interestRate = 2;
};

