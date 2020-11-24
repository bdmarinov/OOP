#pragma once
#include "Account.h"
class CurrentAccount :
	public Account
{
public:
	CurrentAccount(int, int , double);

	void deposit(double) override;
	bool withdraw(double) override;

	void display() const override;

	~CurrentAccount();
};

