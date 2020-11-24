// zadacha.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Customer.h"
#include "Account.h"
#include "CurrentAccount.h"
#include "SavingsAccount.h"
#include "PrivilegeAccount.h"
#include "Bank.h"
#include <string>
#include <vector>

using namespace std;

void menu(Bank & bank)
{
	int number;
	while (cin >> number && (number>0 && number < 12)) {
		cin.ignore();
		switch (number) {
		case 1:bank.listCustomers();
			break;
		case 2:
		{
			int id;
			string name;
			string address;
			cin >> id;
			cin.ignore();
			getline(cin, name);
			getline(cin, address);
			bank.addCustomer(id, name, address);
		}
			break;
		case 3:
		{
			int userID;
			cin >> userID;
			cin.ignore();
			bank.deleteCustomer(userID);
		}
			break;
		case 4:bank.listAccounts();
			break;
		case 5:
			int customerID;
			cin >> customerID;
			bank.listCustomerAccount(customerID);
			break;
		case 6:
		{
			string type;
			int iban, ownerid;
			double amount;
			getline(cin, type);
			cin >> iban;
			cin.ignore();
			cin >> ownerid;
			cin.ignore();
			cin >> amount;
			cin.ignore();
			bank.addAccount(type, iban, ownerid, amount);
		}
			break;
		case 7:
		{
			int customerIban;
			cin >> customerIban;
			bank.deleteAccount(customerIban);
		}
			break;
		case 8:
		{
			int withdrawIban;
			double withdrawAmount;
			cin >> withdrawIban >> withdrawAmount;
			bank.withdraw(withdrawIban, withdrawAmount);
		}
			break;
		case 9:
		{
			int depositIban;
			double depositAmount;
			cin >> depositIban >> depositAmount;
			bank.deposit(depositIban, depositAmount);
		}
		break;
		case 10:
		{
			int fromIBAN, toIBAN;
			double transferAmount;
			cin >> fromIBAN >> toIBAN >> transferAmount;
			bank.transfer(fromIBAN, toIBAN, transferAmount);
		}
			break;
		case 11:
			bank.display();
			break;
		case 12:
			break;
		}
	}	
}

int main()
{
	vector<Customer> customers;
	vector<Account *> accounts;
	
	customers.push_back(Customer(1, "Bogdan Dechkov Marinov", "Rakovski 146, Stara Zagora"));
	customers.push_back(Customer(2, "Daniela Baeva Ivanova", "Rakovski 146, Stara Zagora"));
	customers.push_back(Customer(3, "Dechko Marinov Ivanov", "Rakovski 146, Stara Zagora"));
	customers.push_back(Customer(4, "Diana Peneva Baeva", "12-ti Pehoten Polk, Stara Zagora"));
	customers.push_back(Customer(5, "Iveta Jivkova Toteva", "Buglarsko Opulchenie 5B, Stara Zagora"));
	customers.push_back(Customer(6, "Simeon Ivanov Gidikov", "Sveta Troica 35, Stara Zagora"));
	
	accounts.push_back(new CurrentAccount(970704, 1, 350));
	accounts.push_back(new CurrentAccount(970528, 5, 1100));
	accounts.push_back(new CurrentAccount(970705, 6, 120));
	accounts.push_back(new SavingsAccount(97070476, 1, 520));
	accounts.push_back(new PrivilegeAccount(97070408, 1, 2020));

	Bank bank("DSK", "Stara Zagora, Lenin 14", customers, accounts);
	menu(bank);

	for (int i = 0; i < accounts.size(); i++) {
		delete accounts[i];
	}

    return 0;
}

