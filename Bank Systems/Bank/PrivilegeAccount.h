#pragma once
#include "Account.h"
class PrivilegeAccount :
	public Account
{
public:
	PrivilegeAccount(int, int, double, double  = 250);

	double getOverdraft() const;

	void deposit(double) override;
	bool withdraw(double) override;

	void display() const override;

	~PrivilegeAccount();

private:
	double overdraft = 250;
};

