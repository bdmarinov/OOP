#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Observer.h"
#include "ConcreteObserver.h"

using namespace std;

class Currency
{
public:
	Currency(const string & n_currency = "", double n_rate = 0) : currency(n_currency), rate(n_rate)
	{

	}

	void setCurrency(const string & n_currency)
	{
		currency = n_currency;
	}

	void setRate(double n_rate)
	{
		rate = n_rate;
	}

	const string & getCurrency() const
	{
		return currency;
	}

	void print() const
	{
		cout << currency << "  " << rate << "\n";
	}

	double getRate() const
	{
		return rate;
	}

	~Currency()
	{

	}

private:
	string currency;
	double rate;
};

class CentralBank		// : public Observer //Firstly, i got the wrong idea of the task, and made central bank a derived class of Observers
{
public:
	CentralBank(const string & );
	CentralBank(const CentralBank & );
	CentralBank & operator =(const CentralBank &);
	
	void addCurrency(const string &, double = 0);
	void deleteCurrency(const string &);
	bool setRate(const string &, double);

	const string & getName() const;
	void listCurrencies() const;
	void listObservers() const;

	void Register(const Observer &);
	void unregister(const Observer &);
	void notify(int, const string &, double ) const;

	void update(const Observer &,const string &, double);
	
	//Observer* clone() const override;
	//void update(const string &, double = 0) override;
	//const string & getName() const override;
	~CentralBank();


private:
	string name;
	vector<Currency> currencies;
	vector<Observer *> observers;
	
	void eraseObservers();
	void copyObservers(const CentralBank &);
	
	bool existCurrency(const string &) const;
	bool existObserver(const Observer &) const;
};

