#include "stdafx.h"
#include "Bank.h"


Bank::Bank(string n_name, string n_address, vector <Customer> & n_customers, vector <Account *> & n_accounts)
{
	name = n_name;
	address = n_address;
	customers = n_customers;
	accounts = n_accounts;
}

string Bank::getName() const
{
	return name;
}

string Bank::getAddress() const
{
	return address;
}

void Bank::addCustomer(int customerId, string name, string address)
{
	bool flag = false;
	for (int i = 0; i < customers.size(); i++) {
		if (customers[i].getID() == customerId) {
			flag = true;
		}
	}
	if (flag == false) {
		Customer temp(customerId, name, address);
		customers.push_back(temp);
	}
}

void Bank::listCustomers() const
{
	for (int i = 0; i < customers.size(); i++) {
		customers[i].display();
	}
}

const bool Bank::accountCheckOwnerID(int ownerID) const
{
	for (int i = 0; i < accounts.size(); i++) {
		if (accounts[i]->getCustomerId() == ownerID) {
			return true;
		}
	}
	return false;
}

void Bank::deleteCustomer(const int customerId)
{
	for (int i = 0; i < customers.size(); i++) {
		if (customers[i].getID() == customerId) {
			customers.erase(customers.begin()+i);
		}
	}
	
	while (accountCheckOwnerID(customerId)) {
		for (int i = 0; i < accounts.size(); i++) {
			if (accounts[i]->getCustomerId() == customerId) {
				accounts.erase(accounts.begin() + i);
			}
		}
	}
}

const bool Bank::checkOwnerID(int ownerid) const
{
	bool flag = false;
	for (int i = 0; i < customers.size(); i++) {
		if (customers[i].getID() == ownerid) {
			flag = true;
		}
	}
	return flag;
}

const bool Bank::checkIban(int iban) const
{
	bool flag = true;
	for (int i = 0; i < accounts.size(); i++) {
		if (accounts[i]->getIban() == iban) {
			flag = false;
		}
	}
	return flag;
}

void Bank::addAccount(string type, int iban, int ownerid, double amount)
{
	if (checkOwnerID(ownerid) && checkIban(iban))
	{
		if (type == "Current Account" || type == "CurrentAccount" || type == "current account" || type == "Current account" || type == "current" || type == "Current") {
			accounts.push_back(new CurrentAccount(iban, ownerid, amount));
		}
		else if (type == "Savings Account" || type =="SavingsAccount" || type == "savings account" || type == "Savings account" || type =="Savings" || type == "savings") {
			accounts.push_back(new SavingsAccount(iban, ownerid, amount));
		}
		else if (type == "Privilege Account" || type =="PrivilegeAccount" || type == "privilege account" || type == "Privilege account" || type == "Privilege" || type == "privilege") {
			accounts.push_back(new PrivilegeAccount(iban, ownerid, amount));
		}
		else {
			cout << "Invalid account type\n";
			return;
		}
	}
	else {
		cout << "Error adding account. Customer id doesn't exist or iban number is already used\n";
		return;
	}
}

void Bank::listCustomerAccount(const int customerId) const
{
	/*
	for (int i = 0; i < customers.size(); i++) {
		if (customers[i].getID() == customerId) {
			customers[i].display();
		}
	}
	*/

	for (int i = 0; i < accounts.size(); i++) {
		if (accounts[i]->getCustomerId() == customerId) {
			accounts[i]->display();
		}
	}
}

void Bank::listAccounts() const
{
	for (int i = 0; i < accounts.size(); i++) {
		accounts[i]->display();
	}
}

void Bank::deleteAccount(const int iban)
{
	for (int i = 0; i < accounts.size(); i++) {
		if (accounts[i]->getIban() == iban) {
			accounts.erase(accounts.begin() + i);
		}
	}
}

void Bank::transfer(int fromIBAN, int toIBAN, double amount)
{
	bool hasMoney = false;
	if ((!checkIban(fromIBAN) && !checkIban(toIBAN))) {
		for (int i = 0; i < accounts.size(); i++) {
			if (accounts[i]->getIban() == fromIBAN) {
				if (accounts[i]->withdraw(amount)) {
					hasMoney = true;
				}
			}
			if (accounts[i]->getIban() == toIBAN && hasMoney) {
				accounts[i]->deposit(amount);
			}
		}
	}
}

void Bank::deposit(int iban, double amount)
{
	for (int i = 0; i < accounts.size(); i++) {
		if (accounts[i]->getIban() == iban) {
			accounts[i]->deposit(amount);
		}
	}
}

void Bank::withdraw(int iban, double amount)
{
	for (int i = 0; i < accounts.size(); i++) {
		if (accounts[i]->getIban() == iban) {
			accounts[i]->withdraw(amount);
		}
	}
}

void Bank::display() const
{
	cout << "Bank " << name << " " << address << " " << customers.size() << " " << accounts.size() << "\n";
}

Bank::~Bank()
{
	
}
