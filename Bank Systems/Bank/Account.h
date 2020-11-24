#pragma once
#include <iostream>

using namespace std;

class Account
{
public:
	Account(int, int, double);

	virtual void deposit(double) = 0;
	virtual bool withdraw(double) = 0;
	virtual void display() const = 0;

	double getBalance() const;

	int getIban() const;

	int getCustomerId() const;

	virtual ~Account();

protected:
	int iban;
	int ownerid;
	double amount;
};

