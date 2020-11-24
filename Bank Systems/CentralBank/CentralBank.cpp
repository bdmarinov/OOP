#include "stdafx.h"
#include "CentralBank.h"

void CentralBank::eraseObservers()
{
	for (int i = 0; i < observers.size(); i++) {
		delete observers[i];
	}
	observers.clear();
}

void CentralBank::copyObservers(const CentralBank & other)
{
	for (int i = 0; i < other.observers.size(); i++) {
		observers.push_back(other.observers[i]->clone());
	}
}

bool CentralBank::existCurrency(const string & currency) const
{
	for (int i = 0; i < currencies.size(); i++) {
		if (currencies[i].getCurrency() == currency) {
			return true;
		}
	}
	return false;
}

bool CentralBank::existObserver(const Observer & observer) const
{
	for (int i = 0; i < observers.size(); i++) {
		if (observers[i]->getName() == observer.getName()) {
			return true;
		}
	}
	return false;
}

CentralBank::CentralBank(const string & n_name) : name(n_name)
{

}

CentralBank::CentralBank(const CentralBank & other) : name(other.name), currencies(other.currencies)
{
	copyObservers(other);
}

CentralBank & CentralBank::operator =(const CentralBank & other)
{
	if (this != &other) {
		name = other.name;
		eraseObservers();
		copyObservers(other);
	}
	return *this;
}

void CentralBank::addCurrency(const string & currency, double rate)
{
	if (!existCurrency(currency)) {
		currencies.push_back(Currency(currency,rate));
	}
	else {
		cout << "Error adding currency type.Currency already exists\n";
		return;
	}
}

void CentralBank::deleteCurrency(const string & currency)
{
	for (int i = 0; i < currencies.size(); i++) {
		if (currencies[i].getCurrency() == currency) {
			currencies.erase(currencies.begin() + i);
		}
	}
}
bool CentralBank::setRate(const string & currency, double rate)
{
	for (int i = 0; i < currencies.size(); i++) {
		if (currencies[i].getCurrency() == currency) {
			currencies[i].setRate(rate);
			return true;
		}
	}
	return false;
}

void CentralBank::listCurrencies() const
{
	cout << "Bank: " << name << "\n";
	for (int i = 0; i < currencies.size(); i++) {
		currencies[i].print();
	}
}

void CentralBank::listObservers() const
{
	for (int i = 0; i < observers.size(); i++) {
		cout << observers[i]->getName() << "\n";
	}
}

void CentralBank::Register(const Observer & observer)
{
	if (!existObserver(observer)) {
		observers.push_back(observer.clone());
	}
	else {
		cout << "Observer with the same name already exists\n";
		return;
	}
}

void CentralBank::unregister(const Observer & observer)
{
	for (int i = 0; i < observers.size(); i++) {
		if (observers[i]->getName() == observer.getName()) {
			delete observers[i];
			observers.erase(observers.begin() + i);
		}
	}
}

void CentralBank::notify(int index, const string & currency, double rate) const
{
	observers[index]->update(currency,rate);
}

void CentralBank::update(const Observer & observer, const string & currency, double rate)
{
	for (int i = 0; i < observers.size(); i++) {
		if (observers[i]->getName() == observer.getName()) {
			if (setRate(currency, rate)) {
				notify(i, currency, rate);
			}
			else {
				cout << "Wrong currency name\n";
				return;
			}
		}
	}
}

const string & CentralBank::getName() const
{
	return name;
}

CentralBank::~CentralBank()
{
	eraseObservers();
}


/*
void CentralBank::update(const string & currency, double rate)
{
for (int i = 0; i < currencies.size(); i++) {
if (currencies[i].getCurrency() == currency) {
setRate(currency, rate);
notify(i, currency, rate);
}
}
}

Observer* CentralBank::clone() const
{
return new CentralBank(*this);
}

const string & CentralBank::getName() const
{
return name;
}
*/