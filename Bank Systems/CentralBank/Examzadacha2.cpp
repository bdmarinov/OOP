// Examzadacha2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "CentralBank.h"

using namespace std;

int main()
{
	CentralBank bank("BNB");
	
	bank.addCurrency("Euro", 1.96);
	bank.addCurrency("Dollar", 1.67);
	bank.addCurrency("Pound", 2.21);
	bank.addCurrency("MKD", 0.377);
	bank.addCurrency("CZK", 0.4221);
	bank.addCurrency("UKR", 0.6667);

	ConcreteObserver one("Banka DSK");
	ConcreteObserver two("Biznes poshta");
	ConcreteObserver three("BNT");
	ConcreteObserver four("BTV");
	ConcreteObserver five("OBB - Obedinena Bulgarska Banka");
	ConcreteObserver six("Nova TV");
	ConcreteObserver seven("Vestnik 24 chasa");

	bank.Register(one);
	bank.Register(two);
	bank.Register(three);
	bank.Register(four);
	bank.Register(five);
	bank.Register(six);
	bank.Register(seven);

	//bank.listCurrencies();
	//bank.listObservers();

	bank.update(two, "Dollar", 1.77);
	bank.update(six, "Dollar", 1.69);
	bank.update(six, "CZK", 0.4223);
	bank.update(one, "Euro", 1.97);

	//bank.listCurrencies();
	//bank.listObservers();

	bank.unregister(three);
	bank.unregister(four);

	bank.update(seven, "MKD", 0.3766);
	bank.update(seven, "MKD", 0.3767);
	bank.update(two, "Pound", 2.27);

	//bank.listCurrencies();
	//bank.listObservers();

	
	/*
	CentralBank bank2 = bank;
	bank2.listCurrencies();
	bank2.listObservers();
	*/

    return 0;
}

