#pragma once
#include "Observer.h"
class ConcreteObserver :
	public Observer
{
public:
	ConcreteObserver(const string & );

	void update(const string &, double = 0) override;
	Observer * clone() const override;
	const string & getName() const override;

	~ConcreteObserver();

private:
	string name;
};

