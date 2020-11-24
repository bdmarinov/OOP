#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Observer
{
public:
	Observer();

	virtual void update(const string &, double = 0) = 0;

	virtual const string & getName() const = 0;

	virtual Observer * clone() const = 0;

	//virtual void print() const = 0;

	~Observer();
};

