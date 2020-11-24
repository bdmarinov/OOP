#include "stdafx.h"
#include "ConcreteObserver.h"


ConcreteObserver::ConcreteObserver(const string & n_name) : name(n_name)
{

}

void ConcreteObserver::update(const string & currency, double rate)
{
	cout << "Update " << name << ": " << currency << " " << rate << "\n";
}

const string & ConcreteObserver::getName() const
{
	return name;
}

Observer * ConcreteObserver::clone() const
{
	return new ConcreteObserver(*this);
}

ConcreteObserver::~ConcreteObserver()
{

}
