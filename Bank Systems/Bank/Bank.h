#pragma once
#include "Customer.h"
#include "Account.h"
#include "CurrentAccount.h"
#include "SavingsAccount.h"
#include "PrivilegeAccount.h"
#include <vector>

class Bank
{
public:
	Bank(string, string, vector<Customer> &, vector<Account *> &);
	string getName() const;
	string getAddress() const;

	void addCustomer(int, string, string);
	void listCustomers() const;
	void deleteCustomer(const int);

	void addAccount(string, int, int, double);
	void listAccounts() const;
	void deleteAccount(const int);
	void listCustomerAccount(const int) const;

	void transfer(int, int, double);

	void deposit(int, double);
	void withdraw(int, double);

	void display() const;

	~Bank();

private:
	string name;
	string address;
	vector<Customer> customers;
	vector<Account *> accounts;
	const bool checkOwnerID(int) const;
	const bool checkIban(int) const;
	const bool accountCheckOwnerID(int) const;

};

